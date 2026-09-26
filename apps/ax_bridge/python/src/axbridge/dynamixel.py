"""Dynamixel protocol 1 (AX-12 family) on top of a WixelBridge."""
from collections import namedtuple

from . import protocol as p
from .families import AX, Register

BROADCAST_ID = 254

INST_PING = 0x01
INST_READ = 0x02
INST_WRITE = 0x03
INST_REG_WRITE = 0x04
INST_ACTION = 0x05
INST_RESET = 0x06
INST_SYNC_WRITE = 0x83

# Re-exported for convenience/compat; the tables live in families.py.
AX_REGISTERS = AX.registers
BY_NAME = AX.by_name
BY_ADDR = AX.by_addr

ERROR_BITS = [(0x01, "input voltage"), (0x02, "angle limit"), (0x04, "overheating"),
              (0x08, "range"), (0x10, "checksum"), (0x20, "overload"),
              (0x40, "instruction")]


def baud_for_register(n):
    """AX baud register value -> bits per second (2,000,000 / (n + 1))."""
    return AX.baud_for_code(n)


def register_for_baud(bps):
    """Nearest AX baud register value for `bps`, and the rate it gives."""
    return AX.code_for_baud(bps)


class NoReply(Exception):
    """A servo didn't answer (or the answer was unreadable)."""


Status = namedtuple("Status", "id error params")


def error_names(error):
    return [name for bit, name in ERROR_BITS if error & bit]


def build_packet(dev_id, instruction, params=()):
    body = bytes([dev_id, len(params) + 2, instruction]) + bytes(params)
    return bytes([0xFF, 0xFF]) + body + bytes([p.checksum(body)])


def find_status(data):
    """First valid status packet inside `data`, or None.

    Tolerates junk before the header (turnaround glitches on the wire).
    """
    data = bytes(data)
    i = 0
    while i + 6 <= len(data):  # shortest status packet is 6 bytes
        if data[i] == 0xFF and data[i + 1] == 0xFF and data[i + 2] != 0xFF:
            length = data[i + 3]
            end = i + 4 + length
            if length >= 2 and end <= len(data):
                body = data[i + 2:end - 1]
                if p.checksum(body) == data[end - 1]:
                    return Status(data[i + 2], data[i + 4], bytes(data[i + 5:end - 1]))
        i += 1
    return None


class Bus:
    """Dynamixel operations over a WixelBridge."""

    def __init__(self, bridge, reply_timeout_ms=10, family=AX):
        self.bridge = bridge
        self.family = family
        self.reply_timeout_ms = reply_timeout_ms
        # True if the last reply began with the exact bytes we sent: the RX path
        # is hearing our own transmission. (A ping to a servo reporting error
        # 0x01 produces the same bytes, so it is a suspicion, not a proof.)
        self.echo_suspected = False

    def _transact(self, packet, timeout_ms=None):
        _, reply = self.bridge.xfer(
            packet, reply_timeout_ms=timeout_ms or self.reply_timeout_ms)
        self.echo_suspected = bytes(reply).startswith(bytes(packet))
        return find_status(reply)

    def ping(self, dev_id, timeout_ms=None):
        """Status if the servo answered, else None."""
        return self._transact(build_packet(dev_id, INST_PING), timeout_ms)

    def read(self, dev_id, addr, count):
        st = self._transact(build_packet(dev_id, INST_READ, [addr, count]))
        if st is None:
            raise NoReply("servo %d did not answer a read of register %d" % (dev_id, addr))
        if len(st.params) != count:
            raise NoReply("servo %d returned %d bytes for a %d byte read (error 0x%02x)"
                          % (dev_id, len(st.params), count, st.error))
        return st.params

    def read_value(self, dev_id, reg):
        raw = self.read(dev_id, reg.addr, reg.size)
        return raw[0] | (raw[1] << 8) if reg.size == 2 else raw[0]

    def write(self, dev_id, addr, data):
        """Write registers. Returns the Status ack, or None if the servo stayed
        silent (normal when its status return level is below 2)."""
        packet = build_packet(dev_id, INST_WRITE, [addr] + list(data))
        if dev_id == BROADCAST_ID:
            self.bridge.xfer(packet, no_reply=True)
            return None
        return self._transact(packet)

    def write_value(self, dev_id, reg, value, relock=True):
        """Write one register value (1 or 2 bytes, low byte first).

        For families with an EEPROM lock (Feetech), EEPROM registers are written
        inside an unlock ... relock bracket. After an ID change the relock goes
        to the NEW id. relock=False leaves it unlocked (used when the servo is
        about to change baud, so the relock must happen at the new rate).
        """
        data = [value & 0xFF] if reg.size == 1 else [value & 0xFF, (value >> 8) & 0xFF]
        lock = self.family.lock_reg
        if lock is None or not reg.eeprom:
            return self.write(dev_id, reg.addr, data)
        self.write(dev_id, lock.addr, [0])
        ack = self.write(dev_id, reg.addr, data)
        if relock:
            target = value if reg.name == self.family.id_reg.name else dev_id
            self.write(target, lock.addr, [1])
        return ack

    def relock(self, dev_id):
        """Set the EEPROM lock again (no-op for families without one)."""
        if self.family.lock_reg is not None:
            self.write(dev_id, self.family.lock_reg.addr, [1])

    def factory_reset(self, dev_id):
        """Restores defaults: ID 1, 1 Mbaud, ... Returns the ack Status or None."""
        return self._transact(build_packet(dev_id, INST_RESET))

    def scan(self, first=1, last=253, timeout_ms=3, found=None):
        """IDs that answered a ping. `found(id)` is called as each is seen."""
        ids = []
        echoes = 0
        for dev_id in range(first, last + 1):
            if self.ping(dev_id, timeout_ms) is not None:
                ids.append(dev_id)
                echoes += self.echo_suspected
                if found:
                    found(dev_id)
        # Sticky over the whole scan: true if any "answer" was really our echo.
        self.echo_suspected = bool(echoes)
        return ids
