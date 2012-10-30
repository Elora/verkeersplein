#include "variabelebeheerder.h"
#include "Serial.h"

//De maxima en minima voor de veschillende lichtkeluren in seconden
#define maxtijd  60 //De maximale tijd dat auto's mogen wachten bij het stoplicht
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
		if (*p == 'g' || *p == 'o' || *p == 'r' || *p == 'n') 	//Als hetgeen op de poort een 'g', 'o', 'r' of 'n' is
			type = *p; 											//Ken dat character dan toe aan de variabele type
		else if (*p == 'a'){ //Als hetgeen op de lijn een 'a' is, zet de variabele nacht op true
			nacht = true;
			serial->schrijf_serial(8);
		}
		else if (*p == 'u'){	//Als hetgeen op de lijn een 'u' is, zet de variabele nacht op false
			nacht = false;
			serial->schrijf_serial(9);
		}
		else {			//Wanneer bovenstaande niet geldt, wordt er een getal doorgestuurd
			switch (type) {	//Ken dat getal toe aan het type dat op dit moment actief is

				case 'g':
					//Testen of ingevoerde tijd kleiner is dat de minimale groentijd
					if (*p < mingroentijd) {
						stuurErrorCode(1, mingroentijd);
					} 
					//Testen of ingevoerde tijd groter is dat de maximale groentijd of de totale 
					//tijd groter wordt dan de maximale wachttijd
					else if ((*p + roodtijd + oranjetijd)*(aantalScenarios - 1)+roodtijd > maxtijd || *p > maxgroentijd) {
						berekening = (maxtijd - roodtijd)/(aantalScenarios - 1) - roodtijd - oranjetijd;
						//Het kan zijn dat de maximale groentijd uit de berekening groter is dan de 
						//maximale groentijd die is gedefinieerd.
						if (berekening > maxgroentijd)
							berekening = maxgroentijd;
						stuurErrorCode(2, berekening);
					}
					//De ingevoerde tijd is toegestaan
					else {
						groentijd = *p;
						serial->stuurSuccesCode();
					}
					break;

				case 'o':
					//Testen of ingevoerde tijd kleiner is dat de minimale oranjetijd
					if (*p < minoranjetijd) {
						stuurErrorCode(3, minoranjetijd);
					//Testen of ingevoerde tijd groter is dat de maximale oranjetijd of de totale 
					//tijd groter wordt dan de maximale wachttijd
					} else if ((*p + roodtijd + groentijd)*(aantalScenarios - 1)+roodtijd > maxtijd || *p > maxoranjetijd) {
						berekening = (maxtijd - roodtijd)/(aantalScenarios - 1) - roodtijd - groentijd;
						//Het kan zijn dat de maximale oranjetijd uit de berekening groter is dan de 
						//maximale oranjetijd die is gedefinieerd.
						if (berekening > maxoranjetijd)
							berekening = maxoranjetijd;
						stuurErrorCode(4, berekening);	
					}
					//De ingevoerde tijd is toegestaan
					else {
						oranjetijd = *p;
						serial->stuurSuccesCode();
					}
					break;

				case 'r':
				//Testen of ingevoerde tijd kleiner is dat de minimale roodtijd
					if (*p < minroodtijd) {
						stuurErrorCode(5, minroodtijd);
					//Testen of ingevoerde tijd groter is dat de maximale roodtijd of de totale 
					//tijd groter wordt dan de maximale wachttijd
					} else if ((*p + oranjetijd + groentijd)*(aantalScenarios - 1)+*p > maxtijd) {
						berekening = (maxtijd - groentijd*(aantalScenarios - 1) - oranjetijd*(aantalScenarios - 1))/3;
						stuurErrorCode(6, berekening);
					}
					//De ingevoerde tijd is toegestaan
					else {
						roodtijd = *p;
						serial->stuurSuccesCode();
					}
					break;
				case 'n':
					//Testen of ingevoerde tijd groter is dat de maximale knippertijd
					if (*p > maxknippertijd) {
						stuurErrorCode(7, maxknippertijd);
					}
					//De ingevoerde tijd is toegestaan
					else {
						nachtstandtijd = *p;
						serial->stuurSuccesCode();
					}

					break;
				default:
					//doe niks
					break;
			}
		}
	}
}

void VariabeleBeheerder::stuurErrorCode(int error, int limiet) {
	serial->schrijf_serial(error);
	serial->schrijf_serial(limiet);
}
