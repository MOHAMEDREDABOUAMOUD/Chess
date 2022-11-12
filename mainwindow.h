#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "proc.h"
#include <QMainWindow>
#include "fin.h"
#include <game.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow,public proc
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init_table();
    void Possible();
private slots:
    void on_pushButton1_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
