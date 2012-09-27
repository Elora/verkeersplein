#include <avr/io.h>

#ifndef VOETGANGERLICHT
#define VOETGANGERLICHT

class VoetgangerLicht
{
	public: 
		VoetgangerLicht(uint8_t rood, uint8_t groen, uint8_t poort); //constructor
		void lichtNaarRood();
		void lichtNaarGroen();
		virtual void vanGroenNaarRood(int);
		virtual void alleLichtenUit();

		//operator overload
		bool operator ==(VoetgangerLicht &rhs);

		//getters en setters
		uint8_t krijgRood() const;
		uint8_t krijgGroen() const;
		uint8_t krijgPoort() const;
	
	protected:
		uint8_t poort;
		uint8_t rood;
		uint8_t groen;
		
	private:
		
		
};

#endif
