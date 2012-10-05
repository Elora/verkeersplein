#include <avr/io.h>
#include <avr/interrupt.h>
#include "voetgangerlicht.h"
#include "autolicht.h"
#include "list.c"
#include "verkeersregelaar.h"
#include "scenario.h"
#include "sensor.h"
#include "wachtrijbeheerder.h"

// Definieer de adressen van PORTA t/m PORTC voor output
#define ADRESPORTA 0x1B
#define ADRESPORTB 0x18
#define ADRESPORTC 0x15

//Definieer het adres van PINE voor input
#define ADRESPINE 0x01

//Sensoren definieren
Sensor svz(ADRESPINE, 0xFE);
Sensor svhr(ADRESPINE, 0xFD);
Sensor svhl(ADRESPINE, 0xFB);
Sensor start(ADRESPINE, 0xF7); //Start schakelaar
Sensor sahr(ADRESPINE, 0xEF);
Sensor sahl(ADRESPINE, 0xDF);
Sensor sazl(ADRESPINE, 0xBF);
Sensor sazr(ADRESPINE, 0x7F);

//WachtrijBeheerder definieren en hem een lijst meegeven
List<Scenario*> wachtrij;
WachtrijBeheerder wachtrijbeheerder(&wachtrij);

ISR(TIMER0_OVF_vect) {
	if(svz.isGeactiveert() != false) {
		Scenario* scenario = svz.geefScenario();
		wachtrijbeheerder.voegToe(scenario);
	}
	if(svhr.isGeactiveert() != false) {
		Scenario* scenario = svhr.geefScenario();
		wachtrijbeheerder.voegToe(scenario);
	}
	if(svhl.isGeactiveert() != false) {
		Scenario* scenario = svhl.geefScenario();
		wachtrijbeheerder.voegToe(scenario);
	}
	if(sahr.isGeactiveert() != false) {
		Scenario* scenario = sahr.geefScenario();
		wachtrijbeheerder.voegToe(scenario);
	}
	if(sahl.isGeactiveert() != false) {
		Scenario* scenario = sahl.geefScenario();
		wachtrijbeheerder.voegToe(scenario);
	}
	if(sazl.isGeactiveert() != false) {
		Scenario* scenario = sazl.geefScenario();
		wachtrijbeheerder.voegToe(scenario);
	}
	if(sazr.isGeactiveert() != false) {
		Scenario* scenario = sazr.geefScenario();
		wachtrijbeheerder.voegToe(scenario);
	}
}

int main()
{
	//Stel onderstaande poorten in op Output en laad allemaal enen in
	DDRA=0xFF;
	DDRB=0xFF;
	DDRC=0xFF;
	PORTA=0xFF;
	PORTB=0xFF;
	PORTC=0xFF;

	//Stel de timer in die een interrupt genereert bij en overflow
	TCCR0=0x05;
	TIMSK=0x01;
	
	//Stel odnerstaande poorten in op Input en laad allemaal enen in
	DDRE=0x00;
	PINE=0xFF;

	// Aanmaken van de verschillende autolichtobjecten
	AutoLicht azl(0xFE, 0xFD, 0xFB, ADRESPORTB);
	AutoLicht azr(0xF7, 0xEF, 0xDF, ADRESPORTB);
	AutoLicht ahl(0xFE, 0xFD, 0xFB, ADRESPORTC);
	AutoLicht ahr(0xF7, 0xEF, 0xDF, ADRESPORTC);

	// Aanmaken van de verschillende voetgangerlichtobjecten
	VoetgangerLicht vhr(0xFE, 0xFD, ADRESPORTA);
	VoetgangerLicht vz(0xBF, 0x7F, ADRESPORTB);
	VoetgangerLicht vhl(0xBF, 0x7F, ADRESPORTC);

	//Testen van sensor
	//if(svz.isGeactiveert())
	//	vz.lichtNaarGroen();


	List<VoetgangerLicht*> l1, l2, l3;
	List<Scenario*> s;

	//Lijst l1 vullen
	l1.push_back(&azl);
	l1.push_back(&azr);

	//Lijst l2 vullen
	l2.push_back(&ahl);
	l2.push_back(&ahr);

	//Lijst l3 vullen
	l3.push_back(&vhr);
	l3.push_back(&vz);
	l3.push_back(&vhl);
	
	//Scenario's definieren
	Scenario s1(&l1);
	Scenario s2(&l2);
	Scenario s3(&l3);
	s.push_back(&s1);
	s.push_back(&s2);
	s.push_back(&s3);

	//Scenario's toekennen aan sensoren
	svz.kenScenarioToe(&s3);
	svhr.kenScenarioToe(&s3);
	svhl.kenScenarioToe(&s3);
	sahr.kenScenarioToe(&s2);
	sahl.kenScenarioToe(&s2);
	sazl.kenScenarioToe(&s1);
	sazr.kenScenarioToe(&s1);

	VerkeersRegelaar vr(&s, &wachtrijbeheerder);
	
	sei(); //Zet interrupts aan

	while(1) {
		vr.kiesFunctie();
	}
}
