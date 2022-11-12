/********************************************************************************
** Form generated from reading UI file 'fin.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIN_H
#define UI_FIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_fin
{
public:
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QDialog *fin)
    {
        if (fin->objectName().isEmpty())
            fin->setObjectName(QString::fromUtf8("fin"));
        fin->resize(753, 465);
        button1 = new QPushButton(fin);
        button1->setObjectName(QString::fromUtf8("button1"));
        button1->setGeometry(QRect(60, 330, 151, 101));
        button2 = new QPushButton(fin);
        button2->setObjectName(QString::fromUtf8("button2"));
        button2->setGeometry(QRect(310, 330, 151, 101));
        button3 = new QPushButton(fin);
        button3->setObjectName(QString::fromUtf8("button3"));
        button3->setGeometry(QRect(560, 330, 151, 101));
        textEdit = new QTextEdit(fin);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(140, 160, 471, 121));
        QFont font;
        font.setPointSize(60);
        textEdit->setFont(font);
        label = new QLabel(fin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -20, 791, 541));
        label->raise();
        button1->raise();
        button2->raise();
        button3->raise();
        textEdit->raise();

        retranslateUi(fin);

        QMetaObject::connectSlotsByName(fin);
    } // setupUi

    void retranslateUi(QDialog *fin)
    {
        fin->setWindowTitle(QCoreApplication::translate("fin", "END", nullptr));
        button1->setText(QCoreApplication::translate("fin", "REPLAY", nullptr));
        button2->setText(QCoreApplication::translate("fin", "MENU", nullptr));
        button3->setText(QCoreApplication::translate("fin", "QUITTER", nullptr));
        label->setText(QCoreApplication::translate("fin", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fin: public Ui_fin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIN_H
