#include "VerkeersRegelaar.h"
#include "avr/delay.h"
#include "autolicht.h"

VerkeersRegelaar::VerkeersRegelaar(List<AutoLicht*>* a, List<VoetgangerLicht*>* v, List<Scenario*>* s) : autolichten(a), voetgangerlichten(v), scenariolijst(s){

} //In de constructor worden lijsten meegegeven

void VerkeersRegelaar::doeNachtStand(){ //Deze functie voert de nachtstand uit
	for (int i = 1; voetgangerlichten->geefPositie(i) != 0; i++) //In deze loop worden alle voetgangerlichten uitgezet
	{
		voetgangerlichten->geefPositie(i)->alleLichtenUit();
	}

	int t = 0;

	while(t < 10) //Voorlopig 10x knipperen als test
	{
		for (int b = 1; autolichten->geefPositie(b) != 0; b++) //Alle autolichten uit
		{
			AutoLicht *temp;
			temp = autolichten->geefPositie(b);
			temp->alleLichtenUit();
		}

		_delay_ms(1000); //Seconde lang uit

		for (int c = 1; autolichten->geefPositie(c) != 0; c++) //Alle autolichten naar oranje
		{
			AutoLicht *temp;
			temp = autolichten->geefPositie(c);
			temp->lichtNaarOranje();
		}

		_delay_ms(1000); //Seconde lang aan

		t++;
	}
}

void VerkeersRegelaar::doeStandaardSequentie() { //Deze functie voert de standaard sequentie uit
	for (int i = 1; scenariolijst->geefPositie(i) != 0; i++) { //Doorloop alle scenario's omstebeurt
		Scenario* scenario = scenariolijst->geefPositie(i);
		scenario->zetAllesNaarGroen(); 	//In het scenario alles naar groen zetten
		//_delay_ms(10000);				//Een bepaalde tijd wachten
		scenario->zetAllesNaarRood();	//En alles weer naar rood laten gaan
		//_delay_ms(5000);				//En 5 sec wachten voordat het volgende scenario op groen gaat

		int j = i + 1;	
		if(scenariolijst->geefPositie(j) == 0)	//Checken of de volgende positie in scenariolijst een scenario bevat
			i = 0;								//Zo niet, dan begint de lijst weer van voor af aan
	}		//i wordt op 0 gezet ipv op 1 omdat aan het eind van de loop er eentje wordt opgeteld
}

void VerkeersRegelaar::doeWachtrij(){

}

void VerkeersRegelaar::kiesFunctie(){

}

void VerkeersRegelaar::voegAutoLichtToe(AutoLicht* a){ //Voeg een autolicht toe aan de lijst autolichten
	autolichten->push_back(a);
}

void VerkeersRegelaar::voegVoetgangerLichtToe(VoetgangerLicht* v){ //Voeg een voetgangerlicht toe aan de lijst voetgangerlichten
	voetgangerlichten->push_back(v);
}

void VerkeersRegelaar::voegScenarioToe(Scenario* s){ //Voeg een scenario toe aan de lijst scenariolijst
	scenariolijst->push_back(s);
}
