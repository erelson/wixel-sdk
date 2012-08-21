// This library is adapted for the Wixel microcontroller.
// The Wixel uses the TI CC2511F32 chip ( @ 24 MHz)
// This library is adapted from RyanLowerr's work for AVRs on github.  Check his stuff out!

#include "dynamixel.h"
#include <malloc.h>		// Using this for arrays... wtf.
#include <wixel.h>
#include <uart1.h>

volatile uint8 *dynamixel_txpacket; // Trying this...
volatile uint8 *dynamixel_rxpacket; // Trying this...
// volatile uint8 dynamixel_txpacket[DYNAMIXEL_PACKET_SIZE];
// volatile uint8 dynamixel_rxpacket[DYNAMIXEL_PACKET_SIZE];
volatile uint8 dynamixel_rxindex = 0;

// Interrupts;
// Relevant equivalent code for the TI chip is probably in libraries/include/cc2511_map.h
// --------
// //handler declaration
// // The vector name (USART_RXC_vect in this case)
// // will vary from part to part, based on the
// // name given to that vector in your part's
// // datasheet. 
// ISR(USART_RX_vect)
// {
	// //What we do if the interrupt is triggered ...
	// dynamixel_rxpacket[dynamixel_rxindex++] = UDR0;
// }

void dynamixel_init(void)
{
	//This should all be largely unneccsary since we initialize the UART elsewhere.
	
	// // Set UART baudrate
	// UBRR0H = ((F_CPU / 16 + DYNAMIXEL_BAUDRATE / 2) / DYNAMIXEL_BAUDRATE - 1) >> 8;
	// UBRR0L = ((F_CPU / 16 + DYNAMIXEL_BAUDRATE / 2) / DYNAMIXEL_BAUDRATE - 1);
	
	// // Enable UART TX, RX, and RX interrupt
	// UCSR0B |= (1 << TXEN0);
	// UCSR0B |= (1 << RXEN0);
	// UCSR0B |= (1 << RXCIE0);
	
	// // Set UART direction pins as outputs
	// DDRD |= (1 << PD2);
	// DDRD |= (1 << PD3);
	
	// Reset rx index
	dynamixel_rxindex = 0;
	
	// No clue why I have to do this to allocate global arrays in SDCC...
	dynamixel_txpacket = malloc(sizeof(uint8)*DYNAMIXEL_PACKET_SIZE);
	dynamixel_rxpacket = malloc(sizeof(uint8)*DYNAMIXEL_PACKET_SIZE);
	
}

void dynamixel_settx(void)
{
	// // Set UART direction pins
	// PORTD |= (1 << PD2);
	// PORTD &= ~(1 << PD3);
	
	delayMicroseconds(10);
	P1DIR &= ~0x02; //Disable pin P1_1
	P1DIR |= 0x20; //Enable pin P1_5
	
	//  // These were commented out in the original code.
	// //UCSR0B |= (1 << TXEN0);
	// //UCSR0B &= ~(1 << RXEN0);
	// //UCSR0B &= ~(1 << RXCIE0);
}

void dynamixel_setrx(void)
{
	// // Wait for TX complete flag before turning the bus around
	// // Note: bit_is_clear( port, bit );  	Returns something != 0, if bit 'bit' in 'port' is clear, otherwise 0. Macro.
	// while(bit_is_clear(UCSR0A, TXC0));
	// // Not apparent what the SDCC equivalent is.
	
	// _delay_us(1);
	delayMicroseconds(10);
	
	// // Set UART direction pins
	// PORTD &= ~(1 << PD2);
	// PORTD |= (1 << PD3);
	// TI chip's version?
	// Based on: #define LED_RED(v)          {((v) ? (P2DIR |= 0x02) : (P2DIR &= ~0x02));}
	//which says: if v, then PSDIR |= 0x02; else PSDIR &= ~0x02
	//               note |= means binary or... if a bit is already high, it stays high. only bit 2 is toggled.
	
	P1DIR &= ~0x20; //Disable pin P1_5
	P1DIR |= 0x02; //Enable pin P1_1
	
	//  // These were commented out in the original code.
	// //UCSR0B &= ~(1 << TXEN0);
	// //UCSR0B |= (1 << RXEN0);
	// //UCSR0B |= (1 << RXCIE0);
	
	// Reset rx index
	dynamixel_rxindex = 0;
}

void dynamixel_write(uint8 c)
// Sends byte c out the TX pin.
{
	// // Note: bit_is_clear( port, bit );  	Returns something != 0, if bit 'bit' in 'port' is clear, otherwise 0. Macro.
	// while(bit_is_clear(UCSR0A, UDRE0));
	// UDR0 = c;
	
	//Derived from uartToRadioService() in wireless_serial.c
	// Should accomplish what the original AVR-specific code above did.
    // while(uart1TxAvailable())
    // {
        // uart1TxSendByte(c);
    // }
	
	//But I didn't like the above... so
	uart1TxSendByte(c);
}

uint8 dynamixel_calculatechecksum(volatile uint8* packet)
// Calculate the checksum that ends every dynamixel packet.
{
	uint16 checksum = 0;
	uint8 i=0; //Seems SDCC doesn't like definition within the for statement.
	for(i = DYNAMIXEL_ID; i <= (packet[DYNAMIXEL_LENGTH] + 2); i++)
		checksum += packet[i];
	
	return ~(checksum % 256);
}

uint8 dynamixel_writepacket(volatile uint8* txpacket, uint8 packetlength)
{	
	uint8 i = 0;
	for(i = 0; i < packetlength; i++)
		dynamixel_write(txpacket[i]);
	
	return DYNAMIXEL_SUCCESS;
}

uint8 dynamixel_readpacket(volatile uint8* rxpacket, uint8 packetlength)
{
	uint16 ulcounter = 0; // ul = ??

	while(dynamixel_rxindex < packetlength) // wait for a full packet?
										// should this be based on checking rx buffer instead?
	{
		if(ulcounter++ > 10000)
			return DYNAMIXEL_RX_TIMEOUT;
	}

	// ?????? when does rxpacket get filled?
	
	if((rxpacket[0] != 255) || (rxpacket[1] != 255))
		return DYNAMIXEL_RX_CORRUPT;
		
	if(rxpacket[packetlength - 1] != dynamixel_calculatechecksum(rxpacket))
		return DYNAMIXEL_RX_CORRUPT;

	return DYNAMIXEL_SUCCESS;
}

uint8 dynamixel_txrx(volatile uint8* txpacket, volatile uint8* rxpacket)
{
	/* Function ...
	1: Calcs tx packet checksum
	2: sets tx mode
	3: writes tx packet
	4: sets rx mode
	5: determine rx packet length
	6: read rx packet
	7: set tx mode	
	*/
	
	uint8 rxlength = 0;
	uint8 txlength = dynamixel_txpacket[DYNAMIXEL_LENGTH] + 4; // 0xff,0xff, ID, packet, checksum ?
	
	txpacket[0] = (uint8) 0xff;
	txpacket[1] = (uint8) 0xff;
	txpacket[txlength - 1] = (uint8) dynamixel_calculatechecksum(txpacket);
	
	dynamixel_settx();
	dynamixel_writepacket(txpacket, txlength);
	dynamixel_setrx();
	
	// If talking to a specific servo,...
	if(txpacket[DYNAMIXEL_ID] != DYNAMIXEL_BROADCAST_ID)
	{	
		// and if TX packet was a read request
		if(txpacket[DYNAMIXEL_INSTRUCTION] == DYNAMIXEL_READ)
			//Read back whatever the servos says in return...
			rxlength = txpacket[DYNAMIXEL_PARAMETER + 1] + 6;
		else
			rxlength = 6; // Default answer packet length? for DYNAMIXEL_WRITE?
			
		return dynamixel_readpacket(rxpacket, rxlength);			
	}
	
	dynamixel_settx();
		
	return DYNAMIXEL_SUCCESS;
}

/// RECEIVE STUFF

// uint8 dynamixel_ping(uint8 id)
// {	
	// dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
	// dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 2;
	// dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_PING;
	
	// return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
// }

// uint8 dynamixel_readbyte(uint8 id, uint8 address, uint8* value)
// {
	// uint8 result;
	
	// dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
	// dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 4;
	// dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_READ;
	// dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
	// dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) 1;
	
	// result = dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
	
	// if(result == DYNAMIXEL_SUCCESS)
		// *value = dynamixel_rxpacket[DYNAMIXEL_PARAMETER];
	
	// return result;
// }

// uint8 dynamixel_readword(uint8 id, uint8 address, uint16* value)
// {
	// uint8 result;
	
	// dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
	// dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 4;
	// dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_READ;
	// dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
	// dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) 2;
	
	// result = dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
	
	// if(result == DYNAMIXEL_SUCCESS)
		// *value = (uint16) dynamixel_makeword(dynamixel_rxpacket[DYNAMIXEL_PARAMETER], dynamixel_rxpacket[DYNAMIXEL_PARAMETER+1]);
	
	// return result;
// }

// uint8 dynamixel_readtable(uint8 id, uint8 start_address, uint8 end_address, uint8* table)
// {
	// uint8 result;
	// uint8 length = end_address - start_address + 1;
	
	// dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
	// dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 4;
	// dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_READ;
	// dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) start_address;
	// dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) length;
	
	// result = dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
	
	// if(result == DYNAMIXEL_SUCCESS)
	// {
		// uint8 i = 0;
		// for(i = 0; i < length; i++)
			// table[start_address + i] = dynamixel_rxpacket[DYNAMIXEL_PARAMETER + i];
	// }
	
	// return result;
// }

/// TRANSMIT STUFF
// uint8 dynamixel_writebyte(uint8 id, uint8 address, uint8 value)
// {	//Call this method to setup writing a 8bit value
	// dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
	// dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 4;
	// dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_WRITE;
	// dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
	// dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) value;
	
	// return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
// }

uint8 dynamixel_writeword(uint8 id, uint8 address, uint16 value)
{	//Call this method to setup writing a 16bit value
	dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
	dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 5;
	dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_WRITE;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) dynamixel_getlowbyte(value);
	dynamixel_txpacket[DYNAMIXEL_PARAMETER+2] = (uint8) dynamixel_gethighbyte(value);
	
	return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
}

uint8 dynamixel_syncwrite(uint8 address, uint8 length, uint8 number, uint8* param)
{	//Call this method to ????
	uint8 i;
	
	dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) DYNAMIXEL_BROADCAST_ID;
	dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_SYNC_WRITE;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) length; // The length of the packet where its value is “Number of parameters (N) +2”
	dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) ((length + 1) * number + 4);

	for(i = 0; i < ((length + 1) * number); i++){
		dynamixel_txpacket[DYNAMIXEL_PARAMETER + 2 + i] = (uint8) param[i];
	}
	return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
}

// uint8 dynamixel_reset(uint8 id)
// {
	// dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
	// dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 2;
	// dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_RESET;
	
	// return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
// }

uint16 dynamixel_makeword(uint8 lowbyte, uint8 highbyte)
{
	return ((highbyte << 8) + lowbyte);
}

uint8 dynamixel_getlowbyte(uint16 word)
{
	return (word & 0xff);
}

uint8 dynamixel_gethighbyte(uint16 word)
{
	return ((word & 0xff00) >> 8);
}
