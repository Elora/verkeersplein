#include "sensor.h"

Sensor::Sensor(uint8_t pin, uint8_t adres): pin(pin), adres(adres) { //constructor

}

bool Sensor::isGeactiveert() {
	if((_SFR_IO8(pin) | adres) == adres) {	//checken of de de sensor op dit moment wordt geactiveerd
		_SFR_IO8(pin) |= ~adres;			//Zo ja, zet het bitje terug naar 1
		return true;						//En return true
	}										
	else	
		return false;						//Zo nee, return false
}

void Sensor::kenScenarioToe(Scenario* s) {	//Ken scenario toe aan sensor
	scenario = s;
}
