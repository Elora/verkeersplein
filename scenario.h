#ifndef SCENARIO_H
#define SCENARIO_H

//template <typename T> class List;
#include "list.h"
#include "voetgangerlicht.h"

class Scenario {
	public:
		Scenario(List<VoetgangerLicht*>* l);
	private:
		List<VoetgangerLicht*>* list;
};

#endif
