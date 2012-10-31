#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "hoofdscherm.h"
#include "ui_hoofdscherm.h"

using namespace std;

HoofdScherm::HoofdScherm(QWidget *parent) : QMainWindow(parent), ui(new Ui::HoofdScherm)
{
    ui->setupUi(this);
    communicatiebeheerder = new CommunicatieBeheerder();

    //Alle menuknoppen verbinden met de bijbehorende methodes
    connect(ui->groenButton,SIGNAL(clicked()),this,SLOT(zetGroenTijd()));
    connect(ui->roodButton,SIGNAL(clicked()),this,SLOT(zetRoodTijd()));
    connect(ui->oranjeButton,SIGNAL(clicked()),this,SLOT(zetOranjeTijd()));
    connect(ui->knipperButton,SIGNAL(clicked()),this,SLOT(zetKnipperTijd()));
    connect(ui->nachtAanButton,SIGNAL(clicked()),this,SLOT(zetNachtstandAan()));
    connect(ui->nachtUitButton,SIGNAL(clicked()),this,SLOT(zetNachtstandUit()));
}

HoofdScherm::~HoofdScherm()
{
    delete ui;
}

void HoofdScherm::zetGroenTijd() {
    int waarde;
    char letter = 'g';
    waarde = ui->spinBox->value();
    communicatiebeheerder->rs232_SchrijfChar(letter);
    communicatiebeheerder->rs232_SchrijfChar(waarde);
    errorCheck();
}

void HoofdScherm::zetRoodTijd() {
    int waarde;
    char letter = 'r';
    waarde = ui->spinBox->value();
    communicatiebeheerder->rs232_SchrijfChar(letter);
    communicatiebeheerder->rs232_SchrijfChar(waarde);
    errorCheck();
}

void HoofdScherm::zetOranjeTijd() {
    int waarde;
    char letter = 'o';
    waarde = ui->spinBox->value();
    communicatiebeheerder->rs232_SchrijfChar(letter);
    communicatiebeheerder->rs232_SchrijfChar(waarde);
    errorCheck();
}

void HoofdScherm::zetKnipperTijd() {
    int waarde;
    char letter = 'n';
    waarde = ui->spinBox->value();
    communicatiebeheerder->rs232_SchrijfChar(letter);
    communicatiebeheerder->rs232_SchrijfChar(waarde);
    errorCheck();
}

void HoofdScherm::zetNachtstandAan() {
    char letter = 'a';
    communicatiebeheerder->rs232_SchrijfChar(letter);
    errorCheck();
}

void HoofdScherm::zetNachtstandUit() {
    char letter = 'u';
    communicatiebeheerder->rs232_SchrijfChar(letter);
    errorCheck();
}

// errorCheck() begint met het lezen van een karakter
// Het karakter geeft een bepaalde status weer en de status
// wordt dan geprint in de text box.
void HoofdScherm::errorCheck(){
    char buffer[100];
    int tijd;
    int errorCode = communicatiebeheerder->rs232_KrijgChar();
    cout<<"errocode: " << errorCode << endl;
    switch(errorCode) {
        case 1:
            tijd = communicatiebeheerder->rs232_KrijgChar();
            sprintf(buffer, "Groen tijd te laag, minimale waarde: %d", tijd);
            ui->infoLog->append(buffer);
            break;
        case 2:
            tijd = communicatiebeheerder->rs232_KrijgChar();
            sprintf(buffer, "Groen tijd te hoog, maximale waarde: %d", tijd);
            ui->infoLog->append(buffer);
            break;
        case 3:
            tijd = communicatiebeheerder->rs232_KrijgChar();
            sprintf(buffer, "Oranje tijd te laag, minimale waarde: %d", tijd);
            ui->infoLog->append(buffer);
            break;
        case 4:
            tijd = communicatiebeheerder->rs232_KrijgChar();
            sprintf(buffer, "Oranje tijd te hoog, maximale waarde: %d", tijd);
            ui->infoLog->append(buffer);
            break;
        case 5:
            tijd = communicatiebeheerder->rs232_KrijgChar();
            sprintf(buffer, "Rood tijd te laag, minimale waarde: %d", tijd);
            ui->infoLog->append(buffer);
            break;
        case 6:
            tijd = communicatiebeheerder->rs232_KrijgChar();
            sprintf(buffer, "Rood tijd te hoog, maximale waarde: %d", tijd);
            ui->infoLog->append(buffer);
            break;
        case 7:
            tijd = communicatiebeheerder->rs232_KrijgChar();
            sprintf(buffer, "Knipper tijd te hoog, maximale waarde: %d", tijd);
            ui->infoLog->append(buffer);
            break;
        case 8:
            sprintf(buffer, "De nachtstand is aangezet");
            ui->infoLog->append(buffer);
            break;
        case 9:
            sprintf(buffer, "De nachtstand is uitgezet");
            ui->infoLog->append(buffer);
            break;
        default:
            ui->infoLog->append("Tijd succesvol opgeslagen");
            break;
    }
}
