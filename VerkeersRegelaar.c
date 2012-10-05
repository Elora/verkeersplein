#include "VerkeersRegelaar.h"
#include "avr/delay.h"

VerkeersRegelaar::VerkeersRegelaar(List<Scenario*>* s, WachtrijBeheerder* w) : scenariolijst(s), wachtrijbeheerder(w) {

} //In de constructor worden lijsten meegegeven

void VerkeersRegelaar::doeNachtStand(){ //Deze functie voert de nachtstand uit
	int t = 0;

	while(t < 10) //Voorlopig 10x knipperen als test
	{
		for (int b = 1; scenariolijst->geefPositie(b) != 0; b++) //Alle scenario's langslopen
		{
			scenariolijst->geefPositie(b)->zetAllesUit(); //Van dat scenario alle lichten uitzetten
		}

		_delay_ms(7500); //Seconde lang uit

		for (int c = 1; scenariolijst->geefPositie(c) != 0; c++) //Alle scenario's langslopen
		{
			scenariolijst->geefPositie(c)->zetAllesNaarOranje();
		}

		_delay_ms(7500); //Seconde lang aan

		t++;
	}
}

void VerkeersRegelaar::doeStandaardSequentie() { //Deze functie voert de standaard sequentie uit
	for (int i = 1; scenariolijst->geefPositie(i) != 0; i++) { //Doorloop alle scenario's omstebeurt
		Scenario* scenario = scenariolijst->geefPositie(i);
		scenario->zetAllesNaarGroen(); 	//In het scenario alles naar groen zetten
		for(int n = 0; n < 15; n++)
			_delay_ms(5000);				//Een bepaalde tijd wachten
		scenario->zetAllesNaarRood();	//En alles weer naar rood laten gaan
		for(int n = 0; n < 10; n++)
			_delay_ms(5000);			//En 5 sec wachten voordat het volgende scenario op groen gaat

		int j = i + 1;	
		if(scenariolijst->geefPositie(j) == 0)	//Checken of de volgende positie in scenariolijst een scenario bevat
			i = 0;								//Zo niet, dan begint de lijst weer van voor af aan
	}		//i wordt op 0 gezet ipv op 1 omdat aan het eind van de loop er eentje wordt opgeteld
}

void VerkeersRegelaar::doeWachtrij(){

	while(wachtrijbeheerder->geefEersteInWachtrij() != 0) {  //Wanneer er iets in de wachtrij staat wordt de loop doorlopen
		Scenario* scenario = wachtrijbeheerder->geefEersteInWachtrij(); //Het eerste scenario uit de wachtrij wordt gegeven
		scenario->zetAllesNaarGroen(); 	//In het scenario alles naar groen zetten
		for(int n = 0; n < 15; n++)
			_delay_ms(5000);				//Een bepaalde tijd wachten
		scenario->zetAllesNaarRood();	//En alles weer naar rood laten gaan
		wachtrijbeheerder->haalEersteUitWachtrij(); //Het eerste scenario uit de wachtrij halen
		for(int n = 0; n < 10; n++)
			_delay_ms(5000);			//En 5 sec wachten voordat het volgende scenario op groen gaat
		
	}

}

void VerkeersRegelaar::kiesFunctie(){
	doeNachtStand();
}

void VerkeersRegelaar::voegScenarioToe(Scenario* s){ //Voeg een scenario toe aan de lijst scenariolijst
	scenariolijst->push_back(s);
}
