
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "dynamixel.h"

volatile uint8 dynamixel_txpacket[DYNAMIXEL_PACKET_SIZE];
volatile uint8 dynamixel_rxpacket[DYNAMIXEL_PACKET_SIZE];
volatile uint8 dynamixel_rxindex = 0;

ISR(USART_RX_vect)
{
	dynamixel_rxpacket[dynamixel_rxindex++] = UDR0;
}

void dynamixel_init(void)
{
	// Set UART baudrate
	UBRR0H = ((F_CPU / 16 + DYNAMIXEL_BAUDRATE / 2) / DYNAMIXEL_BAUDRATE - 1) >> 8;
	UBRR0L = ((F_CPU / 16 + DYNAMIXEL_BAUDRATE / 2) / DYNAMIXEL_BAUDRATE - 1);
	
	// Enable UART TX, RX, and RX interrupt
	UCSR0B |= (1 << TXEN0);
	UCSR0B |= (1 << RXEN0);
	UCSR0B |= (1 << RXCIE0);
	
	// Set UART direction pins as outputs
	DDRD |= (1 << PD2);
	DDRD |= (1 << PD3);
	
	// Reset rx index
	dynamixel_rxindex = 0;
}

void dynamixel_settx(void)
{
	// Set UART direction pins
	PORTD |= (1 << PD2);
	PORTD &= ~(1 << PD3);
	
	//UCSR0B |= (1 << TXEN0);
	//UCSR0B &= ~(1 << RXEN0);
	//UCSR0B &= ~(1 << RXCIE0);
}

void dynamixel_setrx(void)
{
	// Wait for TX complete flag before turning the bus around
	while(bit_is_clear(UCSR0A, TXC0));
	
	_delay_us(1);
	
	// Set UART direction pins
	PORTD &= ~(1 << PD2);
	PORTD |= (1 << PD3);
	
	//UCSR0B &= ~(1 << TXEN0);
	//UCSR0B |= (1 << RXEN0);
	//UCSR0B |= (1 << RXCIE0);
	
	// Reset rx index
	dynamixel_rxindex = 0;
}

void dynamixel_write(uint8 c)
{
	while(bit_is_clear(UCSR0A, UDRE0));
	UDR0 = c;
}

uint8 dynamixel_calculatechecksum(volatile uint8* packet)
{
	uint16 checksum = 0;
	
	for(uint8 i = DYNAMIXEL_ID; i <= (packet[DYNAMIXEL_LENGTH] + 2); i++)
		checksum += packet[i];
	
	return ~(checksum % 256);
}

uint8 dynamixel_writepacket(volatile uint8* txpacket, uint8 packetlength)
{	
	for(uint8 i = 0; i < packetlength; i++)
		dynamixel_write(txpacket[i]);
	
	return DYNAMIXEL_SUCCESS;
}

uint8 dynamixel_readpacket(volatile uint8* rxpacket, uint8 packetlength)
{
	uint16 ulcounter = 0;

	while(dynamixel_rxindex < packetlength)
	{
		if(ulcounter++ > 10000)
			return DYNAMIXEL_RX_TIMEOUT;
	}

	if((rxpacket[0] != 255) || (rxpacket[1] != 255))
		return DYNAMIXEL_RX_CORRUPT;
		
	if(rxpacket[packetlength - 1] != dynamixel_calculatechecksum(rxpacket))
		return DYNAMIXEL_RX_CORRUPT;

	return DYNAMIXEL_SUCCESS;
}

uint8 dynamixel_txrx(volatile uint8* txpacket, volatile uint8* rxpacket)
{
	uint8 rxlength = 0;
	uint8 txlength = dynamixel_txpacket[DYNAMIXEL_LENGTH] + 4;
	
	txpacket[0] = (uint8) 0xff;
	txpacket[1] = (uint8) 0xff;
	txpacket[txlength - 1] = (uint8) dynamixel_calculatechecksum(txpacket);
	
	dynamixel_settx();
	dynamixel_writepacket(txpacket, txlength);
	dynamixel_setrx();
	
	if(txpacket[DYNAMIXEL_ID] != DYNAMIXEL_BROADCAST_ID)
	{	
		if(txpacket[DYNAMIXEL_INSTRUCTION] == DYNAMIXEL_READ)
			rxlength = txpacket[DYNAMIXEL_PARAMETER + 1] + 6;
		else
			rxlength = 6;
			
		return dynamixel_readpacket(rxpacket, rxlength);			
	}
	
	dynamixel_settx();
		
	return DYNAMIXEL_SUCCESS;
}

uint8 dynamixel_ping(uint8 id)
{	
	dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
	dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 2;
	dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_PING;
	
	return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
}

uint8 dynamixel_readbyte(uint8 id, uint8 address, uint8* value)
{
	uint8 result;
	
	dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
	dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 4;
	dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_READ;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) 1;
	
	result = dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
	
	if(result == DYNAMIXEL_SUCCESS)
		*value = dynamixel_rxpacket[DYNAMIXEL_PARAMETER];
	
	return result;
}

uint8 dynamixel_readword(uint8 id, uint8 address, uint16* value)
{
	uint8 result;
	
	dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
	dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 4;
	dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_READ;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) 2;
	
	result = dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
	
	if(result == DYNAMIXEL_SUCCESS)
		*value = (uint16) dynamixel_makeword(dynamixel_rxpacket[DYNAMIXEL_PARAMETER], dynamixel_rxpacket[DYNAMIXEL_PARAMETER+1]);
	
	return result;
}

uint8 dynamixel_readtable(uint8 id, uint8 start_address, uint8 end_address, uint8* table)
{
	uint8 result;
	uint8 length = end_address - start_address + 1;
	
	dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
	dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 4;
	dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_READ;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) start_address;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) length;
	
	result = dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
	
	if(result == DYNAMIXEL_SUCCESS)
	{
		for(uint8 i = 0; i < length; i++)
			table[start_address + i] = dynamixel_rxpacket[DYNAMIXEL_PARAMETER + i];
	}
	
	return result;
}

uint8 dynamixel_writebyte(uint8 id, uint8 address, uint8 value)
{	
	dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
	dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 4;
	dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_WRITE;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) value;
	
	return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
}

uint8 dynamixel_writeword(uint8 id, uint8 address, uint16 value)
{	
	dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
	dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 5;
	dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_WRITE;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) dynamixel_getlowbyte(value);
	dynamixel_txpacket[DYNAMIXEL_PARAMETER+2] = (uint8) dynamixel_gethighbyte(value);
	
	return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
}

uint8 dynamixel_syncwrite(uint8 address, uint8 length, uint8 number, uint8* param)
{	
	dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) DYNAMIXEL_BROADCAST_ID;
	dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_SYNC_WRITE;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
	dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) length;
	dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) ((length + 1) * number + 4);
	
	for(uint8 i = 0; i < ((length + 1) * number); i++)
		dynamixel_txpacket[DYNAMIXEL_PARAMETER + 2 + i] = (uint8) param[i];
	
	return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
}

uint8 dynamixel_reset(uint8 id)
{
	dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
	dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 2;
	dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_RESET;
	
	return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
}

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
