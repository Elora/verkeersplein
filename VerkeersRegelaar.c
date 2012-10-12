#include "VerkeersRegelaar.h"

#define F_CPU 8000000
#include "util/delay.h"

VerkeersRegelaar::VerkeersRegelaar(List<Scenario*>* s, WachtrijBeheerder* w, VariabeleBeheerder* v) : scenariolijst(s), wachtrijbeheerder(w), variabelebeheerder(v) {

} //In de constructor wordt een lijst met scenario's meegegeven, een wachtrijbeheerder en een variabelebeheerder

void VerkeersRegelaar::doeNachtStand(){ //Deze functie voert de nachtstand uit

	while(variabelebeheerder->krijgNacht() == true) //controleren of het nacht is
	{
		for (int b = 1; scenariolijst->geefPositie(b) != 0; b++) //Alle scenario's langslopen
		{
			scenariolijst->geefPositie(b)->zetAllesUit(); //Van dat scenario alle lichten uitzetten
		}
		
		for (int n = 0; n < variabelebeheerder->krijgVariabele('n'); n++)
			_delay_ms(1000); //Seconde lang uit

		for (int c = 1; scenariolijst->geefPositie(c) != 0; c++) //Alle scenario's langslopen
		{
			scenariolijst->geefPositie(c)->zetAllesNaarOranje();
		}

		for (int n = 0; n < variabelebeheerder->krijgVariabele('n'); n++)
			_delay_ms(1000); //Seconde lang aan
	}
	komtUitNachtStand();
}


void VerkeersRegelaar::komtUitNachtStand() { 	//Deze functie wordt aangeroepen bij de overgang van nacht naar dag
												//Alle scenario's worden eenmalig langsgelopen in hun vaste patroon
	
	//Eerst wordt van alle scenario's alle verkeerslichten op rood gezet
	for (int i = 1; scenariolijst->geefPositie(i) != 0; i++) { 
		Scenario* scenario = scenariolijst->geefPositie(i);
		scenario->allesDirectRood();
	}
	
	for (int n = 0; n < variabelebeheerder->krijgVariabele('r'); n++)
		_delay_ms(1000);		//Vijf seconden wachten 

	for (int i = 1; scenariolijst->geefPositie(i) != 0; i++) { //Doorloop alle scenario's omstebeurt
		Scenario* scenario = scenariolijst->geefPositie(i);
		scenario->zetAllesNaarGroen(); 	//In het scenario alles naar groen zetten
		for (int n = 0; n < variabelebeheerder->krijgVariabele('g'); n++)
			_delay_ms(1000);				//Een bepaalde tijd wachten
		scenario->zetAllesNaarRood();	//En alles weer naar rood laten gaan
		wachtrijbeheerder->haalUitWachtrij(scenario);

		for (int n = 0; n < variabelebeheerder->krijgVariabele('r'); n++)
			_delay_ms(1000);			//En 5 sec wachten voordat het volgende scenario op groen gaat
	}											
}


void VerkeersRegelaar::doeStandaardSequentie() { //Deze functie voert de standaard sequentie uit
	
	for (int i = 1; scenariolijst->geefPositie(i) != 0; i++) { //Doorloop alle scenario's omstebeurt
		Scenario* scenario = scenariolijst->geefPositie(i);
		scenario->zetAllesNaarGroen(); 	//In het scenario alles naar groen zetten
		for (int n = 0; n < variabelebeheerder->krijgVariabele('g'); n++)
			_delay_ms(1000);				//Een bepaalde tijd wachten
		scenario->zetAllesNaarRood();	//En alles weer naar rood laten gaan
		
		for (int n = 0; n < variabelebeheerder->krijgVariabele('r'); n++)
			_delay_ms(1000);			//En 5 sec wachten voordat het volgende scenario op groen gaat

		int j = i + 1;	
		if(scenariolijst->geefPositie(j) == 0)	//Checken of de volgende positie in scenariolijst een scenario bevat
			i = 0;								//Zo niet, dan begint de lijst weer van voor af aan
												//i wordt op 0 gezet ipv op 1 omdat aan het eind van de loop er eentje wordt opgeteld
		
		//Wanneer er iets in de wachtrij staat of wanneer het nacht is moet er uit deze functie gesprongen worden
		if((wachtrijbeheerder->geefEersteInWachtrij() != 0) || variabelebeheerder->krijgNacht())
			return;
	}											
}


void VerkeersRegelaar::doeWachtrij() {

	while(wachtrijbeheerder->geefEersteInWachtrij() != 0) {  //Wanneer er iets in de wachtrij staat wordt de loop doorlopen
		Scenario* scenario = wachtrijbeheerder->geefEersteInWachtrij(); //Het eerste scenario uit de wachtrij wordt gegeven
		scenario->zetAllesNaarGroen(); 	//In het scenario alles naar groen zetten

		for (int n = 0; n < variabelebeheerder->krijgVariabele('g'); n++)
			_delay_ms(1000);				//Een bepaalde tijd wachten

		scenario->zetAllesNaarRood();	//En alles weer naar rood laten gaan
		wachtrijbeheerder->haalEersteUitWachtrij(); //Het eerste scenario uit de wachtrij halen
		
		for (int n = 0; n < variabelebeheerder->krijgVariabele('r'); n++)
			_delay_ms(1000);			//En 5 sec wachten voordat het volgende scenario op groen gaat
		
		if(variabelebeheerder->krijgNacht() == true) //Checken of het onderhand nacht is, zo ja dan moet er uit de functie worden gesprongen
			return;
	}

}

void VerkeersRegelaar::kiesFunctie() {
	if (variabelebeheerder->krijgNacht() == true)
		doeNachtStand();
	else if (wachtrijbeheerder->geefEersteInWachtrij() != 0)
		doeWachtrij();
	else
		doeStandaardSequentie();
}

void VerkeersRegelaar::voegScenarioToe(Scenario* s){ //Voeg een scenario toe aan de lijst scenariolijst
	scenariolijst->push_back(s);
}
