#ifndef VERKEERSREGELAAR
#define VERKEERSREGELAAR

#include "list.c"
#include "voetgangerlicht.h"
#include "autolicht.h"
#include "scenario.h"
#include "wachtrijbeheerder.h"
#include "nachtwaarder.h"


class VerkeersRegelaar
{

	public:
		VerkeersRegelaar(List<Scenario*>*, WachtrijBeheerder*, NachtWaarder*);
		void doeNachtStand();
		void doeStandaardSequentie();
		void doeWachtrij();
		void kiesFunctie();
		void voegScenarioToe(Scenario*);	

	private:
		List<Scenario*>* scenariolijst;
		WachtrijBeheerder* wachtrijbeheerder;
		NachtWaarder* nachtwaarder;
	
	
};

#endif
