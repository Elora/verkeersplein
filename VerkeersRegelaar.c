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

	int t = 0;

	while(t < 10)
	{
		for (int b = 1; autolichten->geefPositie(b) != 0; b++)
		{
			autolichten->geefPositie(b)->alleLichtenUit();
		}

		//_delay_ms(5000);

		for (int c = 1; autolichten->geefPositie(c) != 0; c++)
		{
			autolichten->geefPositie(c)->lichtNaarOranje();
		}

		//_delay_ms(5000);

		t++;
	}
}

void VerkeersRegelaar::doeStandaardSequentie(){

}

void VerkeersRegelaar::doeWachtrij(){

}

void VerkeersRegelaar::kiesFunctie(){

}
