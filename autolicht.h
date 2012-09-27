#include "voetgangerlicht.h"

#ifndef AUTOLICHT
#define AUTOLICHT

class AutoLicht: public VoetgangerLicht
{
	public: 
		AutoLicht(uint8_t rood, uint8_t oranje, uint8_t groen, uint8_t poort); //constructor
		void lichtNaarOranje();
		virtual void vanGroenNaarRood(int);
		virtual void alleLichtenUit();
	
	private:
		uint8_t oranje;
		
};

#endif
