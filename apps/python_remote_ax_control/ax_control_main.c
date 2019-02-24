/* python_remote_ax_control app:
 * This app allows you to connect two Wixels together to make a wireless,
 * bidirectional, lossless serial link, with a dynamixel servo bus on the
 * other end.  On the controlling end, a python script for sending specific
 * serial commands to instruct the servo-controlling Wixel is provided,
 * send_bytes.py.
 *
 * Adapted from the example wireless_serial app.
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

/** Enables *******************************************************************/
#define INCL_USB

/** Dependencies **************************************************************/
#include <wixel.h>


#ifdef INCL_USB
#include <usb.h>
#include <usb_com.h>
#endif

#include <radio_com.h>
#include <radio_link.h>

#include <uart1.h>

#include <malloc.h>


#include "HeaderDefs.h"

#include "dynamixel.h"
#include "ax.h"
// #define ax12SetGOAL_POSITION(servo,val)     dynamixel_writeword(servo,AX_GOAL_POSITION_L,CLAMP(val,0,1023))
#define ax12LED(servo,val)                    dynamixel_writebyte(servo,AX_LED,CLAMP(val,0,1))
#define ax12TorqueOff(servo)                  dynamixel_writebyte(servo,AX_TORQUE_ENABLE,0)
#define ax12TorqueOn(servo)                   dynamixel_writebyte(servo,AX_TORQUE_ENABLE,1)
#define TARGET_SERVO_ID  74

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

BIT rcolor = 0; // 0 red; 1 yellow
BIT gcolor = 1; // 0 red; 1 yellow
BIT ycolor = 1; // 0 red; 1 yellow

#define START_SPEED 75

#define START_POS   100
#define SIT_POS     101
#define MOVING_POS  102

///MATHEMATICA CODE
///loopSpeed = 1000;
///Plot[65.536*loopSpeed/speed, {speed, 0, 128}, PlotRange -> {500, 4000}]
const uint16 g8loopSpeed = 1000;
uint16 g8speed = 25;
int8 g8playbackDir = 1; // value should only ever be -1 or 1.
int8 g8repeatCount = 0;

uint16 currentPos;
uint16 desiredPos;


/** Functions *****************************************************************/

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


void uartToRadioService()
{
    // Data from uart to radio
    while(uart1RxAvailable() && radioComTxAvailable())
    {
        LED_RED(1);
        radioComTxSendByte(uart1RxReceiveByte());
    }

    // We read radio's buffer in the rest of ReadReceivedBytes()

    // Control Signals.
    ioTxSignals(radioComRxControlSignals());
    radioComTxControlSignals(ioRxSignals());
}


/* process messages coming from Serial
 *  packet format = 0xFF 0xFF DATA1 DATA2 checksum
 *  Note: Checksum is calculated as: (255 - (DATA1 + DATA2)) % 256
 *  Note: DATA2 is unused in this first planned application */
uint8 ReadReceivedBytes(int8 *data1, int8 *data2){
    uint8 buttonval;
    uartToRadioService();
    while(radioComRxAvailable() > 0 && uart1TxAvailable()){
        LED_RED(1);
        if(index_cmdr == -2 || index_cmdr == -1){ // looking for new packet + second byte
            buttonval = radioComRxReceiveByte();
            if(buttonval == 0xff){ // read until packet start
                LED_GREEN(1);
                index_cmdr += 1;
                checksum_cmdr = 0;
            }else{
                ycolor ^= 1;
                LED_YELLOW(ycolor);
                index_cmdr = -2;
            }

        }else if(index_cmdr == 0){
            // add next byte to vals
            vals[index_cmdr] = (unsigned char) radioComRxReceiveByte();
            // look for first real byte (non 0xFF)
            if(vals[index_cmdr] != 0xff){
                checksum_cmdr += (uint8) vals[index_cmdr];
                index_cmdr++;
            }
        }else{ // for bytes after the 0th data byte
            // loops will sequentially read bytes and store them here
            vals[index_cmdr] = (unsigned char) radioComRxReceiveByte();

            checksum_cmdr += (uint8) vals[index_cmdr];
            index_cmdr++;

            /// COMPLETE PACKET of 3 bytes (not including the first two 0xFFs)
            if(index_cmdr == 3){
                if(checksum_cmdr%256 != 255){
                    index_cmdr = -2;
                    return 0;
                }
                else{
                    // Update data1 and data2
                    *data1 = vals[0];
                    *data2 = vals[1];
                }
                index_cmdr = -2;

                // Manually empty the packet buffer:
                while (radioComRxAvailable() > 0) { radioComRxReceiveByte(); }
            }
        }
    }
    return 0;
}


void ProcessAction(int8 data1){
    uint8 tmp;

    switch(data1) {

        case 0  : // Do nothing
            return;
            break;

        case 1  : // "On"
            desiredPos = onPos;
            break;

        case 2  : // "Off"
            desiredPos = offPos;
            break;

        case 3  : // Toggle position
            if (currentPos == onPos){
                desiredPos = offPos;
            }
            else {
                desiredPos = onPos;
            }
            break;

        case 4  : // Swap On and Off positions
            tmp = onPos;
            onPos = offPos;
            offPos = tmp;
            return;
    }

    if (currentPos == desiredPos) {
        ax12TorqueOn(TARGET_SERVO_ID);
        // Move to other position and then back again
        if (desiredPos == onPos) {
            dynamixel_writeword(TARGET_SERVO_ID, AX_GOAL_POSITION_L, offPos);
            // sleep; TODO don't just go dead to the world?
            delayMs(1000);
            dynamixel_writeword(TARGET_SERVO_ID, AX_GOAL_POSITION_L, onPos);
            delayMs(1000);
        }
        else {
            dynamixel_writeword(TARGET_SERVO_ID, AX_GOAL_POSITION_L, onPos);
            // sleep; TODO don't just go dead to the world?
            delayMs(1000);
            dynamixel_writeword(TARGET_SERVO_ID, AX_GOAL_POSITION_L, offPos);
            delayMs(1000);
        }
    }
    else if (currentPos != desiredPos) {
        ax12TorqueOn(TARGET_SERVO_ID);
        // Move to other position
        dynamixel_writeword(TARGET_SERVO_ID, AX_GOAL_POSITION_L, desiredPos);
        delayMs(1000);
        currentPos = desiredPos;
    }

    // turn off motor position holding
    ax12TorqueOff(TARGET_SERVO_ID);
}

//
void main()
{
    int8 data1 = 0;  // Stores value sent from other wixel (aka from Python script typically)
    int8 data2 = 0;  // Unused
    uint8 success = 0;

    // These positions have the servo moving roughly +/- 117 degrees from center
    onPos = 112;
    offPos = 912;
    desiredPos = onPos;

    systemInit();

    // Move servo to initial position
    ax12TorqueOn(TARGET_SERVO_ID);
    dynamixel_writeword(TARGET_SERVO_ID, AX_GOAL_POSITION_L, offPos);
    ax12TorqueOff(TARGET_SERVO_ID);
    currentPos = offPos;

    //Among other things, allocates byte arrays for sending commands.
    dynamixel_init();

    setDigitalOutput(param_arduino_DTR_pin, LOW);
    ioTxSignals(0);

    usbInit();
    uart1Init();
    uart1SetBaudRate(param_baud_rate);
    index_cmdr = -2; // index in packet that we're currently reading over serial

    if (param_serial_mode != SERIAL_MODE_USB_UART)
    {
        radioComRxEnforceOrdering = 1;
        radioComInit();
    }

    delayMs(200);

    while(1)
    {

        // Wixel lib things
        //updateSerialMode();
        boardService();
        errorService();

        //
        if (param_serial_mode != SERIAL_MODE_USB_UART)
        {
            radioComTxService();
        }

        {
        int8 led = 0;

        // Process bytes received (from other wixel)
        success = ReadReceivedBytes(&data1, &data2);

        // Take action on the data, and then reset them to non-actionable
        ProcessAction(data1);
        data1 = 0;
        data2 = 0;
        }

#ifdef INCL_USB
        usbComService();
#endif

        delayMs(10);
    }
}
