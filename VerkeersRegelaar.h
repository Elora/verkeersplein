#ifndef VERKEERSREGELAAR
#define VERKEERSREGELAAR

#include "list.c"
#include "voetgangerlicht.h"
#include "autolicht.h"

class VerkeersRegelaar
{

	public:
		VerkeersRegelaar(List<AutoLicht*>*, List<VoetgangerLicht*>*);
		void doeNachtStand();
		void doeStandaardSequentie();
		void doeWachtrij();
		void kiesFunctie();
	
	private:
		List<AutoLicht*>* autolichten;
		List<VoetgangerLicht*>* voetgangerlichten;
	
	
};

#endif
