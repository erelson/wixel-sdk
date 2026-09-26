"""Talks to the Wixel ax_bridge firmware over its USB virtual COM port."""
import struct
import time

from . import protocol as p

POLOLU_VID = 0x1FFB
DEFAULT_BAUD = 1000000


class BridgeError(Exception):
    """The Wixel didn't answer, or answered with an error."""


def find_port():
    """Path of the one attached Pololu (Wixel) serial port.

    Raises BridgeError if there are none or several; pass --port then.
    """
    from serial.tools import list_ports
    found = [x.device for x in list_ports.comports() if x.vid == POLOLU_VID]
    if len(found) == 1:
        return found[0]
    if not found:
        raise BridgeError("no Wixel (USB vendor 0x1FFB) found; is it plugged in "
                          "and running ax_bridge? Use --port to name a device.")
    raise BridgeError("several Wixels found (%s); use --port to pick one"
                      % ", ".join(sorted(found)))


class WixelBridge:
    """Request/response client. `ser` is anything with pyserial's read/write API."""

    def __init__(self, ser, timeout=1.0):
        self.ser = ser
        self.timeout = timeout
        self._decoder = p.ResponseDecoder()
        self._pending = []

    @classmethod
    def open(cls, port=None, timeout=1.0):
        import serial
        ser = serial.Serial(port or find_port(), 115200, timeout=0.05,
                            write_timeout=1.0)
        bridge = cls(ser, timeout)
        ser.reset_input_buffer()
        return bridge

    def close(self):
        self.ser.close()

    def __enter__(self):
        return self

    def __exit__(self, *exc):
        self.close()

    def _call(self, cmd, payload=b"", timeout=None):
        """Send one request, return its Response (skipping stale ones)."""
        self.ser.write(p.encode_request(cmd, payload))
        deadline = time.monotonic() + (self.timeout if timeout is None else timeout)
        while True:
            for resp in self._pending:
                if resp.cmd == cmd:
                    self._pending.remove(resp)
                    return resp
            if time.monotonic() > deadline:
                raise BridgeError("no response from the Wixel (command 0x%02x); "
                                  "is ax_bridge running on it?" % cmd)
            data = self.ser.read(self.ser.in_waiting or 1)
            if data:
                self._pending.extend(self._decoder.feed(data))

    def xfer(self, packet, reply_timeout_ms=10, gap_ms=2, no_reply=False):
        """Put `packet` on the servo bus; return (status, reply_bytes).

        status is one of protocol.ST_*. With no_reply the Wixel returns as soon
        as the bytes are out (broadcasts / sync writes).
        """
        for name, v in (("reply_timeout_ms", reply_timeout_ms), ("gap_ms", gap_ms)):
            if not 0 <= v <= 255:
                raise ValueError("%s must be 0..255" % name)
        flags = p.FLAG_NO_REPLY if no_reply else 0
        payload = bytes([flags, reply_timeout_ms, gap_ms]) + bytes(packet)
        # The Wixel takes up to reply_timeout_ms; allow for that plus USB slack.
        resp = self._call(p.CMD_XFER, payload,
                          timeout=self.timeout + reply_timeout_ms / 1000.0)
        if resp.status == p.ST_BAD_REQUEST:
            raise BridgeError("the Wixel rejected the transfer as malformed")
        return resp.status, resp.payload

    def set_baud(self, baud):
        resp = self._call(p.CMD_SET_BAUD, struct.pack("<I", baud))
        if resp.status != p.ST_OK:
            raise BridgeError("the Wixel rejected baud rate %d (valid: 23..1500000)"
                              % baud)

    def info(self):
        """Returns dict(proto=, firmware=, baud=)."""
        resp = self._call(p.CMD_GET_INFO)
        if resp.status != p.ST_OK or len(resp.payload) != 6:
            raise BridgeError("unexpected GET_INFO response")
        proto, fw = resp.payload[0], resp.payload[1]
        (baud,) = struct.unpack("<I", resp.payload[2:6])
        return {"proto": proto, "firmware": fw, "baud": baud}

    def set_direction(self, mode):
        """p.DIR_RX / DIR_TX / DIR_IDLE: force the buffer state (wiring checks)."""
        resp = self._call(p.CMD_SET_DIR, bytes([mode]))
        if resp.status != p.ST_OK:
            raise BridgeError("the Wixel rejected the direction change")

    def set_options(self, echo=False):
        """echo=True: discard bytes that merely echo what we just sent (for
        buffers where the RX path hears TX). Persists until changed."""
        flags = p.OPT_ECHO if echo else 0
        resp = self._call(p.CMD_SET_OPTIONS, bytes([flags]))
        if resp.status != p.ST_OK:
            raise BridgeError("the Wixel rejected the options (old firmware?)")

    def p1_access(self, sel_mask=0, sel_val=0, dir_mask=0, dir_val=0,
                  latch_mask=0, latch_val=0):
        """Set masked bits of P1SEL / P1DIR / P1 and read back the pins.

        Returns (pins, sel, dir) as bytes read after the change. Bring-up aid
        for probing buffer wiring; see ax_bridge.c CMD_P1_ACCESS.
        """
        resp = self._call(p.CMD_P1_ACCESS, bytes([sel_mask, sel_val, dir_mask,
                                                   dir_val, latch_mask, latch_val]))
        if resp.status != p.ST_OK or len(resp.payload) != 3:
            raise BridgeError("the Wixel rejected the pin access (old firmware?)")
        return tuple(resp.payload)
