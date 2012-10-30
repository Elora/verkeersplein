#include <avr/io.h>
#include <stdlib.h>
#include "Serial.h"

Serial::Serial() : baud(51)
{

}

void Serial::init() {
	UCSR1A=0x00;  
	UCSR1B=(1 << TXEN1)|(1 << RXEN1);
	UCSR1C=(1 << UCSZ11) | (1 << UCSZ10);
	UBRR1L=(baud);
	UBRR1H=(baud >> 8);
}

void Serial::schrijf_serial(uint8_t d)
{

	while(~UCSR1A & 1<<UDRE);
	UDR1=d;

}

uint8_t Serial::lees_serial(uint8_t* p)
{
	if(~UCSR1A & 1<< RXC)
		return 1;
	if(UCSR1A & (1<<FE |1<<DOR))
		return -1;
	*p=UDR1;
	return 0;
}

void Serial::stuurSuccesCode(){
	schrijf_serial(255);
}

