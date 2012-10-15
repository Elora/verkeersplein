#include <avr/io.h>
#include <stdlib.h>
#include "Serial.h"

Serial::Serial() : baud(51)
{

}

void Serial::init() {
	UCSR0A=0x00;  
	UCSR0B=(1 << TXEN1)|(1 << RXEN1);
	UCSR0C=(1 << UCSZ11) | (1 << UCSZ10);
	UBRR0L=(baud);
	UBRR0H=(baud >> 8);
}

void Serial::schrijf_serial(uint8_t d)
{

	while(~UCSR0A & 1<<UDRE);
	UDR0=d;

}

uint8_t Serial::lees_serial(uint8_t* p)
{
	if(~UCSR0A & 1<< RXC)
		return 1;
	if(UCSR0A & (1<<FE |1<<DOR))
		return -1;
	*p=UDR0;
	return 0;
}

void Serial::writeChar(char ch)

{
	schrijf_serial(ch);


}

void Serial::writeString(char *string)

{

	while(*string)

		writeChar(*string++);

}


void Serial::writeInteger(int16_t number, uint8_t base)

{

	char buffer[17];

	itoa(number, &buffer[0], base);

	writeString(&buffer[0]);

}

