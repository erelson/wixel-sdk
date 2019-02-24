README
===========

Most recently, a simple project for controlling a Dynamixel remotely from
a computer with a pair of Wixels was added.

:``python_remote_ax_control``:
    Set up this app on the Wixel connected to an AX12 servo via a TriState buffer.
    Set up the example wireless_serial app on the other wixel, and connect
    it to your computer.  Run `python send_bytes.py -h` to learn how to send
    instructions as part of a packet.

Code for various robots using the Wixel MCU from Pololu.

See the following within the ``apps`` folder:

*AX-12 version of Twitch*

:``twitch_ax``:
    Original Twitch's code; uses AX-12 servos

*Mech Warfare version of Twitch, with AX-12 servos*

:``twitch_mx_servo``:
    Mech warfare version of Twitch; code for the Wixel controlling MX-28T servos

:``twitch_mx_xbee``:
    Mech warfare version of Twitch; code for the Wixel interfaced with xBee and motor driver

*Hobby servo version of Twitch*

:``twitch_pwm``:
    Todo
    
Original Readme
================
See https://github.com/pololu/wixel-sdk

Pololu Wixel Software Development Kit (SDK)
--------------------------------------------


This package contains code and Makefiles that will help you create
your own applications for the Pololu Wixel.  The Wixel is a general-
purpose programmable module featuring a 2.4 GHz radio and USB.  The
Wixel is based on the CC2511F32 microcontroller from Texas Instruments,
which has an integrated radio transceiver, 32 KB of flash memory, 4 KB
of RAM, and a full-speed USB interface.

For documentation of this SDK, see:
http://pololu.github.com/wixel-sdk

(You can also generate the documentation yourself by running
Doxygen on libraries/Doxyfile.)

For more information about the Wixel, see the Wixel User's Guide:
http://www.pololu.com/docs/0J46
