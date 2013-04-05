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
#include "MotorDriver.h"
#include "print_number.h" // Local library for debug printing...

// #include "Commander.h"
#include "Interpolate.h"

// #define ax12SetGOAL_POSITION(servo,val) 	dynamixel_writeword(servo,AX_GOAL_POSITION_L,CLAMP(val,0,1023))	


/** Enables *******************************************************************/
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
// int32 CODE param_baud_rate_DYNA = DYNAMIXEL_BAUDRATE;
int32 CODE param_baud_rate_XBEE = 38400;
int32 CODE param_baud_rate_UART = 115200;

int32 CODE param_nDTR_pin = 10;
int32 CODE param_nRTS_pin = 11;
int32 CODE param_nDSR_pin = 12;
int32 CODE param_nCD_pin = 13;

int32 CODE param_DTR_pin = -1;
int32 CODE param_RTS_pin = -1;
int32 CODE param_DSR_pin = -1;
int32 CODE param_CD_pin = -1;


int32 CODE param_laser_pin = 15;

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


#define START_SPEED 75

#define START_POS   100
#define SIT_POS     101
#define MOVING_POS  102

///MATHEMATICA CODE
///loopSpeed = 1000;
///Plot[65.536*loopSpeed/speed, {speed, 0, 128}, PlotRange -> {500, 4000}]


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

    // if (radioLinkActivityOccurred)
    // {
        // radioLinkActivityOccurred = 0;
        // dimYellowLed ^= 1;
        // //dimYellowLed = 1;
        // lastRadioActivityTime = now;
    // }

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
// void ioTxSignals(uint8 signals)
// {
    // static uint8 nTrstPulseStartTime;
    // static uint8 lastSignals;

    // // Inverted outputs
    // setDigitalOutput(param_nDTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 0 : 1);
    // setDigitalOutput(param_nRTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 0 : 1);

    // // Non-inverted outputs.
    // setDigitalOutput(param_DTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 1 : 0);
    // setDigitalOutput(param_RTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 1 : 0);

    // // Arduino DTR pin.
    // if (!(lastSignals & ACM_CONTROL_LINE_DTR) && (signals & ACM_CONTROL_LINE_DTR))
    // {
        // // We just made a falling edge on the nDTR line, so start a 1-2ms high pulse
        // // on the nTRST line.
        // setDigitalOutput(param_arduino_DTR_pin, HIGH);
        // nTrstPulseStartTime = getMs();
    // }
    // else if ((uint8)(getMs() - nTrstPulseStartTime) >= 2)
    // {
        // setDigitalOutput(param_arduino_DTR_pin, LOW);
    // }

    // lastSignals = signals;
// }

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


// void uartToRadioService()
// {
    // // Data
    // while(uart1RxAvailable() && radioComTxAvailable())
    // {
        // radioComTxSendByte(uart1RxReceiveByte());
    // }
	
	// //Read radio's buffer
    // // CmdrReadMsgs(); //In this case, CmdrReadMsgs() does the reading.
	// ///We handle CmdrReadMsgs() elsewhere since it has parameters now.
	
	// //    while(radioComRxAvailable() && uart1TxAvailable())
// //    {
// //        uart1TxSendByte(radioComRxReceiveByte());
// //    }

    // // Control Signals.
    // ioTxSignals(radioComRxControlSignals());
    // radioComTxControlSignals(ioRxSignals());
// }

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
uint8 CmdrReadMsgs(){
	int8 buttonval;
	while(uart1RxAvailable() > 0){
		if(index_cmdr == -1){         // looking for new packet
			if(uart1RxReceiveByte() == 0xff){ //read until packet start
				index_cmdr = 0;
				checksum_cmdr = 0;
				// forward byte to other wixel
				uart0TxSendByte(0xff);
			}
		}else if(index_cmdr == 0){
			// add next byte to vals
			vals[index_cmdr] = (unsigned char) uart1RxReceiveByte();
			// forward byte to other wixel
			uart0TxSendByte(vals[index_cmdr]);
			// look for first real byte (non 0xFF)
			if(vals[index_cmdr] != 0xff){
				checksum_cmdr += (uint8) vals[index_cmdr];
				index_cmdr++;  // will now save subsequent bytes
			}
		}else{ //for bytes after the 0th byte
			vals[index_cmdr] = (unsigned char) uart1RxReceiveByte(); 
			// forward byte to other wixel
			uart0TxSendByte(vals[index_cmdr]);
			//loops will sequentially read bytes and store them here

			checksum_cmdr += (uint8) vals[index_cmdr];
			index_cmdr++;
			
			// DEBUG: if all packets go through, shoudl see x2 through 
			// 	x7 when Commander input is being received.
			// rprintf("x%u ",index_cmdr);
			
			if(index_cmdr == 7){ // packet complete
				// if(vals[0] == 0xff) {
					// ax12LED(61,1);
				// }
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
					if((buttonval&BUT_L6) > 0){
						gunbutton = zTRUE;
						// if(PRINT_DEBUG_COMMANDER){rprintf("guns\t");}
					}
					else{gunbutton = zFALSE;}

					// if((buttonval&BUT_R3) > 0){
						// panicbutton = zTRUE;
						// // if(PRINT_DEBUG_COMMANDER){rprintf("panic\t");}
					// }
					// else{panicbutton = zFALSE;}
					
					if((buttonval&BUT_L4) > 0){
						laserbutton = zTRUE;
						// if(PRINT_DEBUG_COMMANDER){rprintf("info\t");}
					}
					else{laserbutton = zFALSE;}
					
					// if((buttonval&BUT_R2) > 0){
						// // if(PRINT_DEBUG_COMMANDER){rprintf("look\t");}
					// }
					// else{infobutton = zFALSE;}
					
					// if((buttonval&BUT_R1) > 0){
						// agitbutton = zTRUE;
						// // if(PRINT_DEBUG_COMMANDER){rprintf("agit\t");}
					// }
					// else{agitbutton = zFALSE;}
					
						// vals - 128 gives look a vlaue in the range from -128 to 127?
					// lookV = (signed char)( (int8)vals[0]-128 );
					// lookH = (signed char)( (int8)vals[1]-128 );
					// if( (int)vals[0] >= 128){
						// tilt_pos = interpolateU( (int)vals[0],128,128+102,TILT_CENTER,servo52Max);
					// }
					// else {
						// tilt_pos = interpolateU( (int)vals[0],128-102,128,servo52Min,TILT_CENTER);
					// }
					
					//Default handling in original Commander.c - sets to range of -127 to 127 or so...
					// walkV = (signed char)( (int8)vals[2]-128 );
					// walkH = (signed char)( (int8)vals[3]-128 );
					// }
					// pan = (vals[0]<<8) + vals[1];
					// tilt = (vals[2]<<8) + vals[3];
					// buttons = vals[4];
					// ext = vals[5];
				}
				index_cmdr = -1;
				
				//Empty the packet buffer
				while (uart1RxAvailable() > 0) { uart1RxReceiveByte(); }
				
				return 1;
			}
		}
	}
	return 0;
}	// End of CmdrReadMsgs


boolean clockHasElapsed(uint32 usStart, uint32 usWait){
	return clockHasElapsedGetOverflow(usStart,usWait,NULL);
}

boolean clockHasElapsedGetOverflow(uint32 usStart, uint32 usWait, uint32* overflow){
	boolean rtn = zFALSE;
	uint32 now = getMs();
	uint32 elapsed = now;
	elapsed -= usStart;					// The actual delay that has happened

	if( elapsed >= usWait){
		// We have exceeded the delay
		if(overflow){
			uint32 ovr = elapsed - usWait;
			*overflow = ovr;
		}
		rtn = zTRUE;
	}else{
		if(overflow){
			uint32 ovr = usWait - elapsed;
			*overflow = ovr;
		}
	}
	return rtn;
}


void main()
{

	// uint32 ms;
	// uint32 now;
	
	MOTOR gunMotor = MAKE_MOTOR_3_PIN(11, 12, 13);  //(PWM, B, A)
	MOTOR *ptrGunMotor = &gunMotor;
	
	// Here we define what pins we will be using for PWM.
	// uint8 CODE pwmPins[] = {ptrGunMotor->pwmpin};
	uint8 CODE pwmPins[] = {11};
	
    // setDigitalOutput(param_arduino_DTR_pin, LOW);
    // ioTxSignals(0);

    // Initialize UARTs
    uart0Init();
    uart0SetBaudRate(param_baud_rate_UART);
    uart1Init();
    uart1SetBaudRate(param_baud_rate_XBEE);
	
	pwmStart((uint8 XDATA *)pwmPins, sizeof(pwmPins), 10000);
	
	guns_firing_duration = 250; // time in ms
	gunbutton = zFALSE;
	laserbutton = zFALSE;
	
    systemInit();

	print_number2bytes(ptrGunMotor->pwmpin);
	print_number2bytes(pwmPins[0]);
	
	// Initialize other stuff
	index_cmdr = -1;

    /// MAIN LOOP ///
    while(1)
    {
		
        // updateSerialMode();
        boardService();
        updateLeds();
        errorService();
		
		
		CmdrReadMsgs();
		
		// ms = getMs();		// Get current time in ms
		// now = getMs();
		// now = ms % (uint32)10000; 	// 10 sec for a full swing
		// if(now >= (uint16)5000){				// Goes from 0ms...5000ms
			// now = (uint16)10000 - now;			// then 5000ms...0ms
		// }
		// speed = interpolate(now, 0, 5000, 100, 900);
		
		if (laserbutton == zTRUE){
			// uart0TxSendByte('L');
			setDigitalOutput(param_laser_pin, HIGH);
		}
		else {setDigitalOutput(param_laser_pin, LOW);}
		
		//FIRE THE GUNS!!!!!
		//Resets timer while button is held down.
		if (gunbutton == zTRUE){
			// uart0TxSendByte('Z');
			guns_firing = zTRUE;
			// setMotorSpeed(&LeftGun,-65); 	//NOTE: (7.2 / 12.6) * 127 = 72.5714286
			setMotorSpeed(ptrGunMotor, -65);
			guns_firing_start_time = getMs();
		}
		
		
		//Check whether to stop firing guns
		if (guns_firing && clockHasElapsed(guns_firing_start_time, guns_firing_duration)){
			// uart0TxSendByte('X');
			// guns_firing_duration = 0;
			guns_firing = zFALSE;
			// setMotorSpeed(&LeftGun,0); 	//NOTE: (7.2 / 12.6) * 127 = 72.5714286
			setMotorSpeed(ptrGunMotor, 0);
			guns_firing_start_time = getMs();
		}
	
		delayMs(5);
    }
}
