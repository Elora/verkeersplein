#include "VerkeersRegelaar.h"
#include "avr/delay.h"

VerkeersRegelaar::VerkeersRegelaar(List<Scenario*>* s, WachtrijBeheerder* w, NachtWaarder* n) : scenariolijst(s), wachtrijbeheerder(w), nachtwaarder(n) {

} //In de constructor wordt een lijst met scenario's meegegeven, een wachtrijbeheerder en een nachtwaarder

void VerkeersRegelaar::doeNachtStand(){ //Deze functie voert de nachtstand uit

	while(nachtwaarder->krijgNacht() == true) //controleren of het nacht is
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
	}
	komtUitNachtStand();
}

void VerkeersRegelaar::komtUitNachtStand() { 	//Deze functie wordt aangeroepen bij de overgang van nacht naar dag
												//Alle scenario's worden eenmalig langsgelopen in hun vaste patroon
	for (int i = 1; scenariolijst->geefPositie(i) != 0; i++) { //Doorloop alle scenario's omstebeurt
		Scenario* scenario = scenariolijst->geefPositie(i);
		scenario->zetAllesNaarGroen(); 	//In het scenario alles naar groen zetten
		for(int n = 0; n < 15; n++)
			_delay_ms(5000);				//Een bepaalde tijd wachten
		scenario->zetAllesNaarRood();	//En alles weer naar rood laten gaan
		for(int n = 0; n < 10; n++)
			_delay_ms(5000);			//En 5 sec wachten voordat het volgende scenario op groen gaat
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
												//i wordt op 0 gezet ipv op 1 omdat aan het eind van de loop er eentje wordt opgeteld
		
		//Wanneer er iets in de wachtrij staat of wanneer het nacht is moet er uit deze functie gesprongen worden
		if((wachtrijbeheerder->geefEersteInWachtrij() != 0) || (nachtwaarder->krijgNacht() == true))
			return;
	}											
}

void VerkeersRegelaar::doeWachtrij() {

	while(wachtrijbeheerder->geefEersteInWachtrij() != 0) {  //Wanneer er iets in de wachtrij staat wordt de loop doorlopen
		Scenario* scenario = wachtrijbeheerder->geefEersteInWachtrij(); //Het eerste scenario uit de wachtrij wordt gegeven
		scenario->zetAllesNaarGroen(); 	//In het scenario alles naar groen zetten
		for(int n = 0; n < 15; n++)
			_delay_ms(5000);				//Een bepaalde tijd wachten
		scenario->zetAllesNaarRood();	//En alles weer naar rood laten gaan
		wachtrijbeheerder->haalEersteUitWachtrij(); //Het eerste scenario uit de wachtrij halen
		for(int n = 0; n < 10; n++)
			_delay_ms(5000);			//En 5 sec wachten voordat het volgende scenario op groen gaat
		
		if(nachtwaarder->krijgNacht() == true) //Checken of het onderhand nacht is, zo ja dan moet er uit de functie worden gesprongen
			return;
	}

}

void VerkeersRegelaar::kiesFunctie() {
	if (nachtwaarder->krijgNacht() == true)
		doeNachtStand();
	else if (wachtrijbeheerder->geefEersteInWachtrij() != 0)
		doeWachtrij();
	else
		doeStandaardSequentie();
}

void VerkeersRegelaar::voegScenarioToe(Scenario* s){ //Voeg een scenario toe aan de lijst scenariolijst
	scenariolijst->push_back(s);
}
