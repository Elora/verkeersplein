#include "variabelebeheerder.h"

VariabeleBeheerder::VariabeleBeheerder(Serial* s) : serial(s), nacht(false), groentijd(10), oranjetijd(3), roodtijd(5), nachtstandtijd(1), type('o') {
}

void VariabeleBeheerder::zetNacht(bool w) {
	nacht = w;
}

bool VariabeleBeheerder::krijgNacht(void) {
	return nacht;
}


/*
Onderstaande functie geeft de waarde van een variabele terug. De volgende parameters kunnen worden meegegeven:
'o' : oranjetijd
'g' : groentijd
'r' : roodtijd
'n' : nachtstandtijd
*/
int VariabeleBeheerder::krijgVariabele(char v) {
	switch (v) {	
		case 'g':
			return groentijd;
			break;
		case 'o':
			return oranjetijd;
			break;
		case 'r':
			return roodtijd;
			break;
		case 'n':
			return nachtstandtijd;
			break;
		default:
			//doe niks
			break;
	}
}

//Lees de waarde van de seriele poort af en ken die toe aan een variabele
void VariabeleBeheerder::leesSerielePoort(void) {
	uint8_t *p; 
	if(serial->lees_serial(p) == 0) { //Wanneer er iets is ingelezen
		if (*p == 'g' || *p == 'o' || *p == 'r' || *p == 'n') 	//Als hetgeen op de poort een 'g', 'o', 'r' of 'n' is
			type = *p; 											//Ken dat character dan toe aan de variabele type
		else if (*p == 'a') //Als hetgeen op de lijn een 'a' is, zet de variabele nacht op true
			nacht = true;
		else if (*p == 'u')	//Als hetgeen op de lijn een 'u' is, zet de variabele nacht op false
			nacht = false;
		else {				//Wanneer bovenstaande niet geldt, wordt er een getal doorgestuurd
			switch (type) {	//Ken dat getal toe aan het type dat op dit moment actief is
				case 'g':
					groentijd = *p;
				case 'o':
					oranjetijd = *p;
				case 'r':
					roodtijd = *p;
				case 'n':
					nachtstandtijd = *p;
			}
		}
	}
}

