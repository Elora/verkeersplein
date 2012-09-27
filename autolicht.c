#include "autolicht.h"

AutoLicht::AutoLicht(uint8_t rood, uint8_t oranje, uint8_t groen, uint8_t poort):VoetgangerLicht(rood, groen, poort), oranje(oranje) {
}

void AutoLicht::lichtNaarOranje(){
	alleLichtenUit(); // Eerst worden de lichten die nu aanstaan uitgezet
	uint8_t temp = oranje; // Daarna wordt het oranje licht aangezet
	_SFR_IO8(poort) &= temp; 
}

void AutoLicht::vanGroenNaarRood(int a){
	lichtNaarOranje();
}

void AutoLicht::alleLichtenUit() {
	uint8_t temp = ~(groen & oranje & rood); //Zorgt ervoor dat alleen de pinnetjes behorend bij groen, oranje en rood weer 1 worden
	_SFR_IO8(poort) |= temp;		//De rest van de pinnetjes van de poort wordt niet aangepast
}
