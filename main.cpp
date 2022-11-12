#include "mainwindow.h"
#include "ia.h"
#include "game.h"
#include "fin.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game g;
    g.show();
    //ia2 i;
    //i.show();
    //MainWindow w;
   // w.show();
    return a.exec();
}
