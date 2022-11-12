#ifndef IA_H
#define IA_H

#include "time.h"
#include "stdlib.h"
#include <QDialog>
#include "proc.h"
#include "game.h"
#include "fin.h"
#include <QThread>


namespace Ui {class ia;}

class ia : public QDialog,public proc
{
    Q_OBJECT

public:
    explicit ia(QWidget *parent = nullptr);
    ~ia();
    void analyseBoard(int&,int&,int&,int&);
    void inittab();
    void Possible1();
    void init_table();

private slots:
    void on_pushButton1_clicked();

private:
    Ui::ia *ui;
    mange tma[32];
    mov tmo[32];
    int nma=0,nmo=0;
};

#endif // IA_H
