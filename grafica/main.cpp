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
} butonMatrice, butonVectori, adunareM, scadereM, inmultireM, putereM, detM, transM, sumaV, produsV, inmultireSV, shiftV, sortV, inapoi;


void initButon(buton &b, char text[], int xx,int yy,int m);
void showButton(buton b);
bool isInside(int xx, int yy, int x1, int y1, int x2, int y2);
void showMainText(char text[]);
void showSecondaryText(char text[]);

void pagina1();
void paginaMatrice();
void paginaVectori();
void init();

void afisareMatrice();
void paginaAdunareMat();
void paginaScadereMat();

void afisareV();
void paginaAdunareElV();
void inmultireElV();

bool ok=false;
int x,y;

/// variabile Matrice
int mat1[4][4], mat2[4][4], mat3[4][4];

/// variabile Vectori
int n;
int sum=0;
int produs=1;
int vec[50];
int scalar;
char numar[10];

void citireVector(int a[50])
{
        cout<<"Introduceti numarul de elemente al vectorului: ";
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>a[i];
}

void afisareVector(int a[50])
{
    cout<<"[ ";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"]";
}


///


int main()
{
    citireVector(vec);
    afisareVector(vec);
    init();
    pagina1();

}

void init()
{
    initwindow(latimeEcran, inaltimeEcran, "bibMat");
    initButon(butonMatrice, "Matrice", getmaxx()/2, 4*getmaxy()/9, 7);
    initButon(butonVectori, "Vectori", getmaxx()/2, 3*getmaxy()/5, 7);

    initButon(inapoi, "inapoi", 0.6*getmaxx()/10, 0.7*getmaxy()/9, 5);

    initButon(adunareM, "Adunare 2 matrici", getmaxx()/2, 2*getmaxy()/9, 7);
    initButon(scadereM, "Scadere 2 matrici", getmaxx()/2, 3*getmaxy()/9, 7);
    initButon(inmultireM, "Inmultire 2 matrici", getmaxx()/2, 4*getmaxy()/9, 7);
    initButon(putereM, "Ridicarea la putere", getmaxx()/2, 5*getmaxy()/9, 7);
    initButon(detM, "Obtinerea determinantului", getmaxx()/2, 6*getmaxy()/9, 7);
    initButon(transM, "Obtinerea transpusei", getmaxx()/2, 7*getmaxy()/9, 7);

    initButon(sumaV, "Suma elementelor", getmaxx()/2, 2*getmaxy()/9, 7);
    initButon(produsV, "Produsul elementelor", getmaxx()/2, 3*getmaxy()/9, 7);
    initButon(inmultireSV, "Inmultire cu scalar", getmaxx()/2, 4*getmaxy()/9, 7);
    initButon(shiftV, "Shiftare vector", getmaxx()/2, 5*getmaxy()/9, 7);
    initButon(sortV, "Sortare vector", getmaxx()/2, 6*getmaxy()/9, 7);

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
        }
        if(isInside(x, y, butonVectori.x1-1.5, butonVectori.y1-12, butonVectori.x2, butonVectori.y2-12)==true) /// daca am apasat pe butonul de vectori
        {
            paginaVectori();
        }
    }
}

void paginaVectori()
{
    cleardevice();
    setbkcolor(WHITE);
    cleardevice();
    showMainText("Operatii cu vectori");
    showButton(sumaV);
    showButton(produsV);
    showButton(inmultireSV);
    showButton(shiftV);
    showButton(sortV);
    showButton(inapoi);
    int ok=false;
    int x,y;
    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            pagina1();
        }
        if(isInside(x, y, sumaV.x1-1.5, sumaV.y1-12, sumaV.x2, sumaV.y2-12)==true)
        {
            paginaAdunareElV();
            //ok=true;
        }
        if(isInside(x, y, produsV.x1-1.5, produsV.y1-12, produsV.x2, produsV.y2-12)==true)
        {
            inmultireElV();
            //ok=true;
        }
        if(isInside(x, y, inmultireSV.x1-1.5, inmultireSV.y1-12, inmultireSV.x2, inmultireSV.y2-12)==true)
        {
            ///inmultirescalarV();
            ok=true;
        }
        if(isInside(x, y, shiftV.x1-1.5, shiftV.y1-12, shiftV.x2, shiftV.y2-12)==true)
        {
            ok=true;
        }
        if(isInside(x, y, sortV.x1-1.5, sortV.y1-12, sortV.x2, sortV.y2-12)==true)
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
    showButton(inapoi);
    int ok=false;
    int x,y;
     while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            pagina1();
        }
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
        if(isInside(x, y, putereM.x1-1.5, putereM.y1-12, putereM.x2, putereM.y2-12)==true)
        {
            ok=true;
        }
        if(isInside(x, y, detM.x1-1.5, detM.y1-12, detM.x2, detM.y2-12)==true)
        {
            ok=true;
        }
        if(isInside(x, y, transM.x1-1.5, transM.y1-12, transM.x2, transM.y2-12)==true)
        {
            ok=true;
        }
    }

}


///OPERATII MATRICE

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
    showButton(inapoi);
    showMainText("Adunare");
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

  while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            paginaMatrice();
        }
    }
}

void paginaScadereMat()
{
    cleardevice();
    setbkcolor(WHITE);
    cleardevice();
    showButton(inapoi);
    showMainText("Scadere");

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

     while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            paginaMatrice();
        }
    }
}


///OPERATII VECTORI

void afisareV(int vec[50], int x1, int y1, int ii)
{
    int i;
    char str[50] = "";
    for(i = 0; i < n; i++)
    {
        if(i == ii)
        {
            settextjustify(CENTER_TEXT, CENTER_TEXT);
            setcolor(WHITE);
            setbkcolor(COLOR(244, 158, 76));
            sprintf(str, "%d", vec[i]);
            outtextxy(i*60 + x1*50, 1*60 + y1*50, str);
        }
        else
        {
            settextjustify(CENTER_TEXT, CENTER_TEXT);
            setcolor(BLACK);
            setbkcolor(COLOR(255, 255, 255));
            sprintf(str, "%d", vec[i]);
            outtextxy(i*60 + x1*50, 1*60 + y1*50, str);
        }
    }
    delay(500);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(BLACK);
    setbkcolor(COLOR(255, 255, 255));
    sprintf(str, "%d", vec[i-1]);
    outtextxy((i-1)*60 + x1*50, 1*60 + y1*50, str);
}


void paginaAdunareElV()
{
    int i; sum = 1;
    char str[50] = "";
    char nr[50] = "";
    cleardevice();
    setbkcolor(WHITE);
    cleardevice();
    showButton(inapoi);
    setcolor(BLACK);
    setbkcolor(WHITE);
    showMainText("Adunarea elementelor din vector");
    outtextxy(300,325,"suma = ");
    for(i=0; i<n; i++)
    {
        afisareV(vec, 5, 4, i);
        setcolor(BLACK);
        setbkcolor(COLOR(255, 255, 255));
        sum = sum + vec[i];
        sprintf(nr, "%d", vec[i]);
        if(i==(n-1))
        {
            outtextxy(450+i*50, 350, nr);
        }
        else
        {
            outtextxy(450+i*50, 350, nr);
            outtextxy(475+i*50, 350, "+");
        }
        delay(500);
    }
    sprintf(str, "%d", sum);
    outtextxy(430+i*50,350,"=");
    outtextxy(467+i*50,350,str);
     while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            paginaVectori();
        }
    }
}

void inmultireElV()
{
    int i; produs=1;
    char str[50] = "";
    char nr[50] = "";
    cleardevice();
    setbkcolor(WHITE);
    cleardevice();
    showButton(inapoi);
    setcolor(BLACK);
    setbkcolor(WHITE);
    showMainText("Inmultirea elementelor din vector");
    outtextxy(300,325,"produsul = ");
    for(i=0; i<n; i++)
    {
        afisareV(vec, 5, 4, i);
        setcolor(BLACK);
        setbkcolor(COLOR(255, 255, 255));
        produs = produs * vec[i];
        sprintf(nr, "%d", vec[i]);
        if(i==(n-1))
        {
            outtextxy(500+i*50, 350, nr);
        }
        else
        {
            outtextxy(500+i*50, 350, nr);
            outtextxy(525+i*50, 350, "*");
        }
        delay(500);
    }
    sprintf(str, "%d", produs);
    outtextxy(480+i*50,350,"=");
    outtextxy(517+i*50,350,str);
    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            paginaVectori();
        }
    }
}

