#! /usr/bin/env python

from argparse import ArgumentParser
from serial import Serial, SerialException, SerialTimeoutException
from time import sleep


PORT_DEFAULT = "COM1"
BAUD_DEFAULT = 38400


def byte_from_int(val):
    val = int(val)
    if not (0 <= val <= 254):
        raise ValueError("Only values from 0 to 254 are accepted")
    print(val)
    return val

def make_packet(bytelist):
    #plen = len(bytelist)
    packet = [0xff, 0xff]

    checksum = (255 - sum(bytelist)) % 256
    packet.extend(bytelist)
    packet.append(checksum)
    return bytearray(packet)

def main(args):
    ser = Serial(port=args.port, baudrate=args.baud)
    #with ser.open():
    #ser.write(bytearray([args.data1, args.data2]))
    packet = make_packet([args.data1, args.data2])
    ser.write(packet)
    print(map(int, packet))
    #for item in packet:
    #    print(item)
    #    ser.write([item])
    #    sleep(1)
    ser.close()


if __name__ == "__main__":
    parser = ArgumentParser()

    parser.add_argument("data1", type=byte_from_int, 
                        help="First value to send; typically an integer from 0 to 254.")
    parser.add_argument("data2", type=byte_from_int,
                        help="Second value to send; typically an integer from 0 to 254.")
    parser.add_argument("-p", "--port", type=str, default=PORT_DEFAULT,
                        help="Name of serial port to use. E.g. COM1, /dev/tty/ser1. Default: %(default)s")
    parser.add_argument("-b", "--baud", type=int, default=BAUD_DEFAULT,
                        help="Baud rate to send bytes at. Default: %(default)s")

    args = parser.parse_args()

    main(args)
