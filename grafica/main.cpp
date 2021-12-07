#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <math.h>
#define MAX 90

using namespace std;

char title[] = "bibMat - O biblioteca pentru efectuarea operatiilor cu matrice si vectori";
int inaltimeEcran=getmaxheight(), latimeEcran=getmaxwidth();

struct punct {
    int x, y;
};

struct buton
{
    char msj[MAX];
    int marime;
    int x,y;
    int x1,y1,x2,y2;
} butonMatrice, butonVectori;


void initButon(buton &b, char text[], int xx,int yy,int m);
void showButton(buton b);
bool isInside(int xx, int yy, int x1, int y1, int x2, int y2);
void showMainText(char text[]);
void showSecondaryText(char text[]);

void pagina1();
void init();

int main()
{
    init();
    pagina1();
    closegraph( );

}

void init()
{
    initwindow(latimeEcran, inaltimeEcran);
    initButon(butonMatrice, "Matrice", getmaxx()/2, 3.5*getmaxy()/9, 7);
    initButon(butonVectori, "Vectori", getmaxx()/2, 3*getmaxy()/5, 7);

}

void initButon(buton &b, char text[], int xx, int yy, int m)
{
    strcpy(b.msj,text);
    b.x = xx;
    b.y = yy;
    b.marime = m;
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, b.marime);
    b.x1 = xx - textwidth(b.msj)/2;
    b.y1 = yy - textheight(b.msj)/2;
    b.x2 = xx + textwidth(b.msj)/2;
    b.y2 = yy + textheight(b.msj)/2;
}

void showButton(buton b)
{
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, b.marime);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setbkcolor(COLOR(244, 158, 76));
    setcolor(BLACK);
    outtextxy((b.x1 + b.x2) / 2, (b.y1 + b.y2) / 2, b.msj);
}

bool isInside(int xx, int yy, int x1, int y1, int x2, int y2)
{
    return x1<=xx && xx<=x2 && y1<=yy && yy<=y2;
}

void showMainText(char text[])
{
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR, 4.5);
    setcolor(BLACK);
    settextjustify(LEFT_TEXT,TOP_TEXT);
    int a=(latimeEcran-textwidth(text))/2;
    int b=inaltimeEcran/9;
    outtextxy(a,b,&text[0]);
}

void showSecondaryText(char text[])
{
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR, 2);
    setcolor(BLACK);
    settextjustify(LEFT_TEXT,TOP_TEXT);
    int a=(latimeEcran-textwidth(text))/2;
    int b=inaltimeEcran/5;
    outtextxy(a,b,&text[0]);
}

void pagina1()
{
    cleardevice();
    setbkcolor(WHITE);
    cleardevice();
    showMainText(title);
    showSecondaryText("Cu ce doriti sa efectuati operatii?");
    showButton(butonMatrice);
    showButton(butonVectori);

    int ok=false;
    int x,y;
    while(ok==false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, butonMatrice.x1-1.5, butonMatrice.y1-12, butonMatrice.x2, butonMatrice.y2-12)==true) /// daca am apasat pe butonul de matrice
        {

            ok=true;
        }
        if(isInside(x, y, butonVectori.x1-1.5, butonVectori.y1-12, butonVectori.x2, butonVectori.y2-12)==true) /// daca am apasat pe butonul de vectori
        {
            ok=true;
        }
    }
}
