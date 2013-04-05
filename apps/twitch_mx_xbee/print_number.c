#include "print_number.h"

uint8 print_number2bytes(uint16 i){
	uint8 cnt = 7;
	
	uint8 j[] = {32,32,32,32,32,32,32,32};
	
	while (i>0){
		j[cnt] = (i%10) + 48;
		i = i/10;
		cnt -= 1;
	}
	
	uart0TxSendByte(j[2]);
	uart0TxSendByte(j[3]);
	uart0TxSendByte(j[4]);
	uart0TxSendByte(j[5]);
	uart0TxSendByte(j[6]);
	uart0TxSendByte(j[7]);
	
	return cnt;
}