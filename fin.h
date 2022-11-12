#ifndef FIN_H
#define FIN_H
#include "proc.h"
#include "ia.h"
#include "ia2.h"
#include "mainwindow.h"
#include "game.h"
#include <QDialog>

namespace Ui {
class fin;
}

class fin : public QDialog , public proc
{
    Q_OBJECT

public:
    explicit fin(QWidget *parent = nullptr,int mode=3,int e=1);
    ~fin();
private slots:

    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

private:
    Ui::fin *ui;
    int m;
};

#endif // FIN_H
