#include <avr/io.h>

#ifndef VOETGANGERLICHT
#define VOETGANGERLICHT

class VoetgangerLicht
{
	public: 
		VoetgangerLicht(uint8_t rood, uint8_t groen, uint8_t poort); //constructor
		void lichtNaarRood();
		void lichtNaarGroen();
		virtual void alleLichtenUit();
		bool operator==(VoetgangerLicht &rhs);
		uint8_t getRood() const;
		uint8_t getGroen() const;
		uint8_t getPoort() const;
	
	protected:
		uint8_t poort;
		uint8_t rood;
		uint8_t groen;
		
	private:
		
		
};

#endif
