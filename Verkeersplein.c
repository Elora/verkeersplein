#include <avr/io.h>
#include <avr/interrupt.h>
#include "voetgangerlicht.h"
#include "autolicht.h"
#include "list.c"
#include "verkeersregelaar.h"
#include "scenario.h"

// Definieer de adressen van PORTA t/m PORTD
#define ADRESPORTA 0x1B
#define ADRESPORTB 0x18
#define ADRESPORTC 0x15
#define ADRESPORTD 0x12

int main()
{
	//Stel onderstaande poorten in op Output en laad allemaal enen in
	DDRA=0xFF;
	DDRB=0xFF;
	DDRC=0xFF;
	PORTA=0xFF;
	PORTB=0xFF;
	PORTC=0xFF;

	// Aanmaken van de verschillende autolichtobjecten
	AutoLicht azl(0xFE, 0xFD, 0xFB, ADRESPORTB);
	AutoLicht azr(0xF7, 0xEF, 0xDF, ADRESPORTB);
	AutoLicht ahl(0xFE, 0xFD, 0xFB, ADRESPORTC);
	AutoLicht ahr(0xF7, 0xEF, 0xDF, ADRESPORTC);

	// Aanmaken van de verschillende voetgangerlichtobjecten
	VoetgangerLicht vhr(0xFE, 0xFD, ADRESPORTA);
	VoetgangerLicht vz(0xBF, 0x7F, ADRESPORTB);
	VoetgangerLicht vhl(0xBF, 0x7F, ADRESPORTC);

	List<AutoLicht*> a1;
	List<AutoLicht*> a2;
	List<AutoLicht*> al;
	List<AutoLicht*> aalles;
	List<VoetgangerLicht*> valles;
	List<VoetgangerLicht*> v;
	List<VoetgangerLicht*> vl;
	List<Scenario*> s;

	a1.push_back(&azl);
	a1.push_back(&azr);
	a2.push_back(&ahl);
	a2.push_back(&ahr);
	v.push_back(&vhr);
	v.push_back(&vz);
	v.push_back(&vhl);

	aalles.push_back(&azl);
	aalles.push_back(&azr);
	aalles.push_back(&ahl);
	aalles.push_back(&ahr);
	valles.push_back(&vhr);
	valles.push_back(&vz);
	valles.push_back(&vhl);
	
	Scenario s1(&v, &al);
	Scenario s2(&vl, &a1);
	Scenario s3(&vl, &a2);
	s.push_back(&s1);
	s.push_back(&s2);
	s.push_back(&s3);

	VerkeersRegelaar vr(&aalles, &valles, &s);
	vr.kiesFunctie();

	while(1) {
		PINE = PINE;
	}
}
