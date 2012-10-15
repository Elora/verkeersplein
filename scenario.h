#ifndef SCENARIO_H
#define SCENARIO_H

#include "list.h"
#include "variabelebeheerder.h"

class AutoLicht;
class VoetgangerLicht;

class Scenario {
	public:
		Scenario(List<VoetgangerLicht*>*, VariabeleBeheerder*);
		void zetAllesNaarGroen();
		void zetAllesNaarRood();
		void zetAllesNaarOranje();
		void zetAllesUit();
		void allesDirectRood();
		void voegLichtToe(VoetgangerLicht*);
		
	private:
		List<VoetgangerLicht*> *lichten;
		VariabeleBeheerder *variabelebeheerder;
};

#endif
