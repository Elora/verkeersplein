#include "voetgangerlicht.h"

VoetgangerLicht::VoetgangerLicht(uint8_t rood, uint8_t groen, uint8_t poort):rood(rood), groen(groen), poort(poort) {	
}

void VoetgangerLicht::lichtNaarRood() {
	alleLichtenUit(); // Eerst worden de lichten die nu aanstaan uitgezet
	uint8_t temp = rood; 
	_SFR_IO8(poort) &= temp; //Daarna wordt het rode licht aangezet
}

void VoetgangerLicht::lichtNaarGroen() {
	alleLichtenUit(); // Eerst worden de lichten die nu aanstaan uitgezet
	uint8_t temp = groen;
	_SFR_IO8(poort) &= temp;  //Daarna wordt het groene licht aangezet
}

void VoetgangerLicht::alleLichtenUit() {
	uint8_t temp = ~(groen & rood); //Zorgt ervoor dat alleen de pinnetjes behorend bij groen en rood weer 1 worden
	_SFR_IO8(poort) |= temp;		//De rest van de pinnetjes van de poort wordt niet aangepast
}

//Hier overloaden wij de 'is gelijk aan' operator om dezelfde lichten
// te detecteren
bool VoetgangerLicht::operator ==(VoetgangerLicht &rhs){
	if((*this).krijgRood() == rhs.krijgRood() &&
	   (*this).krijgGroen() == rhs.krijgGroen() &&
	   (*this).krijgPoort() == rhs.krijgPoort())
		return true;
	return false;
}


//Getters en Setters
uint8_t VoetgangerLicht::krijgRood() const {
	return rood;
}

uint8_t VoetgangerLicht::krijgGroen() const {
	return groen;
}

uint8_t VoetgangerLicht::krijgPoort() const {
	return poort;
}
