#include "scenario.h"
#include "list.c"
#include "voetgangerlicht.h"
#include "autolicht.h"

Scenario::Scenario(List<VoetgangerLicht*> *v, List<AutoLicht*>* a) : voetgangerlichten(v), autolichten(a) {

}

void Scenario::zetAllesNaarGroen() {
	VoetgangerLicht* vObj = voetgangerlichten->krijgKop();
	AutoLicht* aObj = autolichten->krijgKop();
	uint8_t i = 1;
	while(vObj != 0) {
		vObj->lichtNaarGroen();
		i++;
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

void Scenario::voegAutoLichtToe(AutoLicht* a) {
	autolichten->push_back(a);
}

void Scenario::voegVoetgangerLichtToe(VoetgangerLicht *v) {
	voetgangerlichten->push_back(v);
}
