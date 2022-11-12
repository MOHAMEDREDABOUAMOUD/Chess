#ifndef HELP_H
#define HELP_H
#include "game.h"
#include <QDialog>

namespace Ui {
class help;
}

class help : public QDialog
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = nullptr);
    ~help();

private slots:
    void on_BACK_clicked();

private:
    Ui::help *ui;
};

#endif // HELP_H
