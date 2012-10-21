#include "hoofdscherm.h"
#include "ui_hoofdscherm.h"

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
}

void HoofdScherm::zetRoodTijd() {
    int waarde;
    char letter = 'r';
    waarde = ui->spinBox->value();
    communicatiebeheerder->rs232_putchar(letter);
    communicatiebeheerder->rs232_putchar(waarde);
}

void HoofdScherm::zetOranjeTijd() {
    int waarde;
    char letter = 'o';
    waarde = ui->spinBox->value();
    communicatiebeheerder->rs232_putchar(letter);
    communicatiebeheerder->rs232_putchar(waarde);
}

void HoofdScherm::zetKnipperTijd() {
    int waarde;
    char letter = 'n';
    waarde = ui->spinBox->value();
    communicatiebeheerder->rs232_putchar(letter);
    communicatiebeheerder->rs232_putchar(waarde);
}

void HoofdScherm::zetNachtstandAan() {
    char letter = 'a';
    communicatiebeheerder->rs232_putchar(letter);
}

void HoofdScherm::zetNachtstandUit() {
    char letter = 'u';
    communicatiebeheerder->rs232_putchar(letter);
}
