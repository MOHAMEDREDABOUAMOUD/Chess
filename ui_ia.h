/********************************************************************************
** Form generated from reading UI file 'ia.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IA_H
#define UI_IA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ia
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton1;
    QGroupBox *groupBox_2;
    QLabel *labeltour;
    QLabel *labelechec;

    void setupUi(QDialog *ia)
    {
        if (ia->objectName().isEmpty())
            ia->setObjectName(QString::fromUtf8("ia"));
        ia->resize(799, 464);
        groupBox = new QGroupBox(ia);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, -20, 801, 91));
        pushButton1 = new QPushButton(groupBox);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        pushButton1->setGeometry(QRect(80, 30, 71, 51));
        QFont font;
        font.setPointSize(14);
        pushButton1->setFont(font);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(200, 30, 411, 41));
        labeltour = new QLabel(groupBox_2);
        labeltour->setObjectName(QString::fromUtf8("labeltour"));
        labeltour->setGeometry(QRect(20, 10, 131, 21));
        QFont font1;
        font1.setPointSize(11);
        labeltour->setFont(font1);
        labelechec = new QLabel(groupBox_2);
        labelechec->setObjectName(QString::fromUtf8("labelechec"));
        labelechec->setGeometry(QRect(190, 10, 131, 21));
        QFont font2;
        font2.setPointSize(10);
        labelechec->setFont(font2);

        retranslateUi(ia);

        QMetaObject::connectSlotsByName(ia);
    } // setupUi

    void retranslateUi(QDialog *ia)
    {
        ia->setWindowTitle(QCoreApplication::translate("ia", "IA V1", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ia", "GroupBox", nullptr));
        pushButton1->setText(QString());
        groupBox_2->setTitle(QString());
        labeltour->setText(QCoreApplication::translate("ia", "Le Tour :", nullptr));
        labelechec->setText(QCoreApplication::translate("ia", "vide 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ia: public Ui_ia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IA_H
