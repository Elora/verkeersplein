/********************************************************************************
** Form generated from reading UI file 'hoofdscherm.ui'
**
** Created: Tue Oct 30 16:31:28 2012
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
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HoofdScherm
{
public:
    QWidget *centralWidget;
    QPushButton *groenButton;
    QPushButton *roodButton;
    QPushButton *oranjeButton;
    QPushButton *knipperButton;
    QPushButton *nachtAanButton;
    QPushButton *nachtUitButton;
    QLabel *label_2;
    QLabel *label_3;
    QTextBrowser *infoLog;
    QLabel *label_4;
    QFrame *frame;
    QSpinBox *spinBox;
    QFrame *frame_2;
    QLabel *label;

    void setupUi(QMainWindow *HoofdScherm)
    {
        if (HoofdScherm->objectName().isEmpty())
            HoofdScherm->setObjectName(QString::fromUtf8("HoofdScherm"));
        HoofdScherm->resize(699, 270);
        centralWidget = new QWidget(HoofdScherm);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groenButton = new QPushButton(centralWidget);
        groenButton->setObjectName(QString::fromUtf8("groenButton"));
        groenButton->setGeometry(QRect(240, 60, 121, 41));
        groenButton->setInputMethodHints(Qt::ImhNone);
        groenButton->setCheckable(false);
        roodButton = new QPushButton(centralWidget);
        roodButton->setObjectName(QString::fromUtf8("roodButton"));
        roodButton->setGeometry(QRect(240, 110, 121, 41));
        oranjeButton = new QPushButton(centralWidget);
        oranjeButton->setObjectName(QString::fromUtf8("oranjeButton"));
        oranjeButton->setGeometry(QRect(240, 160, 121, 41));
        knipperButton = new QPushButton(centralWidget);
        knipperButton->setObjectName(QString::fromUtf8("knipperButton"));
        knipperButton->setGeometry(QRect(240, 210, 121, 41));
        nachtAanButton = new QPushButton(centralWidget);
        nachtAanButton->setObjectName(QString::fromUtf8("nachtAanButton"));
        nachtAanButton->setGeometry(QRect(460, 130, 151, 41));
        nachtUitButton = new QPushButton(centralWidget);
        nachtUitButton->setObjectName(QString::fromUtf8("nachtUitButton"));
        nachtUitButton->setGeometry(QRect(460, 180, 151, 41));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 20, 121, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 20, 121, 16));
        infoLog = new QTextBrowser(centralWidget);
        infoLog->setObjectName(QString::fromUtf8("infoLog"));
        infoLog->setGeometry(QRect(20, 160, 211, 91));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 140, 62, 17));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 361, 251));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(80, 40, 71, 41));
        spinBox->setMinimum(1);
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(380, 10, 311, 251));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 0, 131, 31));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        HoofdScherm->setCentralWidget(centralWidget);
        frame_2->raise();
        frame->raise();
        groenButton->raise();
        roodButton->raise();
        oranjeButton->raise();
        knipperButton->raise();
        nachtAanButton->raise();
        nachtUitButton->raise();
        label_2->raise();
        label_3->raise();
        infoLog->raise();
        label_4->raise();

        retranslateUi(HoofdScherm);

        QMetaObject::connectSlotsByName(HoofdScherm);
    } // setupUi

    void retranslateUi(QMainWindow *HoofdScherm)
    {
        HoofdScherm->setWindowTitle(QApplication::translate("HoofdScherm", "Verkeersplein Configuratie Tool", 0, QApplication::UnicodeUTF8));
        groenButton->setText(QApplication::translate("HoofdScherm", "Zet groene tijd", 0, QApplication::UnicodeUTF8));
        roodButton->setText(QApplication::translate("HoofdScherm", "Zet rode tijd", 0, QApplication::UnicodeUTF8));
        oranjeButton->setText(QApplication::translate("HoofdScherm", "Zet oranje tijd", 0, QApplication::UnicodeUTF8));
        knipperButton->setText(QApplication::translate("HoofdScherm", "Zet knippertijd\n"
"nachtstand", 0, QApplication::UnicodeUTF8));
        nachtAanButton->setText(QApplication::translate("HoofdScherm", "Zet nachtstand aan", 0, QApplication::UnicodeUTF8));
        nachtUitButton->setText(QApplication::translate("HoofdScherm", "Zet nachtstand uit", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("HoofdScherm", "Pas de tijden aan", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HoofdScherm", "Aantal seconden", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("HoofdScherm", "Log", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HoofdScherm", "Wijzig nachtstand", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HoofdScherm: public Ui_HoofdScherm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOOFDSCHERM_H
