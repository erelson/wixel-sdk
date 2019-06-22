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

#include <usb.h>
#include <usb_com.h>

#include <radio_com.h>
#include <radio_link.h>

#include <uart1.h>
#include <spi0_master.h>
#include <radio_registers.h>

int32 CODE param_spi_on = 1;
//int32 CODE param_height = 48;


/** Parameters ****************************************************************/
#define SERIAL_MODE_AUTO        0
#define SERIAL_MODE_USB_RADIO   1
#define SERIAL_MODE_UART_RADIO  2
#define SERIAL_MODE_USB_UART    3
//int32 CODE param_serial_mode = SERIAL_MODE_AUTO;
int32 CODE param_serial_mode = SERIAL_MODE_USB_RADIO;

int32 CODE param_baud_rate = 38400;

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

uint8 DATA currentSerialMode;

BIT framingErrorActive = 0;

BIT errorOccurredRecently = 0;
uint8 lastErrorTime;

static uint8 XDATA initData[25] = 
{
    0xAE,       // display off
    0xD5,0x80,  // set display clock divide ratio/oscillator frequency
    0xA8,0x3F,  // set multiplex ratio(1 to 64)
    0xD3,0x00,  // set display offset (unused)
    0x40,       // TODO display start line
    0x8D,0x14,  // inclusion of an internal voltage converter
    0x20,0x00,  // Set Memory Addressing Mode 00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET,0);11,Invalid
    0xA0,       // set segment re-map 0 to 127 (A0 -> horizontal flip)
    0xC0,       // set COM output scan direction
    0xDA,0x12,  // set COM pins
    0x81,0xCF,  // set contrast control register
    0xD9,0xF1,  // set pre-charge period
    0xDB,0x40,  // set vcomh
    0xA4,       // 0xA4 output follows RAM content; 0xA5 output ignores RAM content
    0xA6,       // 0xA6 normal / 0xA7 reverse; switches pixel meaning of 0/1
    0xAF        // display on
};

// oled variables!
uint8 rowsize = 16; // number of characters we can display in a row
uint8 nrows = 6; // number of rows we can display (pixels/8)
uint8 data_index = 0; // index in data[] to place bytes # NOTE change type if we have larger screen...
uint8 rrr = 0;
uint8 col = 0; // spot in the row where the next byte goes
//static char data[16*6] = {"9"}; // (rowsize * nrows)
//static char data[16*6];// = {}; // (rowsize * nrows) // This is what I expect to work
static char data[16*6];// = {}; // (rowsize * nrows) // Does XDATA help?
uint8 charwidth = 4;
uint8 newest_row = 0; // TODO what's this? Is this rrr?
//static uint8 XDATA data[(64/4) * (48/8)] = {1};

//# TODO remove
//static int16 XDATA rssiValue[256];
//static int16 XDATA rssiHalfValue[128];

//static uint8 XDATA rxData[1024] = {0};
//static uint8 XDATA txData[1024] = {0};
static uint8 XDATA rxData[1024] = {0};
static uint8 XDATA txData[1024] = {55}; // {127};

// 4-wire SPI0
#define RESlow      setDigitalOutput(1,0)   // P0_1 to RES
#define REShigh     setDigitalOutput(1,1)

#define DClow       setDigitalOutput(2,0)   // P0_2 to D/C (MISO)
#define DChigh      setDigitalOutput(2,1)
                                            // P0_3 to DIN (MOSI)
#define CSlow       setDigitalOutput(4,0)   // P0_4 to CS (!CC)
#define CShigh      setDigitalOutput(4,1)
                                            // P0_5 to CLK

BIT rcolor = 0; // 0 red; 1 yellow
BIT gcolor = 1; // 0 red; 1 yellow
BIT ycolor = 1; // 0 red; 1 yellow

/** Functions *****************************************************************/

void updateLeds()
{
    static BIT dimYellowLed = 0;
    static uint16 lastRadioActivityTime;
    uint16 now;

    usbShowStatusWithGreenLed();

    now = (uint16)getMs();

    if (currentSerialMode == SERIAL_MODE_USB_UART)
    {
        // The radio is not being used, so turn off the yellow LED.
        LED_YELLOW(0);
    }
    else if (!radioLinkConnected())
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

void SPI0Init(void)
{
    spi0MasterInit();
    spi0MasterSetFrequency(3000000);
    spi0MasterSetClockPolarity(SPI_POLARITY_IDLE_LOW);  // Sets the clock polarity CPOL = 0 (SPI_POLARITY_IDLE_HIGH)
    spi0MasterSetClockPhase(SPI_PHASE_EDGE_LEADING);    // Sets the clock phase CPHA = 0 (SPI_PHASE_EDGE_TRAILING)
    spi0MasterSetBitOrder(SPI_BIT_ORDER_MSB_FIRST);     // The most-significant bit is transmitted first
}

void oledSPI0Init(void)
{
    uint8 i;
    
    RESlow;
    delayMicroseconds(3);
    REShigh;
    DClow;
    CSlow;
    for (i = 0; i < 25; i++) 
    {
        spi0MasterSendByte(initData[i]);
        delayMs(1);
    }
    CShigh;
    DChigh;
}

void oledSPI0FramePreamble(void)
{
    uint8 i;
    uint8 initData[6] =
    {
        0x21,0x00,0x7F,
        0x22,0x00,0x07
    };
    
    DClow;
    CSlow;
    
    for (i = 0; i < 6; i++) 
    {
        spi0MasterSendByte(initData[i]);
        delayMicroseconds(3);
    }
    
    CShigh;
}

uint8 power(uint8 base, uint16 n)
{
    uint8 p;
    for (p = 1; n > 0; --n)
        p *= base;
    return p;
}

void drawBlank(uint16 middle)
{
    middle += 2;    txData[middle] = 0x0;
    middle--;       txData[middle] = 0x0;
    middle--;       txData[middle] = 0x1;
    middle--;       txData[middle] = 0x0;
    middle--;       txData[middle] = 0x0;
}
void drawNumber(uint16 middle, uint8 number, BIT size)
{
    if (size)
    {
        switch(number)
        {
        case 1:
            middle++;       txData[middle] = 0x21;
            middle--;       txData[middle] = 0x7F;
            middle--;       txData[middle] = 0x01;
            break;
        case 2:
            middle += 2;    txData[middle] = 0x21;
            middle--;       txData[middle] = 0x43;
            middle--;       txData[middle] = 0x45;
            middle--;       txData[middle] = 0x49;
            middle--;       txData[middle] = 0x31;
            break;
        case 3:
            middle += 2;    txData[middle] = 0x42;
            middle--;       txData[middle] = 0x41;
            middle--;       txData[middle] = 0x51;
            middle--;       txData[middle] = 0x69;
            middle--;       txData[middle] = 0x46;
            break;
        case 5:
            middle += 2;    txData[middle] = 0x72;
            middle--;       txData[middle] = 0x51;
            middle--;       txData[middle] = 0x51;
            middle--;       txData[middle] = 0x51;
            middle--;       txData[middle] = 0x4E;
            break;
        case 6:
            middle += 2;    txData[middle] = 0x1E;
            middle--;       txData[middle] = 0x29;
            middle--;       txData[middle] = 0x49;
            middle--;       txData[middle] = 0x49;
            middle--;       txData[middle] = 0x06;
            break;
        case 7:
            middle += 2;    txData[middle] = 0x40;
            middle--;       txData[middle] = 0x47;
            middle--;       txData[middle] = 0x48;
            middle--;       txData[middle] = 0x50;
            middle--;       txData[middle] = 0x60;
            break;
        }
    }
    else
    {
        switch(number)
        {
        case 0:
            middle++;       txData[middle] = 0x1F;
            middle--;       txData[middle] = 0x11;
            middle--;       txData[middle] = 0x1F;
            break;
        case 1:
            middle++;       txData[middle] = 0x10;
            middle--;       txData[middle] = 0x1F;
            break;
        case 2:
            middle++;       txData[middle] = 0x17;
            middle--;       txData[middle] = 0x15;
            middle--;       txData[middle] = 0x1D;
            break;
        case 3:
            middle++;       txData[middle] = 0x15;
            middle--;       txData[middle] = 0x15;
            middle--;       txData[middle] = 0x1F;
            break;
        case 4:
            middle++;       txData[middle] = 0x1C;
            middle--;       txData[middle] = 0x04;
            middle--;       txData[middle] = 0x1F;
            break;
        case 5:
            middle++;       txData[middle] = 0x1D;
            middle--;       txData[middle] = 0x15;
            middle--;       txData[middle] = 0x17;
            break;
        case 6:
            middle++;       txData[middle] = 0x1F;
            middle--;       txData[middle] = 0x05;
            middle--;       txData[middle] = 0x07;
            break;
        case 7:
            middle++;       txData[middle] = 0x10;
            middle--;       txData[middle] = 0x10;
            middle--;       txData[middle] = 0x1F;
            break;
        case 8:
            middle++;       txData[middle] = 0x1F;
            middle--;       txData[middle] = 0x15;
            middle--;       txData[middle] = 0x1F;
            break;
        case 9:
            middle++;       txData[middle] = 0x1C;
            middle--;       txData[middle] = 0x14;
            middle--;       txData[middle] = 0x1F;
            break;
        case 10:  // "-"
            middle++;       txData[middle] = 0x04;
            middle--;       txData[middle] = 0x04;
            middle--;       txData[middle] = 0x04;
            break;
        }
    }
}

void updateSerialMode()
{
    if ((uint8)param_serial_mode > 0 && (uint8)param_serial_mode <= 3)
    {
        currentSerialMode = (uint8)param_serial_mode;
        return;
    }

    if (usbPowerPresent())
    {
        if (vinPowerPresent())
        {
            currentSerialMode = SERIAL_MODE_USB_UART;
        }
        else
        {
            currentSerialMode = SERIAL_MODE_USB_RADIO;
        }
    }
    else
    {
        currentSerialMode = SERIAL_MODE_UART_RADIO;
    }
}

void usbToRadioService()
{
    uint8 signals;
    uint8 newbyte;
    uint16 middle;
    uint8 val;
    uint16 i, v, data_pos;

    // Data
    while(usbComRxAvailable() && radioComTxAvailable())
    {
      newbyte = usbComRxReceiveByte();
      radioComTxSendByte(newbyte);
      // this next line is the good one...
      if (newbyte == '\n'){ // new row
      // Alternate line for troubleshooting
      //if (newbyte == '\n' || newbyte == '8' || col > rowsize){ // new row of data # TODO
        rrr = (rrr + 1) % nrows; //increment row index 
        col = 0;
        data_index = rrr * rowsize; // beginning of new row
        // Zero out the row # TODO verify this works
        for (i=data_index;i<data_index+rowsize;i++){
          data[i] = '11'; //blank
        }
      }
      else{
        if (col >= rowsize){ // We're not doing any line wrapping; ignore current byte
          continue;
        }
    
        if ('0' <= newbyte && newbyte <= '9'){ // numbers
          data[data_index] = newbyte - '0';
        }
        else if (32 == newbyte){ // space character
          data[data_index] = newbyte; // should result in a space via drawBlank()
        }
        else{
          // Non number/space/newline; skip!
        }

        col += 1;
        data_index += 1;
      }

    }

    // Put data[] contents onto SPI_0 OLED
    for (i=0; i<nrows; i++){ // i iterates over rows
      for (v=0; v<rowsize; v++){ // v tracks column
        // base offset is 290, and then there's a 60 (15 * 4) offset
        data_pos = ( (nrows + rrr - i) % nrows ) * rowsize + v; 
        val = (uint8) data[ (uint8) data_pos ];
        middle = 290 + i * 128 + 60 - 4 * v;
        if (val <= 9){
          drawNumber(middle, val, 0);
        }
        else{
          drawBlank(middle);
        }
      }
    }

    while(radioComRxAvailable() && usbComTxAvailable())
    {
      usbComTxSendByte(radioComRxReceiveByte());
    }

    // Control Signals
    radioComTxControlSignals(usbComRxControlSignals() & 3);

    // Need to switch bits 0 and 1 so that DTR pairs up with DSR.
    signals = radioComRxControlSignals();
    usbComTxControlSignals( ((signals & 1) ? 2 : 0) | ((signals & 2) ? 1 : 0));
}


void uartToRadioService()
{
    uint8 signals;
    uint8 newbyte;
    uint16 middle;
    uint8 val;
    uint16 i, v, data_pos;

    // Data from uart1
    while(uart1RxAvailable() && radioComTxAvailable())
    {
      newbyte = uart1RxReceiveByte();
      radioComTxSendByte(newbyte);
      // this next line is the good one...
      if (newbyte == '\n'){ // new row of data
      // Alternate line for troubleshooting
      //if (newbyte == '\n' || newbyte == '8' || col > rowsize){ // new row of data
        rrr = (rrr + 1) % nrows; //increment row index 
        col = 0;
        data_index = rrr * rowsize; // beginning of new row
        // Zero out the row # TODO verify this works
        for (i=data_index;i<data_index+rowsize;i++){
          data[i] = '11'; //blank
        }
      }
      else{
        if (col >= rowsize){ // We're not doing any line wrapping; ignore current byte
          continue;
        }
    
        if ('0' <= newbyte && newbyte <= '9'){ // numbers
          data[data_index] = newbyte - '0';
          radioComTxSendByte('U');
        }
        else if (32 == newbyte){ // space character
          data[data_index] = newbyte; // should result in a space via drawBlank()
        }
        else{
          // Non number/space/newline; skip!
          //radioComTxSendByte(newbyte); // For debugging
        }

        col += 1;
        data_index += 1;
      }

    }

    // Put data[] contents onto SPI_0 OLED
    for (i=0; i<nrows; i++){ // i iterates over rows
      for (v=0; v<rowsize; v++){ // v tracks column
        // base offset is 290, and then there's a 60 (15 * 4) offset
        data_pos = ( (nrows + rrr - i) % nrows ) * rowsize + v; 
        val = (uint8) data[ (uint8) data_pos ];
        //middle = 290 + i * 128 + 60 - 4 * v;
        middle = 290 + i * 128 + 60 - 4 * v - 256;
        if (val <= 9){
          drawNumber(middle, val, 0);
        }
        else{
          drawBlank(middle);
        }
      }
    }


    while(radioComRxAvailable() && uart1TxAvailable())
    {
        uart1TxSendByte(radioComRxReceiveByte());
    }

    // Control Signals.
    ioTxSignals(radioComRxControlSignals());
    radioComTxControlSignals(ioRxSignals());
}

void usbToUartService()
{
    uint8 signals;

    // Data
    while(usbComRxAvailable() && uart1TxAvailable())
    {
        uart1TxSendByte(usbComRxReceiveByte());
    }

    while(uart1RxAvailable() && usbComTxAvailable())
    {
        usbComTxSendByte(uart1RxReceiveByte());
    }

    ioTxSignals(usbComRxControlSignals());

    // Need to switch bits 0 and 1 so that DTR pairs up with DSR.
    signals = ioRxSignals();
    usbComTxControlSignals( ((signals & 1) ? 2 : 0) | ((signals & 2) ? 1 : 0));

    // TODO: report framing, parity, and overrun errors to the USB host here
}

void main()
{
    uint16 cnt;
    uint8 i, v;
    uint16 middle;
    char val;

    systemInit();

    //setDigitalOutput(param_arduino_DTR_pin, LOW);
    ioTxSignals(0);

    usbInit();

    uart1Init();
    uart1SetBaudRate(param_baud_rate);

    if (param_spi_on)
    {
        SPI0Init();
        delayMicroseconds(100);
        oledSPI0Init();
    }

    if (param_serial_mode != SERIAL_MODE_USB_UART)
    {
        radioComRxEnforceOrdering = 1;
        radioComInit();
    }

    // Set up P1_5 to be the radio's TX debug signal.
    P1DIR |= (1<<5);
    IOCFG0 = 0b011011; // P1_5 = PA_PD (TX mode)

    for(cnt=0;cnt<nrows*rowsize;cnt++){
      data[cnt] = 11;
    }

    for (i=0;i<6;i++){
      //radioComTxSendByte('a' + newbyte); // TODO remove
      //row = ( i + 12*0 ) % 16;
      //rowoffset = i; //
      //rowposition = i %
      for (v=0; v<16; v++){
        val = data[(rrr - i) * rowsize + v];
        middle = 290 - 256 + i * 128 + 60 - 4 * v;
//        // base offset is 290
//        // then there's a 64 offset?
//        //txData[] = data[i];  // This is not a correct line at all lol
//        if ('1' <= val <= '9'){
//          drawNumber(middle, val, 0);
//          //radioComTxSendByte(val); // TODO remove
//          //radioComTxSendByte('a' + val); // TODO remove
//        }
//        else if ('0' <= val <= '9'){
//          drawNumber(middle, 4, 0); // TODO should send val, not 4
//          //radioComTxSendByte(val); // TODO remove
//          //radioComTxSendByte('a' + val); // TODO remove
//        }
//        else{
//          drawBlank(middle);
//          //radioComTxSendByte('X'); // TODO remove
//        }
        //drawNumber(middle, 4, 0);
        drawBlank(middle);
      }
    }


    drawNumber(412, 0, 0);
    drawNumber(422, 1, 0);
    drawNumber(432, 2, 0);
    drawNumber(564, 3, 0);
    drawNumber(696, 4, 0);
    drawNumber(760, 7, 0);
    drawNumber(824, 9, 0);
    //drawBlank(412);
    //drawBlank(422);
    //drawBlank(432);
    //drawBlank(564);
    //drawBlank(696);
    //drawBlank(760);
    //drawBlank(824);

    oledSPI0FramePreamble();
    
    DChigh;
    CSlow;
    spi0MasterTransfer(txData, rxData, 1024);
    delayMs(6);
    CShigh;
    
    delayMs(1500);

    while(1)
    {
      ycolor ^= 1;
      LED_GREEN(ycolor);
      //updateSerialMode();
      boardService();
      //updateLeds();
      errorService();
      uartToRadioService();
      //usbToRadioService();

      delayMs(100);

      //if (param_serial_mode != SERIAL_MODE_USB_UART)
      //{
      //    radioComTxService();
      //}
      // TODO remove this when we go back to using uart
      radioComTxService();

      usbComService();

      //switch(currentSerialMode)
      //{
      //case SERIAL_MODE_USB_RADIO:  usbToRadioService();  break;
      //case SERIAL_MODE_UART_RADIO: uartToRadioService(); break;
      //case SERIAL_MODE_USB_UART:   usbToUartService();   break;
      //}

      oledSPI0FramePreamble();
      
      DChigh;
      CSlow;
      spi0MasterTransfer(txData, rxData, 1024);
      delayMs(6);
      CShigh;

    }
}
