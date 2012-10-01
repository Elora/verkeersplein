#ifndef SENSOR_H
#define SENSOR_H

#include <avr/io.h>
#include "list.c"
#include "scenario.h"


class Sensor
{

	public:
		Sensor(uint8_t pin, uint8_t adres); 	//constructor
		bool isGeactiveert(); 					//checkt of de sensor op dit moment wordt geactiveerd
		void kenScenarioToe(Scenario*); 		//Ken een scenario toe

	private:
		uint8_t pin;							//De PIN waar de sensor zich op bevind
		uint8_t adres;							//Het adres van de sensor op de poort als hexadecimaal getal
		Scenario* scenario;
			
};

#endif
