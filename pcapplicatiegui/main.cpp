#include <QtGui/QApplication>
#include "hoofdscherm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HoofdScherm w;
    w.show();
    
    return a.exec();
}
