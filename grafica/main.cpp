#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <math.h>
#include <fstream>
#define MAX 90
using namespace std;
ifstream fin("matrice.txt");

/// variabile Matrice
int mat1[4][4], mat2[4][4], mat3[4][4];

char title[] = "bibMat - O biblioteca pentru efectuarea operatiilor cu matrice si vectori";
int inaltimeEcran=getmaxheight(), latimeEcran=getmaxwidth();

struct punct
{
    int x, y;
};

struct buton
{
    char msj[MAX];
    int marime;
    int x,y;
    int x1,y1,x2,y2;
} butonMatrice, butonVectori, adunareM, scadereM, inmultireM, meniu;


void initButon(buton &b, char text[], int xx,int yy,int m);
void showButton(buton b);
bool isInside(int xx, int yy, int x1, int y1, int x2, int y2);
void showMainText(char text[]);
void showSecondaryText(char text[]);

void pagina1();
void paginaMatrice();
void paginaAdunareMat();
void paginaScadereMat();
void afisareMatrice(int mat[4][4], int x1, int y1, int i, int j);
void init();

int main()
{


    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            fin>>mat1[i][j];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            fin>>mat2[i][j];

    init();
    pagina1();
    closegraph( );

}

void init()
{
    initwindow(latimeEcran, inaltimeEcran, "bibMat");
    initButon(butonMatrice, "Matrice", getmaxx()/2, 4*getmaxy()/9, 7);
    initButon(butonVectori, "Vectori", getmaxx()/2, 3*getmaxy()/5, 7);
    initButon(adunareM, "Adunare", getmaxx()/2, 2*getmaxy()/5, 7);
    initButon(scadereM, "Scadere", getmaxx()/2, 3*getmaxy()/5, 7);
    initButon(inmultireM, "Inmultire", getmaxx()/2, 4*getmaxy()/5, 7);
    initButon(meniu, "Meniu", getmaxx(), 4*getmaxy()/5, 7);


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
            paginaMatrice();
            ok=true;
        }
        if(isInside(x, y, butonVectori.x1-1.5, butonVectori.y1-12, butonVectori.x2, butonVectori.y2-12)==true) /// daca am apasat pe butonul de vectori
        {
            ok=true;
        }
    }
}

void paginaMatrice()
{
    cleardevice();
    setbkcolor(WHITE);
    cleardevice();
    showMainText("Operatii cu matrice");
    showButton(adunareM);
    showButton(scadereM);
    showButton(inmultireM);
    int ok=false;
    int x,y;
    while(ok==false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, adunareM.x1-1.5, adunareM.y1-12, adunareM.x2, adunareM.y2-12)==true) /// daca am apasat pe butonul de adunare
        {
            paginaAdunareMat();
            ok=true;
        }
        if(isInside(x, y, scadereM.x1-1.5, scadereM.y1-12, scadereM.x2, scadereM.y2-12)==true) /// daca am apasat pe butonul de scadere
        {
            paginaScadereMat();
            ok=true;
        }
        if(isInside(x, y, inmultireM.x1-1.5, inmultireM.y1-12, inmultireM.x2, inmultireM.y2-12)==true) /// daca am apasat pe butonul de inmultire
        {
            ok=true;
        }
    }

}

void afisareMatrice(int mat[4][4], int x1, int y1, int ii, int jj)
{

    char str[50] = "";
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            if(i == ii && j == jj)
            {
                settextjustify(CENTER_TEXT, CENTER_TEXT);
                setcolor(WHITE);
                setbkcolor(COLOR(244, 158, 76));
                sprintf(str, "%d", mat[i][j]);
                outtextxy(i*80 + x1*150, j*80 + y1*150, str);
            }
            else
            {
                settextjustify(CENTER_TEXT, CENTER_TEXT);
                setcolor(BLACK);
                setbkcolor(COLOR(255, 255, 255));
                sprintf(str, "%d", mat[i][j]);
                outtextxy(i*80 + x1*150, j*80 + y1*150, str);
            }
        }
}

void paginaAdunareMat()
{
    cleardevice();
    setbkcolor(WHITE);
    cleardevice();
    showMainText("Adunare");
    while(1)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                mat3[i][j] = mat1[i][j] + mat2[i][j];

                afisareMatrice(mat3, 5, 3, i, j);
                afisareMatrice(mat1, 1, 2, i, j);
                afisareMatrice(mat2, 1, 4, i, j);

                delay(300);
            }
        }

    }

}

void paginaScadereMat()
{
    cleardevice();
    setbkcolor(WHITE);
    cleardevice();
    showMainText("Scadere");

    while(1)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                mat3[i][j] = mat1[i][j] - mat2[i][j];

                afisareMatrice(mat3, 5, 3, i, j);
                afisareMatrice(mat1, 1, 2, i, j);
                afisareMatrice(mat2, 1, 4, i, j);

                delay(300);
            }
        }

    }


}
