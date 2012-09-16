#include <avr/io.h>
#include <avr/interrupt.h>
#include "voetgangerlicht.h"
#include "autolicht.h"
#include "list.c"

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

	//test
	ahl.lichtNaarGroen(); 
	ahl.lichtNaarRood();
	ahl.lichtNaarOranje();
	ahl.alleLichtenUit();

	//Rien test ;)
	//eerste lijst met lichten
	List<VoetgangerLicht> l1;
	l1.push_back(azl);
	if(l1.komtAlVoor(azr))
		ahl.lichtNaarRood();
	l1.push_back(azr);
	if(l1.komtAlVoor(azr))
		ahl.lichtNaarGroen();


	List<int> a;

	while(1) {
		PINE = PINE;
	}



}
