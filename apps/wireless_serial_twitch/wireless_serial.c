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

#define INCL_USB
#include <usb.h>
#include <usb_com.h>

#include <radio_com.h>
#include <radio_link.h>

#include <uart1.h>

#include <malloc.h>


#include "HeaderDefs.h"

// #include "Commander.h"
#include "Interpolate.h"

#include "dynamixel.h"
#include "ax.h"

#include "GaitRunner.h"
#include "gait.h"

/** Enables *******************************************************************/
#define GAIT_ENABLE

/** Parameters ****************************************************************/
#define SERIAL_MODE_AUTO        0
#define SERIAL_MODE_USB_RADIO   1
#define SERIAL_MODE_UART_RADIO  2
#define SERIAL_MODE_USB_UART    3
// int32 CODE param_serial_mode = SERIAL_MODE_AUTO;
int32 CODE param_serial_mode = SERIAL_MODE_UART_RADIO;

// This is the baud rate used by UART
// Note: Wixel maximum UART sbaud rate is 1.5 Mbaud.
int32 CODE param_baud_rate = DYNAMIXEL_BAUDRATE;

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
uint8 lastErrorTime;


// volatile const uint8 *all;

/** Functions *****************************************************************/

void updateLeds()
{
    static BIT dimYellowLed = 0;
    static uint16 lastRadioActivityTime;
    uint16 now;

    usbShowStatusWithGreenLed();

    now = (uint16)getMs();

    // if (currentSerialMode == SERIAL_MODE_USB_UART)
    // {
        // // The radio is not being used, so turn off the yellow LED.
        // LED_YELLOW(0);
    // }
    if (!radioLinkConnected())
    {
        // We have not connected to another device wirelessly yet, so do a
        // 50% blink with a period of 1024 ms.
        LED_YELLOW(now & 0x200 ? 1 : 0);
    }
    else
    {
        // We have connected.

        if ((now & 0x3FF) <= 20)
        {
            // Do a heartbeat every 1024ms for 21ms.
            LED_YELLOW(1);
        }
        else if (dimYellowLed)
        {
            static uint8 DATA count;
            count++;
            LED_YELLOW((count & 0x7)==0);
        }
        else
        {
            LED_YELLOW(0);
        }
    }

    if (radioLinkActivityOccurred)
    {
        radioLinkActivityOccurred = 0;
        dimYellowLed ^= 1;
        //dimYellowLed = 1;
        lastRadioActivityTime = now;
    }

    if ((uint16)(now - lastRadioActivityTime) > 32)
    {
        dimYellowLed = 0;
    }

    if ((uint8)(now - lastErrorTime) > 100)
    {
        errorOccurredRecently = 0;
    }

    LED_RED(errorOccurredRecently || uartRxDisabled);
}

/* Returns the logical values of the input control signal pins.
   Bit 0 is DSR.
   Bit 1 is CD. */
uint8 ioRxSignals()
{
    uint8 signals = 0;

    if ((param_CD_pin >= 0 && isPinHigh(param_CD_pin)) ||
            (param_nCD_pin >= 0 && !isPinHigh(param_nCD_pin)))
    {
        signals |= 2;
    }

    if ((param_DSR_pin >= 0 && isPinHigh(param_DSR_pin)) ||
            (param_nDSR_pin >= 0 && !isPinHigh(param_nDSR_pin)))
    {
        signals |= 1;
    }

    return signals;
}

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
    lastErrorTime = (uint8)getMs();
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

// void updateSerialMode()
// //Switches between USB/UART/radio pairings
// {
	// currentSerialMode = SERIAL_MODE_UART_RADIO;
// }


void uartToRadioService()
{
    // Data
    while(uart1RxAvailable() && radioComTxAvailable())
    {
        radioComTxSendByte(uart1RxReceiveByte());
    }
	
	//Read radio's buffer
    CmdrReadMsgs(); //In this case, CmdrReadMsgs() does the reading.
	//    while(radioComRxAvailable() && uart1TxAvailable())
//    {
//        uart1TxSendByte(radioComRxReceiveByte());
//    }

    // Control Signals.
    ioTxSignals(radioComRxControlSignals());
    radioComTxControlSignals(ioRxSignals());
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
int CmdrReadMsgs(){
	//while(LISTEN.available() > 0){
	while(radioComRxAvailable() == zFALSE){
		if(index_cmdr == -1){         // looking for new packet
			if(radioComRxReceiveByte() == 0xff){ //read until packet start
				index_cmdr = 0;
				checksum_cmdr = 0;
			}
		}else if(index_cmdr == 0){
			vals[index_cmdr] = (unsigned char) radioComRxReceiveByte();
			if(vals[index_cmdr] != 0xff){            
				checksum_cmdr += (int) vals[index_cmdr];
				index_cmdr++;
			}
		}else{
			vals[index_cmdr] = (unsigned char) radioComRxReceiveByte(); 
			//loops will sequentially read bytes and store them here

			checksum_cmdr += (int) vals[index_cmdr];
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
					char buttonval = vals[4];
					short dowalking = zTRUE;
					
					//rprintf("\t%d\t",(int)buttonval);
					//Turn gait...
					// if((buttonval&0x40) > 0){ //if(buttonval & BUT_LT){
						// // if(PRINT_DEBUG_COMMANDER){rprintf("lft\t");}
						// turnleft = zTRUE;
						// turnright = zFALSE;
						
						// dowalking = zFALSE;
					// }
					// else if((buttonval&0x80) > 0){ //if(buttonval & BUT_RT){
						// // if(PRINT_DEBUG_COMMANDER){rprintf("rgt\t");}
						// turnright = zTRUE;
						// turnleft = zFALSE;
						
						// dowalking = zFALSE;
					// }
					// else { // Do nothing
						// turnright = zFALSE;
						// turnleft = zFALSE;
						// turn = zFALSE;
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
					
					// if((buttonval&BUT_R2) > 0){
						// pan_pos = PAN_CENTER;
						// tilt_pos = TILT_CENTER;
						// // if(PRINT_DEBUG_COMMANDER){rprintf("look\t");}
					// }
					// else{infobutton = zFALSE;}
					
					// if((buttonval&BUT_R1) > 0){
						// agitbutton = zTRUE;
						// // if(PRINT_DEBUG_COMMANDER){rprintf("agit\t");}
					// }
					// else{agitbutton = zFALSE;}
					
					// if((southpaw&0x01) > 0){     // SouthPaw
						// walkV = (signed char)( (int)vals[0]-128 );
						// walkH = (signed char)( (int)vals[1]-128 );
						// // lookV = (signed char)( (int)vals[2]-128 );
						// // lookH = (signed char)( (int)vals[3]-128 );
					// }
					// else if (dowalking){
					// if (dowalking){
						// vals - 128 gives look a vlaue in the range from -128 to 127?
						lookV = (signed char)( (int)vals[0]-128 );
						lookH = (signed char)( (int)vals[1]-128 );
						// if( (int)vals[0] >= 128){
							// tilt_pos = interpolateU( (int)vals[0],128,128+102,TILT_CENTER,servo52Max);
						// }
						// else {
							// tilt_pos = interpolateU( (int)vals[0],128-102,128,servo52Min,TILT_CENTER);
						// }
						
						// int pan_add = (-(float)lookH)/17;
						// int tilt_add = (-(float)lookV)/25;
						// pan_add = (-(float)lookH)/17;
						// tilt_add = (-(float)lookV)/25;
						
						
						// pan_pos = interpolate( (int)vals[1],0,255,servo51Max,servo51Min);
						
						// pan_pos = CLAMP(pan_pos + pan_add, servo51Min, servo51Max);
						// tilt_pos = CLAMP(tilt_pos + tilt_add, servo52Min, servo52Max);
						
						//Default handling in original Commander.c - sets to range of -127 to 127 or so...
						walkV = (signed char)( (int)vals[2]-128 );
						walkH = (signed char)( (int)vals[3]-128 );
					// }
					// pan = (vals[0]<<8) + vals[1];
					// tilt = (vals[2]<<8) + vals[3];
					// buttons = vals[4];
					// ext = vals[5];
				}
				index_cmdr = -1;
				//LISTEN.flush(); //flush after reading an entire packet... why?
				// uartFlushReceiveBuffer(LISTEN);
				//Doesn't seem to be an equivalent method for Wixels.
				return 1;
			}
		}
	}
	return 0;
}



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
void gaitRunnerPlay(G8_RUNNER* runner, uint8 animation, int16 loopSpeed, int8 speed, int16 repeatCount){
	// Update variables with interrupts off - in case the gait is
	// updated under interrupts
	uint32 now = getMs();
	// CRITICAL_SECTION {
		runner->animation = animation;
		runner->repeatCount = repeatCount;
		runner->frame = 0;
		runner->playing = TRUE;
		runner->startTime =  now;
		runner->currentTime = (speed<0) ? loopSpeed : 0;
		runner->totalTime = loopSpeed;
		runner->speed = speed;
		runner->backwards = FALSE;
	// }
	// Set servos to initial position
	gaitRunnerProcess(runner);
}

static uint16 calcX(const G8_LIMB_POSITION* limb, float t1){
	int16 a = (int)pgm_read_word(&limb->cubeX);
	int16 b = (int)pgm_read_word(&limb->squareX);
	int16 c = (int)pgm_read_word(&limb->timeX);
	float t2 = t1 * t1;
	float t3 = t2 * t1;
	uint16 nx = (uint16) ( (t3 * a) + (t2 * b) + (t1 * c) );
	return nx;
}

static int8 calcY(const G8_LIMB_POSITION* limb, float t1){
	int16 a = (int)pgm_read_word(&limb->cubeY);
	int16 b = (int)pgm_read_word(&limb->squareY);
	int16 c = (int)pgm_read_word(&limb->timeY);
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
boolean gaitRunnerProcess(G8_RUNNER* runner){

	uint32 now = getMs();
	// int16_t  interval = (now - runner->startTime)>>16; //original
	int16  interval = (int16)(now);// - (runner->startTime))>>16;
	// int16  interval;

	// int16 test2 = (int16)(runner->startTime);
	// interval = (int16)(now - test2)>>16;
	
	// interval = (int16)(now - (runner->startTime))>>16;

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
	
	if(!gaitRunnerIsPlaying(runner) || (runner->speeds)==null){
		return FALSE;
	}

	if(interval == 0){
		// return TRUE;
		interval = 1;
	}

	// There has been a noticeable change in time
	runner->startTime = now;
	if(runner->backwards){
		interval *= -1;
	}
	interval *= runner->speed;

	// Re-check as drive speed could be zero
	if(interval == 0){
		return TRUE;
	}

	// Locate the current animation
	animation = &runner->animations[runner->animation];

	// Update the current time with the new interval
	currentTime = runner->currentTime + interval;
	if(currentTime >= runner->totalTime){
		// We have finished playing the animation
		if(pgm_read_byte(&animation->sweep)==FALSE){
			currentTime %= runner->totalTime;			// Set back to start of loop
			if(runner->repeatCount){
				runner->repeatCount -= 1;				// One less frame to go
				if(runner->repeatCount==0){
					runner->playing = FALSE;			// we have reached the end
					currentTime = 0;					// set servos to final position
				}
			}
		}else{
			// Start going backwards through the animation
			currentTime = runner->totalTime - (currentTime - runner->totalTime);
			runner->backwards = TRUE;
		}
	}else if(currentTime < 0){
		// We have moved before the start
		if(pgm_read_byte(&animation->sweep)==FALSE){
			currentTime = runner->totalTime + currentTime;
			if(runner->repeatCount){
				runner->repeatCount += 1;				// One more frame to go
				if(runner->repeatCount==0){
					runner->playing = FALSE;			// we have reached the end
					currentTime = 0;					// set servos to start position
				}
			}
		}else{
			// We have completed a sweep
			runner->backwards = FALSE;
			currentTime = -currentTime;

			if(runner->repeatCount){
				runner->repeatCount -= 1;			// One less frame to go
				if(runner->repeatCount==0){
					runner->playing = FALSE;		// we have reached the end
					currentTime = 0;				// set servos to initial position
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

// #ifdef DEBUG
// PRINTF(DEBUG,"\n%u,%d",i,currentTime);
// #endif

	// Now have:- frameStartTime <= frameTime <= frameEndTime

	// We now need to find the distance along the curve (0...1) that represents
	// the x value = frameTime

	// First guess from 0..1
	frameTimeOffset = frameTime-frameStartTime;
	i = 0;
	distanceGuess = ((float)(frameTimeOffset)) / ((float)(frameEndTime-frameStartTime));

	limb = (const G8_LIMB_POSITION*)pgm_read_word(&frame->limbs);
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

// #ifdef DEBUG
// PRINTF(DEBUG,",%d",speed);
// #endif
	}	// next limb

#ifndef DEBUG
	// Set all the servo speeds in quick succession
	{
	uint16 limbNumber = 0;
	for(limbNumber = 0; limbNumber < NUM_ACTUATORS; limbNumber++){
		// __ACTUATOR* servo = (__ACTUATOR*)pgm_read_word(&runner->actuators[limbNumber]);
		// uint8 servo = (uint8)(runner->ids[limbNumber]);
		uint8 servo = (uint8)(61+limbNumber); // Using IDs 61, 62, 63
		int16 speed = (int16)(runner->speeds[limbNumber]);// + (int16)(runner->delta[limbNumber]);
		speed = CLAMP(speed,DRIVE_SPEED_MIN,DRIVE_SPEED_MAX);
		speed = interpolateU(speed, DRIVE_SPEED_MIN, DRIVE_SPEED_MAX, 0, 1023);
		// __act_setSpeed(servo,(int8)speed);
		ax12SetGOAL_POSITION(servo, (uint16)speed);
	}
	}
#endif

	return gaitRunnerIsPlaying(runner);
}

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

	//
	
	uint32 ms;
	uint16 now;
	uint16 speed;
	
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

    setDigitalOutput(param_arduino_DTR_pin, LOW);
    ioTxSignals(0);

    usbInit();
    uart1Init();
    uart1SetBaudRate(param_baud_rate);

    if (param_serial_mode != SERIAL_MODE_USB_UART)
    {
        radioComRxEnforceOrdering = 1;
        radioComInit();
    }
	
#ifdef GAIT_ENABLE
	// gaitRunnerInit(&gait);
#endif
	
	// Initial setting of serial mode
	// // updateSerialMode();
	// currentSerialMode = SERIAL_MODE_UART_RADIO;
	

    // Set up P1_5 to be the radio's TX debug signal.
    // P1DIR |= (1<<5);
    // IOCFG0 = 0b011011; // P1_5 = PA_PD (TX mode)

	// P1DIR |= 0x20; //Enable pin P1_5
	
    while(1)
    {
		
        // updateSerialMode();
        boardService();
        updateLeds();
        errorService();

        if (param_serial_mode != SERIAL_MODE_USB_UART)
        {
            radioComTxService();
        }

		//Unneeded?
        usbComService();

        // switch(currentSerialMode)
        // {
	// //case SERIAL_MODE_USB_RADIO:  usbToRadioService();  break;
        // case SERIAL_MODE_UART_RADIO: uartToRadioService(); break;
        // //case SERIAL_MODE_USB_UART:   usbToUartService();   break;
        // }
		ms = getMs();		// Get current time in ms
		now = ms % (uint32)10000; 	// 10 sec for a full swing
		if(now >= (uint16)5000){				// Goes from 0ms...5000ms
			now = (uint16)10000 - now;			// then 5000ms...0ms
		}
		speed = interpolate(now, 0, 5000, 100, 900);
		
		ax12SetGOAL_POSITION(32, speed);
	
		delayMs(30);
    }
}
