#include "VerkeersRegelaar.h"
#include "avr/delay.h"
#include "autolicht.h"

VerkeersRegelaar::VerkeersRegelaar(List<AutoLicht*>* a, List<VoetgangerLicht*>* v) : autolichten(a), voetgangerlichten(v){

}

void VerkeersRegelaar::doeNachtStand(){
	for (int i = 1; voetgangerlichten->geefPositie(i) != 0; i++)
	{
		voetgangerlichten->geefPositie(i)->alleLichtenUit();
	}

	int i;

	while(i < 10)
	{
		for (int b = 1; autolichten->geefPositie(b) != 0; i++)
		{
			autolichten->geefPositie(b)->alleLichtenUit();
		}

		_delay_ms(1000);

		for (int c = 1; autolichten->geefPositie(c) != 0; i++)
		{
			autolichten->geefPositie(c)->lichtNaarOranje();
		}

		_delay_ms(1000);

		i++;
	}
}

void VerkeersRegelaar::doeStandaardSequentie(){

}

void VerkeersRegelaar::doeWachtrij(){

}

void VerkeersRegelaar::kiesFunctie(){

}
