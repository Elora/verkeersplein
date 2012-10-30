#include "nachtwaarder.h"

NachtWaarder::NachtWaarder(void) : nacht(false) { //Constructor zet bij initialisatie nacht op false
}

void NachtWaarder::zetNacht(bool w) {
	nacht = w;
}

bool NachtWaarder::krijgNacht(void) {
	return nacht;
}
