/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HVH
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButton1;
    QGroupBox *groupBox_2;
    QLabel *labeltour;
    QLabel *labelechec;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HVH)
    {
        if (HVH->objectName().isEmpty())
            HVH->setObjectName(QString::fromUtf8("HVH"));
        HVH->resize(800, 600);
        centralwidget = new QWidget(HVH);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
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
        HVH->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HVH);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        HVH->setMenuBar(menubar);
        statusbar = new QStatusBar(HVH);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HVH->setStatusBar(statusbar);

        retranslateUi(HVH);

        QMetaObject::connectSlotsByName(HVH);
    } // setupUi

    void retranslateUi(QMainWindow *HVH)
    {
        HVH->setWindowTitle(QCoreApplication::translate("HVH", "1 Vs 1", nullptr));
        groupBox->setTitle(QCoreApplication::translate("HVH", "GroupBox", nullptr));
        pushButton1->setText(QString());
        groupBox_2->setTitle(QString());
        labeltour->setText(QCoreApplication::translate("HVH", "Le Tour :", nullptr));
        labelechec->setText(QCoreApplication::translate("HVH", "vide 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HVH: public Ui_HVH {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
