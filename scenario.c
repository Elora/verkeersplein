#include "scenario.h"
#include "list.c"
#include "voetgangerlicht.h"
#include "autolicht.h"
#include "avr/delay.h"


//constructor
Scenario::Scenario(List<VoetgangerLicht*> *v, List<AutoLicht*>* a) : voetgangerlichten(v), autolichten(a) {

}


//Zet alle lichten in de lijsten op groen
void Scenario::zetAllesNaarGroen() {
	//Haal de eerste voetgangers licht uit de lijst op
	VoetgangerLicht* vObj = voetgangerlichten->krijgKop();
	//Haal de eerste auto licht uit de lijst op
	AutoLicht* aObj = autolichten->krijgKop();
	uint8_t i = 1;
	//Als er geen object gevonden wordt wordt er 0 gegeven
	while(vObj != 0) {
		vObj->lichtNaarGroen();
		i++;
		//Haal een voetganger uit de lijst op de locatie van iterator i
		vObj = voetgangerlichten->geefPositie(i);
	}
	i = 1;
	while(aObj != 0) {
		aObj->lichtNaarGroen();
		i++;
		aObj = autolichten->geefPositie(i);
	}
}

void Scenario::zetAllesNaarRood() {
	//"Zet van alle autolichten uit scenario .. het licht op oranje"
	for (int c = 1; autolichten->geefPositie(c) != 0; c++)
		{
			autolichten->geefPositie(c)->lichtNaarOranje();
		}

	
	for(int k=0; k <6; k++) 
	{    // Een loopje die de voetgangerlichten 3 keer laat knipperen
	
		if(k%2 == 0){ // Dus bij i = 0, i = 2, i = 4
		//"Roep in een loopje van alle Voetgangerlichten uit scenario .. de alleLichtenUit() functie aan"
			for (int l = 1; voetgangerlichten->geefPositie(l) != 0; l++)
			{
				voetgangerlichten->geefPositie(l)->alleLichtenUit();
			}
		}
		else 
		{
		//"Roep in een loopje van alle Voetgangerlichten uit scenario .. de lichtNaarGroen() aan"
			for (int l = 1; voetgangerlichten->geefPositie(l) != 0; l++)
			{
				voetgangerlichten->geefPositie(l)->lichtNaarGroen();
			}
		}
		_delay_ms(4000);
	
	}
	
	//"Zet van alle stoplichten uit scenario .. het licht op rood"
	for (int i = 1; voetgangerlichten->geefPositie(i) != 0; i++)
	{
		voetgangerlichten->geefPositie(i)->lichtNaarRood();
	}
	for (int i = 1; autolichten->geefPositie(i) != 0; i++)
	{
		autolichten->geefPositie(i)->lichtNaarRood();
	}
	
}

//Voeg een nieuw licht toe aan de lijst met auto lichten
void Scenario::voegAutoLichtToe(AutoLicht* a) {
	autolichten->push_back(a);
}

//Voeg een nieuw licht toe aan de lijst met voetganger lichten
void Scenario::voegVoetgangerLichtToe(VoetgangerLicht *v) {
	voetgangerlichten->push_back(v);
}
