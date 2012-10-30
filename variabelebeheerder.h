#ifndef VARIABELEBEHEERDER_H
#define VARIABELEBEHEERDER_H

#include "Serial.h"

class VariabeleBeheerder {
	public:
		VariabeleBeheerder(Serial*);		//Constructor
		void zetNacht(bool);	//Zet de variabele nacht naar true of false
		bool krijgNacht(void);	//Vraag op of de variabele nacht true of false is
		int krijgVariabele(char);
		void leesSerielePoort(void);

	private:
		char type;
		int groentijd;
		int oranjetijd;
		int roodtijd;
		int nachtstandtijd;
		bool nacht;				//Variabele die bijhoudt of het nacht is of niet
		Serial *serial;
};

#endif
