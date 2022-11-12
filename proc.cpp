#include "proc.h"

proc::proc()
{

}
bool proc::echecKingBlanc(int& xk,int& yk,int& xs,int& ys)
{
    for(int i=0;i<=7;i++)
    {
        for(int j=0;j<=7;j++)
        {
            if(t[i][j]==6)
            {
                xk=i;
                yk=j;
                i=8;j=8;
            }
        }
    }
    bool echec=false;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(t[i][j]<0)
            {
                if((possible(i,j,xk,yk)==1)and(cheminPlein(i,j,xk,yk)==0))
                {
                    echec=true;xs=i;ys=j;
                    i=8;j=8;
                }
            }
        }
    }
    return echec;
}
bool proc::echecKingNoir(int& xk,int& yk,int& xs,int& ys)
{
    for(int i=0;i<=7;i++)
    {
        for(int j=0;j<=7;j++)
        {
            if(t[i][j]==-6)
            {
                xk=i;
                yk=j;
                i=8;j=8;
            }
        }
    }
    bool echec=false;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(t[i][j]>0)
            {
                if((possible(i,j,xk,yk)==1)and(cheminPlein(i,j,xk,yk)==0))
                {
                    echec=true;xs=i;ys=j;
                    i=8;j=8;
                }
            }
        }
    }
    return echec;
}

bool proc::echecKingBlancap(int xa,int ya,int &xs,int &ys)
{
    int xk,yk;
    echecKingBlanc(xk,yk,xs,ys);
    int val=t[xa][ya];
    t[xa][ya]=t[xk][yk];
    t[xk][yk]=0;
    bool echec=false;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(t[i][j]<0)
            {
                if((possible(i,j,xa,ya)==1)and(cheminPlein(i,j,xa,ya)==0))
                {
                    echec=true;
                    xs=i;ys=j;
                    i=8;j=8;
                }
            }
        }
    }
    t[xk][yk]=t[xa][ya];
    t[xa][ya]=val;
    return echec;
}
bool proc::echecKingNoirap(int xa,int ya,int &xs,int &ys)
{
    int xk,yk;
    echecKingNoir(xk,yk,xs,ys);
    int val=t[xa][ya];
    t[xa][ya]=t[xk][yk];
    t[xk][yk]=0;
    bool echec=false;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(t[i][j]>0)
            {
                if((possible(i,j,xa,ya)==1)and(cheminPlein(i,j,xa,ya)==0))
                {
                    echec=true;xs=i;ys=j;
                    i=8;j=8;
                }
            }
        }
    }
    t[xk][yk]=t[xa][ya];
    t[xa][ya]=val;
    return echec;
}

bool proc::partienull()
{
    int x,y,cp1=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(t[i][j]!=0)
            {
                cp1++;
                if((t[i][j]!=6)and(t[i][j]!=-6))
                {
                    x=i;y=j;
                }
            }
        }
    }
    if(cp1==2)
    {
        return true;
    }
    else if(cp1==3)
    {
        if((t[x][y]==4)or(t[x][y]==-4)or(t[x][y]==3)or(t[x][y]==-3))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(cp1>3)
    {
        int nB=0,nN=0;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(t[i][j]>0)
                {
                    nB++;
                }
                else if(t[i][j]<0)
                {
                    nN++;
                }
            }
        }
        int nBb=0,nNb=0;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if((t[i][j]>0)and(peutJouerfunc(i,j)==0))
                {
                    nBb++;
                }
                else if((t[i][j]<0)and(peutJouerfunc(i,j)==0))
                {
                    nNb++;
                }
            }
        }
        if((nB==nBb)or(nN==nNb))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int proc::runKing(int xd,int yd)
{
    int xk,yk,xs,ys;
    if(t[xd][yd]>0)
    {
        echecKingBlanc(xk,yk,xs,ys);
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(possible(xk,yk,i,j)==1 and cheminPlein(xk,yk,i,j)==0 and echecKingBalncApresMove(xk,yk,i,j)==false) return 1;
            }
        }
        return 0;
    }
    else
    {
        echecKingNoir(xk,yk,xs,ys);
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(possible(xk,yk,i,j)==1 and cheminPlein(xk,yk,i,j)==0 and echecKingNoirApresMove(xk,yk,i,j)==false) return 1;
            }
        }
        return 0;
    }
}

int proc::pion2step(int x,int y)
{
    for(int i=0;i<n;i++)
    {
        if((tp[i].x==x)and(tp[i].y==y)and(tp[i].tr<=2)) return 1;
    }
    return 0;
}
void proc::peutJouer(int xd,int yd)
{
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if(possible(xd,yd,i,j)==1 and cheminPlein(xd,yd,i,j)==0)
            {
                tpiece[i][j].btn->setStyleSheet("background-color: red");
                tpiece[i][j].bgRED=true;
            }
        }
    }
}

int proc::peutJouerfunc(int xd,int yd)
{
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if(possible(xd,yd,i,j)==1 and cheminPlein(xd,yd,i,j)==0)
            {
                return 1;
            }
        }
    }
    return 0;
}

void proc::clearETOIL()
{
            for(int i=0;i<8;i++)
            {
                for(int j=0;j<8;j++)
                {
                    tpiece[i][j].bgRED=false;
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
}
int proc::possible(int xd,int yd,int xa,int ya)
{
    int xk,yk,xs,ys;
    if(t[xd][yd]==5 or t[xd][yd]==-5)
    {
        int a=abs(xa-xd);
        int b=abs(ya-yd);
        if(xa==xd or ya==yd or a==b)
        {
            if(t[xd][yd]==5)
            {
                if(t[xa][ya]<=0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if(t[xa][ya]>=0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }

        }
        else
        {
            return 0;
        }
    }
    else if((t[xd][yd]==6)or(t[xd][yd]==-6))
    {
        if(((xa==xd+1)and(ya==yd))or((xa==xd-1)and(ya==yd))or((ya==yd+1)and(xa==xd))or((ya==yd-1)and(xa==xd))or((xa==xd-1)and(ya==yd-1))or((xa==xd-1)and(ya==yd+1))or((xa==xd+1)and(ya==yd-1))or((xa==xd+1)and(ya==yd+1)))
        {
            if(t[xd][yd]==6)
            {
                if(t[xa][ya]<=0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if(t[xa][ya]>=0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        else if((xa==0) and (ya==1) and (tourLB==false) and (t[0][1]==0) and (t[0][2]==0) and (t[0][3]==0) and (kingB==false)and(echecKingBlanc(xk,yk,xs,ys)==false)and(echecKingBalncApresMove(xd,yd,xa,ya)==false))
        {
            rlb=true;
            return 1;
        }
        else if((xa==7) and (ya==1) and (tourLN==false) and (t[7][1]==0) and (t[7][2]==0) and (t[7][3]==0) and (kingN==false)and(echecKingNoir(xk,yk,xs,ys)==false)and(echecKingNoirApresMove(xd,yd,xa,ya)==false))
        {
            rln=true;
            return 1;
        }
        else if((xa==0) and (ya==6) and (tourRB==false) and (t[0][5]==0) and (t[0][6]==0) and (kingB==false)and(echecKingBlanc(xk,yk,xs,ys)==false)and(echecKingBalncApresMove(xd,yd,xa,ya)==false))
        {
            rrb=true;
            return 1;
        }
        else if((xa==7) and (ya==6) and (tourRN==false) and (t[7][5]==0) and (t[7][6]==0) and (kingN==false)and(echecKingNoir(xk,yk,xs,ys)==false)and(echecKingNoirApresMove(xd,yd,xa,ya)==false))
        {
            rrn=true;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(t[xd][yd]==4 or t[xd][yd]==-4)
    {
        int a=abs(xa-xd);
        int b=abs(ya-yd);
        if(a==b)
        {
            if(t[xd][yd]==4)
            {
                if(t[xa][ya]<=0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if(t[xa][ya]>=0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            return 0;
        }
    }
    else if(t[xd][yd]==3 or t[xd][yd]==-3)
    {
        if(((xa==xd+2)and(ya==yd+1))or((xa==xd+2)and(ya==yd-1))or((xa==xd-2)and(ya==yd+1))or((xa==xd-2)and(ya==yd-1))or((xa==xd+1)and(ya==yd+2))or((xa==xd+1)and(ya==yd-2))or((xa==xd-1)and(ya==yd+2))or((xa==xd-1)and(ya==yd-2)))
        {
            if(t[xd][yd]==3)
            {
                if(t[xa][ya]<=0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if(t[xa][ya]>=0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            return 0;
        }
    }
    else if(t[xd][yd]==2 or t[xd][yd]==-2)
    {
        if(xa==xd or ya==yd)
        {
            if(t[xd][yd]==2)
            {
                if(t[xa][ya]<=0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if(t[xa][ya]>=0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            return 0;
        }
    }
    else if(t[xd][yd]==1)
    {
        if(xd==1)
        {
            if(((xa==xd+1)and(ya==yd))or((xa==xd+2)and(ya==yd)))
            {
                if(t[xa][ya]==0)
                {
                    if(xa==xd+2)
                    {
                        ap2s=true;
                    }
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else if(((xa==xd+1)and(ya==yd+1))or((xa==xd+1)and(ya==yd-1)))
            {
                if(t[xa][ya]<0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if((xa==xd+1)and(ya==yd))
            {
                if(t[xa][ya]==0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else if(((xa==xd+1)and(ya==yd+1))or((xa==xd+1)and(ya==yd-1)))
            {
                if(t[xa][ya]<0)
                {
                    return 1;
                }
                else if((t[xd][ya]==-1)and(xd==4)and(t[xa][ya]==0))
                {
                    if(pion2step(xd,ya)==1)
                    {
                        peps=true;
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }
    else if(t[xd][yd]==-1)
    {
        if(xd==6)
        {
            if(((xa==xd-1)and(ya==yd))or((xa==xd-2)and(ya==yd)))
            {
                if(t[xa][ya]==0)
                {
                    if(xa==xd-2)
                    {
                        ap2s=true;
                    }
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else if(((xa==xd-1)and(ya==yd+1))or((xa==xd-1)and(ya==yd-1)))
            {
                if(t[xa][ya]>0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if((xa==xd-1)and(ya==yd))
            {
                if(t[xa][ya]==0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else if(((xa==xd-1)and(ya==yd+1))or((xa==xd-1)and(ya==yd-1)))
            {
                if(t[xa][ya]>0)
                {
                    return 1;
                }
                else if((t[xd][ya]==1)and(xd==3)and(t[xa][ya]==0))
                {
                        if(pion2step(xd,ya)==1)
                        {
                            peps=true;
                            return 1;
                        }
                        else
                        {
                           return 0;
                        }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }
}

int proc::cheminPlein(int xd,int yd,int xa,int ya)
{
    if(t[xd][yd]==5 or t[xd][yd]==-5)
    {
        if(abs(xa-xd)==abs(ya-yd))
        {
            if((xa<xd)and(ya>yd))
            {
                int a=abs(xa-xd)-1;
                for(int i=0;i<a;i++)
                {
                    xd--;yd++;
                    if(t[xd][yd]!=0) return 1;
                }
                return 0;
            }
            else if((xa>xd)and(ya<yd))
            {
                int a=abs(xa-xd)-1;
                for(int i=0;i<a;i++)
                {
                    xd++;yd--;
                    if(t[xd][yd]!=0) return 1;
                }
                return 0;
            }
            else if((xa>xd)and(ya>yd))
            {
                int a=abs(xa-xd)-1;
                for(int i=0;i<a;i++)
                {
                    xd++;yd++;
                    if(t[xd][yd]!=0) return 1;
                }
                return 0;
            }
            else if((xa<xd)and(ya<yd))
            {
                int a=abs(xa-xd)-1;
                for(int i=0;i<a;i++)
                {
                    xd--;yd--;
                    if(t[xd][yd]!=0) return 1;
                }
                return 0;
            }
        }
        else
        {
            if(xa<xd)
            {
                for(int i=xa+1;i<xd;i++)
                {
                    if(t[i][ya]!=0)
                    {
                        return 1;
                    }
                }
            }
            else if(xa>xd)
            {
                for(int i=xd+1;i<xa;i++)
                {
                    if(t[i][ya]!=0)
                    {
                        return 1;
                    }
                }
            }
            else if(ya<yd)
            {
                for(int i=ya+1;i<yd;i++)
                {
                    if(t[xa][i]!=0)
                    {
                        return 1;
                    }
                }
            }
            else if(ya>yd)
            {
                for(int i=yd+1;i<ya;i++)
                {
                    if(t[xa][i]!=0)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    else if(t[xd][yd]==6 or t[xd][yd]==-6)
    {
        if((xa==0) and (ya==1) and (t[0][1]==0) and (t[0][2]==0) and (t[0][3]==0))
        {
            return 0;
        }
        else if((xa==7) and (ya==1) and (t[7][1]==0) and (t[7][2]==0) and (t[7][3]==0))
        {
            return 0;
        }
        else if((xa==0) and (ya==6) and (t[0][5]==0) and (t[0][6]==0))
        {
            return 0;
        }
        else if((xa==7) and (ya==6) and (t[7][5]==0) and (t[7][6]==0))
        {
            return 0;
        }
        else if(t[xd][yd]==6)
        {
            if(t[xa][ya]>0)
            {
                return 1;
            }
            else return 0;
        }
        else if(t[xd][yd]==-6)
        {
            if(t[xa][ya]<0)
            {
                return 1;
            }
            else return 0;
        }
        else
        {
            return 0;
        }
    }
    else if(t[xd][yd]==4 or t[xd][yd]==-4)
    {
        if(abs(xa-xd)==abs(ya-yd))
        {
            if((xa<xd)and(ya>yd))
            {
                int a=abs(xa-xd)-1;
                for(int i=0;i<a;i++)
                {
                    xd--;yd++;
                    if(t[xd][yd]!=0) return 1;
                }
                return 0;
            }
            else if((xa>xd)and(ya<yd))
            {
                int a=abs(xa-xd)-1;
                for(int i=0;i<a;i++)
                {
                    xd++;yd--;
                    if(t[xd][yd]!=0) return 1;
                }
                return 0;
            }
            else if((xa>xd)and(ya>yd))
            {
                int a=abs(xa-xd)-1;
                for(int i=0;i<a;i++)
                {
                    xd++;yd++;
                    if(t[xd][yd]!=0) return 1;
                }
                return 0;
            }
            else if((xa<xd)and(ya<yd))
            {
                int a=abs(xa-xd)-1;
                for(int i=0;i<a;i++)
                {
                    xd--;yd--;
                    if(t[xd][yd]!=0) return 1;
                }
                return 0;
            }
        }
    }
    else if(t[xd][yd]==3 or t[xd][yd]==-3)
    {
        return 0;
    }
    else if(t[xd][yd]==2 or t[xd][yd]==-2)
    {
        if(xa<xd)
        {
            for(int i=xa+1;i<xd;i++)
            {
                if(t[i][ya]!=0)
                {
                    return 1;
                }
            }
        }
        else if(xa>xd)
        {
            for(int i=xd+1;i<xa;i++)
            {
                if(t[i][ya]!=0)
                {
                    return 1;
                }
            }
        }
        else if(ya<yd)
        {
            for(int i=ya+1;i<yd;i++)
            {
                if(t[xa][i]!=0)
                {
                    return 1;
                }
            }
        }
        else if(ya>yd)
        {
            for(int i=yd+1;i<ya;i++)
            {
                if(t[xa][i]!=0)
                {
                    return 1;
                }
            }
        }
    }
    else if(t[xd][yd]==1)
    {
        if((ya==yd)and(xa==xd+1))
        {
            if(t[xa][ya]!=0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if((ya==yd)and(xa==xd+2))
        {
            if(t[xa][ya]!=0 or t[xd+1][ya]!=0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if((xa==xd+1)and((ya==yd+1)or(ya==yd-1)))
        {
            if(t[xa][ya]>0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else if(t[xd][yd]==-1)
    {
        if((ya==yd)and(xa==xd-1))
        {
            if(t[xa][ya]!=0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if((ya==yd)and(xa==xd-2))
        {
            if(t[xa][ya]!=0 or t[xd-1][ya]!=0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if((xa==xd-1)and((ya==yd+1)or(ya==yd-1)))
        {
            if(t[xa][ya]<0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
void proc::eat(QPushButton *but,QPushButton *but2,int xd,int yd,int xa,int ya)
{
    if((xa==xd+2)and(ya==yd)and(ap2s==true))
    {
        tp[n].x=xa;tp[n].y=ya;n++;ap2s=false;
    }
    if((xa==xd-2)and(ya==yd)and(ap2s==true))
    {
        tp[n].x=xa;tp[n].y=ya;n++;ap2s=false;
    }
    if(t[xd][yd]==1 and t[xd][ya]==-1 and t[xa][ya]==0 and peps==true)
    {
        t[xd][ya]=0;
        tpiece[xd][ya].btn->setIcon(QIcon());
        peps=false;
    }
    if(t[xd][yd]==-1 and t[xd][ya]==1 and t[xa][ya]==0 and peps==true)
    {
        t[xd][ya]=0;
        tpiece[xd][ya].btn->setIcon(QIcon());
        peps=false;
    }
    if(t[xd][yd]==6 and ya==yd-3 and rlb==true)
    {
        t[0][2]=2;
        tpiece[0][2].btn->setIcon(QIcon(tpiece[0][0].btn->icon()));
        t[0][0]=0;
        tpiece[0][0].btn->setIcon(QIcon());
        rlb=false;
        tourLB=true;rockB=true;kingB=true;
    }
    else
    {
        rlb=false;
    }
    if(t[xd][yd]==-6 and ya==yd-3 and rln==true)
    {
        t[7][2]=-2;
        tpiece[7][2].btn->setIcon(QIcon(tpiece[7][0].btn->icon()));
        t[7][0]=0;
        tpiece[7][0].btn->setIcon(QIcon());
        rln=false;
        tourLN=true;rockN=true;kingN=true;
    }
    else
    {
        rln=false;
    }
    if(t[xd][yd]==6 and ya==yd+2 and rrb==true)
    {
        t[0][5]=2;
        tpiece[0][5].btn->setIcon(QIcon(tpiece[0][7].btn->icon()));
        t[0][7]=0;
        tpiece[0][7].btn->setIcon(QIcon());
        rrb=false;
        tourRB=true;rockB=true;kingB=true;
    }
    else
    {
        rrb=false;
    }
    if(t[xd][yd]==-6 and ya==yd+2 and rrn==true)
    {
        t[7][5]=-2;
        tpiece[7][5].btn->setIcon(QIcon(tpiece[7][7].btn->icon()));
        t[7][7]=0;
        tpiece[7][7].btn->setIcon(QIcon());
        rrn=false;
        tourRN=true;rockN=true;kingN=true;
    }
    else
    {
        rrn=false;
    }
    if(t[xd][yd]==6) kingB=true;
    if(t[xd][yd]==-6) kingN=true;
    if((t[xd][yd]==2)and(yd==0)) tourLB=true;
    if((t[xd][yd]==2)and(yd==7)) tourRB=true;
    if((t[xd][yd]==-2)and(yd==0)) tourLN=true;
    if((t[xd][yd]==-2)and(yd==7)) tourRN=true;
    t[xa][ya]=t[xd][yd];
    t[xd][yd]=0;
    but2->setIcon(QIcon(but->icon()));
    but->setIcon(QIcon());
    but2->setIconSize(QSize(50,50));
    if(t[xa][ya]==1 and xa==7)
    {
        maxpb=true;
    }
    else if(t[xa][ya]==-1 and xa==0)
    {
        maxpn=true;
    }
}

int proc::pieceblanc(QPushButton *but)
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(but==tpiece[i][j].btn)
            {
                if(t[i][j]>0) return 1;
                else if(t[i][j]<0) return 3;
                else if(t[i][j]==0 and tpiece[i][j].bgRED==false) return 2;
                else return 0;
            }
        }
    }
}

void proc::inctr()
{
    for(int i=0;i<n;i++)
    {
        tp[i].tr++;
    }
}

int proc::annulEcheck(int xd,int yd)
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(possible(xd,yd,i,j)==1 and cheminPlein(xd,yd,i,j)==0)
            {
                if(t[xd][yd]>0)
                {
                    if(echecKingBalncApresMove(xd,yd,i,j)==false)
                    {
                        return 1;
                    }
                }
                else
                {
                    if(echecKingNoirApresMove(xd,yd,i,j)==false)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int proc::annulEcheckA(int xd,int yd,int xa,int ya)
{
    if(t[xd][yd]>0 and echecKingBalncApresMove(xd,yd,xa,ya)==false)
    {
        return 1;
    }
    else if(t[xd][yd]<0 and echecKingNoirApresMove(xd,yd,xa,ya)==false)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int proc::echecTotal(int xk,int yk,int xs,int ys)
{
    if(t[xk][yk]==6)
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(t[i][j]>0)
                {
                    if(annulEcheck(i,j)==1)
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
    else if(t[xk][yk]==-6)
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(t[i][j]<0)
                {
                    if(annulEcheck(i,j)==1)
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
}

int proc::finPartie(int i)
{
    if(i%2==0)
    {
        //////tester si le roi blanc est on echec
        int xk,yk,xs,ys;
        bool echec=echecKingBlanc(xk,yk,xs,ys);
        if(echec==true)
        {
            if(echecTotal(xk,yk,xs,ys)==0)
            {
                return 0;
            }
            else
            {
                //cout<<"fin partie !!!"<<endl<<"joueur 2 gagne";
                return 1;
            }
        }
        else if(partienull()==true)
        {
                //cout<<"fin partie !!!"<<endl<<"partie null";
                return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        //////tester si le roi noir est on echec
        int xk,yk,xs,ys;
        bool echec=echecKingNoir(xk,yk,xs,ys);
        if(echec==true)
        {
            if(echecTotal(xk,yk,xs,ys)==0)
            {
                return 0;
            }
            else
            {
                //cout<<"fin partie !!!"<<endl<<"joueur 1 gagne";
                return 1;
            }
        }
        else if(partienull()==true)
        {
            //cout<<"fin partie !!!"<<endl<<"partie null";
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

bool proc::echecKingBalncApresMove(int xd, int yd, int xa, int ya)
{
    int xk,yk,xs,ys;
    bool echec=false;
    int val=t[xa][ya];
    t[xa][ya]=t[xd][yd];
    t[xd][yd]=0;
    if(echecKingBlanc(xk,yk,xs,ys)==true)
    {
        echec=true;
    }
    t[xd][yd]=t[xa][ya];
    t[xa][ya]=val;
    return echec;
}

bool proc::echecKingNoirApresMove(int xd, int yd, int xa, int ya)
{
    int xk,yk,xs,ys;
    bool echec=false;
    int val=t[xa][ya];
    t[xa][ya]=t[xd][yd];
    t[xd][yd]=0;
    if(echecKingNoir(xk,yk,xs,ys)==true)
    {
        echec=true;
    }
    t[xd][yd]=t[xa][ya];
    t[xa][ya]=val;
    return echec;
}

int proc::noteataftermove(int xd,int yd,int xa,int ya)
{
    int val=t[xa][ya];
    t[xa][ya]=t[xd][yd];
    t[xd][yd]=0;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(t[i][j]>0)
            {
                if(possible(i,j,xa,ya)==1 and cheminPlein(i,j,xa,ya)==0)
                {
                    t[xd][yd]=t[xa][ya];
                    t[xa][ya]=val;
                    return 0;
                }
            }
        }
    }
    t[xd][yd]=t[xa][ya];
    t[xa][ya]=val;
    return 1;
}

int proc::eatadverseaftermove2(int xd,int yd,int xa,int ya)
{
    int val1=t[xa][ya];
    int val2=t[xd][yd];
    t[xa][ya]=t[xd][yd];
    t[xd][yd]=0;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(t[i][j]>0)
            {
                if(possible(i,j,xa,ya)==1 and cheminPlein(i,j,xa,ya)==0)
                {
                    t[xa][ya]=t[i][j];
                    t[i][j]=0;
                    for(int k=0;k<8;k++)
                    {
                        for(int l=0;l<8;l++)
                        {
                            if(t[k][l]<0)
                            {
                                if(possible(k,l,xa,ya)==1 and cheminPlein(k,l,xa,ya)==0)
                                {
                                    if(val2<=val1+t[xa][ya])
                                    {
                                        t[i][j]=t[xa][ya];
                                        t[xa][ya]=val1;
                                        t[xd][yd]=val2;
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                    t[i][j]=t[xa][ya];
                    t[xa][ya]=val1;
                    t[xd][yd]=val2;
                }
            }
        }
    }
    return 0;
}

int proc::protectqueenaftermove(int xd,int yd,int xa,int ya)
{
    int xq,yq;
    int val=t[xa][ya];
    t[xa][ya]=t[xd][yd];
    t[xd][yd]=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(t[i][j]==-5)
            {
                xq=i;yq=j;
            }
        }
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(t[i][j]>0)
            {
                if(possible(i,j,xq,yq)==1 and cheminPlein(i,j,xq,yq)==0)
                {
                    t[xd][yd]=t[xa][ya];
                    t[xa][ya]=val;
                    return 0;
                }
            }
        }
    }
    t[xd][yd]=t[xa][ya];
    t[xa][ya]=val;
    return 1;
}

int proc::makekingincheck(int xd,int yd,int xa,int ya)
{
    int xq,yq;
    int val=t[xa][ya];
    t[xa][ya]=t[xd][yd];
    t[xd][yd]=0;
    bool echecB=echecKingBlanc(xk,yk,xs,ys);
    t[xd][yd]=t[xa][ya];
    t[xa][ya]=val;
    if(echecB==true) return 1;
    else return 0;
}

void proc::save()
{
    std::ofstream f("data.txt",std::ios::out|std::ios::trunc);
    if(f.good())
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                f<<t[i][j];
                if(i!=7 || j!=7)
                {
                    f<<std::endl;
                }
            }
        }
        f.close();
    }
}
void proc::load()
{
    std::ifstream f("data.txt",std::ios::in);
    if(f.good())
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                f>>t[i][j];
            }
        }
        f.close();
    }
}
