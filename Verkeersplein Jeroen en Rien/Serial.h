#ifndef SERIAL_H_
#define SERIAL_H_

#include <avr/io.h>

class Serial {
	public:
		Serial();
		void init();
		uint8_t lees_serial(uint8_t*);
		void schrijf_serial(uint8_t d);
		void stuurSuccesCode();
		void stuurErrorCode(int, int);

	private:
		int baud;
};

#endif
