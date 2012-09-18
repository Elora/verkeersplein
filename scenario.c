#include "scenario.h"
#include "list.c"
#include "voetgangerlicht.h"
#include "autolicht.h"


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

//Zet alle lichten in de lijsten op rood
//Verder ziet de code er het zelfde uit als bij zetAllesNaarGroen
void Scenario::zetAllesNaarRood() {
	VoetgangerLicht* vObj = voetgangerlichten->krijgKop();
	AutoLicht* aObj = autolichten->krijgKop();
	uint8_t i = 1;
	while(vObj != 0) {
		vObj->lichtNaarRood();
		i++;
		vObj = voetgangerlichten->geefPositie(i);
	}
	i = 1;
	while(aObj != 0) {
		aObj->lichtNaarRood();
		i++;
		aObj = autolichten->geefPositie(i);
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
