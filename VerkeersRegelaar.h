#ifndef VERKEERSREGELAAR
#define VERKEERSREGELAAR

#include "list.c"
#include "voetgangerlicht.h"
#include "autolicht.h"
#include "scenario.h"


class VerkeersRegelaar
{

	public:
		VerkeersRegelaar(List<Scenario*>*);
		void doeNachtStand();
		void doeStandaardSequentie();
		void doeWachtrij();
		void kiesFunctie();
		void voegScenarioToe(Scenario*);	

	private:
		List<Scenario*>* scenariolijst;
	
	
};

#endif
