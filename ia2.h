#ifndef IA2_H
#define IA2_H

#include "time.h"
#include "stdlib.h"
#include <QDialog>
#include "proc.h"
#include "game.h"
#include "fin.h"
#include <QThread>

namespace Ui {
class ia2;
}

class ia2 : public QDialog,public proc
{
    Q_OBJECT

public:
    explicit ia2(QWidget *parent = nullptr);
    ~ia2();
    void analyseBoard(int&,int&,int&,int&);
    void inittab();
    void Possible1();
    void init_table();

private slots:
    void on_pushButton1_clicked();

private:
    Ui::ia2 *ui;
    mange tma[32];
    mov tmo[32];
    int nma=0,nmo=0;
};

#endif // IA2_H
