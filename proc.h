#ifndef PROC_H
#define PROC_H

#include <fstream>
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <iostream>
#include <QMessageBox>

struct mange
{
    int xd,yd,xa,ya;
};
struct mov
{
    int xd,yd,xa,ya;
};

typedef struct
{
    bool bgRED;
    QPushButton *btn;
}piasa;

struct pion
{
    int x,y;
    int tr=0;
};

class proc
{
public:
    proc();
    int pieceblanc(QPushButton*);
    void permuter(QPushButton*,QPushButton*);
    void eat(QPushButton*,QPushButton*,int,int,int,int);
    void peutJouer(int,int);
    int peutJouerfunc(int,int);
    int possible(int ,int ,int ,int );
    int cheminPlein(int ,int ,int ,int );
    int pion2step(int,int);
    void clearETOIL();
    bool echecKingBlanc(int&,int&,int&,int&);
    bool echecKingNoir(int&,int&,int&,int&);
    bool echecKingBlancap(int,int,int&,int&);
    bool echecKingNoirap(int,int,int&,int&);
    int runKing(int,int);
    bool partienull();
    void inctr();
    int annulEcheck(int,int);
    int annulEcheckA(int,int,int,int);
    int echecTotal(int,int,int,int);
    int finPartie(int);
    bool echecKingBalncApresMove(int,int,int,int);
    bool echecKingNoirApresMove(int,int,int,int);
    int noteataftermove(int,int,int,int);
    int eatadverseaftermove2(int,int,int,int);
    int protectqueenaftermove(int,int,int,int);
    int makekingincheck(int,int,int,int);
    void save();
    void load();
    bool tourRB=false;
    bool tourRN=false;
    bool tourLB=false;
    bool tourLN=false;
    bool rockB=false;
    bool rockN=false;
    bool kingB=false;
    bool kingN=false;
protected:
    piasa tpiece[8][8];
    int t[8][8];
    pion tp[16];
    int n=0;

    int cp=0,tur=0,mek=0,ak=0,k=0,xs,ys;
    bool Pmange,peps=false,rlb=false,rln=false,rrb=false,rrn=false,ap2s=false,maxpb=false,maxpn=false;
    int xd,yd,xa,ya;
    QPushButton *butt,*but2,*but;
    QPushButton *buut1,*buut2,*buut3,*buut4,*buut5,*buut6,*buut7,*buut8;

    int cp2,L,i,j;
    int xk,yk;
    int mode;
};

#endif // PROC_H
