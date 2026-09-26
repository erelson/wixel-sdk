"""Control tables and per-family quirks for Dynamixel-protocol-1 servos.

Two families share the same framing (see dynamixel.py) but differ in registers,
baud encoding, EEPROM protection and position scale:

  ax   Dynamixel AX-12 / AX-12A
  sts  Feetech STS3215 / STS3235 (register map cross-checked in numa3's
       feetech/feetech.py against the protocol manual and the STS3215 spec)
"""
from collections import namedtuple

Register = namedtuple("Register", "addr name size eeprom writable")


class Family:
    def __init__(self, name, registers, *, id_reg, baud_reg, torque_reg, goal_reg,
                 speed_reg, position_reg, position_max, lock_reg=None,
                 led_reg=None, baud_codes=None, forbidden_writes=None):
        self.name = name
        self.registers = registers
        self.by_name = {r.name: r for r in registers}
        self.by_addr = {r.addr: r for r in registers}
        self.id_reg = self.by_name[id_reg]
        self.baud_reg = self.by_name[baud_reg]
        self.torque_reg = self.by_name[torque_reg]
        self.goal_reg = self.by_name[goal_reg]
        self.speed_reg = self.by_name[speed_reg]
        self.position_reg = self.by_name[position_reg]
        self.position_max = position_max
        self.lock_reg = self.by_name[lock_reg] if lock_reg else None
        self.led_reg = self.by_name[led_reg] if led_reg else None
        # code -> bits per second; None means the AX formula 2,000,000/(n+1).
        self.baud_codes = baud_codes
        # {register name: {forbidden values}}: writes we refuse without --force.
        self.forbidden_writes = forbidden_writes or {}

    def baud_for_code(self, n):
        if self.baud_codes is None:
            return 2000000.0 / (n + 1)
        return float(self.baud_codes[n]) if n in self.baud_codes else None

    def code_for_baud(self, bps):
        """(code, actual bps) nearest to `bps`."""
        if self.baud_codes is None:
            n = max(1, min(254, round(2000000.0 / bps) - 1))
            return n, 2000000.0 / (n + 1)
        code = min(self.baud_codes, key=lambda c: abs(self.baud_codes[c] - bps))
        return code, float(self.baud_codes[code])


AX_REGISTERS = [
    Register(0, "model_number", 2, True, False),
    Register(2, "firmware_version", 1, True, False),
    Register(3, "id", 1, True, True),
    Register(4, "baud_rate", 1, True, True),
    Register(5, "return_delay_time", 1, True, True),
    Register(6, "cw_angle_limit", 2, True, True),
    Register(8, "ccw_angle_limit", 2, True, True),
    Register(11, "temperature_limit", 1, True, True),
    Register(12, "low_voltage_limit", 1, True, True),
    Register(13, "high_voltage_limit", 1, True, True),
    Register(14, "max_torque", 2, True, True),
    Register(16, "status_return_level", 1, True, True),
    Register(17, "alarm_led", 1, True, True),
    Register(18, "alarm_shutdown", 1, True, True),
    Register(24, "torque_enable", 1, False, True),
    Register(25, "led", 1, False, True),
    Register(26, "cw_compliance_margin", 1, False, True),
    Register(27, "ccw_compliance_margin", 1, False, True),
    Register(28, "cw_compliance_slope", 1, False, True),
    Register(29, "ccw_compliance_slope", 1, False, True),
    Register(30, "goal_position", 2, False, True),
    Register(32, "moving_speed", 2, False, True),
    Register(34, "torque_limit", 2, False, True),
    Register(36, "present_position", 2, False, False),
    Register(38, "present_speed", 2, False, False),
    Register(40, "present_load", 2, False, False),
    Register(42, "present_voltage", 1, False, False),
    Register(43, "present_temperature", 1, False, False),
    Register(44, "registered", 1, False, False),
    Register(46, "moving", 1, False, False),
    Register(47, "lock", 1, False, True),
    Register(48, "punch", 2, False, True),
]

# STS3215 / STS3235. EEPROM = addresses below 40; RAM from 40 up.
STS_REGISTERS = [
    Register(0, "firmware_major", 1, True, False),
    Register(1, "firmware_minor", 1, True, False),
    Register(3, "servo_major", 1, True, False),
    Register(4, "servo_minor", 1, True, False),
    Register(5, "id", 1, True, True),
    Register(6, "baud_rate", 1, True, True),
    Register(7, "response_delay", 1, True, True),
    Register(8, "response_status_level", 1, True, True),
    Register(9, "min_angle_limit", 2, True, True),
    Register(11, "max_angle_limit", 2, True, True),
    Register(13, "max_temperature", 1, True, True),
    Register(14, "max_voltage", 1, True, True),
    Register(15, "min_voltage", 1, True, True),
    Register(16, "max_torque", 2, True, True),
    Register(19, "unloading_condition", 1, True, True),
    Register(20, "led_alarm_condition", 1, True, True),
    Register(21, "pos_p_gain", 1, True, True),
    Register(22, "pos_d_gain", 1, True, True),
    Register(23, "pos_i_gain", 1, True, True),
    Register(24, "min_startup_force", 2, True, True),
    Register(26, "cw_dead_band", 1, True, True),
    Register(27, "ccw_dead_band", 1, True, True),
    Register(28, "protection_current", 2, True, True),
    Register(30, "angular_resolution", 1, True, True),
    Register(31, "position_correction", 2, True, True),
    Register(33, "operation_mode", 1, True, True),
    Register(34, "protection_torque", 1, True, True),
    Register(35, "protection_time", 1, True, True),
    Register(36, "overload_torque", 1, True, True),
    Register(37, "speed_p_gain", 1, True, True),
    Register(38, "overcurrent_time", 1, True, True),
    Register(39, "speed_i_gain", 1, True, True),
    Register(40, "torque_enable", 1, False, True),
    Register(41, "target_acceleration", 1, False, True),
    Register(42, "goal_position", 2, False, True),
    Register(44, "goal_time", 2, False, True),
    Register(46, "goal_speed", 2, False, True),
    Register(48, "torque_limit", 2, False, True),
    Register(55, "lock", 1, False, True),
    Register(56, "present_position", 2, False, False),
    Register(58, "present_speed", 2, False, False),
    Register(60, "present_load", 2, False, False),
    Register(62, "present_voltage", 1, False, False),
    Register(63, "present_temperature", 1, False, False),
    Register(64, "async_write_flag", 1, False, False),
    Register(65, "status", 1, False, False),
    Register(66, "moving", 1, False, False),
    Register(69, "present_current", 2, False, False),
]

AX = Family(
    "ax", AX_REGISTERS, id_reg="id", baud_reg="baud_rate",
    torque_reg="torque_enable", goal_reg="goal_position", speed_reg="moving_speed",
    position_reg="present_position", position_max=1023, led_reg="led")

STS = Family(
    "sts", STS_REGISTERS, id_reg="id", baud_reg="baud_rate",
    torque_reg="torque_enable", goal_reg="goal_position", speed_reg="goal_speed",
    position_reg="present_position", position_max=4095, lock_reg="lock",
    # From Feetech's STS3215 datasheet as recalled, NOT from the protocol manual
    # in numa3: verify against your servo's documentation before relying on it.
    baud_codes={0: 1000000, 1: 500000, 2: 250000, 3: 128000,
                4: 115200, 5: 76800, 6: 57600, 7: 38400},
    # 128 runs the centering function (redefines neutral), not "torque on".
    forbidden_writes={"torque_enable": {128}})

FAMILIES = {"ax": AX, "sts": STS}
