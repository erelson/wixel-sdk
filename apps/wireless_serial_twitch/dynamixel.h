
#ifndef _DYNAMIXEL_H_
#define _DYNAMIXEL_H_

#include <avr/io.h>

#define DYNAMIXEL_BAUDRATE 1000000

#define DYNAMIXEL_OK      1
#define DYNAMIXEL_TIMEOUT 2

#define DYNAMIXEL_ID           2
#define DYNAMIXEL_LENGTH       3
#define DYNAMIXEL_INSTRUCTION  4
#define DYNAMIXEL_ERROR        4
#define DYNAMIXEL_PARAMETER    5

#define DYNAMIXEL_BROADCAST_ID  254
#define DYNAMIXEL_PACKET_SIZE   128

#define DYNAMIXEL_PING        1
#define DYNAMIXEL_READ        2
#define DYNAMIXEL_WRITE       3
#define DYNAMIXEL_REG_WRITE   4
#define DYNAMIXEL_ACTION      5
#define DYNAMIXEL_RESET       6
#define DYNAMIXEL_SYNC_WRITE  131

#define DYNAMIXEL_SUCCESS     1
#define DYNAMIXEL_RX_CORRUPT  2
#define DYNAMIXEL_RX_TIMEOUT  3
#define DYNAMIXEL_TX_FAIL     4
#define DYNAMIXEL_TX_TIMEOUT  5

void dynamixel_init(void);
void dynamixel_settx(void);
void dynamixel_setrx(void);
void dynamixel_write(uint8 c);

uint8 dynamixel_calculatechecksum(volatile uint8* packet);
uint8 dynamixel_writepacket(volatile uint8* packet, uint8 legnth);
uint8 dynamixel_readpacket(volatile uint8* packet, uint8 legnth);
uint8 dynamixel_txrx(volatile uint8* txpacket, volatile uint8* rxpacket);

uint8 dynamixel_ping(uint8 id);
uint8 dynamixel_readbyte(uint8 id, uint8 address, uint8* value);
uint8 dynamixel_readword(uint8 id, uint8 address, uint16* value);
uint8 dynamixel_readtable(uint8 id, uint8 start_address, uint8 end_address, uint8* table);
uint8 dynamixel_writebyte(uint8 id, uint8 address, uint8 value);
uint8 dynamixel_writeword(uint8 id, uint8 address, uint16 value);
uint8 dynamixel_syncwrite(uint8 address, uint8 legnth, uint8 number, uint8* param);
uint8 dynamixel_reset(uint8 id);

uint16 dynamixel_makeword(uint8 lowbyte, uint8 highbyte);
uint8 dynamixel_getlowbyte(uint16 word);
uint8 dynamixel_gethighbyte(uint16 word);

#endif
