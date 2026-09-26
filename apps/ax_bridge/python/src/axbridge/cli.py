"""axbridge: command line tool for servos behind a Wixel running ax_bridge.

  uv run axbridge scan
  uv run axbridge ping 52
  uv run axbridge --family sts dump 1
  uv run axbridge baud 52 --bps 500000
"""
import argparse
import sys

from . import diagnose
from . import dynamixel as dxl
from . import protocol as p
from .bridge import BridgeError, WixelBridge
from .families import FAMILIES


def parse_int(text):
    return int(text, 0)


def resolve_register(family, text):
    """Register by name (id, goal_position, ...) or number, for `family`."""
    if text in family.by_name:
        return family.by_name[text]
    try:
        addr = parse_int(text)
    except ValueError:
        raise SystemExit("error: unknown register %r for family %s; names: %s"
                         % (text, family.name, ", ".join(sorted(family.by_name))))
    return family.by_addr.get(addr, dxl.Register(addr, "reg%d" % addr, 1, False, True))


def _describe_status(st):
    errs = dxl.error_names(st.error)
    return "error 0x%02x (%s)" % (st.error, ", ".join(errs)) if st.error else "ok"


ECHO_WARNING = ("warning: the reply repeats exactly what was sent, so this is probably "
                "the Wixel hearing its own transmission, not a servo. Echo skipping is "
                "on by default, so check the buffer wiring with `pinscan`.")


def _value(raw, size):
    return raw[0] | (raw[1] << 8) if size == 2 else raw[0]


def cmd_info(bus, args):
    info = bus.bridge.info()
    print("Wixel ax_bridge: protocol %d, firmware %d, bus baud requested %d"
          % (info["proto"], info["firmware"], info["baud"]))


def cmd_dir(bus, args):
    bus.bridge.set_direction({"rx": p.DIR_RX, "tx": p.DIR_TX, "idle": p.DIR_IDLE}[args.mode])
    print("buffer direction set to %s (stays until the next transfer)" % args.mode)


def cmd_ping(bus, args):
    st = bus.ping(args.id)
    if st is not None and bus.echo_suspected:
        print(ECHO_WARNING)
        return 1
    if st is None:
        print("no reply from ID %d at %d baud" % (args.id, args.bus_baud))
        return 1
    print("ID %d answered: %s" % (st.id, _describe_status(st)))


def cmd_scan(bus, args):
    print("scanning IDs %d-%d at %d baud..." % (args.first, args.last, args.bus_baud))
    ids = bus.scan(args.first, args.last,
                   found=lambda i: print("  found ID %d" % i, flush=True))
    if ids and bus.echo_suspected:
        print(ECHO_WARNING)
        return 1
    print("%d servo(s) found" % len(ids))
    return 0 if ids else 1


def cmd_identify(bus, args):
    """Hint at which family a servo belongs to (not conclusive)."""
    try:
        raw = bus.read(args.id, 0, 5)
    except dxl.NoReply as e:
        print(e)
        return 1
    model = raw[0] | (raw[1] << 8)
    print("bytes 0-4: %s" % " ".join("%d" % b for b in raw))
    if model in (12, 18, 300, 24, 28, 29):
        print("looks like a Dynamixel (model number %d): use --family ax" % model)
    else:
        print("model number %d is not a known Dynamixel AX value; if this is a Feetech "
              "STS (firmware %d.%d, servo %d.%d) use --family sts. This is a hint only."
              % (model, raw[0], raw[1], raw[3], raw[4]))


def cmd_dump(bus, args):
    fam = bus.family
    for reg in fam.registers:
        try:
            value = bus.read_value(args.id, reg)
        except dxl.NoReply as e:
            print("%s" % e)
            return 1
        extra = ""
        if reg is fam.baud_reg:
            actual = fam.baud_for_code(value)
            extra = "  (%d baud)" % actual if actual else "  (unknown code)"
        elif reg.name == "present_voltage":
            extra = "  (%.1f V)" % (value / 10.0)
        print("%3d %-22s %5d%s" % (reg.addr, reg.name, value, extra))


def cmd_read(bus, args):
    reg = resolve_register(bus.family, args.register)
    count = args.count or reg.size
    raw = bus.read(args.id, reg.addr, count)
    if count == reg.size and reg.size in (1, 2):
        print(_value(raw, reg.size))
    else:
        print(" ".join("%d" % b for b in raw))


def _write_and_verify(bus, dev_id, reg, value):
    ack = bus.write_value(dev_id, reg, value)
    if ack is not None and ack.error:
        print("servo reported %s" % _describe_status(ack))
        return False
    try:
        back = bus.read_value(dev_id, reg)
    except dxl.NoReply as e:
        print("write sent%s but read-back failed: %s"
              % (" (acked)" if ack else " (no ack)", e))
        return False
    if back != value:
        print("write did not stick: %s reads %d, wanted %d" % (reg.name, back, value))
        return False
    print("%s = %d on ID %d" % (reg.name, back, dev_id))
    return True


def cmd_write(bus, args):
    reg = resolve_register(bus.family, args.register)
    if not reg.writable and not args.force:
        print("%s is read-only (use --force to try anyway)" % reg.name)
        return 2
    if args.value in bus.family.forbidden_writes.get(reg.name, ()) and not args.force:
        print("refusing to write %d to %s: it does not mean what it looks like "
              "(centering function on Feetech). Use --force if you really mean it."
              % (args.value, reg.name))
        return 2
    return 0 if _write_and_verify(bus, args.id, reg, args.value) else 1


def cmd_id(bus, args):
    fam = bus.family
    if bus.ping(args.new) is not None:
        print("ID %d is already in use; refusing to create a duplicate" % args.new)
        return 1
    if bus.ping(args.old) is None:
        print("no servo answers at ID %d" % args.old)
        return 1
    bus.write_value(args.old, fam.id_reg, args.new)
    if bus.ping(args.new) is None:
        print("changed ID %d -> %d but the servo doesn't answer at the new ID"
              % (args.old, args.new))
        return 1
    print("servo is now ID %d" % args.new)


def cmd_baud(bus, args):
    fam = bus.family
    if args.reg is not None:
        n = args.reg
        actual = fam.baud_for_code(n)
        if actual is None:
            print("baud code %d is not defined for family %s" % (n, fam.name))
            return 2
    else:
        n, actual = fam.code_for_baud(args.bps)
    print("baud code %d = %d baud" % (n, actual))
    if args.bps and abs(actual - args.bps) / args.bps > 0.03:
        print("that is more than 3%% away from the requested %d; refusing" % args.bps)
        return 2
    broadcast = args.id == dxl.BROADCAST_ID
    if broadcast and not args.yes:
        print("broadcast changes every servo on the bus; add --yes to confirm")
        return 2
    # Leave the EEPROM unlocked: the relock must happen at the NEW rate.
    bus.write_value(args.id, fam.baud_reg, n, relock=False)
    # The servo(s) changed rate: follow them and confirm.
    bus.bridge.set_baud(int(round(actual)))
    if broadcast:
        print("sent. Bus is now at ~%d baud; run `scan --bus-baud %d` to confirm"
              % (actual, int(round(actual))))
        return 0
    if bus.ping(args.id) is None:
        print("ID %d does not answer at %d baud (some servos apply a new baud only after "
              "a power cycle); try `scan --bus-baud %d`, then the old rate."
              % (args.id, actual, int(round(actual))))
        return 1
    bus.relock(args.id)
    print("ID %d now answers at %d baud" % (args.id, actual))


def _simple_write(name):
    def cmd(bus, args):
        reg = getattr(bus.family, name)
        if reg is None:
            print("%s is not supported for family %s" % (name.replace("_reg", ""), bus.family.name))
            return 2
        return 0 if _write_and_verify(bus, args.id, reg, 1 if args.state == "on" else 0) else 1
    return cmd


cmd_torque = _simple_write("torque_reg")
cmd_led = _simple_write("led_reg")


def cmd_move(bus, args):
    fam = bus.family
    if not 0 <= args.position <= fam.position_max:
        print("position must be 0..%d for family %s" % (fam.position_max, fam.name))
        return 2
    if args.speed is not None:
        bus.write_value(args.id, fam.speed_reg, args.speed)
    bus.write_value(args.id, fam.torque_reg, 1)
    return 0 if _write_and_verify(bus, args.id, fam.goal_reg, args.position) else 1


def cmd_factory_reset(bus, args):
    if not args.yes:
        print("factory reset clears all settings (ID and baud go back to defaults); "
              "add --yes to confirm")
        return 2
    bus.factory_reset(args.id)
    print("reset sent to ID %d" % args.id)


def cmd_pinscan(bus, args):
    rows = diagnose.pin_scan(bus.bridge, args.tx_en, args.rx_en)
    print(diagnose.summarize(rows, args.tx_en, args.rx_en))


def cmd_raw(bus, args):
    packet = bytes(int(x, 16) for x in args.hex)
    status, reply = bus.bridge.xfer(packet, reply_timeout_ms=args.timeout_ms,
                                    no_reply=args.no_reply)
    print("status: %s" % p.STATUS_NAMES.get(status, status))
    print("reply : %s" % (" ".join("%02x" % b for b in reply) or "(none)"))


def build_parser():
    ap = argparse.ArgumentParser(prog="axbridge", description=__doc__.split("\n")[0])
    ap.add_argument("--port", help="Wixel serial device (default: auto-detect)")
    ap.add_argument("--bus-baud", type=int, default=1000000,
                    help="servo bus baud rate the Wixel should use (default 1000000)")
    ap.add_argument("--family", choices=sorted(FAMILIES), default="ax",
                    help="servo family: ax (Dynamixel AX-12) or sts (Feetech STS3215/3235); "
                         "selects the register table (default ax)")
    ap.add_argument("--no-echo", action="store_true",
                    help="don't discard echoed bytes (the buffer's RX side is always on, "
                         "so echo skipping is normally wanted)")
    sub = ap.add_subparsers(dest="command", required=True)

    def add(name, fn, help_):
        sp = sub.add_parser(name, help=help_)
        sp.set_defaults(func=fn)
        return sp

    add("info", cmd_info, "show Wixel firmware info")
    sp = add("pinscan", cmd_pinscan, "probe the buffer wiring using the Wixel's own pins")
    sp.add_argument("--tx-en", type=parse_int, default=5, help="P1 bit of the TX enable (default 5)")
    sp.add_argument("--rx-en", type=parse_int, default=1, help="P1 bit of the RX enable (default 1)")
    sp = add("dir", cmd_dir, "force the tri-state buffer direction (wiring test)")
    sp.add_argument("mode", choices=["rx", "tx", "idle"])
    sp = add("ping", cmd_ping, "ping one servo")
    sp.add_argument("id", type=parse_int)
    sp = add("scan", cmd_scan, "ping a range of IDs")
    sp.add_argument("--first", type=parse_int, default=1)
    sp.add_argument("--last", type=parse_int, default=253)
    sp = add("identify", cmd_identify, "hint which servo family an ID belongs to")
    sp.add_argument("id", type=parse_int)
    sp = add("dump", cmd_dump, "read the whole control table")
    sp.add_argument("id", type=parse_int)
    sp = add("read", cmd_read, "read a register")
    sp.add_argument("id", type=parse_int)
    sp.add_argument("register", help="register name or number")
    sp.add_argument("--count", type=parse_int, help="bytes to read (default: register size)")
    sp = add("write", cmd_write, "write a register and read it back")
    sp.add_argument("id", type=parse_int)
    sp.add_argument("register", help="register name or number")
    sp.add_argument("value", type=parse_int)
    sp.add_argument("--force", action="store_true", help="allow read-only/forbidden writes")
    sp = add("id", cmd_id, "change a servo's ID")
    sp.add_argument("old", type=parse_int)
    sp.add_argument("new", type=parse_int)
    sp = add("baud", cmd_baud, "set a servo's baud rate, then follow it")
    sp.add_argument("id", type=parse_int, help="servo ID, or 254 for every servo (needs --yes)")
    grp = sp.add_mutually_exclusive_group(required=True)
    grp.add_argument("--bps", type=parse_int)
    grp.add_argument("--reg", type=parse_int,
                     help="baud code (AX: 1 = 1 Mbaud, 3 = 500k; STS: 0 = 1 Mbaud, 1 = 500k)")
    sp.add_argument("--yes", action="store_true")
    sp = add("torque", cmd_torque, "torque on/off")
    sp.add_argument("id", type=parse_int)
    sp.add_argument("state", choices=["on", "off"])
    sp = add("led", cmd_led, "LED on/off (AX only)")
    sp.add_argument("id", type=parse_int)
    sp.add_argument("state", choices=["on", "off"])
    sp = add("move", cmd_move, "enable torque and move to a position")
    sp.add_argument("id", type=parse_int)
    sp.add_argument("position", type=parse_int, help="AX 0..1023 (512 centre); STS 0..4095 (2048 centre)")
    sp.add_argument("--speed", type=parse_int, help="speed register value (0 = max)")
    sp = add("factory-reset", cmd_factory_reset, "restore a servo's defaults")
    sp.add_argument("id", type=parse_int)
    sp.add_argument("--yes", action="store_true")
    sp = add("raw", cmd_raw, "send raw bytes (hex) to the bus and show the reply")
    sp.add_argument("hex", nargs="+")
    sp.add_argument("--timeout-ms", type=parse_int, default=10)
    sp.add_argument("--no-reply", action="store_true")
    return ap


def run(args, bridge):
    """Dispatch a parsed command against `bridge` (split out for testing)."""
    if args.command not in ("info", "dir", "pinscan"):
        bridge.set_baud(args.bus_baud)
        bridge.set_options(echo=not args.no_echo)
    bus = dxl.Bus(bridge, family=FAMILIES[args.family])
    return args.func(bus, args) or 0


def main(argv=None):
    args = build_parser().parse_args(argv)
    try:
        with WixelBridge.open(args.port) as bridge:
            return run(args, bridge)
    except (BridgeError, dxl.NoReply) as e:
        print("error: %s" % e, file=sys.stderr)
        return 1


if __name__ == "__main__":
    sys.exit(main())
