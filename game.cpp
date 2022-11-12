#include "game.h"
#include "ui_game.h"
#include <QMessageBox>
game::game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game)
{
    QString safe= "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}";
    ui->setupUi(this);
    QPixmap pix("C:/Users/msii/Desktop/JeuxDechec/images/bgrd");
    ui->CHESS->setGeometry(0,-150,900,700);
    ui->CHESS->setPixmap(pix);
    ui->button1->setStyleSheet("background-color: #1e3799; color: black;");
    ui->button2->setStyleSheet("background-color: #1e3799; color: black;");
    ui->button2_2->setStyleSheet("background-color: #1e3799; color: black;");
    ui->buttonh->setStyleSheet("background-color: #1e3799; color: black;");
    ui->button3->setStyleSheet("background-color: #1e3799; color: black;");
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->reset();
    ui->progressBar->setStyleSheet(safe);
}

game::~game()
{
    delete ui;
}

void game::on_button3_clicked()
{
    exit(EXIT_FAILURE);
}

void game::on_button1_clicked()
{
    MainWindow *m;
    m=new MainWindow(this);
    for(int i=0;i<=100;i++)
    {
        ui->progressBar->setValue(i);
        QThread::msleep(25);
    }
    m->show();
    hide();
    ui->progressBar->reset();
}

void game::on_button2_clicked()
{
    ia *i;
    i=new ia(this);
    for(int i=0;i<=100;i++)
    {
        ui->progressBar->setValue(i);
        QThread::msleep(25);
    }
    hide();
    i->show();
    ui->progressBar->reset();
}

void game::on_button2_2_clicked()
{
    ia2 *i2;
    i2=new ia2(this);
    for(int i=0;i<=100;i++)
    {
        ui->progressBar->setValue(i);
        QThread::msleep(25);
    }
    hide();
    i2->show();
    ui->progressBar->reset();
}

void game::on_buttonh_clicked()
{
    help *h;
    h=new help(this);
    hide();
    h->show();
}

