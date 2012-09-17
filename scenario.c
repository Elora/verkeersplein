#include "scenario.h"
#include "list.c"
#include "voetgangerlicht.h"

Scenario::Scenario(List<VoetgangerLicht*> *l) : list(l) {

}

void Scenario::speelAf() {
	VoetgangerLicht* obj = list->krijgKop();
	uint8_t i = 1;
	while(obj != 0) {
		obj->lichtNaarGroen();
		i++;
		obj = list->geefPositie(i);
	}
}
