/** \file uart.c
 * This is the main source file for <code>uart.lib</code>.  See uart.h for
 * information on how to use this library.
 */

#include "uart.h"
#include <cc2511_map.h>
#include <cc2511_types.h>

#if defined(__CDT_PARSER__)
#define UART0
#endif

#if defined(UART0)
#define INTERRUPT_PRIORITY_GROUP    2
#define ISR_URX()  void ISR_URX0()  __interrupt(URX0_VECTOR) __using(1)
#define ISR_UTX()  void ISR_UTX0()  __interrupt(UTX0_VECTOR) __using(1)
#define UTXNIF                      UTX0IF
#define URXNIF                      URX0IF
#define URXNIE                      URX0IE
#define UNCSR                       U0CSR
#define UNGCR                       U0GCR
#define UNBAUD                      U0BAUD
#define UNDBUF                      U0DBUF
#define BV_UTXNIE                   (1<<2)
#define uartNRxParityErrorOccurred  uart0RxParityErrorOccurred
#define uartNRxFramingErrorOccurred uart0RxParityErrorOccurred
#define uartNRxBufferFullOccurred   uart0RxParityErrorOccurred
#define uartNRxAvailable            uart0RxAvailable
#define uartNTxAvailable            uart0TxAvailable
#define uartNInit                   uart0Init
#define uartNSetBaudRate            uart0SetBaudRate
#define uartNTxSend                 uart0TxSend
#define uartNRxReceiveByte          uart0RxReceiveByte
#define uartNTxSend                 uart0TxSend
#define uartNTxSendByte             uart0TxSendByte

#elif defined(UART1)
#define INTERRUPT_PRIORITY_GROUP     3
#define ISR_URX()  void ISR_URX1() __interrupt(URX1_VECTOR) __using(1)
#define ISR_UTX()  void ISR_UTX1() __interrupt(UTX1_VECTOR) __using(1)
#define UTXNIF                       UTX1IF
#define URXNIF                       URX1IF
#define URXNIE                       URX1IE
#define UNCSR                        U1CSR
#define UNGCR                        U1GCR
#define UNBAUD                       U1BAUD
#define UNDBUF                       U1DBUF
#define BV_UTXNIE                    (1<<3)
#define uartNRxParityErrorOccurred   uart1RxParityErrorOccurred
#define uartNRxFramingErrorOccurred  uart1RxParityErrorOccurred
#define uartNRxBufferFullOccurred    uart1RxParityErrorOccurred
#define uartNRxAvailable             uart1RxAvailable
#define uartNTxAvailable             uart1TxAvailable
#define uartNInit                    uart1Init
#define uartNSetBaudRate             uart1SetBaudRate
#define uartNTxSend                  uart1TxSend
#define uartNRxReceiveByte           uart1RxReceiveByte
#define uartNTxSend                  uart1TxSend
#define uartNTxSendByte              uart1TxSendByte
#endif

static volatile uint8 XDATA uartTxBuffer[256];         // sizeof(uartTxBuffer) must be a power of two
static volatile uint8 DATA uartTxBufferMainLoopIndex;  // Index of next byte main loop will write.
static volatile uint8 DATA uartTxBufferInterruptIndex; // Index of next byte interrupt will read.

#define UART_TX_BUFFER_FREE_BYTES() ((uartTxBufferInterruptIndex - uartTxBufferMainLoopIndex - 1) & (sizeof(uartTxBuffer) - 1))

static volatile uint8 XDATA uartRxBuffer[256];     // sizeof(uartRxBuffer) must be a power of two
static volatile uint8 DATA uartRxBufferMainLoopIndex;  // Index of next byte main loop will read.
static volatile uint8 DATA uartRxBufferInterruptIndex; // Index of next byte interrupt will write.

#define UART_RX_BUFFER_FREE_BYTES() ((uartRxBufferMainLoopIndex - uartRxBufferInterruptIndex - 1) & (sizeof(uartRxBuffer) - 1))
#define UART_RX_BUFFER_USED_BYTES() ((uartRxBufferInterruptIndex - uartRxBufferMainLoopIndex) & (sizeof(uartRxBuffer) - 1))

volatile BIT uartNRxParityErrorOccurred;
volatile BIT uartNRxFramingErrorOccurred;
volatile BIT uartNRxBufferFullOccurred;

void uartNInit(void)
{
    /* USART0 UART Alt. 1:
     *                     TX  = P0_3
     *                     RX  = P0_2
     */

    /* USART1 UART Alt. 2:
     *                     TX  = P1_6
     *                     RX  = P1_7
     */

    uartTxBufferMainLoopIndex = 0;
    uartTxBufferInterruptIndex = 0;
    uartRxBufferMainLoopIndex = 0;
    uartRxBufferInterruptIndex = 0;
    uartNRxParityErrorOccurred = 0;
    uartNRxFramingErrorOccurred = 0;
    uartNRxBufferFullOccurred = 0;

    // Note: We do NOT set the mode of the RX pin to "peripheral function"
    // because that seems to have no benefits, and is actually bad because
    // it disables the internal pull-up resistor.

#ifdef UART0
    P2DIR &= ~0xC0;  // P2DIR.PRIP0 (7:6) = 00 : USART0 takes priority over USART1.
    PERCFG &= ~0x01; // PERCFG.U0CFG (0) = 0 (Alt. 1) : USART0 uses alt. location 0.
    P0SEL |= (1<<3); // TX pin mode = peripheral func.  P0SEL.SELP0_3 = 1
    U0UCR |= 0x80;   // U0UCR.FLUSH (7) = 1 : Stops the "current operation".
#else
    P2SEL |= 0x40;   // USART1 takes priority over USART0 on Port 1.
    PERCFG |= 0x02;  // PERCFG.U1CFG (1) = 1 (Alt. 2) : USART1 uses alt. location 2.
    P1SEL |= (1<<6); // TX pin mode = peripheral func.  P1SEL.SELP1_6 = 1
    U1UCR |= 0x80;   // U0UCR.FLUSH (7) = 1 : Stops the "current operation".
#endif

    UNCSR |= 0xc0;   // Enable UART mode and enable receiver.  TODO: change '|=' to '='

    // Below, we set the priority of the RX and TX interrupts to be 1 (second lowest priority).
    // They need to be higher than the RF interrupt because that one could take a long time.
    // The UART0 interrupts are grouped with the T2 interrupt, so its priority also gets set.
    // The UART1 interrupts are grouped with the T3 interrupts, so its prioerity also gets set.
    IP0 |= (1<<INTERRUPT_PRIORITY_GROUP);
    IP1 &= ~(1<<INTERRUPT_PRIORITY_GROUP);

    UTXNIF = 1; // Set TX flag so the interrupt fires when we enable it for the first time.
    URXNIF = 0; // Clear RX flag.
    URXNIE = 1; // Enable Rx interrupt.
    EA = 1;     // Enable interrupts in general.
}

void uartNSetBaudRate(uint32 baud)
{
    uint32 baudMPlus256;
    uint8 baudE = 0;

    // actual max baud rate is 1500000 (F/16) - we are limited by the way we calculate the exponent and mantissa
    if (baud < 23 || baud > 495782)
        return;

    // calculate baud rate - see datasheet 12.14.3
    // this is derived from (baudM + 256) = baud * 2^28 / 24000000
    baudMPlus256 = (baud * 11) + (baud * 8663 / 46875);

    // get baudMPlus256 into the range 256-511 (so BAUD_M is in the range 0-255)
    while (baudMPlus256 > 0x1ff)
    {
        baudE++;
        baudMPlus256 /= 2;
    }
    UNGCR = baudE; // UNGCR.BAUD_E (4:0)
    UNBAUD = baudMPlus256; // UNBAUD.BAUD_M (7:0) - only the lowest 8 bits of baudMPlus256 are used, so this is effectively baudMPlus256 - 256
}

uint8 uartNTxAvailable(void)
{
    return UART_TX_BUFFER_FREE_BYTES();
}

void uartNTxSend(const uint8 XDATA * buffer, uint8 size)
{
    // Assumption: uartNTxSend() was recently called and it returned a number at least as big as 'size'.
    // TODO: after DMA memcpy is implemented, use it to make this function faster

    while (size)
    {
        uartTxBuffer[uartTxBufferMainLoopIndex] = *buffer;

        buffer++;
        uartTxBufferMainLoopIndex = (uartTxBufferMainLoopIndex + 1) & (sizeof(uartTxBuffer) - 1);
        size--;

        IEN2 |= BV_UTXNIE; // Enable TX interrupt
    }
}

void uartNTxSendByte(uint8 byte)
{
    // Assumption: uartNTxAvailable() was recently called and it returned a non-zero number.

    uartTxBuffer[uartTxBufferMainLoopIndex] = byte;
    uartTxBufferMainLoopIndex = (uartTxBufferMainLoopIndex + 1) & (sizeof(uartTxBuffer) - 1);

    IEN2 |= BV_UTXNIE; // Enable TX interrupt
}

uint8 uartNRxAvailable(void)
{
    return UART_RX_BUFFER_USED_BYTES();
}

uint8 uartNRxReceiveByte(void)
{
    // Assumption: uartNRxAvailable was recently called and it returned a non-zero value.

    uint8 byte = uartRxBuffer[uartRxBufferMainLoopIndex];
    uartRxBufferMainLoopIndex = (uartRxBufferMainLoopIndex + 1) & (sizeof(uartRxBuffer) - 1);
    return byte;
}

ISR_UTX()
{
    // A byte has just started transmitting on TX and there is room in
    // the UART's hardware buffer for us to add another byte.

    if (uartTxBufferInterruptIndex != uartTxBufferMainLoopIndex)
    {
        // There more bytes available in our software buffer, so send
        // the next byte.

        UTXNIF = 0;

        UNDBUF = uartTxBuffer[uartTxBufferInterruptIndex];
        uartTxBufferInterruptIndex = (uartTxBufferInterruptIndex + 1) & (sizeof(uartTxBuffer) - 1);
    }
    else
    {
        // There are no more bytes to send in our buffer, so disable the TX interrupt.
        IEN2 &= ~BV_UTXNIE;
    }
}

ISR_URX()
{
    URXNIF = 0;

    // check for frame and parity errors
    if (!(UNCSR & 0x18)) // UNCSR.FE (4) == 0; UNCSR.ERR (3) == 0
    {
        // There were no errors.

        if (UART_RX_BUFFER_FREE_BYTES())
        {
            // The software RX buffer has space, so add this new byte to the buffer.
            uartRxBuffer[uartRxBufferInterruptIndex] = UNDBUF;
            uartRxBufferInterruptIndex = (uartRxBufferInterruptIndex + 1) & (sizeof(uartRxBuffer) - 1);
        }
        else
        {
            // The buffer is full, so discard the received byte and report and overflow error.
            uartNRxBufferFullOccurred = 1;
        }
    }
    else
    {
        if (UNCSR & 0x10) // UNCSR.FE (4) == 1
        {
            uartNRxFramingErrorOccurred = 1;
        }
        if (UNCSR & 0x08) // UNCSR.ERR (3) == 1
        {
            uartNRxParityErrorOccurred = 1;
        }
    }
}