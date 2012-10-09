#ifndef SERIAL_H_
#define SERIAL_H_

#define BAUD 51

class Serial {
	public:
		Serial();
		void init();
		void writeChar(char);
		void writeString(char *string);
		void writeInteger(int16_t, uint8_t);
		uint8_t lees_serial(uint8_t*);
		void schrijf_serial(uint8_t d);
};

#endif
