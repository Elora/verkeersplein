#include <avr/io.h>
#include <avr/interrupt.h>
#include "voetgangerlicht.h"
#include "autolicht.h"
#include "list.c"
#include "verkeersregelaar.h"
#include "scenario.h"
#include "sensor.h"

// Definieer de adressen van PORTA t/m PORTC voor output
#define ADRESPORTA 0x1B
#define ADRESPORTB 0x18
#define ADRESPORTC 0x15

//Definieer het adres van PIND voor input
#define ADRESPIND 0x10

//Sensoren definieren
Sensor svz(ADRESPIND, 0xFE);
Sensor svhr(ADRESPIND, 0xFD);
Sensor svhl(ADRESPIND, 0xFB);
Sensor start(ADRESPIND, 0xF7); //Start schakelaar
Sensor sahr(ADRESPIND, 0xEF);
Sensor sahl(ADRESPIND, 0xDF);
Sensor sazl(ADRESPIND, 0xBF);
Sensor sazr(ADRESPIND, 0x7F);

int main()
{
	//Stel onderstaande poorten in op Output en laad allemaal enen in
	DDRA=0xFF;
	DDRB=0xFF;
	DDRC=0xFF;
	DDRD=0x00;
	PORTA=0xFF;
	PORTB=0xFF;
	PORTC=0xFF;
	PIND=0xFF;

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

	VerkeersRegelaar vr(&s);
	vr.kiesFunctie();

	while(1) {
		PINE = PINE;
	}
}
