/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QLabel *CHESS;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QProgressBar *progressBar;
    QPushButton *button2_2;
    QPushButton *buttonh;

    void setupUi(QDialog *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QString::fromUtf8("game"));
        game->resize(760, 423);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../AdobeStock_364059453.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        game->setWindowIcon(icon);
        CHESS = new QLabel(game);
        CHESS->setObjectName(QString::fromUtf8("CHESS"));
        CHESS->setGeometry(QRect(10, 10, 1251, 571));
        button1 = new QPushButton(game);
        button1->setObjectName(QString::fromUtf8("button1"));
        button1->setGeometry(QRect(90, 260, 101, 51));
        QFont font;
        font.setPointSize(14);
        button1->setFont(font);
        button2 = new QPushButton(game);
        button2->setObjectName(QString::fromUtf8("button2"));
        button2->setGeometry(QRect(230, 260, 101, 51));
        button2->setFont(font);
        button3 = new QPushButton(game);
        button3->setObjectName(QString::fromUtf8("button3"));
        button3->setGeometry(QRect(520, 260, 101, 51));
        button3->setFont(font);
        progressBar = new QProgressBar(game);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(40, 330, 671, 21));
        progressBar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-bottom-color: rgb(0, 0, 255);"));
        progressBar->setValue(24);
        button2_2 = new QPushButton(game);
        button2_2->setObjectName(QString::fromUtf8("button2_2"));
        button2_2->setGeometry(QRect(380, 260, 101, 51));
        button2_2->setFont(font);
        buttonh = new QPushButton(game);
        buttonh->setObjectName(QString::fromUtf8("buttonh"));
        buttonh->setGeometry(QRect(670, 368, 83, 41));

        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QDialog *game)
    {
        game->setWindowTitle(QCoreApplication::translate("game", "Dialog", nullptr));
        CHESS->setText(QString());
        button1->setText(QCoreApplication::translate("game", "1 v 1", nullptr));
        button2->setText(QCoreApplication::translate("game", "IA", nullptr));
        button3->setText(QCoreApplication::translate("game", "QUITTER", nullptr));
        button2_2->setText(QCoreApplication::translate("game", "IA 2", nullptr));
        buttonh->setText(QCoreApplication::translate("game", "HELP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
