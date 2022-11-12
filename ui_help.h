/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_help
{
public:
    QTextBrowser *texthelp;
    QPushButton *BACK;

    void setupUi(QDialog *help)
    {
        if (help->objectName().isEmpty())
            help->setObjectName(QString::fromUtf8("help"));
        help->resize(625, 725);
        texthelp = new QTextBrowser(help);
        texthelp->setObjectName(QString::fromUtf8("texthelp"));
        texthelp->setGeometry(QRect(0, 0, 621, 661));
        BACK = new QPushButton(help);
        BACK->setObjectName(QString::fromUtf8("BACK"));
        BACK->setGeometry(QRect(240, 670, 141, 61));

        retranslateUi(help);

        QMetaObject::connectSlotsByName(help);
    } // setupUi

    void retranslateUi(QDialog *help)
    {
        help->setWindowTitle(QCoreApplication::translate("help", "HELP", nullptr));
        BACK->setText(QCoreApplication::translate("help", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class help: public Ui_help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
