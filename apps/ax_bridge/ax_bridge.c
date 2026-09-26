/** ax_bridge app:

Turns a Wixel into a USB <-> half-duplex servo bus bridge (Dynamixel AX-12 and
other Dynamixel-protocol-1 style buses, e.g. Feetech STS), for use behind a
tri-state buffer. The Wixel does only the timing-critical work: put a packet on
the wire with the buffer in TX mode, turn the bus around, and hand back whatever
comes back. All protocol knowledge (pings, register tables, ...) lives on the
host, see python/ next to this file.

== Pinout ==

P1_6 = TX  (UART1)  -> buffer input for the servo wire
P1_7 = RX  (UART1)  <- buffer output from the servo wire
P1_5 = TX buffer enable, P1_1 = RX buffer enable. Both are ACTIVE-HIGH on the
       author's board, and a released (input) pin is pulled high by the board,
       i.e. counts as ENABLED. So both pins are always driven explicitly as
       push-pull outputs (measured with `axbridge pinscan`; do not use the old
       dynamixel.c scheme of toggling P1DIR, which leaves a side enabled when
       "disabled"). Change TX_EN_ACTIVE_HIGH / RX_EN_ACTIVE_HIGH for other boards.
       A disabled RX buffer reads LOW on the RX pin (a break to the UART), so
       RX is left enabled at all times; TX enable is high only while sending.
       The RX path therefore hears our own bytes: they are discarded by matching
       them against what was sent (options bit ECHO, on by default).

The Wixel's UART1 baud generator gives 999,023 baud for a 1,000,000 request
(-0.1%), well within servo tolerance. Default is 1 Mbaud (param_baud_rate).

== Serial protocol (USB virtual COM port) ==

All multi-byte values are little-endian. chk = (~(sum of all bytes between SOF
and chk)) & 0xFF, the same idea as a Dynamixel checksum.

Request (host -> Wixel):   SOF cmd len payload[len] chk        SOF = 0xA5
Response (Wixel -> host):  SOF cmd status len payload[len] chk

cmd (echoed in the response):
  0x01 XFER      payload = flags, timeout_ms, gap_ms, bus_bytes...
                   flags bit0 = NO_REPLY: send and return at once (broadcasts,
                   sync-writes). Otherwise, after sending, collect bytes until
                   `timeout_ms` (0 = 10) pass with none received, or until
                   `gap_ms` (0 = 2) pass after the last received byte.
                   Response payload = the bytes received (may be empty).
  0x02 SET_BAUD  payload = u32 baud (23 .. 1500000). Response payload empty.
  0x03 GET_INFO  payload empty. Response = proto_version, fw_version, u32 baud.
  0x04 SET_DIR   payload = 0 receive (TX buffer off), 1 transmit (TX buffer
                   on), 2 both buffers off (RX pin then reads low).
                   For checking the buffer wiring with a meter/scope.
  0x05 SET_OPTIONS  payload = flags. bit0 = ECHO: the RX path hears our own
                   transmission (RX buffer ungated or wired to TX); while
                   collecting a reply, discard received bytes that match the
                   bytes just sent, in order, so only real replies come back.
                   Default ON (RX is always enabled, see Pinout). Response
                   payload empty.
  0x06 P1_ACCESS bring-up aid for probing buffer wiring. payload = selMask,
                   selVal, dirMask, dirVal, latchMask, latchVal. Applies the
                   masked bits to P1SEL, P1DIR and P1 (the output latch), in
                   that order, then returns 3 bytes: P1 (pin levels), P1SEL,
                   P1DIR. Bit 7 (UART RX) is protected. Bit 6 is UART TX:
                   clear its P1SEL bit to drive it as a plain pin, and set it
                   again afterwards (or send SET_DIR) to restore the UART.

status:
  0 OK           1 TIMEOUT (XFER: nothing received)
  2 BAD_REQUEST  3 UART_ERROR (bytes received but a framing/overrun error was
                 seen; payload still returned)

A frame that stalls part-way is dropped after 50 ms; garbage between frames is
ignored until the next SOF.
*/

/** Dependencies **************************************************************/
#include <wixel.h>
#include <usb.h>
#include <usb_com.h>
#include <uart1.h>

/** Parameters ****************************************************************/
int32 CODE param_baud_rate = 1000000;

/** Protocol ******************************************************************/
#define PROTO_VERSION   1
#define FW_VERSION      1

#define SOF             0xA5

#define CMD_XFER        0x01
#define CMD_SET_BAUD    0x02
#define CMD_GET_INFO    0x03
#define CMD_SET_DIR     0x04
#define CMD_SET_OPTIONS 0x05
#define CMD_P1_ACCESS   0x06

#define OPT_ECHO        0x01

#define ST_OK           0
#define ST_TIMEOUT      1
#define ST_BAD_REQUEST  2
#define ST_UART_ERROR   3

#define FLAG_NO_REPLY   0x01

#define DEFAULT_TIMEOUT_MS  10
#define DEFAULT_GAP_MS      2
#define FRAME_STALL_MS      50

// Largest request payload / reply we handle. The UART TX ring holds 255 bytes;
// leave headroom.
#define MAX_PAYLOAD     200
#define MAX_REPLY       200

/** Buffer direction pins (P1DIR bits) ****************************************/
#define TX_EN_BIT       0x20    // P1_5
#define RX_EN_BIT       0x02    // P1_1
#define TX_EN_ACTIVE_HIGH   1
#define RX_EN_ACTIVE_HIGH   1

#if TX_EN_ACTIVE_HIGH
#define TX_EN_ON()      { P1 |= TX_EN_BIT; }
#define TX_EN_OFF()     { P1 &= ~TX_EN_BIT; }
#else
#define TX_EN_ON()      { P1 &= ~TX_EN_BIT; }
#define TX_EN_OFF()     { P1 |= TX_EN_BIT; }
#endif
#if RX_EN_ACTIVE_HIGH
#define RX_EN_ON()      { P1 |= RX_EN_BIT; }
#define RX_EN_OFF()     { P1 &= ~RX_EN_BIT; }
#else
#define RX_EN_ON()      { P1 &= ~RX_EN_BIT; }
#define RX_EN_OFF()     { P1 |= RX_EN_BIT; }
#endif

/** State *********************************************************************/
static uint8 XDATA reqPayload[MAX_PAYLOAD];
static uint8 XDATA reply[MAX_REPLY];
static uint8 XDATA outFrame[MAX_REPLY + 8];
static uint8 XDATA infoPayload[6];
static uint8 XDATA p1Payload[3];

static uint32 currentBaud;
static BIT echoSkip = 1;   // RX is always enabled, so we always hear our own bytes
static BIT busyLed = 0;
static BIT errorLed = 0;
static uint8 lastErrorMs;

/** Bus direction *************************************************************/

// Bus not driven by us; we listen. The RX buffer stays enabled in every mode
// except idle (see the pinout note above).
static void busRx(void)
{
    TX_EN_OFF();
    RX_EN_ON();
}

static void busTx(void)
{
    RX_EN_ON();     // RX stays on; the echo of our bytes is discarded on receive
    TX_EN_ON();
}

// Both buffers off (wiring tests only). The RX pin then reads low.
static void busIdle(void)
{
    TX_EN_OFF();
    RX_EN_OFF();
}

static void busPinsInit(void)
{
    P1DIR |= TX_EN_BIT | RX_EN_BIT;     // always driven, never released
    busRx();
}

/** Bus transfer **************************************************************/

// Block until the last byte we queued has fully left the UART. The UART TX ring
// buffer drains by interrupt; once it is empty the last byte may still be in the
// shift register, so also wait for U1CSR.ACTIVE to clear. (Reading U1CSR can
// clear FE/ERR flags, which is harmless here: the RX buffer is disabled.)
// Bounded so a hardware surprise can't hang the bridge.
static void waitTxDone(void)
{
    uint8 start = (uint8)getMs();

    while (uart1TxAvailable() < 255)
    {
        if ((uint8)((uint8)getMs() - start) > 50) return;
    }
    while (U1CSR & 0x01)
    {
        if ((uint8)((uint8)getMs() - start) > 50) return;
    }
    delayMicroseconds(2);   // margin after the stop bit
}

static void flushRx(void)
{
    while (uart1RxAvailable())
    {
        uart1RxReceiveByte();
    }
    uart1RxBufferFullOccurred = 0;
    uart1RxFramingErrorOccurred = 0;
    uart1RxParityErrorOccurred = 0;
}

// Send `n` bytes on the bus, turn around, and (unless noReply) collect the
// reply into reply[]. Returns the number of reply bytes; *status is set.
static uint8 busTransfer(const uint8 XDATA * data, uint8 n, uint8 flags,
                         uint8 timeoutMs, uint8 gapMs, uint8 * status)
{
    uint8 count = 0;
    uint8 startMs, lastMs, nowMs;
    uint8 echoIdx = 0;
    uint8 b;
    BIT got = 0;

    if (timeoutMs == 0) timeoutMs = DEFAULT_TIMEOUT_MS;
    if (gapMs == 0) gapMs = DEFAULT_GAP_MS;

    flushRx();
    busTx();
    uart1TxSend(data, n);
    waitTxDone();
    busRx();

    if (flags & FLAG_NO_REPLY)
    {
        *status = ST_OK;
        return 0;
    }

    startMs = lastMs = (uint8)getMs();
    while (1)
    {
        while (uart1RxAvailable() && count < MAX_REPLY)
        {
            b = uart1RxReceiveByte();
            if (echoSkip && echoIdx < n && b == data[echoIdx])
            {
                echoIdx++;      // our own byte coming back; not a reply
                continue;
            }
            echoIdx = n;        // first mismatch ends echo skipping
            reply[count++] = b;
            lastMs = (uint8)getMs();
            got = 1;
        }
        if (count >= MAX_REPLY) break;

        nowMs = (uint8)getMs();
        if (!got && (uint8)(nowMs - startMs) >= timeoutMs) break;
        if (got && (uint8)(nowMs - lastMs) >= gapMs) break;
    }

    if (uart1RxBufferFullOccurred || uart1RxFramingErrorOccurred)
    {
        *status = ST_UART_ERROR;
        lastErrorMs = (uint8)getMs();
        errorLed = 1;
    }
    else
    {
        *status = got ? ST_OK : ST_TIMEOUT;
        if (!got)
        {
            lastErrorMs = (uint8)getMs();
            errorLed = 1;
        }
    }
    return count;
}

/** USB framing ***************************************************************/

// Write `n` bytes to the host, waiting for USB buffer space. Gives up after
// 200 ms so an absent/stalled host can't wedge the bridge.
static void usbWrite(const uint8 XDATA * buf, uint8 n)
{
    uint8 avail;
    uint8 chunk;
    uint8 start = (uint8)getMs();

    while (n)
    {
        usbComService();
        avail = usbComTxAvailable();
        if (avail)
        {
            chunk = (avail < n) ? avail : n;
            usbComTxSend(buf, chunk);
            buf += chunk;
            n -= chunk;
            start = (uint8)getMs();
        }
        else if ((uint8)((uint8)getMs() - start) > 200)
        {
            return;
        }
    }
    usbComService();
}

static void sendResponse(uint8 cmd, uint8 status, const uint8 XDATA * payload, uint8 len)
{
    uint8 i;
    uint8 sum;

    outFrame[0] = SOF;
    outFrame[1] = cmd;
    outFrame[2] = status;
    outFrame[3] = len;
    sum = cmd + status + len;
    for (i = 0; i < len; i++)
    {
        outFrame[4 + i] = payload[i];
        sum += payload[i];
    }
    outFrame[4 + len] = ~sum;
    usbWrite(outFrame, 5 + len);
}

static void handleRequest(uint8 cmd, uint8 len)
{
    uint8 status;
    uint8 n;
    uint32 baud;

    busyLed = 1;
    switch (cmd)
    {
    case CMD_XFER:
        // payload = flags, timeout_ms, gap_ms, bus_bytes...
        if (len < 4)
        {
            sendResponse(cmd, ST_BAD_REQUEST, reqPayload, 0);
            break;
        }
        n = busTransfer(reqPayload + 3, len - 3, reqPayload[0],
                        reqPayload[1], reqPayload[2], &status);
        sendResponse(cmd, status, reply, n);
        break;

    case CMD_SET_BAUD:
        if (len != 4)
        {
            sendResponse(cmd, ST_BAD_REQUEST, reqPayload, 0);
            break;
        }
        baud = (uint32)reqPayload[0] | ((uint32)reqPayload[1] << 8) |
               ((uint32)reqPayload[2] << 16) | ((uint32)reqPayload[3] << 24);
        if (baud < 23 || baud > 1500000)
        {
            sendResponse(cmd, ST_BAD_REQUEST, reqPayload, 0);
            break;
        }
        uart1SetBaudRate(baud);
        currentBaud = baud;
        sendResponse(cmd, ST_OK, reqPayload, 0);
        break;

    case CMD_GET_INFO:
        infoPayload[0] = PROTO_VERSION;
        infoPayload[1] = FW_VERSION;
        infoPayload[2] = (uint8)currentBaud;
        infoPayload[3] = (uint8)(currentBaud >> 8);
        infoPayload[4] = (uint8)(currentBaud >> 16);
        infoPayload[5] = (uint8)(currentBaud >> 24);
        sendResponse(cmd, ST_OK, infoPayload, 6);
        break;

    case CMD_SET_DIR:
        if (len != 1 || reqPayload[0] > 2)
        {
            sendResponse(cmd, ST_BAD_REQUEST, reqPayload, 0);
            break;
        }
        if (reqPayload[0] == 0) busRx();
        else if (reqPayload[0] == 1) busTx();
        else busIdle();
        sendResponse(cmd, ST_OK, reqPayload, 0);
        break;

    case CMD_SET_OPTIONS:
        if (len != 1)
        {
            sendResponse(cmd, ST_BAD_REQUEST, reqPayload, 0);
            break;
        }
        echoSkip = (reqPayload[0] & OPT_ECHO) ? 1 : 0;
        sendResponse(cmd, ST_OK, reqPayload, 0);
        break;

    case CMD_P1_ACCESS:
        if (len != 6)
        {
            sendResponse(cmd, ST_BAD_REQUEST, reqPayload, 0);
            break;
        }
        // Bit 7 is the UART RX pin: leave it alone.
        P1SEL = (P1SEL & ~(reqPayload[0] & 0x7F)) | (reqPayload[1] & reqPayload[0] & 0x7F);
        P1DIR = (P1DIR & ~(reqPayload[2] & 0x7F)) | (reqPayload[3] & reqPayload[2] & 0x7F);
        P1    = (P1    & ~(reqPayload[4] & 0x7F)) | (reqPayload[5] & reqPayload[4] & 0x7F);
        delayMicroseconds(20);      // let the pins settle before reading them
        p1Payload[0] = P1;
        p1Payload[1] = P1SEL;
        p1Payload[2] = P1DIR;
        sendResponse(cmd, ST_OK, p1Payload, 3);
        break;

    default:
        sendResponse(cmd, ST_BAD_REQUEST, reqPayload, 0);
        break;
    }
    busyLed = 0;
}

// Byte-at-a-time frame parser fed from the USB receive buffer.
#define S_SOF       0
#define S_CMD       1
#define S_LEN       2
#define S_PAYLOAD   3
#define S_CHK       4

static void protocolService(void)
{
    static uint8 state = S_SOF;
    static uint8 cmd, len, got, sum;
    static uint8 lastByteMs;
    uint8 b;

    if (state != S_SOF && (uint8)((uint8)getMs() - lastByteMs) > FRAME_STALL_MS)
    {
        state = S_SOF;  // frame stalled part-way; resync
    }

    while (usbComRxAvailable())
    {
        b = usbComRxReceiveByte();
        lastByteMs = (uint8)getMs();

        switch (state)
        {
        case S_SOF:
            if (b == SOF) state = S_CMD;
            break;
        case S_CMD:
            cmd = b;
            sum = b;
            state = S_LEN;
            break;
        case S_LEN:
            len = b;
            sum += b;
            got = 0;
            if (len > MAX_PAYLOAD)
            {
                sendResponse(cmd, ST_BAD_REQUEST, reqPayload, 0);
                state = S_SOF;
            }
            else
            {
                state = len ? S_PAYLOAD : S_CHK;
            }
            break;
        case S_PAYLOAD:
            reqPayload[got++] = b;
            sum += b;
            if (got == len) state = S_CHK;
            break;
        case S_CHK:
            state = S_SOF;
            if ((uint8)~sum == b)
            {
                handleRequest(cmd, len);
            }
            else
            {
                sendResponse(cmd, ST_BAD_REQUEST, reqPayload, 0);
            }
            break;
        }
    }
}

/** Main **********************************************************************/

static void updateLeds(void)
{
    usbShowStatusWithGreenLed();
    LED_RED(busyLed);
    if (errorLed && (uint8)((uint8)getMs() - lastErrorMs) > 100)
    {
        errorLed = 0;
    }
    LED_YELLOW(errorLed);
}

void main()
{
    systemInit();
    usbInit();

    uart1Init();
    currentBaud = (uint32)param_baud_rate;
    uart1SetBaudRate(currentBaud);
    busPinsInit();

    while (1)
    {
        boardService();
        updateLeds();
        usbComService();
        protocolService();
    }
}
