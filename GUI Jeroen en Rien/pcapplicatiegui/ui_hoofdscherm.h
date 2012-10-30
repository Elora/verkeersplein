/********************************************************************************
** Form generated from reading UI file 'hoofdscherm.ui'
**
** Created: Fri Oct 19 12:39:55 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOOFDSCHERM_H
#define UI_HOOFDSCHERM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HoofdScherm
{
public:
    QWidget *centralWidget;
    QSpinBox *spinBox;
    QPushButton *groenButton;
    QPushButton *roodButton;
    QPushButton *oranjeButton;
    QPushButton *knipperButton;
    QPushButton *nachtAanButton;
    QPushButton *nachtUitButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextBrowser *infoLog;
    QLabel *label_4;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HoofdScherm)
    {
        if (HoofdScherm->objectName().isEmpty())
            HoofdScherm->setObjectName(QString::fromUtf8("HoofdScherm"));
        HoofdScherm->resize(699, 308);
        centralWidget = new QWidget(HoofdScherm);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(40, 80, 71, 41));
        groenButton = new QPushButton(centralWidget);
        groenButton->setObjectName(QString::fromUtf8("groenButton"));
        groenButton->setGeometry(QRect(230, 60, 121, 41));
        roodButton = new QPushButton(centralWidget);
        roodButton->setObjectName(QString::fromUtf8("roodButton"));
        roodButton->setGeometry(QRect(230, 110, 121, 41));
        oranjeButton = new QPushButton(centralWidget);
        oranjeButton->setObjectName(QString::fromUtf8("oranjeButton"));
        oranjeButton->setGeometry(QRect(230, 160, 121, 41));
        knipperButton = new QPushButton(centralWidget);
        knipperButton->setObjectName(QString::fromUtf8("knipperButton"));
        knipperButton->setGeometry(QRect(230, 210, 121, 41));
        nachtAanButton = new QPushButton(centralWidget);
        nachtAanButton->setObjectName(QString::fromUtf8("nachtAanButton"));
        nachtAanButton->setGeometry(QRect(440, 110, 151, 41));
        nachtUitButton = new QPushButton(centralWidget);
        nachtUitButton->setObjectName(QString::fromUtf8("nachtUitButton"));
        nachtUitButton->setGeometry(QRect(440, 160, 151, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(450, 10, 151, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 20, 121, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 20, 91, 16));
        infoLog = new QTextBrowser(centralWidget);
        infoLog->setObjectName(QString::fromUtf8("infoLog"));
        infoLog->setGeometry(QRect(10, 160, 211, 91));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 140, 62, 17));
        HoofdScherm->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HoofdScherm);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 699, 23));
        HoofdScherm->setMenuBar(menuBar);
        statusBar = new QStatusBar(HoofdScherm);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        HoofdScherm->setStatusBar(statusBar);

        retranslateUi(HoofdScherm);

        QMetaObject::connectSlotsByName(HoofdScherm);
    } // setupUi

    void retranslateUi(QMainWindow *HoofdScherm)
    {
        HoofdScherm->setWindowTitle(QApplication::translate("HoofdScherm", "HoofdScherm", 0, QApplication::UnicodeUTF8));
        groenButton->setText(QApplication::translate("HoofdScherm", "Zet groene tijd", 0, QApplication::UnicodeUTF8));
        roodButton->setText(QApplication::translate("HoofdScherm", "Zet rode tijd", 0, QApplication::UnicodeUTF8));
        oranjeButton->setText(QApplication::translate("HoofdScherm", "Zet oranje tijd", 0, QApplication::UnicodeUTF8));
        knipperButton->setText(QApplication::translate("HoofdScherm", "Zet knippertijd", 0, QApplication::UnicodeUTF8));
        nachtAanButton->setText(QApplication::translate("HoofdScherm", "Zet nachtstand aan", 0, QApplication::UnicodeUTF8));
        nachtUitButton->setText(QApplication::translate("HoofdScherm", "Zet nachtstand uit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HoofdScherm", "Zet de nachtstand aan of uit", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("HoofdScherm", "Pas de tijden aan", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HoofdScherm", "Aantal seconden", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("HoofdScherm", "Log", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HoofdScherm: public Ui_HoofdScherm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOOFDSCHERM_H
