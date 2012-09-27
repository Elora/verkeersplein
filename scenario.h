#ifndef SCENARIO_H
#define SCENARIO_H

#include "list.h"
class AutoLicht;
class VoetgangerLicht;

class Scenario {
	public:
		Scenario(List<VoetgangerLicht*> *v);
		void zetAllesNaarGroen();
		void zetAllesNaarRood();
		void zetAllesNaarOranje();
		void zetAllesUit();
		void voegLichtToe(VoetgangerLicht *v);
		
	private:
		List<VoetgangerLicht*> *lichten;
};

#endif
