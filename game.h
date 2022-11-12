#ifndef GAME_H
#define GAME_H
#include "ia.h"
#include "ia2.h"
#include "help.h"
#include "mainwindow.h"
#include <QDialog>
#include <QProgressBar>
#include <QThread>
#include <QStandardItemModel>
//#include <QMediaPlayer>
//#include <QMediaPlaylist>

namespace Ui {
class game;
}

class game : public QDialog
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    ~game();

private slots:
    void on_button3_clicked();

    void on_button1_clicked();

    void on_button2_clicked();

    void on_button2_2_clicked();

    void on_buttonh_clicked();

private:
    Ui::game *ui;
    //QStandardItemModel  *m_playListModel;
};

#endif // GAME_H
