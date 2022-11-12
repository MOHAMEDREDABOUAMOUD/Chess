#include "fin.h"
#include "ui_fin.h"
#include <QColorDialog>
fin::fin(QWidget *parent,int mode,int e) :
    QDialog(parent),
    ui(new Ui::fin)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/msii/Desktop/JeuxDechec/images/bgrd");
    ui->label->setGeometry(0,0,900,500);
    ui->label->setPixmap(pix);
    ui->textEdit->setTextBackgroundColor("blue");
    if(e==1)
    {
        ui->textEdit->append("player 2 won");
        QMessageBox::information(0,"win","end game");
    }
    else
    {
        ui->textEdit->append("player 1 won");
        QMessageBox::information(0,"win","end game");
    }
    ui->button1->setStyleSheet("background-color: #1e3799; color: black;");
    ui->button2->setStyleSheet("background-color: #1e3799; color: black;");
    ui->button3->setStyleSheet("background-color: #1e3799; color: black;");
    m=mode;
}

fin::~fin()
{
    delete ui;
}

void fin::on_button1_clicked()
{
    if(m==1)
    {
        MainWindow *m;
        m=new MainWindow(this);
        hide();
        m->show();
    }
    else if(m==2)
    {
        ia *i;
        i=new ia(this);
        hide();
        i->show();
    }
    else if(m==3)
    {
        ia2 *i2;
        i2=new ia2(this);
        hide();
        i2->show();
    }
}


void fin::on_button2_clicked()
{
    game *g;
    g=new game(this);
    hide();
    g->show();
}


void fin::on_button3_clicked()
{
    exit(EXIT_FAILURE);
}
