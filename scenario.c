#include "scenario.h"
#include "list.c"
#include "voetgangerlicht.h"
#include "autolicht.h"
#include "avr/delay.h"


//constructor
Scenario::Scenario(List<VoetgangerLicht*> *v) : lichten(v){

}

//Zet alle lichten in de lijsten op groen
void Scenario::zetAllesNaarGroen() {
	//Haal de eerste voetgangers licht uit de lijst op
	VoetgangerLicht* vObj = lichten->krijgKop();
	uint8_t i = 1;
	//Als er geen object gevonden wordt wordt er 0 gegeven
	while(vObj != 0) {
		vObj->lichtNaarGroen();
		i++;
		//Haal een voetganger uit de lijst op de locatie van iterator i
		vObj = lichten->geefPositie(i);
	}
}

void Scenario::zetAllesNaarRood() { 
	for(int k=0; k <6; k++) //Roept 6 keer de tussen fase van Groen naar Rood bij alle lichten aan
	{
		for (int c = 1; lichten->geefPositie(c) != 0; c++)
		{
			lichten->geefPositie(c)->vanGroenNaarRood(k);
		}
		_delay_ms(4000); //Een bepaalde tijd wachten
	}
	//Zet van alle stoplichten uit scenario .. het licht op rood
	for (int i = 1; lichten->geefPositie(i) != 0; i++)
	{
		lichten->geefPositie(i)->lichtNaarRood();
	}
}

void Scenario::zetAllesUit() {
	for (int i = 1; lichten->geefPositie(i) != 0; i++) //Alle lichten uit
	{
		lichten->geefPositie(i)->alleLichtenUit();
	}

}

void Scenario::zetAllesNaarOranje() {
	for (int i = 1; lichten->geefPositie(i) != 0; i++) //Alle autolichten naar oranje en voetgangerlichten uit zetten
	{
		lichten->geefPositie(i)->vanGroenNaarRood(0);
	}

}

//Voeg een nieuw licht toe aan de lijst met lichten
void Scenario::voegLichtToe(VoetgangerLicht *v) {
	lichten->push_back(v);
}
