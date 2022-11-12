#include "ia2.h"
#include "ui_ia2.h"

ia2::ia2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ia2)
{
    ui->setupUi(this);
    ui->groupBox->setStyleSheet("background-color: #60a3bc;");
    ui->pushButton1->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/icondb"));
    ui->pushButton1->setStyleSheet("background-color: #3c6382;");
    ui->pushButton1->setIconSize(QSize(40,40));
    ui->pushButton1->setFixedSize(76,45);
    init_table();
    Possible1();
}

ia2::~ia2()
{
    delete ui;
}

void ia2::init_table()
{
    const  QSize btnsize = QSize(80,80);
    setFixedSize(625,785);

    int s=60;
    int r=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            tpiece[i][j].btn=new QPushButton(this);
            tpiece[i][j].btn->move(r,s);
            tpiece[i][j].btn->setFixedSize(btnsize);
            connect(tpiece[i][j].btn,&QPushButton::clicked,this,&ia2::Possible1);
            r+=78;
        }
        s+=78;
        r=0;
    }
    s+=20;
    r=0;
    buut1=new QPushButton(this);
    buut1->move(r,s);
    buut1->setFixedSize(btnsize);
    buut1->setStyleSheet("background-color: #60a3bc");
    connect(buut1,&QPushButton::clicked,this,&ia2::Possible1);
    r+=78;
    buut2=new QPushButton(this);
    buut2->move(r,s);
    buut2->setFixedSize(btnsize);
    buut2->setStyleSheet("background-color: #3c6382");
    connect(buut2,&QPushButton::clicked,this,&ia2::Possible1);
    r+=78;
    buut3=new QPushButton(this);
    buut3->move(r,s);
    buut3->setFixedSize(btnsize);
    buut3->setStyleSheet("background-color: #60a3bc");
    connect(buut3,&QPushButton::clicked,this,&ia2::Possible1);
    r+=78;
    buut4=new QPushButton(this);
    buut4->move(r,s);
    buut4->setFixedSize(btnsize);
    buut4->setStyleSheet("background-color: #3c6382");
    connect(buut4,&QPushButton::clicked,this,&ia2::Possible1);
    r+=78;
    buut5=new QPushButton(this);
    buut5->move(r,s);
    buut5->setFixedSize(btnsize);
    buut5->setStyleSheet("background-color: #60a3bc");
    connect(buut5,&QPushButton::clicked,this,&ia2::Possible1);
    r+=78;
    buut6=new QPushButton(this);
    buut6->move(r,s);
    buut6->setFixedSize(btnsize);
    buut6->setStyleSheet("background-color: #3c6382");
    connect(buut6,&QPushButton::clicked,this,&ia2::Possible1);
    r+=78;
    buut7=new QPushButton(this);
    buut7->move(r,s);
    buut7->setFixedSize(btnsize);
    buut7->setStyleSheet("background-color: #3c6382");
    connect(buut7,&QPushButton::clicked,this,&ia2::Possible1);
    r+=78;
    buut8=new QPushButton(this);
    buut8->move(r,s);
    buut8->setFixedSize(btnsize);
    buut8->setStyleSheet("background-color: #60a3bc");
    connect(buut8,&QPushButton::clicked,this,&ia2::Possible1);
    r+=78;

    buut1->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_queen"));////5
    buut1->setIconSize(QSize(90,90));
    buut2->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_knight"));/////3
    buut2->setIconSize(QSize(90,90));
    buut3->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_rook"));////2
    buut3->setIconSize(QSize(90,90));
    buut4->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_bishop"));/////4
    buut4->setIconSize(QSize(90,90));
    buut5->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/black_queen"));
    buut5->setIconSize(QSize(90,90));
    buut6->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/black_knight"));
    buut6->setIconSize(QSize(90,90));
    buut7->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/black_rook"));
    buut7->setIconSize(QSize(90,90));
    buut8->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/black_bishop"));
    buut8->setIconSize(QSize(90,90));

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(i%2==0)
            {
                if(j%2==0)
                {
                     tpiece[i][j].btn->setStyleSheet("background-color: #60a3bc");
                }
                else
                {
                    tpiece[i][j].btn->setStyleSheet("background-color: #3c6382");
                }
            }
            else
            {
                if(j%2==0)
                {
                     tpiece[i][j].btn->setStyleSheet("background-color: #3c6382");
                }
                else
                {
                    tpiece[i][j].btn->setStyleSheet("background-color: #60a3bc");
                }
            }
        }
    }

        for(int i=2;i<6;i++)
        {
            for(int j=0;j<8;j++)
            {
                t[i][j]=0;
            }
        }
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                tpiece[i][j].bgRED=false;
            }
        }
        for(int j=0;j<8;j++)
        {
                t[6][j]=-1;
                tpiece[6][j].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/black_pawn"));
                tpiece[6][j].btn->setIconSize(QSize(90,90));
                t[1][j]=1;
                //
                tpiece[1][j].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_pawn"));
                tpiece[1][j].btn->setIconSize(QSize(90,90));
        }
        t[7][0]=-2;
        tpiece[7][0].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/black_rook"));
        tpiece[7][0].btn->setIconSize(QSize(90,90));

        t[7][1]=-3;
        tpiece[7][1].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/black_knight"));
        tpiece[7][1].btn->setIconSize(QSize(90,90));

        t[7][2]=-4;
        tpiece[7][2].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/black_bishop"));
        tpiece[7][2].btn->setIconSize(QSize(90,90));

        t[7][3]=-5;
        tpiece[7][3].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/black_queen"));
        tpiece[7][3].btn->setIconSize(QSize(90,90));

        t[7][4]=-6;
        tpiece[7][4].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/black_king"));
        tpiece[7][4].btn->setIconSize(QSize(90,90));

        t[7][5]=-4;
        tpiece[7][5].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/black_bishop"));
        tpiece[7][5].btn->setIconSize(QSize(90,90));

        t[7][6]=-3;
        tpiece[7][6].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/black_knight"));
        tpiece[7][6].btn->setIconSize(QSize(90,90));

        t[7][7]=-2;
        tpiece[7][7].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/black_rook"));
        tpiece[7][7].btn->setIconSize(QSize(90,90));

        //    white one

        // white rook
        //t[0][0].imEXISTE=true;
        t[0][0]=2;
        tpiece[0][0].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_rook"));
        tpiece[0][0].btn->setIconSize(QSize(90,90));
        // white knight
        //t[0][1].imEXISTE=true;
        t[0][1]=3;
        tpiece[0][1].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_knight"));
        tpiece[0][1].btn->setIconSize(QSize(90,90));
        // black bishop
        //t[0][2].imEXISTE=true;
        t[0][2]=4;
        tpiece[0][2].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_bishop"));
        tpiece[0][2].btn->setIconSize(QSize(90,90));
        // black queen
        //t[0][3].imEXISTE=true;
        t[0][3]=5;
        tpiece[0][3].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_queen"));
        tpiece[0][3].btn->setIconSize(QSize(90,90));
        // black king
        //t[0][4].imEXISTE=true;
        t[0][4]=6;
        tpiece[0][4].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_king"));
        tpiece[0][4].btn->setIconSize(QSize(90,90));
        // black bishop
        //t[0][5].imEXISTE=true;
        t[0][5]=4;
        tpiece[0][5].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_bishop"));
        tpiece[0][5].btn->setIconSize(QSize(90,90));
        // black knight
        //t[0][6].imEXISTE=true;
        t[0][6]=3;
        tpiece[0][6].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_knight"));
        tpiece[0][6].btn->setIconSize(QSize(90,90));
        // black rook
        //t[0][7].imEXISTE=true;
        t[0][7]=2;
        tpiece[0][7].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_rook"));
        tpiece[0][7].btn->setIconSize(QSize(90,90));
        setFixedSize(625,685);
}

void ia2::inittab()
{
    for(int i=0;i<nma;i++)
    {
        tma[i].xd=0;tma[i].yd=0;tma[i].xa=0;tma[i].ya=0;
    }
    for(int j=0;j<nmo;j++)
    {
        tmo[j].xd=0;tmo[j].yd=0;tmo[j].xa=0;tmo[j].ya=0;
    }
    nmo=0;nma=0;
}
void ia2::analyseBoard(int &xd,int &yd,int &xa,int &ya)
{
    int xde=-1,yde=-1,xae=-1,yae=-1;
    inittab();
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(t[i][j]<0 and peutJouerfunc(i,j)==1)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(t[k][l]>0)
                        {
                            if((possible(i,j,k,l)==1) and (cheminPlein(i,j,k,l)==0) and noteataftermove(i,j,k,l)==1 and echecKingNoirApresMove(i,j,k,l)==0 and makekingincheck(i,j,k,l)==1)
                            {
                                xde=i;yde=j;xae=k;yae=l;
                            }
                            if((possible(i,j,k,l)==1) and (cheminPlein(i,j,k,l)==0) and (noteataftermove(i,j,k,l)==1 or eatadverseaftermove2(i,j,k,l)==1) and echecKingNoirApresMove(i,j,k,l)==0 and protectqueenaftermove(i,j,k,l)==1)
                            {
                                tma[nma].xd=i;tma[nma].yd=j;tma[nma].xa=k;tma[nma].ya=l;
                                nma++;
                            }
                            else if(((k==i-1)and(l==j+1))or((k==i-1)and(l==j-1)))
                            {
                                if((t[i][l]>0)and(i==3)and(t[k][l]==0)and(pion2step(i,l)==1)and(noteataftermove(i,j,k,l)==1 or eatadverseaftermove2(i,j,k,l)==1) and echecKingNoirApresMove(i,j,k,l)==0 and protectqueenaftermove(i,j,k,l)==1)
                                {
                                    tma[nma].xd=i;tma[nma].yd=j;tma[nma].xa=k;tma[nma].ya=l;
                                    nma++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(t[i][j]<0 and peutJouerfunc(i,j)==1)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if((possible(i,j,k,l)==1) and (cheminPlein(i,j,k,l)==0) and (noteataftermove(i,j,k,l)==1 and echecKingNoirApresMove(i,j,k,l)==0) and makekingincheck(i,j,k,l)==1)
                        {
                            xde=i;yde=j;xae=k;yae=l;
                        }
                        if(t[k][l]==0 and possible(i,j,k,l)==1 and cheminPlein(i,j,k,l)==0 and noteataftermove(i,j,k,l)==1 and echecKingNoirApresMove(i,j,k,l)==0 and protectqueenaftermove(i,j,k,l)==1)
                        {
                            tmo[nmo].xd=i;tmo[nmo].yd=j;tmo[nmo].xa=k;tmo[nmo].ya=l;
                            nmo++;
                        }
                    }
                }
            }
        }
    }
    if(xde==-1 && nma==0 && nmo==0)
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(t[i][j]<0 and peutJouerfunc(i,j)==1)
                {
                    for(int k=0;k<8;k++)
                    {
                        for(int l=0;l<8;l++)
                        {
                            if((possible(i,j,k,l)==1) and (cheminPlein(i,j,k,l)==0) and echecKingNoirApresMove(i,j,k,l)==0 and makekingincheck(i,j,k,l)==1)
                            {
                                xde=i;yde=j;xae=k;yae=l;
                            }
                            if(t[k][l]>0)
                            {
                                if((possible(i,j,k,l)==1) and (cheminPlein(i,j,k,l)==0) and echecKingNoirApresMove(i,j,k,l)==0)
                                {
                                    tma[nma].xd=i;tma[nma].yd=j;tma[nma].xa=k;tma[nma].ya=l;
                                    nma++;
                                }
                            }
                            else if(((k==i-1)and(l==j+1))or((k==i-1)and(l==j-1)))
                            {
                                if((t[i][l]>0)and(i==3)and(t[k][l]==0)and(pion2step(i,l)==1) and echecKingNoirApresMove(i,j,k,l)==0)
                                {
                                    tma[nma].xd=i;tma[nma].yd=j;tma[nma].xa=k;tma[nma].ya=l;
                                    nma++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(t[i][j]<0 and peutJouerfunc(i,j)==1)
                {
                    for(int k=0;k<8;k++)
                    {
                        for(int l=0;l<8;l++)
                        {
                            if((possible(i,j,k,l)==1) and (cheminPlein(i,j,k,l)==0)and (echecKingNoirApresMove(i,j,k,l)==0) and (makekingincheck(i,j,k,l)==1))
                            {
                                xde=i;yde=j;xae=k;yae=l;
                            }
                            if(t[k][l]==0 and possible(i,j,k,l)==1 and cheminPlein(i,j,k,l)==0 and echecKingNoirApresMove(i,j,k,l)==0)
                            {
                                tmo[nmo].xd=i;tmo[nmo].yd=j;tmo[nmo].xa=k;tmo[nmo].ya=l;
                                nmo++;
                            }
                        }
                    }
                }
            }
        }
    }
    if(xde!=-1)
    {
        xd=xde;yd=yde;xa=xae;ya=yae;
    }
    else if(nma!=0)
    {
        xd=tma[0].xd;yd=tma[0].yd;xa=tma[0].xa;ya=tma[0].ya;
        for(int i=1;i<nma;i++)
        {
            if(t[xa][ya]<t[tma[i].xa][tma[i].ya])
            {
                xd=tma[i].xd;yd=tma[i].yd;xa=tma[i].xa;ya=tma[i].ya;
            }
        }
    }
    else if(nmo!=0)
    {
            xd=tmo[0].xd;yd=tmo[0].yd;xa=tmo[0].xa;ya=tmo[0].ya;
            for(int i=1;i<nmo;i++)
            {
                if(t[xd][yd]<t[tmo[i].xd][tmo[i].yd])
                {
                    xd=tmo[i].xd;
                    yd=tmo[i].yd;
                    xa=tmo[i].xa;
                    ya=tmo[i].ya;
                }
            }
            cp2=0;
            for(int i=0;i<nmo;i++)
            {
                if(t[xd][yd]==t[tmo[i].xd][tmo[i].yd])
                {
                    cp2++;
                }
            }
            if(cp2!=0)
            {
                srand(time(NULL));
                L=rand()%cp2;
                while(t[xd][yd]!=t[tmo[L].xd][tmo[L].yd] and L>=0)
                {
                    L--;
                }
                if(L==-1)
                {
                    while(t[xd][yd]!=t[tmo[L].xd][tmo[L].yd] and L<nmo)
                    {
                        L++;
                    }
                }
                xd=tmo[L].xd;
                yd=tmo[L].yd;
                xa=tmo[L].xa;
                ya=tmo[L].ya;
            }
    }
}

void ia2::Possible1()
{
    QPushButton *butt1 =qobject_cast<QPushButton*>(sender());
    if(finPartie(tur)==0)
    {
        if(maxpb==true)
        {
            if(butt1==buut1)
            {
                t[xa][ya]=5;
                tpiece[xa][ya].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_queen"));
                tpiece[xa][ya].btn->setIconSize(QSize(90,90));
                maxpb=false;
                setFixedSize(625,685);
            }
            else if(butt1==buut2)
            {
                t[xa][ya]=3;
                tpiece[xa][ya].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_knight"));
                tpiece[xa][ya].btn->setIconSize(QSize(90,90));
                maxpb=false;
                setFixedSize(625,685);
            }
            else if(butt1==buut3)
            {
                t[xa][ya]=2;
                tpiece[xa][ya].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_rook"));
                tpiece[xa][ya].btn->setIconSize(QSize(90,90));
                maxpb=false;
                setFixedSize(625,685);
            }
            else if(butt1==buut4)
            {
                t[xa][ya]=4;
                tpiece[xa][ya].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/white_bishop"));
                tpiece[xa][ya].btn->setIconSize(QSize(90,90));
                maxpb=false;
                setFixedSize(625,685);
            }
        }
        else if(maxpn==true)
        {
            t[xa][ya]=-5;
            tpiece[xa][ya].btn->setIcon(QIcon("C:/Users/msii/Desktop/JeuxDechec/images/black_queen"));
            tpiece[xa][ya].btn->setIconSize(QSize(90,90));
            maxpn=false;
        }
        else
        {
             if(pieceblanc(butt1)!=2)
             {
                 for(int i=0;i<8;i++)
                 {
                     for(int j=0;j<8;j++)
                     {
                         if (butt1==tpiece[i][j].btn)
                         {
                             if(tpiece[i][j].bgRED==true)
                             {
                                 Pmange=true;
                                 but2=tpiece[i][j].btn;
                                 xa=i;ya=j;
                             }
                             else
                             {
                                 Pmange=false;
                             }
                         }
                     }
                 }
                 if(Pmange==true)
                 {
                     if(tur%2==0)
                     {
                         if(echecKingBlanc(xk,yk,xs,ys)==true)
                         {
                             if(annulEcheckA(xd,yd,xa,ya)==1)
                             {
                                 clearETOIL();
                                 eat(but,but2,xd,yd,xa,ya);
                                 tur++;
                                 inctr();
                                 QThread::msleep(25);
                                 analyseBoard(xd,yd,xa,ya);
                                 eat(tpiece[xd][yd].btn,tpiece[xa][ya].btn,xd,yd,xa,ya);
                                 tur++;
                                 inctr();
                             }
                         }
                         else
                         {
                             if(t[xd][yd]==6)
                             {
                                 if(echecKingBlancap(xa,ya,xs,ys)==false)
                                 {
                                     clearETOIL();
                                     eat(but,but2,xd,yd,xa,ya);
                                     tur++;
                                     inctr();
                                     QThread::msleep(25);
                                     analyseBoard(xd,yd,xa,ya);
                                     eat(tpiece[xd][yd].btn,tpiece[xa][ya].btn,xd,yd,xa,ya);
                                     tur++;
                                     inctr();
                                 }
                             }
                             else
                             {
                                 clearETOIL();
                                 eat(but,but2,xd,yd,xa,ya);
                                 tur++;
                                 inctr();
                                 QThread::msleep(25);
                                 analyseBoard(xd,yd,xa,ya);
                                 eat(tpiece[xd][yd].btn,tpiece[xa][ya].btn,xd,yd,xa,ya);
                                 tur++;
                                 inctr();
                             }
                         }
                     }
                     if(maxpb==true)
                     {
                        setFixedSize(625,785);
                     }
                 }
                 else
                 {
                     if(butt1==but and cp==1)
                     {
                         cp=0;
                         clearETOIL();
                     }
                     else
                     {
                         if(tur%2==0)
                         {
                             if(pieceblanc(butt1)==1)
                             {
                                 for(int i=0;i<8;i++)
                                 {
                                     for(int j=0;j<8;j++)
                                     {
                                         if (butt1==tpiece[i][j].btn and cp==0 )
                                         {
                                             if(echecKingBlanc(xk,yk,xs,ys)==1)
                                             {
                                                 if(annulEcheck(i,j)==1)
                                                 {
                                                     if(t[i][j]!=0)
                                                     {
                                                         cp=1;
                                                         but=butt1;
                                                         xd=i;yd=j;
                                                         peutJouer(i,j);
                                                     }
                                                 }
                                             }
                                             else
                                             {
                                                 if(t[i][j]==6 and runKing(i,j)==1)
                                                 {
                                                     if(t[i][j]!=0)
                                                     {
                                                         cp=1;
                                                         but=butt1;
                                                         xd=i;yd=j;
                                                         peutJouer(i,j);
                                                     }
                                                 }
                                                 else
                                                 {
                                                     if(t[i][j]!=0)
                                                     {
                                                         cp=1;
                                                         but=butt1;
                                                         xd=i;yd=j;
                                                         peutJouer(i,j);
                                                     }
                                                 }
                                             }
                                         }
                                         else if(butt1==tpiece[i][j].btn and cp==1)
                                         {
                                             if(echecKingBlanc(xk,yk,xs,ys)==1)
                                             {
                                                 if(annulEcheck(i,j)==1)
                                                 {
                                                     if(t[i][j]!=0)
                                                     {
                                                         cp=1;
                                                         clearETOIL();
                                                         but=butt1;
                                                         xd=i;yd=j;
                                                         peutJouer(i,j);
                                                     }
                                                 }
                                             }
                                             else
                                             {
                                                 if(t[i][j]==6 and runKing(i,j)==1)
                                                 {
                                                     if(t[i][j]!=0)
                                                     {
                                                          cp=1;
                                                          clearETOIL();
                                                          but=butt1;
                                                          xd=i;yd=j;
                                                          peutJouer(i,j);
                                                     }
                                                 }
                                                 else
                                                 {
                                                     if(t[i][j]!=0)
                                                     {
                                                         cp=1;
                                                          clearETOIL();
                                                          but=butt1;
                                                          xd=i;yd=j;
                                                          peutJouer(i,j);
                                                     }
                                                 }
                                             }
                                         }
                                     }
                                 }
                             }
                         }
                     }
                }
            }
        }
    }
    else
    {
        int e;
        if(echecKingBlanc(xk,yk,xs,ys)==1)
        {
            if(echecTotal(xk,yk,xs,ys)==1)
            {
                e=1;
            }
            else if(echecKingNoir(xk,yk,xs,ys)==1)
            {
                if(echecTotal(xk,yk,xs,ys)==1)
                {
                    e=2;
                }
            }
        }
        else if(echecKingNoir(xk,yk,xs,ys)==1)
        {
            if(echecTotal(xk,yk,xs,ys)==1)
            {
                e=2;
            }
        }
        fin *g;
        g=new fin(this,3,e);
        hide();
        g->show();
    }
}

void ia2::on_pushButton1_clicked()
{
    game *g;
    g=new game(this);
    hide();
    g->show();
}

