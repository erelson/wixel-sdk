"""Wire protocol between the host and the Wixel ax_bridge firmware.

Kept free of any I/O so it can be tested on its own. The authoritative
description is the header comment of ../../ax_bridge.c.

Request:   SOF cmd len payload[len] chk
Response:  SOF cmd status len payload[len] chk
chk = (~sum(all bytes between SOF and chk)) & 0xFF
"""
from collections import namedtuple

SOF = 0xA5

CMD_XFER = 0x01
CMD_SET_BAUD = 0x02
CMD_GET_INFO = 0x03
CMD_SET_DIR = 0x04
CMD_SET_OPTIONS = 0x05
CMD_P1_ACCESS = 0x06

OPT_ECHO = 0x01

ST_OK = 0
ST_TIMEOUT = 1
ST_BAD_REQUEST = 2
ST_UART_ERROR = 3
STATUS_NAMES = {ST_OK: "ok", ST_TIMEOUT: "timeout",
                ST_BAD_REQUEST: "bad request", ST_UART_ERROR: "uart error"}

FLAG_NO_REPLY = 0x01

MAX_PAYLOAD = 200  # firmware limit for a request payload and a reply

DIR_RX, DIR_TX, DIR_IDLE = 0, 1, 2

Response = namedtuple("Response", "cmd status payload")


def checksum(data):
    return (~sum(data)) & 0xFF


def encode_request(cmd, payload=b""):
    payload = bytes(payload)
    if len(payload) > MAX_PAYLOAD:
        raise ValueError("payload of %d bytes exceeds the %d byte limit"
                         % (len(payload), MAX_PAYLOAD))
    body = bytes([cmd, len(payload)]) + payload
    return bytes([SOF]) + body + bytes([checksum(body)])


def encode_response(cmd, status, payload=b""):
    """What the firmware sends; used by tests and simulators."""
    payload = bytes(payload)
    body = bytes([cmd, status, len(payload)]) + payload
    return bytes([SOF]) + body + bytes([checksum(body)])


class ResponseDecoder:
    """Incremental decoder: feed() raw bytes, get back complete Responses.

    Bytes that don't start a valid frame are skipped, so a stray byte on the
    USB link costs at most the frame it lands in.
    """

    def __init__(self):
        self._buf = bytearray()

    def feed(self, data):
        self._buf.extend(data)
        out = []
        while True:
            try:
                start = self._buf.index(SOF)
            except ValueError:
                self._buf.clear()
                return out
            del self._buf[:start]
            if len(self._buf) < 4:
                return out
            total = 5 + self._buf[3]
            if len(self._buf) < total:
                return out
            frame = bytes(self._buf[:total])
            if checksum(frame[1:-1]) == frame[-1]:
                out.append(Response(frame[1], frame[2], frame[4:-1]))
                del self._buf[:total]
            else:
                del self._buf[:1]  # false SOF; look for the next one
