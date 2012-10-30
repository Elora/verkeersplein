#ifndef HOOFDSCHERM_H
#define HOOFDSCHERM_H

#include <QMainWindow>
#include "communicatiebeheerder.h"

namespace Ui {
class HoofdScherm;
}

class HoofdScherm : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit HoofdScherm(QWidget *parent = 0);
    ~HoofdScherm();

public slots:
    void zetGroenTijd();
    void zetRoodTijd();
    void zetOranjeTijd();
    void zetKnipperTijd();
    void zetNachtstandAan();
    void zetNachtstandUit();

private:
    Ui::HoofdScherm *ui;
    CommunicatieBeheerder* communicatiebeheerder;
};

#endif // HOOFDSCHERM_H
