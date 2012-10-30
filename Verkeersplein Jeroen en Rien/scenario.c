#include "scenario.h"
#include "list.c"
#include "voetgangerlicht.h"
#include "autolicht.h"

#define F_CPU 8000000
#include "util/delay.h"


//constructor
Scenario::Scenario(List<VoetgangerLicht*> *v, VariabeleBeheerder* b) : lichten(v), variabelebeheerder(b) {

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

//De code hieronder laat van elk scenario de verkeerslichten naar rood gaan
//Hierbij gaan de voetgangerlichten groen knipperen en de autolichten gaan op oranje
void Scenario::zetAllesNaarRood() { 
	
	//Loopje wordt aantal keer uitgevoerd afhankelijk van de variabele die de variabelebeheerder teruggeeft
	for(int k=0; k < (variabelebeheerder->krijgVariabele('o') * 2); k++)
	{	
		//Hierdoor gaan de voetgangerslichten groen knipperen en blijven de autolichten oranje					
		for (int c = 1; lichten->geefPositie(c) != 0; c++) 
		{
			lichten->geefPositie(c)->vanGroenNaarRood(k); 
		}
		_delay_ms(500); //Een halve seconde wachten
	}
	//Zet van alle stoplichten uit scenario .. het licht op rood
	for (int i = 1; lichten->geefPositie(i) != 0; i++)
	{
		lichten->geefPositie(i)->lichtNaarRood();
	}
}

//Zet alle verkeerslichten binnen het scenario meteen op rood
void Scenario::allesDirectRood() { 
	VoetgangerLicht* vObj = lichten->krijgKop();
	uint8_t i = 1;

	//Als er geen object gevonden wordt wordt er 0 gegeven
	while(vObj != 0) {
		vObj->lichtNaarRood();
		i++;
		//Haal een voetganger uit de lijst op de locatie van iterator i
		vObj = lichten->geefPositie(i);
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
