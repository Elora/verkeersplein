#include "variabelebeheerder.h"
#include "Serial.h"

//De maxima en minima voor de veschillende lichtkeluren in seconden
#define maxtijd  60 //De maximale tijd dat auto's moeten wachten bij het stoplicht
#define mingroentijd  5
#define maxgroentijd  30
#define minoranjetijd  2
#define maxoranjetijd  4
#define minroodtijd  5
#define maxknippertijd  3 //De maximale tijd dat het oranje licht aan en uit staat in de nachtstand

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

void VariabeleBeheerder::setAantalScenarios(int i) {
	aantalScenarios = i;
}

//Lees de waarde van de seriele poort af en ken die toe aan een variabele
void VariabeleBeheerder::leesSerielePoort(void) {
	uint8_t *p;
	int berekening;
	if(serial->lees_serial(p) == 0) { //Wanneer er iets is ingelezen
		if (*p == 'g' || *p == 'o' || *p == 'r' || *p == 'n' || *p == 'a' || *p == 'u') 	//Als hetgeen op de poort een 'g', 'o', 'r' of 'n' is
			type = *p; 											//Ken dat character dan toe aan de variabele type
		else if (*p == 'a') //Als hetgeen op de lijn een 'a' is, zet de variabele nacht op true
			nacht = true;
		else if (*p == 'u')	//Als hetgeen op de lijn een 'u' is, zet de variabele nacht op false
			nacht = false;
		else {			//Wanneer bovenstaande niet geldt, wordt er een getal doorgestuurd
			switch (type) {	//Ken dat getal toe aan het type dat op dit moment actief is
				case 'g':
					if (*p < mingroentijd) {
						serial->schrijf_serial(1);
						serial->schrijf_serial(mingroentijd);
					} else if ((*p + roodtijd + oranjetijd)*(aantalScenarios - 1) > maxtijd || *p > maxgroentijd) {
						berekening = maxtijd/(aantalScenarios - 1) - roodtijd - oranjetijd;
						if (berekening > maxgroentijd)
							berekening = maxgroentijd;
						serial->schrijf_serial(2);
						serial->schrijf_serial(berekening);
					}else {
						groentijd = *p;
						serial->schrijf_serial(255);
					}
					break;
				case 'o':
					if (*p < minoranjetijd) {
						serial->schrijf_serial(3);
						serial->schrijf_serial(minoranjetijd);
					} else if ((*p + roodtijd + oranjetijd)*(aantalScenarios - 1) > maxtijd || *p > maxoranjetijd) {
						berekening = maxtijd/(aantalScenarios - 1) - roodtijd - groentijd;
						if (berekening > minoranjetijd)
							berekening = minoranjetijd;
						serial->schrijf_serial(4);
						serial->schrijf_serial(berekening);
					}else {
						oranjetijd = *p;
						serial->schrijf_serial(255);
					}
					break;
				case 'r':
					if (*p < minroodtijd) {
						serial->schrijf_serial(5);
						serial->schrijf_serial(minroodtijd);
					} else if ((*p + oranjetijd + groentijd)*(aantalScenarios - 1) > maxtijd) {
						berekening = maxtijd/(aantalScenarios - 1) - groentijd - oranjetijd;
						serial->schrijf_serial(6);
						serial->schrijf_serial(berekening);
					}else {
						serial->schrijf_serial(255);
						roodtijd = *p;
					}
					break;
				case 'n':
					if (*p > maxknippertijd) {
						serial->schrijf_serial(7);
						serial->schrijf_serial(maxknippertijd);
					}
					else nachtstandtijd = *p;
					break;
				case 'a':
					zetNacht(true);
					serial->schrijf_serial(8);
					break;
				case 'u':
					zetNacht(false);
					serial->schrijf_serial(9);;
					break;
				default:
					//doe niks
					break;
			}
		}
	}
}

void VariabeleBeheerder::stuurErrorCode(int error, int limiet) {
	
}

