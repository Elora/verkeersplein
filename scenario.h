#ifndef SCENARIO_H
#define SCENARIO_H

#include "list.h"
class AutoLicht;
class VoetgangerLicht;

class Scenario {
	public:
		Scenario(List<VoetgangerLicht*> *v, List<AutoLicht*> *a);
		void zetAllesNaarGroen();
		void zetAllesNaarRood();
		void voegAutoLichtToe(AutoLicht *a);
		void voegVoetgangerLichtToe(VoetgangerLicht *v);
		
	private:
		List<VoetgangerLicht*> *voetgangerlichten;
		List<AutoLicht*> *autolichten;
};

#endif
