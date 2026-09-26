ax_bridge
=========

Wixel firmware that bridges USB to a half-duplex Dynamixel-protocol-1 servo bus
(AX-12, Feetech STS, ...) through a tri-state buffer, plus a Python library and
CLI for it. The firmware is deliberately thin (timing-critical bus turnaround
only); protocol knowledge lives on the host.

Protocol and pin details: header comment of ``ax_bridge.c``.

Build
-----

From the repository root::

    make ax_bridge AR="sdar -rcs"

``AR="sdar -rcs"`` is needed with SDCC 4.x: the Makefile's default archiver,
``sdcclib``, was removed from SDCC. (Tested with SDCC 4.2.0.) Output:
``apps/ax_bridge/ax_bridge.wxl``, about 6 KB of the 29 KB of flash.

Load it onto the Wixel with the Wixel Configuration Utility, or
``wixelcmd write apps/ax_bridge/ax_bridge.wxl``. ``param_baud_rate`` (default
1000000) sets the initial servo-bus baud rate and can be edited in the utility.

Wiring
------

* P1_6 TX / P1_7 RX (UART1) to the buffer's servo-wire data pins.
* P1_5 enables the TX side of the buffer, P1_1 the RX side. On the author's
  board both are **active-high** and a released pin is pulled high by the
  board (= enabled), so the firmware always drives them explicitly. Don't use
  the old ``dynamixel.c`` scheme of toggling ``P1DIR``: it leaves a side
  enabled when it thinks it is disabled. RX stays enabled at all times (a
  disabled RX buffer reads low), so the Wixel hears its own bytes and the
  firmware discards them by matching against what it sent.
* For a board with other polarity, change ``TX_EN_ACTIVE_HIGH`` /
  ``RX_EN_ACTIVE_HIGH`` in ``ax_bridge.c``.

Check the buffer wiring before trusting it with a servo::

    uv run axbridge pinscan    # probes both enable pins, prints what RX sees
    uv run axbridge dir tx     # TX side on (measure/scope the buffer)
    uv run axbridge dir rx     # TX side off (idle state)

Use
---

::

    cd python
    uv run axbridge scan               # find servos (default 1 Mbaud)
    uv run axbridge ping 52
    uv run axbridge dump 52            # whole control table
    uv run axbridge baud 52 --bps 500000
    uv run axbridge --help

Feetech STS servos
------------------

The firmware also supports the Feetech protocol/servos: framing is identical to Dynamixel
protocol 1. Select the register table with ``--family sts``::

    uv run axbridge --family sts ping 1
    uv run axbridge --family sts dump 1
    uv run axbridge --family sts write 1 max_temperature 80   # EEPROM: lock handled for you
    uv run axbridge --family sts id 1 7                       # relock goes to the NEW id
    uv run axbridge --family sts move 1 2048                  # 0..4095, 2048 = centre

* EEPROM registers (addresses below 40) are written inside an unlock/relock
  bracket on ``lock`` (55) automatically. ``torque_enable`` = 128 is refused:
  on Feetech it runs the centering function, not "torque on".
* STS baud codes (0 = 1 Mbaud, 1 = 500k, ...) come from Feetech's datasheet as
  recalled, not from the protocol manual in numa3; verify before changing a
  servo's baud. ``baud`` follows the servo to the new rate and reports if it
  goes silent (some servos only apply a new baud after a power cycle).
* AX and STS servos share the bus if their IDs don't collide. ``identify ID``
  gives a hint which family an ID belongs to.
* Check the servo's voltage rating and connector pin order (GND / power /
  data) before powering: Feetech's connector wiring differs from Dynamixel's.

Tests (no hardware needed; they run against a simulated Wixel)::

    cd python
    uv run python -m unittest discover -s tests -t .
