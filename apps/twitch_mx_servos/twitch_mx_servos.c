/* wireless_serial app:
 * This app allows you to connect two Wixels together to make a wireless,
 * bidirectional, lossless serial link.  
 * See description.txt or the Wixel User's Guide for more information.
 */

/*
 * TODO: To avoid damage, don't enable nDTR and nRTS outputs by default.
 * TODO: use LEDs to give feedback about sending/receiving bytes.
 * TODO: UART flow control.
 * TODO: Obey CDC-ACM Set Line Coding commands:
 *       In USB-RADIO mode, bauds 0-255 would correspond to radio channels.
 * TODO: shut down radio when we are in a different serial mode
 * TODO: make the heartbeat blinks on the Wixels be synchronized (will require
 *       major changes to the radio_link library)
 * TODO: turn on red LED or flash it if the Wixel is in a mode that requires USB
 *       but has not reached the USB Configured State (this avoids the problem of
 *       having 0 LEDs on when the Wixel is in USB-UART mode and self powered)
 */

/** Dependencies **************************************************************/
#include <wixel.h>


#ifdef INCL_USB
#include <usb.h>
#include <usb_com.h>
#endif

// #include <radio_com.h>
// #include <radio_link.h>

#include <uart0.h>
#include <uart1.h>

#include <malloc.h>


#include "HeaderDefs.h"

// #include "Commander.h"
// #include "Interpolate.h"

#include "dynamixel.h"
#include "ax.h"
// #define ax12SetGOAL_POSITION(servo,val) 	dynamixel_writeword(servo,AX_GOAL_POSITION_L,CLAMP(val,0,1023))	
#define ax12LED(servo,val)					dynamixel_writebyte(servo,AX_LED,CLAMP(val,0,1))

#include "GaitRunner.h"
#include "gait.h"

/** Enables *******************************************************************/
#define GAIT_ENABLE
// #define INCL_USB
// #define LED_DEBUG_GAITPROCESS
// #define LED_DEBUG_GAITRUN
// #define LED_DEBUG_CONTROLOGIC


/** Parameters ****************************************************************/
#define SERIAL_MODE_AUTO        0
#define SERIAL_MODE_USB_RADIO   1
#define SERIAL_MODE_UART_RADIO  2
#define SERIAL_MODE_USB_UART    3
// int32 CODE param_serial_mode = SERIAL_MODE_AUTO;
int32 CODE param_serial_mode = SERIAL_MODE_UART_RADIO;

// This is the baud rate used by UART
// Note: Wixel maximum UART sbaud rate is 1.5 Mbaud.
int32 CODE param_baud_rate_DYNA = DYNAMIXEL_BAUDRATE;
int32 CODE param_baud_rate_UART = 115200;

int32 CODE param_nDTR_pin = 10;
int32 CODE param_nRTS_pin = 11;
int32 CODE param_nDSR_pin = 12;
int32 CODE param_nCD_pin = 13;

int32 CODE param_DTR_pin = -1;
int32 CODE param_RTS_pin = -1;
int32 CODE param_DSR_pin = -1;
int32 CODE param_CD_pin = -1;

int32 CODE param_arduino_DTR_pin = 0;

// Approximate number of milliseconds to disable UART's receiver for after a
// framing error is encountered.
// Valid values are 0-250.
// A value of 0 disables the feature (the UART's receiver will not be disabled).
// The actual number of milliseconds that the receiver is disabled for will be
// between param_framing_error_ms and param_framing_error_ms + 1.
int32 CODE param_framing_error_ms = 0;

/** Global Variables **********************************************************/

// This bit is 1 if the UART's receiver has been disabled due to a framing error.
// This bit should be equal to !U1CSR.RE, but we need this variable because we
// don't want to be reading U1CSR in the main loop, because reading it might
// cause the FE or ERR bits to be cleared and then the ISR
// would not receive notice of those errors.
BIT uartRxDisabled = 0;

// uint8 DATA currentSerialMode;

BIT framingErrorActive = 0;

BIT errorOccurredRecently = 0;
// uint8 lastErrorTime;


#define START_SPEED 75

///////////////////////
/////TURRET////////////
///////////////////////
#define PAN_CENTER 511
#define TILT_CENTER 531 //+ 95
#define PAN_SPEED 100
#define TILT_SPEED 100
// 4*52 -> 60 degrees? for AX-12
#define servo74Min PAN_CENTER - 4 * (52+20)
#define servo74Max PAN_CENTER + 4 * (52+20)
#define servo75Min 511 - 4 * 21
#define servo75Max 511 + 4 * 44

#define gaitMin71  1590 - 50
#define gaitMin72  1691
#define gaitMin73  1691 + 35
#define gaitMin74  457

#define gaitMax71  2506 + 50
#define gaitMax72  2405
#define gaitMax73  2405 - 35
#define gaitMax74  567

uint16 CODE gaitMinPos[4] = {gaitMin71, gaitMin72, gaitMin73, gaitMin74};
uint16 CODE gaitMaxPos[4] = {gaitMax71, gaitMax72, gaitMax73, gaitMax74};

#define clampMin71  1848
#define clampMin72  1691
#define clampMin73  1691
#define clampMin74  452

#define clampMax71  2248
#define clampMax72  2405
#define clampMax73  2405
#define clampMax74  572


uint16 CODE clampMinPos[4] = {clampMin71, clampMin72, clampMin73, clampMin74};
uint16 CODE clampMaxPos[4] = {clampMax71, clampMax72, clampMax73, clampMax74};

// turndir: 1 if using AX, -1 if using MX
#define turndir -1

#define DEADZONE 20	

// Integers corresponding with "positions" used for logic.
#define START_POS   100
#define SIT_POS     101
#define MOVING_POS  102

///MATHEMATICA CODE
///loopSpeed = 1000;
///Plot[65.536*loopSpeed/speed, {speed, 0, 128}, PlotRange -> {500, 4000}]
const uint16 g8loopSpeed = 1800;
uint16 g8speed = 25;
int8 g8playbackDir = 1; // value should only ever be -1 or 1.
// int8 g8repeatCount = 0;

#define FAST_TURN_SPEED  50
#define SLOW_TURN_SPEED  70

uint8 currentPos = SIT_POS;


uint16 pan_pos;
uint16 tilt_pos;


// volatile const uint8 *all;

/** Functions *****************************************************************/

void updateLeds()
{
    static BIT dimYellowLed = 0;
    static uint16 lastRadioActivityTime;
    uint16 now;

#ifdef INCL_USB
    usbShowStatusWithGreenLed();
#endif

    now = (uint16)getMs();

    // if (currentSerialMode == SERIAL_MODE_USB_UART)
    // {
        // // The radio is not being used, so turn off the yellow LED.
        // LED_YELLOW(0);
    // }
    // if (!radioLinkConnected())
    // {
        // // We have not connected to another device wirelessly yet, so do a
        // // 50% blink with a period of 1024 ms.
        // LED_YELLOW(now & 0x200 ? 1 : 0);
    // }
    // else
    // {
        // // We have connected.

        // if ((now & 0x3FF) <= 20)
        // {
            // // Do a heartbeat every 1024ms for 21ms.
            // LED_YELLOW(1);
        // }
        // else if (dimYellowLed)
        // {
            // static uint8 DATA count;
            // count++;
            // LED_YELLOW((count & 0x7)==0);
        // }
        // else
        // {
            // LED_YELLOW(0);
        // }
    // }

    // if ((uint8)(now - lastErrorTime) > 100)
    // {
        // errorOccurredRecently = 0;
    // }

    // LED_RED(errorOccurredRecently || uartRxDisabled);
}

/* Returns the logical values of the input control signal pins.
   Bit 0 is DSR.
   Bit 1 is CD. */
// uint8 ioRxSignals()
// {
    // uint8 signals = 0;

    // if ((param_CD_pin >= 0 && isPinHigh(param_CD_pin)) ||
            // (param_nCD_pin >= 0 && !isPinHigh(param_nCD_pin)))
    // {
        // signals |= 2;
    // }

    // if ((param_DSR_pin >= 0 && isPinHigh(param_DSR_pin)) ||
            // (param_nDSR_pin >= 0 && !isPinHigh(param_nDSR_pin)))
    // {
        // signals |= 1;
    // }

    // return signals;
// }

/* Sets the logical values of the output control signal pins.
   This should be called frequently (not just when the values change).
   Bit 0 is DTR.
   Bit 1 is RTS. */
void ioTxSignals(uint8 signals)
{
    static uint8 nTrstPulseStartTime;
    static uint8 lastSignals;

    // Inverted outputs
    setDigitalOutput(param_nDTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 0 : 1);
    setDigitalOutput(param_nRTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 0 : 1);

    // Non-inverted outputs.
    setDigitalOutput(param_DTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 1 : 0);
    setDigitalOutput(param_RTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 1 : 0);

    // Arduino DTR pin.
    if (!(lastSignals & ACM_CONTROL_LINE_DTR) && (signals & ACM_CONTROL_LINE_DTR))
    {
        // We just made a falling edge on the nDTR line, so start a 1-2ms high pulse
        // on the nTRST line.
        setDigitalOutput(param_arduino_DTR_pin, HIGH);
        nTrstPulseStartTime = getMs();
    }
    else if ((uint8)(getMs() - nTrstPulseStartTime) >= 2)
    {
        setDigitalOutput(param_arduino_DTR_pin, LOW);
    }

    lastSignals = signals;
}

void errorOccurred()
{
    // lastErrorTime = (uint8)getMs();
    errorOccurredRecently = 1;
}

void errorService()
{
    static uint8 lastRxLowTime;

    if (uart1RxBufferFullOccurred)
    {
        uart1RxBufferFullOccurred = 0;
        errorOccurred();
    }

    if (uart1RxFramingErrorOccurred)
    {
        uart1RxFramingErrorOccurred = 0;

        // A framing error occurred.
        framingErrorActive = 1;
        errorOccurred();

        if (param_framing_error_ms > 0)
        {
            // Disable the UART's receiver.
            U1CSR &= ~0x40;    // U1CSR.RE = 0.  Disables reception of bytes on the UART.
            uartRxDisabled = 1;
            lastRxLowTime = (uint8)getMs();  // Initialize lastRxLowTime even if the line isn't low right now.
        }
    }

    if (framingErrorActive)
    {
        if (!isPinHigh(17))
        {
            errorOccurred();
        }
        else
        {
            framingErrorActive = 0;
        }
    }

    if (uartRxDisabled)
    {
        if (!isPinHigh(17))
        {
            // The line is low.
            lastRxLowTime = (uint8)getMs();
        }
        else if ((uint8)(getMs() - lastRxLowTime) > param_framing_error_ms)
        {
            // The line has been high for long enough, so re-enable the receiver.
            U1CSR |= 0x40;
            uartRxDisabled = 0;
        }
    }
}


void uartToRadioService()
{
    // Data
    while(uart1RxAvailable() && uart0TxAvailable())
    {
        uart0TxSendByte(uart1RxReceiveByte());
    }
    // while(uart1RxAvailable() && radioComTxAvailable())
    // {
        // radioComTxSendByte(uart1RxReceiveByte());
    // }
	
	//Read radio's buffer
    // CmdrReadMsgs(); //In this case, CmdrReadMsgs() does the reading.
	///We handle CmdrReadMsgs() elsewhere since it has parameters now.
	
	//    while(radioComRxAvailable() && uart1TxAvailable())
//    {
//        uart1TxSendByte(radioComRxReceiveByte());
//    }

    // // Control Signals.
    // ioTxSignals(radioComRxControlSignals());
    // radioComTxControlSignals(ioRxSignals());
}

// void usbToUartService()
// {
    // uint8 signals;

    // // Data
    // while(usbComRxAvailable() && uart1TxAvailable())
    // {
        // uart1TxSendByte(usbComRxReceiveByte());
    // }

    // while(uart1RxAvailable() && usbComTxAvailable())
    // {
        // usbComTxSendByte(uart1RxReceiveByte());
    // }

    // ioTxSignals(usbComRxControlSignals());

    // // Need to switch bits 0 and 1 so that DTR pairs up with DSR.
    // signals = ioRxSignals();
    // usbComTxControlSignals( ((signals & 1) ? 2 : 0) | ((signals & 2) ? 1 : 0));

    // // TODO: report framing, parity, and overrun errors to the USB host here
// }



/* process messages coming from Commander 
 *  format = 0xFF RIGHT_H RIGHT_V LEFT_H LEFT_V BUTTONS EXT checksum_cmdr */
int8 CmdrReadMsgs(int8 *desiredGait, int8 *desiredDir, int8 *desiredSpeed){
	int8 buttonval;
	// while(radioComRxAvailable() > 0){
	while(uart0RxAvailable() > 0){
		if(index_cmdr == -1){         // looking for new packet
			if(uart0RxReceiveByte() == 0xff){ //read until packet start
				index_cmdr = 0;
				checksum_cmdr = 0;
			}
		}else if(index_cmdr == 0){
			// add next byte to vals
			vals[index_cmdr] = (unsigned char) uart0RxReceiveByte();
			// look for first real byte (non 0xFF)
			// if(checksum_cmdr == 0) { ax12LED(71,0);}
			if(vals[index_cmdr] != 0xff){
				checksum_cmdr += (uint8) vals[index_cmdr];
				index_cmdr++;  // will now save subsequent bytes
			}
		}else{ //for bytes after the 0th byte
			vals[index_cmdr] = (unsigned char) uart0RxReceiveByte(); 
			//loops will sequentially read bytes and store them here

			checksum_cmdr += (uint8) vals[index_cmdr];
			index_cmdr++;
			
			// DEBUG: if all packets go through, shoudl see x2 through 
			// 	x7 when Commander input is being received.
			// rprintf("x%u ",index_cmdr);
			
			if(index_cmdr == 7){ // packet complete
				if(checksum_cmdr%256 != 255){
					// packet error!
					// rprintf("\npacket error!\n");
					index_cmdr = -1;
					return 0;
				}
				else{
					buttonval = vals[4];
					// short dowalking = TRUE;
					
					//rprintf("\t%d\t",(int)buttonval);
					//Turn gait...
					// if((buttonval&0x40) > 0){ //if(buttonval & BUT_LT){
						// // if(PRINT_DEBUG_COMMANDER){rprintf("lft\t");}
						// turnleft = zTRUE;
						// turnright = zFALSE;
						
						// // dowalking = zFALSE;
					// }
					// else if((buttonval&0x80) > 0){ //if(buttonval & BUT_RT){
						// // if(PRINT_DEBUG_COMMANDER){rprintf("rgt\t");}
						// turnright = zTRUE;
						// turnleft = zFALSE;
						
						// // dowalking = zFALSE;
					// }
					// else { // Do nothing
						// turnright = zFALSE;
						// turnleft = zFALSE;
						// // turn = zFALSE;
					// }
					// if((buttonval&BUT_L6) > 0){
						// gunbutton = zTRUE;
						// // if(PRINT_DEBUG_COMMANDER){rprintf("guns\t");}
					// }
					// else{gunbutton = zFALSE;}

					// if((buttonval&BUT_R3) > 0){
						// panicbutton = zTRUE;
						// // if(PRINT_DEBUG_COMMANDER){rprintf("panic\t");}
					// }
					// else{panicbutton = zFALSE;}
					
					// if((buttonval&BUT_L4) > 0){
						// infobutton = zTRUE;
						// // if(PRINT_DEBUG_COMMANDER){rprintf("info\t");}
					// }
					// else{infobutton = zFALSE;}
					
					if((buttonval&BUT_R2) > 0){ // TURRET CENTERING
						pan_pos = PAN_CENTER;
						dynamixel_writeword(74, AX_GOAL_POSITION_L, pan_pos);
						tilt_pos = TILT_CENTER;
						dynamixel_writeword(75, AX_GOAL_POSITION_L, tilt_pos);
						// if(PRINT_DEBUG_COMMANDER){rprintf("look\t");}
					}
					// else{infobutton = zFALSE;}
					
					// if((buttonval&BUT_R1) > 0){
						// agitbutton = zTRUE;
						// // if(PRINT_DEBUG_COMMANDER){rprintf("agit\t");}
					// }
					// else{agitbutton = zFALSE;}
					
					// if (dowalking){
					
					// vals - 128 gives look a vlaue in the range from -128 to 127?
					lookV = (signed char)( (int8)vals[0]-128 );
					lookH = (signed char)( (int8)vals[1]-128 );
					
					//Default handling in original Commander.c - sets to range of -127 to 127 or so...
					walkV = (signed char)( (int8)vals[2]-128 );
					walkH = (signed char)( (int8)vals[3]-128 );
					
					// }
					// pan = (vals[0]<<8) + vals[1];
					// tilt = (vals[2]<<8) + vals[3];
					// buttons = vals[4];
					// ext = vals[5];
				}
				index_cmdr = -1;
				
				///Empty the packet buffer
				while (uart0RxAvailable() > 0) { uart0RxReceiveByte(); }
				
				///////////////////////////////////////////
				///Set commands based on controller signals
				
				/// Conflicting directions -> STOP
				if ( (lookV > DEADZONE && walkV < -DEADZONE) || (walkV > DEADZONE && lookV < -DEADZONE) ) {
					*desiredGait = NO_GAIT;
					*desiredDir = -1;	// Pointless; Logic chain shouldn't use desiredDir with NO_GAIT...
					*desiredSpeed = 0;
					
				/// Turret mode on
				} else if ((buttonval&BUT_L4) > 0){
					int16 add_var;
					
					*desiredGait = NO_GAIT;
					*desiredDir = -1;	// Pointless; Logic chain shouldn't use desiredDir with NO_GAIT...
					*desiredSpeed = 0;
					
					// Move turret
					
					add_var = ((float)lookH)/17;
					pan_pos = CLAMP(pan_pos + add_var, servo74Min, servo74Max);
					dynamixel_writeword(74, AX_GOAL_POSITION_L, pan_pos);
					
					add_var = ((float)lookV)/25;
					tilt_pos = CLAMP(tilt_pos + add_var, servo75Min, servo75Max);
					dynamixel_writeword(75, AX_GOAL_POSITION_L, tilt_pos);
					
				/// Walk mode
				} else if (lookV > DEADZONE || walkV > DEADZONE ) {	///walk 
					if(buttonval&BUT_LT || buttonval&BUT_RT){
						*desiredGait = G8_ANIM_WALK_STRAIGHT;
					} else {
						*desiredGait = G8_ANIM_WALK_STRAIGHT_SLOW;
					}
					*desiredDir = 1;
					*desiredSpeed = 50;
					
				///Walk
				} else if (lookV < -DEADZONE || walkV < -DEADZONE) {	///walk 
					if(buttonval&BUT_LT || buttonval&BUT_RT){
						*desiredGait = G8_ANIM_WALK_STRAIGHT_BACK;
					} else {
						*desiredGait = G8_ANIM_WALK_STRAIGHT_BACK_SLOW;
					}
					*desiredDir = 1;
					*desiredSpeed = 50;
					
				// if (lookV > DEADZONE) {			///walk forward
					// *desiredGait = G8_ANIM_WALK_STRAIGHT_SLOW;
					// *desiredDir = 1;
					// *desiredSpeed = 50;
				// } else if (lookV < -DEADZONE) {	///walk backwards
					// *desiredGait = G8_ANIM_WALK_STRAIGHT_BACK_SLOW;
					// *desiredDir = 1;
					// *desiredSpeed = 50;
				/// **********************************************************
				// // } else if (lookH > DEADZONE) {	///Turn right slow
				// } else if((buttonval&BUT_R1) > 0){
					// if(buttonval&BUT_LT || buttonval&BUT_RT){
						// *desiredGait = G8_ANIM_TURN_RIGHT;
					// } else {
						// *desiredGait = G8_ANIM_TURN_SLOW;
					// }
					// *desiredDir = 1;
					// *desiredSpeed = 70;
				// // } else if (lookH < -DEADZONE) {	///Turn left slow
				// } else if((buttonval&BUT_L6) > 0){
					// if(buttonval&BUT_LT || buttonval&BUT_RT){
						// *desiredGait = G8_ANIM_TURN_RIGHT;
					// } else {
						// *desiredGait = G8_ANIM_TURN_SLOW;
					// }
					// *desiredDir = -1;
					// *desiredSpeed = -70;
				/// **********************************************************
				} else if (walkH * turndir > DEADZONE) {	///Turn right fast
				// } else if(buttonval & BUT_RT){
					*desiredGait = G8_ANIM_TURN_RIGHT;
					*desiredDir = 1;
					*desiredSpeed = FAST_TURN_SPEED;
				} else if (walkH * turndir < -DEADZONE) {	///Turn left
				// } else if(buttonval & BUT_LT){
					*desiredGait = G8_ANIM_TURN_RIGHT;
					*desiredDir = -1;
					*desiredSpeed = -1 * FAST_TURN_SPEED;
				} else if (lookH * turndir > DEADZONE) {	///Turn right fast
				// } else if(buttonval & BUT_RT){
					*desiredGait = G8_ANIM_TURN_SLOW;
					*desiredDir = 1;
					*desiredSpeed = SLOW_TURN_SPEED;
				} else if (lookH * turndir < -DEADZONE) {	///Turn left
				// } else if(buttonval & BUT_LT){
					*desiredGait = G8_ANIM_TURN_SLOW;
					*desiredDir = -1;
					*desiredSpeed = -1 * SLOW_TURN_SPEED;
				/// **********************************************************
				// } else if (walkV > DEADZONE) {			///walk forward
					// *desiredGait = G8_ANIM_WALK_STRAIGHT;
					// *desiredDir = 1;
					// *desiredSpeed = 70;
				// } else if (walkV < -DEADZONE) {	///walk backwards
					// *desiredGait = G8_ANIM_WALK_STRAIGHT_BACK;
					// *desiredDir = 1;
					// *desiredSpeed = 70;
				} else {
					*desiredGait = NO_GAIT;
					*desiredDir = -1;	// Pointless; Logic chain shouldn't use desiredDir with NO_GAIT...
					*desiredSpeed = 0;
				}
				
				// Reset pan_pos when movement is being done.
				if (*desiredGait != NO_GAIT) {
					pan_pos = PAN_CENTER;
				}
				
				return CMDR_ALIVE_CNT;
			}
		}
	}
	return -1;
}	// End of CmdrReadMsgs



// Initialise a gait runner from appInitHardware or appInitSoftware
void gaitRunnerInit(G8_RUNNER* runner){
	if(runner->speeds == null){
		uint8 i=0;
		runner->speeds = malloc(NUM_ACTUATORS * sizeof(int8));
		// runner->delta = malloc(runner->num_actuators * sizeof(int8));
		for(i=0; i < NUM_ACTUATORS; i++){
			// runner->speeds[i] = runner->delta[i] = 0;
			runner->speeds[i] = 0;
		}
	}
}

// Start running a new animation
void gaitRunnerPlay(G8_RUNNER* runner, uint8 animation, int16 loopSpeed, int8 speed, int8 repeatCount){
	// Update variables with interrupts off - in case the gait is
	// updated under interrupts
	uint32 now = getMs();
#ifdef LED_DEBUG_GAITRUN
	ax12LED(71,1);
#endif
	// CRITICAL_SECTION {
	__critical {
		runner->animation = animation;
		runner->repeatCount = repeatCount;
		runner->frame = 0;
		runner->playing = TRUE;
		runner->startTime =  now;
		runner->currentTime = (speed<0) ? loopSpeed : 0;
		runner->totalTime = loopSpeed;	///Always positive?
		runner->speed = speed;
		runner->backwards = FALSE;
	// }
	}
	// Set servos to initial position
	gaitRunnerProcess(runner);
}

//Note that definitions in gait.h are: 
//		MAKE_G8_LIMB_POSITION(cubeX,cubeY, squareX,squareY, timeX, timeY, startY)
// Webbotlib uses Bezier curves. See:
//  http://www.societyofrobots.com/robotforum/index.php?topic=16143.msg114405#msg114405
//Example call: uint16 actualX = calcX(limb, distance);
// cubeX seems to be -2/3 * squareX.
// t1 = distance  ?
//
static uint16 calcX(const G8_LIMB_POSITION* limb, float t1){
	int16 a = (int16)pgm_read_word(&limb->cubeX);
	int16 b = (int16)pgm_read_word(&limb->squareX);
	int16 c = (int16)pgm_read_word(&limb->timeX);
	float t2 = t1 * t1;
	float t3 = t2 * t1;
	uint16 nx = (uint16) ( (t3 * a) + (t2 * b) + (t1 * c) );
	return nx;
}

static int8 calcY(const G8_LIMB_POSITION* limb, float t1){
	int16 a = (int16)pgm_read_word(&limb->cubeY);
	int16 b = (int16)pgm_read_word(&limb->squareY);
	int16 c = (int16)pgm_read_word(&limb->timeY);
	int8 d = (int8)pgm_read_byte(&limb->startY);
	float t2 = t1 * t1;
	float t3 = t2 * t1;
	int8 ny = (int8) ( (t3 * a) + (t2 * b) + (t1 * c) + d );
	return ny;
}


// Update the gait runner and move servos to new positions
// Call it from your main loop or via the scheduler to do it in the background
// NB There is no point scheduling any faster than 20ms as that is the servo refresh rate
// Return true if an animation is playing
void gaitRunnerProcess(G8_RUNNER* runner){

	uint32 now;
	// int16_t  interval = (now - runner->startTime)>>16; //original
	int16  interval;
	
// #ifdef LED_DEBUG_GAITPROCESS
	uint8 led = 0;
// #endif

	const G8_ANIMATION* animation;
	int16 currentTime;
	uint16 frameTime;
	uint16 frameStartTime;
	uint16 frameEndTime;
	const G8_FRAME* frame;
	uint8 i;
	uint16 frameTimeOffset;
	// uint16 l;
	float distanceGuess;
	const G8_LIMB_POSITION* limb;
	
	now = getMs();
	interval = (int16)((now) - (runner->startTime))>>16;	//subtract previous 'startTime'
	
	if(!gaitRunnerIsPlaying(runner) || (runner->speeds)==null){
#ifdef	LED_DEBUG_GAITPROCESS
		ax12LED(71, led);
#endif
		return; // FALSE;
	}
	
	if(runner->animation == NO_GAIT){
#ifdef	LED_DEBUG_GAITPROCESS
		ax12LED(71, led);
#endif
		return; // FALSE;
	}

	if(interval == 0){		//Happens if ....
		// return TRUE;
		interval = 1;
	}

	// There has been a noticeable change in time
	runner->startTime = now;
	if(runner->backwards){
		interval *= -1;
	}
	interval *= runner->speed;
	
	
	if(interval < 0){
		// led = 1;
	}

	// Re-check as drive speed could be zero
	if(interval == 0){
#ifdef	LED_DEBUG_GAITPROCESS
		ax12LED(71, led);
#endif
		return; // TRUE;
	}
	
	// led = 1;

	// Locate the current animation
	animation = &runner->animations[runner->animation];

	// Update the current time with the new interval
	currentTime = runner->currentTime + interval;
	if(currentTime >= runner->totalTime){
		// We have finished playing the animation
		if(pgm_read_byte(&animation->sweep)==FALSE){
			currentTime %= runner->totalTime;			// Set back to start of loop
			if(runner->repeatCount){
				runner->repeatCount -= 1;				// One less frame to go{
				// led = 1;
				if(runner->repeatCount==0){				/// Reached zero from a non-zero repeatCount
					runner->playing = FALSE;			// we have reached the end (of a repeating gait played forward?)
					currentTime = 0;					// set servos to final position
					runner->animation = NO_GAIT;
				}
			}
		}else if(pgm_read_byte(&animation->sweep)==2){
			currentTime = runner->totalTime;		//Triggers block at end of this function
			
		}else{
			// Start going backwards through the animation
			//		currentTime becomes totalTime - x, where x is how much currentTime exceeds totalTime
			currentTime = runner->totalTime - (currentTime - runner->totalTime);
			runner->backwards = TRUE;
		}
	///NOTE: currentTime is negative when... speed is negative, and we overshoot zero.
	}else if(currentTime < 0){
	
		// We have moved before the start
		if(pgm_read_byte(&animation->sweep)==FALSE){
			currentTime = runner->totalTime + currentTime;	///wrap around
			if(runner->repeatCount){
				runner->repeatCount += 1;				// One more frame to go ///(??? One less frame to go, really...){
				// led = 1;
				if(runner->repeatCount==0){				/// Reached zero from a non-zero repeatCount
					runner->playing = FALSE;			// we have reached the end (of a gait played backwards?)
					currentTime = 0;					// set servos to start position
					runner->animation = NO_GAIT;
					// if (currentPos != SIT_POS) {
						// currentPos = START_POS;
					// }
				}
			}
		}else if(pgm_read_byte(&animation->sweep)==2){
			currentTime = 0;		//Triggers block at end of this function
			
		}else{
			// We have completed a sweep; sweep = 1 or 2? Hmmmm...
			runner->backwards = FALSE;
			currentTime = -currentTime;

			if(runner->repeatCount){
				runner->repeatCount -= 1;			// One less frame to go (this is the end of a sweep with negative speed){
				// led = 1;
				if(runner->repeatCount==0){
					runner->playing = FALSE;		// we have reached the end (of a regular sweep)
					currentTime = 0;				// set servos to initial position
					runner->animation = NO_GAIT;
					// if (currentPos != SIT_POS) {
						// currentPos = START_POS;
					// }
				}
			}
		}
	}
	runner->currentTime = currentTime; // range is 0....totalTime

	// Current time in the range 0...SCALE_X
	frameTime = interpolateU(currentTime, 0,runner->totalTime, 0, SCALE_X);
	frameStartTime = 0;
	frameEndTime = SCALE_X;

	// Locate the correct frame
	frame = (const G8_FRAME*)pgm_read_word(&animation->frames);
	for(i = pgm_read_byte(&animation->numFrames)-1; i>0; i--){
		const G8_FRAME* f = &frame[i];
		frameStartTime = pgm_read_word(&f->time);
		if(frameStartTime <= frameTime){
			frame = f;
			break;
		}
		frameEndTime = frameStartTime;
		frameStartTime = 0;
	}
	runner->frame = i;

	// Now have:- frameStartTime <= frameTime <= frameEndTime

	// We now need to find the distance along the curve (0...1) that represents
	// the x value = frameTime

	// First guess from 0..1
	frameTimeOffset = frameTime-frameStartTime;
	i = 0;
	distanceGuess = ((float)(frameTimeOffset)) / ((float)(frameEndTime-frameStartTime));

	limb = (const G8_LIMB_POSITION*)pgm_read_word(&frame->limbs);
	// For each servo ...
	for(i = 0; i < NUM_ACTUATORS; i++, limb++){
		float distanceMin = 0.0;
		float distanceMax = 1.0;
		float distance = distanceGuess;
		uint8 iterations = 0;
		// Find the correct distance along the line for the required frameTime
		for(iterations=0; iterations<20; iterations++){
			uint16 actualX = calcX(limb, distance);
			if(actualX == frameTimeOffset) break;	// Found it

			if( actualX < frameTimeOffset){
				// We need to increase t
				distanceMin = distance;
			}else{
				distanceMax = distance;
			}

			// Next guess is half way between
			distance = distanceMin + ((distanceMax - distanceMin) / 2);
		}

		// We now know the distance
		runner->speeds[i] = calcY(limb,distance);

	}	// next limb

#ifndef DEBUG
	// Set all the servo speeds in quick succession
	{
	uint16 limbNumber = 0;
	uint8 speeds [12];
	for(limbNumber = 0; limbNumber < NUM_ACTUATORS; limbNumber++){
		// __ACTUATOR* servo = (__ACTUATOR*)pgm_read_word(&runner->actuators[limbNumber]);
		// uint8 servo = (uint8)(runner->ids[limbNumber]);
		///Note servo 1 = 71, servo 2 = 72, servo3 = 73, 71 is center servo.  72 is right servo.
		uint8 servo = (uint8)(71+limbNumber); // Using IDs 71, 72, 73
		int16 speed = (int16)(runner->speeds[limbNumber]);// + (int16)(runner->delta[limbNumber]);
		speed = CLAMP(speed, DRIVE_SPEED_MIN, DRIVE_SPEED_MAX); // [+/- 127]
		
		/// Min goal position for ends is 374... -> 650 max, aka +-	138(40deg)
		/// Center servo should go +- 80 at most.
		//speed = interpolateU(speed, DRIVE_SPEED_MIN, DRIVE_SPEED_MAX, 0, 1023);
		// For MX servos, 40deg/179deg*2048 -> +-457.7 -> 1590 to 2506
		//speed = interpolateU(speed, DRIVE_SPEED_MIN, DRIVE_SPEED_MAX, 374, 650);
		// MX in Twitch config +- 458
		//speed = interpolateU(speed, DRIVE_SPEED_MIN, DRIVE_SPEED_MAX, 1590, 2506);
		// MX in TwitchMX config: +- 357
		// speed = interpolateU(speed, DRIVE_SPEED_MIN, DRIVE_SPEED_MAX, 1691, 2405);
		speed = interpolateU(speed, DRIVE_SPEED_MIN, DRIVE_SPEED_MAX, \
								gaitMinPos[limbNumber], gaitMaxPos[limbNumber]);
		
		/// Variable speed when walking
		if( ( (limbNumber == 1) || (limbNumber == 2) ) && \
			((runner->animation == G8_ANIM_WALK_STRAIGHT) || \
			(runner->animation == G8_ANIM_WALK_STRAIGHT_SLOW) || \
			(runner->animation == G8_ANIM_WALK_STRAIGHT_BACK) || \
			(runner->animation == G8_ANIM_WALK_STRAIGHT_BACK_SLOW)) ){
			
			// speedFactor is ???? than 1
			float speedFactor;
			// float oldspeedFactor;
			
			speedFactor = 1.0;
			/// Logic for curved walking via ratios of left/right joysticks
			if(walkV > 20 || lookV > 20) {
				if (servo == RIGHT_SERVO && walkV > lookV){
					if (lookV < 20) { lookV = 20; }
					
					speedFactor = (1.0 + (lookV - 20) / ((float) (walkV - 20)) ) / 2.0;
				} else if (servo == LEFT_SERVO && walkV < lookV){
					if (walkV < 20) { walkV = 20; }
					
					speedFactor = (1.0 + (walkV - 20) / ((float) (lookV - 20)) ) / 2.0;
				}
			} else if(walkV < -20 || lookV < -20){
				if (servo == RIGHT_SERVO && walkV < lookV){
					if (lookV > -20) { lookV = -20; }
					
					speedFactor = (1.0 + (lookV + 20) / ((float) (walkV + 20)) ) / 2.0;
				} else if (servo == LEFT_SERVO && walkV > lookV){
					if (walkV > -20) { walkV = -20; }
					
					speedFactor = (1.0 + (walkV + 20) / ((float) (lookV + 20)) ) / 2.0;
				}
			}
			// speed = (int16)(speed * speedFactor);
			/// We combine (1) speed; and (2) speedFactor times the offset from center that is speed.
			// speed = speed + (int16)( ((int16)speed - 512) * speedFactor );
			// speed = speed + (int16)( ((int16)speed - 2048) * speedFactor );
			/// We combine (1) center position; and (2) speedFactor times the offset from center that is speed.
			// AX - Add
			//speed = 2048 + (int16)( ((int16)speed - 2048) * speedFactor );
			// MX - Subtract
			speed = 2048 - (int16)( ((int16)speed - 2048) * speedFactor );
		}
		
		/// Turret panning during walking
		
		
		/// Clamp all speeds to safe ranges
		speed = CLAMP(speed, clampMinPos[limbNumber], clampMaxPos[limbNumber]);
		// __act_setSpeed(servo,(int8)speed);
		// ax12SetGOAL_POSITION(servo, (uint16)speed);
		speeds[3*limbNumber] = servo;
		speeds[3*limbNumber+1] = (uint8) dynamixel_getlowbyte(speed);
		speeds[3*limbNumber+2] = (uint8) dynamixel_gethighbyte(speed);
		
	}
	dynamixel_syncwrite(AX_GOAL_POSITION_L, 2, NUM_ACTUATORS, speeds);
	}
#endif

	///Extra!
	///Stops gait when we get to the end of a sweep == 2 animation
	if( pgm_read_byte(&animation->sweep) == 2) {
		if( currentTime == runner->totalTime || currentTime == 0) {
			// if (currentTime == runner->totalTime) {
				// led = 1;
			// }
			// currentTime = 0; // affects nothing.
			runner->playing = FALSE;			// we have reached the end
			runner->animation = NO_GAIT;
			
			// if (currentPos != SIT_POS) {
				// currentPos = START_POS;
			// }
				
			// led = 1;
		}
	}
#ifdef	LED_DEBUG_GAITPROCESS
	ax12LED(71, led);
#endif
	
	return;
	// return runner->playing;
	// return gaitRunnerIsPlaying(runner);
}

// void gaitReverse(G8_RUNNER* runner){
	// runner->backwards *= -1;
	// runner->speed *= -1;
	
	

	// return;	
// }

// void gaitRunnerSetDelta(G8_RUNNER* runner, uint8 limbNumber, int8 speed ){
	// if(limbNumber < NUM_ACTUATORS){
		// runner->delta[limbNumber] = speed;
		// if(!gaitRunnerIsPlaying(runner)){
			// // Send the output now
			// // __ACTUATOR* servo = (__ACTUATOR*)pgm_read_word(&runner->actuators[limbNumber]);
			// uint8 servo = (uint8)(runner->ids[limbNumber]);
			// int16 speed = (int16)(runner->speeds[limbNumber]);// + (int16)(runner->delta[limbNumber]);
			// // speed = CLAMP(speed,DRIVE_SPEED_MIN,DRIVE_SPEED_MAX);
			// // speed = interpolateU(speed, DRIVE_SPEED_MIN, DRIVE_SPEED_MAX, 0, 1023);
			// // // __act_setSpeed(servo,(int8)speed);
			// // ax12SetGOAL_POSITION(servo, (uint16)speed);
		// }
	// }
// }




void main()
{
	// uint8 nextGait;
	int8 desiredGait = NO_GAIT;
	int8 desiredDir;
	int8 desiredSpeed;
	
	uint8 cmdrAlive = 0;
	
	// uint32 ms;
	// uint16 now;
	// uint16 speed;
	
	// static uint8 all[3] = {42,43,12};
	
#ifdef GAIT_ENABLE	
	// G8_RUNNER gait;
	// struct s_runner gait;
	
	// struct s_runner gait = { all, animations, 0,0,0,FALSE,0,0,0,FALSE, 0, null };
	
	// const G8_RUNNER gait = { all, animations, 0,0,0,FALSE,0,0,0,FALSE, 0, null };
	
	// G8_RUNNER gait = { all, animations, 0,0,0,FALSE,0,0,0,FALSE, 0, null };
	
	// G8_RUNNER gait;
	// gait = { all, animations, 0,0,0,FALSE,0,0,0,FALSE, 0, null };
	
	// gait = MAKE_G8_RUNNER(all, animations);
	// G8_RUNNER gait = MAKE_G8_RUNNER(all, animations);
	G8_RUNNER gait = MAKE_G8_RUNNER(animations);
	// gait = { all, animations, 0,0,0,FALSE,0,0,0,FALSE, 0, null };
#endif
	
    systemInit();
	
	//Among other things, allocates byte arrays for sending commands.
	dynamixel_init();

    // Initialize UARTs
    uart0Init();
    uart0SetBaudRate(param_baud_rate_UART);
    uart1Init();
    uart1SetBaudRate(param_baud_rate_DYNA);
	
	// Initialize other stuff
	index_cmdr = -1;
	
	
#ifdef GAIT_ENABLE
	gaitRunnerInit(&gait);
	
	gait.animation = NO_GAIT;
#endif
	
	delayMs(200);

///MATHEMATICA CODE
///loopSpeed = 1000;
///Plot[65.536*loopSpeed/speed, {speed, 0, 128}, PlotRange -> {500, 4000}]

// void gaitRunnerPlay(G8_RUNNER* runner, uint8 animation, int16 loopSpeed, int8 speed, int16 repeatCount)
	// gaitRunnerPlay(&gait,    G8_ANIM_DEFAULT,       g8loopSpeed, g8playbackDir * g8speed, g8playbackDir * g8repeatCount);
	// gaitRunnerPlay(&gait,    G8_ANIM_WALK_STRAIGHT, g8loopSpeed, g8playbackDir * g8speed, g8playbackDir * g8repeatCount);
	// gaitRunnerPlay(&gait,    G8_ANIM_START,       g8loopSpeed, g8playbackDir * g8speed, g8playbackDir * 1);
	// g8playbackDir = -1;
	gaitRunnerPlay(&gait,    G8_ANIM_START,       g8loopSpeed, START_SPEED, 1);
				
	// gaitRunnerPlay(&gait,    G8_ANIM_TURN_LEFT,       g8loopSpeed, g8playbackDir * g8speed, g8playbackDir * g8repeatCount);

    // Set turret servo speed limits
    dynamixel_writeword(74, AX_GOAL_SPEED_L, MY_TURRET_SERVO_SPEED);
	delayMs(10);
    dynamixel_writeword(75, AX_GOAL_SPEED_L, MY_TURRET_SERVO_SPEED);
	delayMs(10);
    
    // Center turret
	pan_pos = PAN_CENTER;
	dynamixel_writeword(74, AX_GOAL_POSITION_L, pan_pos);
	delayMs(10);
	tilt_pos = TILT_CENTER;
	dynamixel_writeword(75, AX_GOAL_POSITION_L, tilt_pos);

    while(1)
    {
		
        // updateSerialMode();
        boardService();
        updateLeds();
        errorService();

        // if (param_serial_mode != SERIAL_MODE_USB_UART)
        // {
            // radioComTxService();
        // }
		
		
		{
		int8 currentGait; 
		// int8 currentDir;
		int8 currentSpeed;
		// int8 led = 0;
		
		
		// CmdrReadMsgs(&desiredGait, &desiredDir, &desiredSpeed);
		cmdrAlive = (uint8) CLAMP(cmdrAlive + 
				CmdrReadMsgs(&desiredGait, &desiredDir, &desiredSpeed), 
				0, CMDR_ALIVE_CNT);
		
		// if (desiredGait == G8_ANIM_WALK_STRAIGHT) {
			// ax12LED(71,1);
		// }
		// currentGait = pgm_read_byte(&gait->animation);
		// currentDir = pgm_read_byte(&gait->backwards);
		// currentSpeed = pgm_read_byte(&gait->speed);
		currentGait = gait.animation;
		// currentS = gait.speed;
		currentSpeed = gait.speed;
		// CmdrReadMsgs();
#ifdef LED_DEBUG_GAITRUN
		ax12LED(71,0);
#endif
		// if (currentGait == G8_ANIM_WALK_STRAIGHT) {
		// if (currentGait == G8_ANIM_START) {
			// led = 1; 
		// }
		// if (currentGait == NO_GAIT) { led = 1; }
		// if (currentPos == MOVING_POS) { led = 1; }
		// if (currentPos == SIT_POS) { led = 1; }
		
		//Some gait requested
		if (desiredGait != NO_GAIT) {
			// led = 1;
			if ( currentGait == desiredGait) {
				if (currentSpeed == desiredSpeed) {
					// continue;//Nothing to change.	//1
				} else { //desire a different speed
					//Change speed				//2a
					gait.speed = desiredSpeed;
				}
			} else if (currentGait == G8_ANIM_START) {
				// if (currentDir == 1) {
				if (currentSpeed > 0) {
					// led = 1;
					// continue;					//3a
				// } else if (currentDir == -1) {
				} else if (currentSpeed < 0) {
					// led = 1;
					// gaitReverse();			//3b
					// so that we go TO start position.
					gait.speed = START_SPEED;
					currentPos = START_POS;
					// gait.repeatCount *= -1; // Seems to have no effect
					// if  (gait.speed < 0) {led = 1;}
				}		
			} else if (currentGait != NO_GAIT /* & != G8_ANIM_START*/) { //Some other gait is running. Wait til it ends.
				// led = 1;
				gaitRunnerStop(&gait);				//4
				currentPos = START_POS;
			///below this level, currentGait == NO_GAIT
			} else if (currentPos == SIT_POS) { //No other gait is running, and currently in sit pos. Run START animation.
				// led = 1;
				g8playbackDir = 1;				//6
				g8speed = START_SPEED; //unnecessary?
				gaitRunnerPlay(&gait, G8_ANIM_START, g8loopSpeed, g8playbackDir*g8speed, g8playbackDir * 1);
				currentPos = START_POS;
			} else { //No other gait is running, and currently in start position. Start the desired gait.
				// led = 1;
				g8speed = desiredSpeed;			//5
				g8playbackDir = desiredDir;
		/// void gaitRunnerPlay(*runner, uint8 animation, int16 loopSpeed, int8 speed, repeatCount)
				gaitRunnerPlay(&gait, desiredGait, g8loopSpeed, g8playbackDir*g8speed, 0);
				currentPos = MOVING_POS;	// This should be the only way a moving gait gets started...
				// led = 1; 
			}
		}

		else { // No gait requested; work towards sitting mode.
			if (currentGait != NO_GAIT) {// If moving...
				if (currentGait == G8_ANIM_START) { //If doing start gait...
					// if (currentDir == 1) { //And going to start position
					if (currentSpeed > 0) { //And going to start position
						// gaitReverse();		//8
						gait.speed = -1 * currentSpeed;
						currentPos = SIT_POS;
						// led = 1; 
					} else {	//Going into sit position
						// continue;	//Do nothing//9
						// led = 1; 
					}
				} else { //If doing some movement gait
					//Tell gait engine to stop at end of loop.
					gaitRunnerStop(&gait);			//7
					currentPos = START_POS;
					// led = 1; 
				}
			} 
			
			//Not moving currently
			else if (currentPos == START_POS) { //in START_POS
				// g8playbackDir = -1;					//10
				g8speed = START_SPEED; //unnecessary?
				gaitRunnerPlay(&gait, G8_ANIM_START, g8loopSpeed, -1*g8speed, -1);
				currentPos = SIT_POS;
				// led = 1; 
			} else { // in SIT_POS
				// continue;						//11
				// currentPos = SIT_POS;
				// led = 1; 
			}
			
		}
		
#ifdef LED_DEBUG_CONTROLOGIC
		ax12LED(71, led);
#endif

		}
#ifdef INCL_USB
		//Unneeded?
        usbComService();
#endif

		// ms = getMs();		// Get current time in ms
		// now = ms % (uint32)10000; 	// 10 sec for a full swing
		// if(now >= (uint16)5000){				// Goes from 0ms...5000ms
			// now = (uint16)10000 - now;			// then 5000ms...0ms
		// }
		// speed = interpolate(now, 0, 5000, 100, 900);
		
		// ax12SetGOAL_POSITION(32, speed);
	
		
	
		delayMs(10);
		
		gaitRunnerProcess(&gait);
    }
}
