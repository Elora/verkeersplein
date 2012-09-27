#include "sensor.h"

Sensor::Sensor(uint8_t poort, uint8_t adres): poort(poort), adres(adres) { //constructor

}

bool Sensor::isGeactiveert() {
	if((_SFR_IO8(poort) | adres) == adres) 	//checken of de de sensor op dit moment wordt geactiveerd
		return true;						//Zo ja, return true
	else	
		return false;						//Zo nee, return false
}

void Sensor::kenScenarioToe(Scenario* s) {	//Ken scenario toe aan sensor
	scenario = s;
}
