#ifndef VERKEERSREGELAAR
#define VERKEERSREGELAAR

#include "list.c"
#include "voetgangerlicht.h"
#include "autolicht.h"
#include "scenario.h"


class VerkeersRegelaar
{

	public:
		VerkeersRegelaar(List<AutoLicht*>*, List<VoetgangerLicht*>*, List<Scenario*>*);
		void doeNachtStand();
		void doeStandaardSequentie();
		void doeWachtrij();
		void kiesFunctie();
		void voegAutoLichtToe(AutoLicht*);
		void voegVoetgangerLichtToe(VoetgangerLicht*);
		void voegScenarioToe(Scenario*);	

	private:
		List<AutoLicht*>* autolichten;
		List<VoetgangerLicht*>* voetgangerlichten;
		List<Scenario*>* scenariolijst;
	
	
};

#endif
