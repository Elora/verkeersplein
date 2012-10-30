#include "menu.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

Menu::Menu(CommunicatieBeheerder* c) : communicatiebeheerder(c) {

}

int Menu::toonHoofdMenu() {
    cout << "----------------\n";
    cout << "| Verkeersplein |\n";
    cout << "----------------\n";
    cout << "\nKies een van de volgende opties:\n";
    cout << "1. Tijden van verkeerslichten aanpassen\n";
    cout << "2. Nachtstand aan- of uitzetten\n";
    cout << "3. Exit\n\n";
    cout << "Ik kies: ";

    int keuze;
    cin >> keuze;

    while (keuze > 3 || keuze < 0) {
        cout << "\nFout: Kies een getal tussen de 1 en de 3\n\n";
        cout << "Ik kies: ";
        cin >> keuze;
    }

    switch (keuze) {
        case 1:
            tijdenAanpassen();
            break;
        case 2:
            nachtStandAanpassen();
            break;
        case 3:
            return 0;
            break;
        default:
            return 1;
            break;
    }

    return 1;
}

void Menu::nachtStandAanpassen() {
    cout << "\n-------------------------------\n";
    cout << "| Nachtstand aan- of uitzetten |";
    cout << "\n-------------------------------\n";
    cout << "\nKies hieronder of u de nachtstand aan of uit wilt zetten en druk op enter\n";
    cout << "1. Aan zetten\n";
    cout << "2. Uit zetten\n";
    cout << "3. Terug naar het vorige scherm\n";
    cout << "Ik kies: ";

    int keuze;
    char letter;
    cin >> keuze;

    while (keuze > 3 || keuze < 0) {
        cout << "\nFout: Kies een 1 of een 2\n\n";
        cout << "\nIk kies: ";
        cin >> keuze;
    }

    switch (keuze) {
        case 1:
            letter = 'a';
            communicatiebeheerder->rs232_putchar(letter);
            cout << "\n\nNachtstand is aangezet\n\n";
            cout << "Druk op een toets om terug te gaan naar het beginmenu.\n\n";
            getchar();
            getchar();
            break;
        case 2:
            letter = 'u';
            communicatiebeheerder->rs232_putchar(letter);
            cout << "\n\nNachtstand is uitgezet\n\n";
            cout << "Druk op een toets om terug te gaan naar het beginmenu.\n\n";
            getchar();
            getchar();
            break;
        case 3:
            //Terug naar vorig scherm
        default:
            //doe niks
            break;
    }

}


void Menu::tijdenAanpassen() {
    cout << "\n---------------------------------------\n";
    cout << "| Tijden van verkeerslichten aanpassen |\n";
    cout << "---------------------------------------\n";
    cout << "\nKies een van de volgende opties:\n";
    cout << "1. Tijd van groene licht\n";
    cout << "2. Tijd van oranje licht\n";
    cout << "3. Tijd van rode licht\n";
    cout << "4. De knippertijd bij de nachtstand\n";
    cout << "5. Keer terug naar beginmenu\n\n";
    cout << "Ik kies: ";

    int keuze;
    cin >> keuze;

    while (keuze > 5 || keuze < 0) {
        cout << "\nFout: Kies een getal tussen de 1 en de 5\n\n";
        cout << "Ik kies: ";
        cin >> keuze;
    }

    switch (keuze) {
        case 1:
            pasGroenAan();
            break;
        case 2:
            pasOranjeAan();
            break;
        case 3:
            pasRoodAan();
            break;
        case 4:
            pasKnippertijdAan();
            break;
        case 5:
            //Terug naar beginscherm
        default:
            //doe niks
            break;
    }
}

void Menu::pasKnippertijdAan() {
    cout << "\n\n----------------------------------------------------\n";
    cout << "| De knippertijd van de nachtstand aanpassen |\n";
    cout << "----------------------------------------------------\n";
    cout << "\nVul de nieuwe tijd in in secondes en druk op enter.\n\n";
    cout << "De nieuwe waarde moet zijn: ";

    int waarde;
    char letter;
    cin >> waarde;
    letter = 'n';


    cout << "\n\n";
    communicatiebeheerder->rs232_putchar(letter);
    communicatiebeheerder->rs232_putchar(waarde);
    cout << "De knippertijd van de nachtstand is aangepast naar " << waarde << " seconden.\n";
    cout << "Druk op een toets om terug te gaan naar het beginmenu.\n\n";
    getchar();
    getchar();
}

void Menu::pasRoodAan() {
    cout << "\n\n---------------------------------------\n";
    cout << "| De tijd van het rode licht aanpassen |\n";
    cout << "---------------------------------------\n";
    cout << "\nVul de nieuwe tijd in in secondes en druk op enter.\n\n";
    cout << "De nieuwe waarde moet zijn: ";

    int waarde;
    char letter;
    cin >> waarde;

    letter = 'r';

    cout << "\n\n";
    communicatiebeheerder->rs232_putchar(letter);
    communicatiebeheerder->rs232_putchar(waarde);
    cout << "De tijd van het rode licht is aangepast naar " << waarde << " seconden.\n";
    cout << "Druk op een toets om terug te gaan naar het beginmenu.\n\n";
    getchar();
    getchar();
}

void Menu::pasOranjeAan() {
    cout << "\n\n-----------------------------------------\n";
    cout << "| De tijd van het oranje licht aanpassen |\n";
    cout << "-----------------------------------------\n";
    cout << "\nVul de nieuwe tijd in in secondes en druk op enter.\n\n";
    cout << "De nieuwe waarde moet zijn: ";

    int waarde;
    char letter;
    cin >> waarde;

    letter = 'o';

    cout << "\n\n";
    communicatiebeheerder->rs232_putchar(letter);
    communicatiebeheerder->rs232_putchar(waarde);
    cout << "De tijd van het oranje licht is aangepast naar " << waarde << " seconden.\n";
    cout << "Druk op een toets om terug te gaan naar het beginmenu.\n\n";
    getchar();
    getchar();
}

void Menu::pasGroenAan() {
    cout << "\n\n-----------------------------------------\n";
    cout << "| De tijd van het groene licht aanpassen |\n";
    cout << "-----------------------------------------\n";
    cout << "\nVul de nieuwe tijd in in secondes en druk op enter.\n\n";
    cout << "De nieuwe waarde moet zijn: ";

    int waarde;
    char letter;
    cin >> waarde;
    letter = 'g';

    cout << "\n\n";
    communicatiebeheerder->rs232_putchar(letter);
    communicatiebeheerder->rs232_putchar(waarde);
    cout << "De tijd van het groene licht is aangepast naar " << waarde << " seconden.\n";
    cout << "Druk op een toets om terug te gaan naar het beginmenu.\n\n";
    getchar();
    getchar();
}
