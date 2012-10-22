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
    communicatiebeheerder->rs232_putchar(letter);
    communicatiebeheerder->rs232_putchar(waarde);
    errorCheck();
}

void HoofdScherm::zetRoodTijd() {
    int waarde;
    char letter = 'r';
    waarde = ui->spinBox->value();
    communicatiebeheerder->rs232_putchar(letter);
    communicatiebeheerder->rs232_putchar(waarde);
    errorCheck();
}

void HoofdScherm::zetOranjeTijd() {
    int waarde;
    char letter = 'o';
    waarde = ui->spinBox->value();
    communicatiebeheerder->rs232_putchar(letter);
    communicatiebeheerder->rs232_putchar(waarde);
    errorCheck();
}

void HoofdScherm::zetKnipperTijd() {
    int waarde;
    char letter = 'n';
    waarde = ui->spinBox->value();
    communicatiebeheerder->rs232_putchar(letter);
    communicatiebeheerder->rs232_putchar(waarde);
    errorCheck();
}

void HoofdScherm::zetNachtstandAan() {
    char letter = 'a';
    communicatiebeheerder->rs232_putchar(letter);
    errorCheck();
}

void HoofdScherm::zetNachtstandUit() {
    char letter = 'u';
    communicatiebeheerder->rs232_putchar(letter);
    errorCheck();
}

void HoofdScherm::errorCheck(){
    char buffer[100];
    int limiet;
    int errorCode = communicatiebeheerder->rs232_getchar();
    cout<<"errocode: " << errorCode << endl;
    switch(errorCode) {
        case 1:
            limiet = communicatiebeheerder->rs232_getchar();
            sprintf(buffer, "Groen tijd te laag, minimale waarde: %d", limiet);
            ui->infoLog->append(buffer);
            break;
        case 2:
            limiet = communicatiebeheerder->rs232_getchar();
            sprintf(buffer, "Groen tijd te hoog, maximale waarde: %d", limiet);
            ui->infoLog->append(buffer);
            break;
        case 3:
            limiet = communicatiebeheerder->rs232_getchar();
            sprintf(buffer, "Oranje tijd te laag, minimale waarde: %d", limiet);
            ui->infoLog->append(buffer);
            break;
        case 4:
            limiet = communicatiebeheerder->rs232_getchar();
            sprintf(buffer, "Oranje tijd te hoog, maximale waarde: %d", limiet);
            ui->infoLog->append(buffer);
            break;
        case 5:
            limiet = communicatiebeheerder->rs232_getchar();
            sprintf(buffer, "Rood tijd te laag, minimale waarde: %d", limiet);
            ui->infoLog->append(buffer);
            break;
        case 6:
            limiet = communicatiebeheerder->rs232_getchar();
            sprintf(buffer, "Rood tijd te hoog, maximale waarde: %d", limiet);
            ui->infoLog->append(buffer);
            break;
        case 7:
            limiet = communicatiebeheerder->rs232_getchar();
            sprintf(buffer, "Knipper tijd te hoog, maximale waarde: %d", limiet);
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
