#include "scenario.h"
#include "list.c"
#include "voetgangerlicht.h"

Scenario::Scenario(List<VoetgangerLicht> l) : list(l) {

}

/*void Scenario::speelAf() {
	uint8_t grootte(list->krijgGrootte());
	uint8_t i;
	for(i = 0; i < grootte; i++) {
		(list->krijgPositie(i))->lichtNaarGroen();
	}
}*/
