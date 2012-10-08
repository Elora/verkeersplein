#ifndef NACHTWAARDER_H
#define NACHTWAARDER_H

#include <avr/io.h>


class NachtWaarder
{

	public:
		NachtWaarder(void);		//Constructor
		void zetNacht(bool);	//Zet de variabele nacht naar true of false
		bool krijgNacht(void);	//Vraag op of de variabele nacht true of false is

	private:
		bool nacht;				//Variabele die bijhoudt of het nacht is of niet
			
};

#endif
