"""Wiring diagnosis for the tri-state buffer, using the Wixel's own pins.

pin_scan() drives the buffer enable pins and the UART TX pin as plain GPIO in
every combination and records what the RX pin reads. From the table you can see
whether RX follows TX (an echo path) and under which enable states.

Enable pin states: Z = input (released; the board's pull-up decides), L = driven
low, H = driven high. TX level is what we drive on the UART TX pin (as GPIO).
"""
from . import protocol as p

TX_PIN, RX_PIN = 6, 7      # P1_6 UART TX, P1_7 UART RX (fixed by the hardware)
STATES = {"Z": (0, 0), "L": (1, 0), "H": (1, 1)}   # name -> (dir, latch)


def _apply(bridge, tx_en, rx_en, txen_state, rxen_state, tx_level):
    bits = [(tx_en, txen_state), (rx_en, rxen_state)]
    mask = (1 << TX_PIN) | (1 << tx_en) | (1 << rx_en)
    dir_val = (1 << TX_PIN)                 # we drive the TX pin as GPIO
    latch_val = (tx_level << TX_PIN)
    for bit, state in bits:
        d, l = STATES[state]
        dir_val |= d << bit
        latch_val |= l << bit
    pins, _, _ = bridge.p1_access(sel_mask=1 << TX_PIN, sel_val=0,
                                  dir_mask=mask, dir_val=dir_val,
                                  latch_mask=mask, latch_val=latch_val)
    return (pins >> RX_PIN) & 1


def pin_scan(bridge, tx_en=5, rx_en=1):
    """Returns rows of (txen_state, rxen_state, tx_level, rx_pin_reading)."""
    rows = []
    try:
        for txs in "ZLH":
            for rxs in "ZLH":
                for level in (1, 0):
                    rows.append((txs, rxs, level,
                                 _apply(bridge, tx_en, rx_en, txs, rxs, level)))
    finally:
        # Give the pin back to the UART and rest the bus in RX mode.
        bridge.p1_access(sel_mask=1 << TX_PIN, sel_val=1 << TX_PIN)
        bridge.set_direction(p.DIR_RX)
    return rows


def follows(rows):
    """{(txen, rxen): True/False}: does RX read what TX drives, both levels?"""
    out = {}
    for txs in "ZLH":
        for rxs in "ZLH":
            r = {lvl: rx for (t, x, lvl, rx) in rows if (t, x) == (txs, rxs)}
            out[(txs, rxs)] = (r[1] == 1 and r[0] == 0)
    return out


def summarize(rows, tx_en=5, rx_en=1):
    """Human-readable table plus plain-language observations."""
    f = follows(rows)
    lines = ["RX pin (P1_7) as read while P1_6 is driven high / low,",
             "for each state of TX-enable (P1_%d) and RX-enable (P1_%d):" % (tx_en, rx_en),
             "",
             "  TXEN RXEN | TX=1 TX=0 | RX follows TX?",
             "  ----------+-----------+----------------"]
    for txs in "ZLH":
        for rxs in "ZLH":
            r = {lvl: rx for (t, x, lvl, rx) in rows if (t, x) == (txs, rxs)}
            lines.append("   %s    %s   |  %d    %d   | %s"
                         % (txs, rxs, r[1], r[0], "yes" if f[(txs, rxs)] else "no"))
    lines.append("")
    yes = [k for k, v in f.items() if v]
    if len(yes) == len(f):
        lines.append("RX follows TX in EVERY enable state: the RX pin is wired to the "
                     "TX line (or to a bus the TX side always drives); the enables have "
                     "no effect on it. Use --echo.")
    elif not yes:
        lines.append("RX never follows TX in any enable state. Either the buffers do not "
                     "connect TX to RX through the bus (the TX side is not reaching the "
                     "bus, or the servo wire is not connected), or the enables are on "
                     "other pins. Try --tx-en/--rx-en with other P1 bits.")
    else:
        lines.append("RX follows TX only when (TXEN, RXEN) is one of: %s."
                     % ", ".join("%s/%s" % k for k in yes))
        if ("Z", "Z") not in yes:
            lines.append("Releasing both enables breaks the loop, so the buffers do "
                         "gate the path. The states above are the 'both enabled' ones.")
    return "\n".join(lines)
