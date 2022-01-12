#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <math.h>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <mmsystem.h>
#define MAX 90

using namespace std;

ifstream fin("matrice.txt");
ifstream finV("vectori.txt");

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
} butonMatrice, butonVectori, adunareM, scadereM, inmultireM, putereM, detM, transM, sumaV, produsV, inmultireSV, shiftStgV, shiftDrV, sortCrescV, sortDescrescV, inapoi, butonFisier, setari, despreProiect, butonSunet, bkAlb, bkAlbastru, bkVerde, bkRosu, bkRoz, bkGri;

void initButon(buton &b, char text[], int xx,int yy,int m);
void showButton(buton b);
void showButton(buton bb, int r, int g, int b); /// afisare buton cu o culoare anume
bool isInside(int xx, int yy, int x1, int y1, int x2, int y2);
void showMainText(char text[]);
void showSecondaryText(char text[]);

void resetMat(int m[4][4]);
void pagina1();
void paginaMatrice();
void paginaVectori();
void init();
void paginaSetari();
void paginaDespre();

void citireFisierMatrice();
void citireEcranMatrice();

void afisareMatrice(int mat[4][4], int x1, int y1, int ii, int jj);
void afisareMatrice(int mat[4][4], int x1, int y1, int i1, int j1, int i2, int j2, int i3, int j3);
void afisareInmultireMatrice(int i, int j, int k, int m1[4][4], int m2[4][4]);
void afisareOperatiiMatrice(int i, int j, int m1[4][4], int m2[4][4], char operatie[4]);

void paginaAdunareMat();
void paginaScadereMat();
void paginaInmultireMat();
void paginaPutereMat();
void paginaDeterminantMat();
void paginaTranspusaMat();

void citireFisierVector();
void citireEcranVector();
void afisareV();
void paginaAdunareElV();
void inmultireElV();
void inmultireScalarV();
void shiftareStgV();
void shiftareDrV();
void ordonareCresc();
void ordonareDescresc();

int culoare=15;
bool ok=false;
bool sound=true;
int x,y;
int h, w;
int auxV;

/// variabile Matrice
int mat1[4][4], mat2[4][4], mat3[4][4];
bool citireFisier = false;
bool douaMatrice = false;
int Delay = 700;

/// variabile Vectori
int n;
int sum=0;
long int produs=1;
int vec[50];
int scalar;
char numar[10];


int main()
{
    init();
    pagina1();
}

void init()
{
    initwindow(latimeEcran, inaltimeEcran, "bibMat");
    initButon(butonMatrice, "Operatii cu Matrice", getmaxx()/2, 3*getmaxy()/9, 7);
    initButon(butonVectori, "Operatii cu Vectori", getmaxx()/2, 4*getmaxy()/9, 7);
    initButon(setari, "Setari", getmaxx()/2, 5*getmaxy()/9, 7);
    initButon(despreProiect, "Despre proiect", getmaxx()/2, 6*getmaxy()/9, 7);

    initButon(butonSunet, "Sunet", getmaxx()/2.8, 3*getmaxy()/9, 7);
    initButon(inapoi, "inapoi", 0.6*getmaxx()/10, 0.7*getmaxy()/9, 5);

    initButon(bkAlb, "Alb", getmaxx()/3, 4.8*getmaxy()/9, 7);
    initButon(bkAlbastru, "Albastru", getmaxx()/2, 4.8*getmaxy()/9, 7);
    initButon(bkVerde, "Verde", getmaxx()/1.45, 4.8*getmaxy()/9, 7);
    initButon(bkRosu, "Rosu", getmaxx()/2.85, 6.2*getmaxy()/9, 7);
    initButon(bkRoz, "Roz", getmaxx()/2, 6.2*getmaxy()/9, 7);
    initButon(bkGri, "Gri", getmaxx()/1.6, 6.2*getmaxy()/9, 7);

    initButon(adunareM, "Adunare 2 matrici", getmaxx()/2, 2*getmaxy()/9, 7);
    initButon(scadereM, "Scadere 2 matrici", getmaxx()/2, 3*getmaxy()/9, 7);
    initButon(inmultireM, "Inmultire 2 matrici", getmaxx()/2, 4*getmaxy()/9, 7);
    initButon(putereM, "Ridicarea la putere", getmaxx()/2, 5*getmaxy()/9, 7);
    initButon(detM, "Obtinerea determinantului", getmaxx()/2, 6*getmaxy()/9, 7);
    initButon(transM, "Obtinerea transpusei", getmaxx()/2, 7*getmaxy()/9, 7);
    initButon(butonFisier, "Fisier", getmaxx()/2, 8.8*getmaxy()/9, 7);

    initButon(sumaV, "Suma elementelor", getmaxx()/2, 2*getmaxy()/9, 7);
    initButon(produsV, "Produsul elementelor", getmaxx()/2, 3*getmaxy()/9, 7);
    initButon(inmultireSV, "Inmultire cu scalar", getmaxx()/2, 4*getmaxy()/9, 7);
    initButon(shiftStgV, "Shiftare stanga vector", getmaxx()/2, 5*getmaxy()/9, 7);
    initButon(shiftDrV, "Shiftare dreapta vector", getmaxx()/2, 6*getmaxy()/9, 7);
    initButon(sortCrescV, "Sortare crescatoare vector", getmaxx()/2, 7*getmaxy()/9, 7);
    initButon(sortDescrescV, "Sortare descrescatoare vector", getmaxx()/2, 8*getmaxy()/9, 7);

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

void showButton(buton bb, int r, int g, int b)
{
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, bb.marime);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setbkcolor(COLOR(r, g, b));
    setcolor(BLACK);
    outtextxy((bb.x1 + bb.x2) / 2, (bb.y1 + bb.y2) / 2, bb.msj);
}

bool isInside(int xx, int yy, int x1, int y1, int x2, int y2)
{
    return x1<=xx && xx<=x2 && y1<=yy && yy<=y2;
}

void showMainText(char text[])
{
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR, 4.3);
    setcolor(BLACK);
    settextjustify(LEFT_TEXT,TOP_TEXT);
    int a=(latimeEcran-textwidth(text))/2;
    int b=inaltimeEcran/9;
    outtextxy(a,b,&text[0]);
}

void showSecondaryText(char text[], float h, float w)
{
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR, 3.5);
    setbkcolor(culoare);
    setcolor(BLACK);
    settextjustify(LEFT_TEXT,TOP_TEXT);
    int a=(latimeEcran-textwidth(text))/w;
    int b=inaltimeEcran/h;
    outtextxy(a,b,&text[0]);
}

void pagina1()
{
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showMainText(title);
    showButton(butonMatrice);
    showButton(butonVectori);
    showButton(setari);
    showButton(despreProiect);

    int ok=false;
    int x,y;
    while(ok==false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, butonMatrice.x1-1.5, butonMatrice.y1-12, butonMatrice.x2, butonMatrice.y2-12)==true) /// daca am apasat pe butonul de matrice
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            paginaMatrice();
        }
        if(isInside(x, y, butonVectori.x1-1.5, butonVectori.y1-12, butonVectori.x2, butonVectori.y2-12)==true) /// daca am apasat pe butonul de vectori
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            paginaVectori();
        }
        if(isInside(x, y, setari.x1-1.5, setari.y1-12, setari.x2, setari.y2-12)==true)
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            paginaSetari();
        }
        if(isInside(x, y, despreProiect.x1-1.5, despreProiect.y1-12, despreProiect.x2, despreProiect.y2-12)==true)
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            paginaDespre();
        }
    }
}

void paginaSetari()
{
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showMainText("Setari");
    showButton(inapoi);
    if (sound == true) showButton(butonSunet, 0, 255, 0);
    else showButton(butonSunet, 255, 0, 0);
    showSecondaryText("Sunet ON/OFF:", 3.4, 5);
    showSecondaryText("Culoare fundal:", 2, 5);
    showButton(bkAlb);
    showButton(bkAlbastru);
    showButton(bkVerde);
    showButton(bkRosu);
    showButton(bkRoz);
    showButton(bkGri);


    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            pagina1();
        }
        if(isInside(x, y, butonSunet.x1-1.5, butonSunet.y1-12, butonSunet.x2, butonSunet.y2-12)==true)
        {
            if(sound == false)
            {
                sound = true;
                PlaySound(TEXT("sfx-shooop.WAV"), NULL, SND_ASYNC);
                showButton(butonSunet, 0, 255, 0);
            }
            else
            {
                sound = false;
                showButton(butonSunet, 255, 0, 0);
            }
        }
        if(isInside(x, y, bkAlb.x1-1.5, bkAlb.y1-12, bkAlb.x2, bkAlb.y2-12)==true)
        {
            if (sound == true) PlaySound(TEXT("sfx-shooop.WAV"), NULL, SND_ASYNC);
            culoare = 15;
            setbkcolor(culoare);
            paginaSetari();
        }
        if(isInside(x, y, bkAlbastru.x1-1.5, bkAlbastru.y1-12, bkAlbastru.x2, bkAlbastru.y2-12)==true)
        {
            if (sound == true) PlaySound(TEXT("sfx-shooop.WAV"), NULL, SND_ASYNC);
            culoare = 9;
            setbkcolor(culoare);
            paginaSetari();
        }
        if(isInside(x, y, bkVerde.x1-1.5, bkVerde.y1-12, bkVerde.x2, bkVerde.y2-12)==true)
        {
            if (sound == true) PlaySound(TEXT("sfx-shooop.WAV"), NULL, SND_ASYNC);
            culoare = 10;
            setbkcolor(culoare);
            paginaSetari();
        }
        if(isInside(x, y, bkRosu.x1-1.5, bkRosu.y1-12, bkRosu.x2, bkRosu.y2-12)==true)
        {
            if (sound == true) PlaySound(TEXT("sfx-shooop.WAV"), NULL, SND_ASYNC);
            culoare = 12;
            setbkcolor(culoare);
            paginaSetari();
        }
        if(isInside(x, y, bkRoz.x1-1.5, bkRoz.y1-12, bkRoz.x2, bkRoz.y2-12)==true)
        {
            if (sound == true) PlaySound(TEXT("sfx-shooop.WAV"), NULL, SND_ASYNC);
            culoare = 13;
            setbkcolor(culoare);
            paginaSetari();
        }
        if(isInside(x, y, bkGri.x1-1.5, bkGri.y1-12, bkGri.x2, bkGri.y2-12)==true)
        {
            if (sound == true) PlaySound(TEXT("sfx-shooop.WAV"), NULL, SND_ASYNC);
            culoare = 7;
            setbkcolor(culoare);
            paginaSetari();
        }
    }
}

void paginaDespre()
{
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showMainText("Despre proiect");
    showButton(inapoi);
    showSecondaryText("Acest proiect a fost realizat de Pruteanu Matei si Gheorghiu Maria, studenti in anul 1, grupa E3, pentru ora de Introducere in programare,", 5, 2.1);
    showSecondaryText(" sub indrumarea domnului profesor Patrut Bogdan.       ",4, 6.3);
    showSecondaryText("Operatiile ce pot fi efectuate cu ajutorul acestui program sunt:                                 ", 3, 4.9);
    showSecondaryText("1) Matrice: adunarea/scaderea/inmultirea a doua matrice, ridicarea la putere a unei matrice, obtinerea determinantului/transpusei unei matrice;",2.5,1.8);
    showSecondaryText("2) Vectori: suma/produsul elementelor din vector, inmultirea vectorului cu un scalar, shiftarea la stanga/dreapta", 2,3.3);
    showSecondaryText(" a elementelor din vector, sortarea crescatoare/descrescatoare a elementelor din vector;             ", 1.8, 2.6);
    showSecondaryText("Pentru a accesa codul sursa, vizitati: https://github.com/mateipruteanu/bibMat",1.5,5);

    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            pagina1();
        }
    }
}

void paginaVectori()
{
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showMainText("Operatii cu vectori");
    showButton(sumaV);
    showButton(produsV);
    showButton(inmultireSV);
    showButton(shiftStgV);
    showButton(shiftDrV);
    showButton(sortCrescV);
    showButton(sortDescrescV);
    showButton(inapoi);
    if (citireFisier == false) showButton(butonFisier, 255, 0, 0);
    else showButton(butonFisier, 0, 255, 0);
    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            pagina1();
        }
        if(isInside(x, y, sumaV.x1-1.5, sumaV.y1-12, sumaV.x2, sumaV.y2-12)==true)
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            paginaAdunareElV();
        }
        if(isInside(x, y, produsV.x1-1.5, produsV.y1-12, produsV.x2, produsV.y2-12)==true)
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            inmultireElV();
        }
        if(isInside(x, y, inmultireSV.x1-1.5, inmultireSV.y1-12, inmultireSV.x2, inmultireSV.y2-12)==true)
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            inmultireScalarV();
        }
        if(isInside(x, y, shiftStgV.x1-1.5, shiftStgV.y1-12, shiftStgV.x2, shiftStgV.y2-12)==true)
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            shiftareStgV();
        }
        if(isInside(x, y, shiftDrV.x1-1.5, shiftDrV.y1-12, shiftDrV.x2, shiftDrV.y2-12)==true)
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            shiftareDrV();
        }
        if(isInside(x, y, sortCrescV.x1-1.5, sortCrescV.y1-12, sortCrescV.x2, sortCrescV.y2-12)==true)
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            ordonareCresc();
        }
        if(isInside(x, y, sortDescrescV.x1-1.5, sortDescrescV.y1-12, sortDescrescV.x2, sortDescrescV.y2-12)==true)
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            ordonareDescresc();
        }
        if(isInside(x, y, butonFisier.x1-1.5, butonFisier.y1-12, butonFisier.x2, butonFisier.y2-12)==true)
        {
            if(citireFisier == false)
            {
                citireFisier = true;
                showButton(butonFisier, 0, 255, 0);
            }
            else
            {
                citireFisier = false;
                showButton(butonFisier, 255, 0, 0);
            }
        }

    }
}

void paginaMatrice()
{
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showMainText("Operatii cu matrice");
    showButton(adunareM);
    showButton(scadereM);
    showButton(inmultireM);
    showButton(putereM);
    showButton(inapoi);
    showButton(butonFisier, 255, 0, 0);
    showButton(detM);
    showButton(transM);
    citireFisier = false;
    int ok=false;
    int x,y;
    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            pagina1();
        }
        if(isInside(x, y, adunareM.x1-1.5, adunareM.y1-12, adunareM.x2, adunareM.y2-12)==true) /// daca am apasat pe butonul de adunare
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            paginaAdunareMat();
            clearviewport();
            ok=true;
        }
        if(isInside(x, y, scadereM.x1-1.5, scadereM.y1-12, scadereM.x2, scadereM.y2-12)==true) /// daca am apasat pe butonul de scadere
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            paginaScadereMat();
            clearviewport();
            ok=true;
        }
        if(isInside(x, y, inmultireM.x1-1.5, inmultireM.y1-12, inmultireM.x2, inmultireM.y2-12)==true) /// daca am apasat pe butonul de inmultire
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            paginaInmultireMat();
            ok=true;
        }
        if(isInside(x, y, putereM.x1-1.5, putereM.y1-12, putereM.x2, putereM.y2-12)==true)
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            paginaPutereMat();
            ok=true;
        }
        if(isInside(x, y, detM.x1-1.5, detM.y1-12, detM.x2, detM.y2-12)==true)
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            paginaDeterminantMat();
            ok=true;
        }
        if(isInside(x, y, transM.x1-1.5, transM.y1-12, transM.x2, transM.y2-12)==true)
        {
            if (sound == true){
            PlaySound(TEXT("sfx-bleep.WAV"), NULL, SND_ASYNC);}
            paginaTranspusaMat();
            ok=true;
        }
        if(isInside(x, y, butonFisier.x1-1.5, butonFisier.y1-12, butonFisier.x2, butonFisier.y2-12)==true)
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            if(citireFisier == false)
            {
                citireFisier = true;
                showButton(butonFisier, 0, 255, 0);
            }
            else
            {
                citireFisier = false;
                showButton(butonFisier, 255, 0, 0);
            }
            //ok=true;
        }
    }

}

///OPERATII MATRICE

void citireMatrice(int m[4][4], char cuv[101]) /// functie helper pt citireEcranMatrice
{
        int k = 0;
        int lungime = 300;
        char cuvVechi[101] = "";
        char c;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
            {
                int nrCifre = 0;
                c = (char)getch();

                while(c != 13)
                {
                    cuv[nrCifre++] = c;
                    c = (char)getch();
                }
                cuv[nrCifre] = NULL;

                // cout<<cuvVechi<<" "; // <- pentru troubleshooting

                k = (textwidth(cuvVechi) + textwidth(" "));
                lungime += k;

                outtextxy(lungime,300,cuv);
                strcpy(cuvVechi, cuv);

                m[i][j] = atoi(cuv); // atoi transforma un sir de caractere in numere

                // cout<<mat2[i][j]<<endl; // <- pentru troubleshooting
            }
}

void citireFisierMatrice()
{
    setbkcolor(culoare);
    if(douaMatrice)
    {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                fin>>mat1[i][j];
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                fin>>mat2[i][j];
    }
    else
    {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                fin>>mat1[i][j];
    }

}

void citireEcranMatrice() /// se pot citi nr cu mai multe cifre
{
    char c, cuv[101] = "";
    int k = 0;
    int yEcran = 300;
    setbkcolor(culoare);
    setfillstyle(SOLID_FILL, culoare);
    if(douaMatrice)
    {

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                outtextxy(50*(k++) + 300, yEcran, "      ");

        k = 0;
        int lungime = 300;
        char cuvVechi[101] = "";
        outtextxy(50 + 300, yEcran - 50, "Prima matrice:");

        citireMatrice(mat1, cuv); /// <- functia citeste matricea si afiseaza fiecare numar dupa enter

        outtextxy(50 + 300, yEcran - 50, "                                ");
        outtextxy(50 + 300, yEcran - 50, "A doua matrice:");
        bar(300, yEcran - 10, 50 + 300 + 1000, yEcran + 30);

        k = 0;

        citireMatrice(mat2, cuv); /// <- functia citeste matricea si afiseaza fiecare numar dupa enter

        outtextxy(50 + 300, yEcran - 50, "                                ");
        k = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                outtextxy(50*(k++) + 300, yEcran, "      ");

        bar(300, yEcran - 10, 50 + 300 + 1000, yEcran + 30);

    }
    else
    {
        k = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
            {
                outtextxy(50*(k++) + 300, yEcran, "      ");
            }
        outtextxy(50 + 300, yEcran - 50, "Matricea:");
        citireMatrice(mat1, cuv); /// <- functia citeste matricea si afiseaza fiecare numar dupa enter

        outtextxy(50 + 300, yEcran - 50, "                                ");
        bar(300, yEcran - 10, 50 + 300 + 1000, yEcran + 30);
    }


}

void resetMat(int m[4][4])
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            mat3[i][j] = 0;
}

void afisareMatriceT(int mat[4][4], int x1, int y1, int ii, int jj) /// delete
{

/// de aici incepe originalul
    char str[50] = "";
    for(int j = 0; j < 3; j++)
        for(int i = 0; i < 3; i++)
        {
            if(i == ii && j == jj)
            {
                settextjustify(CENTER_TEXT, CENTER_TEXT);
                setcolor(WHITE);
                setbkcolor(COLOR(244, 158, 76));
                sprintf(str, "%d", mat[i][j]);
                outtextxy(j*110 + x1*150, i*80 + y1*150, str);
            }
            else
            {
                settextjustify(CENTER_TEXT, CENTER_TEXT);
                setcolor(BLACK);
                setbkcolor(COLOR(255, 255, 255));
                sprintf(str, "%d", mat[i][j]);
                outtextxy(j*110 + x1*150, i*80 + y1*150, str);
            }
        }
}

void afisareMatrice(int mat[4][4], int x1, int y1, int ii, int jj)
{

/// de aici incepe originalul
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
                outtextxy(j*110 + x1*150, i*80 + y1*150, str);
            }
            else
            {
                settextjustify(CENTER_TEXT, CENTER_TEXT);
                setcolor(BLACK);
                setbkcolor(culoare);
                sprintf(str, "%d", mat[i][j]);
                outtextxy(j*110 + x1*150, i*80 + y1*150, str);
            }
        }
}

void afisareMatrice(int mat[4][4], int x1, int y1, int i1, int j1, int i2, int j2, int i3, int j3)
{
    char str[50] = "";
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            if(i == i1 && j == j1 || i == i2 && j == j2 || i == i3 && j == j3)
            {
                settextjustify(CENTER_TEXT, CENTER_TEXT);
                setcolor(WHITE);
                setbkcolor(COLOR(244, 158, 76));
                sprintf(str, "%d", mat[i][j]);
                outtextxy(j*80 + x1*150, i*80 + y1*150, str);
            }
            else
            {
                settextjustify(CENTER_TEXT, CENTER_TEXT);
                setcolor(BLACK);
                setbkcolor(culoare);
                sprintf(str, "%d", mat[i][j]);
                outtextxy(j*80 + x1*150, i*80 + y1*150, str);
            }
        }
}

void paginaAdunareMat()
{
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showButton(inapoi);
    showMainText("Adunare");
    douaMatrice = true;


    if(citireFisier)
        citireFisierMatrice();
    else
        citireEcranMatrice();



    resetMat(mat3);

    outtextxy(140, 650, "Matricea 1");
    outtextxy(580, 650, "Matricea 2"); /// 500
    outtextxy(1020, 650, "Rezultat");
    outtextxy(460, 500, "+");
    outtextxy(910, 500, "=");


    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {

            mat3[i][j] = mat1[i][j] + mat2[i][j];
            afisareOperatiiMatrice(i, j, mat1, mat2, " + ");

            afisareMatrice(mat3, 7, 3, i, j);
            afisareMatrice(mat1, 1, 3, i, j);
            afisareMatrice(mat2, 4, 3, i, j);

            delay(Delay);
        }
    }

    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            clearviewport();
            paginaMatrice();
        }
    }

}

void paginaScadereMat()
{
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showButton(inapoi);
    showMainText("Scadere");
    douaMatrice = true;

    if(citireFisier)
        citireFisierMatrice();
    else
        citireEcranMatrice();

    resetMat(mat3);

    outtextxy(140, 650, "Matricea 1");
    outtextxy(580, 650, "Matricea 2");
    outtextxy(1020, 650, "Rezultat");
    outtextxy(460, 500, "-");
    outtextxy(910, 500, "=");

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            mat3[i][j] = mat1[i][j] - mat2[i][j];

            afisareOperatiiMatrice(i, j, mat1, mat2, " - ");

            afisareMatrice(mat3, 7, 3, i, j);
            afisareMatrice(mat1, 1, 3, i, j);
            afisareMatrice(mat2, 4, 3, i, j);

            delay(Delay);
        }
    }

    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            paginaMatrice();
        }
    }
}

void paginaInmultireMat()
{
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showButton(inapoi);
    showMainText("Inmultire");
    douaMatrice = true;

    if(citireFisier)
        citireFisierMatrice();
    else
        citireEcranMatrice();

    resetMat(mat3);

    outtextxy(140, 650, "Matricea 1");
    outtextxy(580, 650, "Matricea 2");
    outtextxy(1020, 650, "Rezultat");
    outtextxy(460, 500, "*");
    outtextxy(910, 500, "=");


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat3[i][j] = 0;

            for (int k = 0; k < 3; k++)
                {
                    afisareInmultireMatrice(i, j, k, mat1, mat2);
                    mat3[i][j] += mat1[i][k] * mat2[k][j];

                    afisareMatrice(mat3, 7, 3, i, j);
                    afisareMatrice(mat1, 1, 3, i, k); /// verifica animatia
                    afisareMatrice(mat2, 4, 3, k, j);
                    delay(Delay);
                }
        }
    }



    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            paginaMatrice();
        }
    }

}

void paginaPutereMat()
{
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showButton(inapoi);
    showMainText("Ridicare la putere");
    douaMatrice = false;

    if(citireFisier)
        citireFisierMatrice();
    else
        citireEcranMatrice();

    resetMat(mat3);

    outtextxy(140, 650, "Matricea 1");
    outtextxy(580, 650, "Matricea 1");
    outtextxy(1020, 650, "Rezultat");
    outtextxy(460, 500, "*");
    outtextxy(910, 500, "=");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat3[i][j] = 0;
            for (int k = 0; k < 3; k++)
                {

                    //cout<<mat3[i][j]<<" + ("<<mat1[i][k]<<" * "<<mat1[k][j]<<")"<<endl;
                    afisareInmultireMatrice(i, j, k, mat1, mat1);
                    mat3[i][j] += mat1[i][k] * mat1[k][j];

                    afisareMatrice(mat3, 7, 3, i, j);
                    afisareMatrice(mat1, 1, 3, i, k);
                    afisareMatrice(mat1, 4, 3, k, j);
                    delay(Delay);
                }
            //cout<<endl;
        }


    }


    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            paginaMatrice();
        }
    }
}

void paginaDeterminantMat()
{
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showButton(inapoi);
    showMainText("Determinantul unei matrice");
    douaMatrice = false;


    if(citireFisier)
        citireFisierMatrice();
    else
        citireEcranMatrice();



    int det = 0;
    det = (mat1[0][0] * mat1[1][1] * mat1[2][2]) + (mat1[0][2] * mat1[2][1] * mat1[1][0]) + (mat1[0][1] * mat1[1][2] * mat1[2][0]) - (mat1[0][2] * mat1[1][1] * mat1[2][0]) - (mat1[0][1] * mat1[1][0] * mat1[2][2]) - (mat1[1][2] * mat1[2][1] * mat1[0][0]);
    char *determinant;
    sprintf(determinant, "%d", det);


    setfillstyle(SOLID_FILL, BLACK);
    bar(100, 415, 105, 625);
    bar(350, 415, 355, 625);

    outtextxy(500, 505, " = ");

    cout<<det;

    int d = Delay;
    afisareMatrice(mat1, 1, 3, 0, 0, 1, 1, 2, 2);
    delay(d);
    afisareMatrice(mat1, 1, 3, 0, 2, 2, 1, 1, 0);
    delay(d);
    afisareMatrice(mat1, 1, 3, 0, 1, 1, 2, 2, 0);
    delay(d);
    afisareMatrice(mat1, 1, 3, 0, 2, 1, 1, 2, 0);
    delay(d);
    afisareMatrice(mat1, 1, 3, 0, 1, 1, 0, 2, 2);
    delay(d);
    afisareMatrice(mat1, 1, 3, 1, 2, 2, 1, 0, 0);
    outtextxy(700, 505, determinant);


    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            paginaMatrice();
        }
    }


}

void paginaTranspusaMat()
{
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showButton(inapoi);
    showMainText("Transpusa");
    douaMatrice = false;


    if(citireFisier)
        citireFisierMatrice();
    else
        citireEcranMatrice();

    resetMat(mat3);

    outtextxy(140, 650, "Matricea");
    outtextxy(580, 650, "Matricea transpusa"); /// 500
    outtextxy(460, 500, "=>");



    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            mat3[i][j] = mat1[j][i];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            afisareMatrice(mat1, 1, 3, i, j);
            afisareMatrice(mat3, 4, 3, j, i);

            delay(Delay);
        }
    }

    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            clearviewport();
            paginaMatrice();
        }
    }

}

void afisareInmultireMatrice(int i, int j, int k, int m1[4][4], int m2[4][4])
{
    setcolor(BLACK);
    setbkcolor(culoare);

    char s1[9], s2[9], s3[9];   /// mat1 = mat2 pt ridicare la putere
    sprintf(s1, "%d", m1[i][k]);
    sprintf(s2, "%d", m2[k][j]);
    sprintf(s3, "%d", mat3[i][j]);


    bar(200, 250, 850, 400);

        outtextxy(250, 300, s3);
        outtextxy(350, 300, " + (");
        outtextxy(450, 300, s1);
        outtextxy(550, 300, " * ");
        outtextxy(650, 300, s2);
        outtextxy(750, 300, ")");

    //cout<<mat3[i][j]<<" + ("<<mat1[i][k]<<" * "<<mat1[k][j]<<")"<<endl;

    setcolor(WHITE);
    setbkcolor(COLOR(244, 158, 76));


}

void afisareOperatiiMatrice(int i, int j, int m1[4][4], int m2[4][4], char operatie[4])
{
    setcolor(BLACK);
    setbkcolor(culoare);

    char s1[9], s2[9], s3[9];   /// mat1 = mat2 pt ridicare la putere
    sprintf(s1, "%d", m1[i][j]);
    sprintf(s2, "%d", m2[i][j]);
    sprintf(s3, "%d", mat3[i][j]);

    setfillstyle(SOLID_FILL, culoare);
    bar(200, 250, 850, 400);

        outtextxy(250, 300, s1);
        outtextxy(350, 300, operatie);
        outtextxy(450, 300, s2);
        outtextxy(550, 300, " = ");
        outtextxy(650, 300, s3);

    //cout<<mat3[i][j]<<" + ("<<mat1[i][k]<<" * "<<mat1[k][j]<<")"<<endl;

    //setcolor(WHITE);
    //setbkcolor(COLOR(244, 158, 76));
}

///OPERATII VECTORI

void citireFisierVector()
{
    finV>>n;
    for(int i = 0; i < n; i++)
        finV>>vec[i];
}

void citireNrElemente(char cuv[101], int &n)
{
        char c;
        int nrCifre = 0;
        c = (char)getch();

        while(c != 13)
        {
            cuv[nrCifre++] = c;
            c = (char)getch();
        }
        cuv[nrCifre] = NULL;


        n = atoi(cuv);
}

void citireVector(int vec[], char cuv[101]) /// functie helper pt citireEcranVector
{
        int k = 0;
        int lungime = 300;
        char cuvVechi[101] = "";
        char c;
        for(int i = 0; i < n; i++)
            {
                int nrCifre = 0;
                c = (char)getch();

                while(c != 13)
                {
                    cuv[nrCifre++] = c;
                    c = (char)getch();
                }
                cuv[nrCifre] = NULL;

                k = (textwidth(cuvVechi) + textwidth(" "));
                lungime += k;

                outtextxy(lungime,300,cuv);
                strcpy(cuvVechi, cuv);

                vec[i] = atoi(cuv); // atoi transforma un sir de caractere in numere

            }
}

void citireEcranVector() /// se pot citi nr cu mai multe cifre
{
    n = 0;
    char c, cuv[] = "";
    int k = 0;
    int yEcran = 300;
    setbkcolor(culoare);
    k = 0;

    outtextxy(300,200,"Cate elemente are vectorul?");

    char cuv1[] = "";
    citireNrElemente(cuv1, n); /// citeste cifrele si stocheaza "cuvantul" in cuv1, iar numarul rezultat in n
    outtextxy(850, 200, cuv1);
    if (n < 1 || n > 20)
    {
        setcolor(RED);
        outtextxy(300, 300, "Vectorul trebuie sa aiba intre 1 si 20 de elemente!");
        delay(1000);
        bar(10, 280, 2000, 350); ///acopera avertismentul
        bar(850, 180, 2000, 250); ///acopera nr de elemente introdus anterior
        setcolor(BLACK);
        citireEcranVector();
    }


    delay(600);
    setfillstyle(SOLID_FILL, culoare);
    bar(10, 180, 2000, 250); /// dupa o secunda acopera nr de cifre si afiseaza partea de citire a vectorului


    for(int i = 0; i < n; i++)
    {
            outtextxy(50*(k++) + 300, yEcran, "      ");
    }
    outtextxy(50 + 300, 200, "Vectorul:");
    citireVector(vec, cuv); /// <- functia citeste vectorul si afiseaza fiecare numar dupa enter
    bar(10, 340, 2000, 280);
}

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
            if (i < 10)
            {
                outtextxy(i*150 + x1*60.4 - 200, 126 + y1*50, str);
            }
            else
            {
                outtextxy((i-10)*150 + x1*60.4 - 200, 176 + y1*50, str);
            }

        }
        else
        {
            settextjustify(CENTER_TEXT, CENTER_TEXT);
            setcolor(BLACK);
            setbkcolor(culoare);
            sprintf(str, "%d", vec[i]);
            if (i < 10)
            {
                outtextxy(i*150 + x1*60.4 - 200, 126 + y1*50, str);
            }
            else
            {
                outtextxy((i-10)*150 + x1*60.4 - 200, 176 + y1*50, str);
            }
        }
    }
    delay(500);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(BLACK);
    setbkcolor(culoare);
    sprintf(str, "%d", vec[i-1]);
    if (i < 10)
            {
                outtextxy((i-1)*150 + x1*60.4 - 200, 126 + y1*50, str);
            }
            else
            {
                outtextxy((i-11)*150 + x1*60.4 - 200, 176 + y1*50, str);
            }
}

void paginaAdunareElV()
{
    int i;
    sum = 0;
    char str[50] = "";
    char nr[50] = "";
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showButton(inapoi);
    setcolor(BLACK);
    showMainText("Adunarea elementelor din vector");
    outtextxy(230,400,"suma = ");
    if(citireFisier)
        citireFisierVector();
    else
        citireEcranVector();

    for(i=0; i<n; i++)
    {
        afisareV(vec, 5, 4, i);
        setcolor(BLACK);
        setbkcolor(culoare);
        sum = sum + vec[i];
        sprintf(nr, "%d", vec[i]);
        if(i==(n-1))
        {
            if (i < 5)
            {
                outtextxy(450+i*180, 425, nr);
            }
            else if (i < 10)
            {
                outtextxy(450+(i-5)*180, 475, nr);
            }
            else if (i < 15)
            {
                outtextxy(450+(i-10)*180, 525, nr);
            }
            else if (i < 20)
            {
                outtextxy(450+(i-15)*180, 575, nr);

            }
        }
        else
        {
            if (i < 5)
            {
                outtextxy(450+i*180, 425, nr);
                outtextxy(525+i*180, 425, "+");
            }
            else if (i < 10)
            {
                outtextxy(450+(i-5)*180, 475, nr);
                outtextxy(525+(i-5)*180, 475, "+");
            }
            else if (i < 15)
            {
                outtextxy(450+(i-10)*180, 525, nr);
                outtextxy(525+(i-10)*180, 525, "+");
            }
            else if (i < 20)
            {
                outtextxy(450+(i-15)*180, 575, nr);
                outtextxy(525+(i-15)*180, 575, "+");
            }
        }
        delay(500);
    }
    sprintf(str, "%d", sum);
    setbkcolor(COLOR(244, 158, 76));
    if (i <= 5)
    {
        outtextxy(290,475,"suma = ");
        outtextxy(440,475,str);
    }
    else if (i <= 10)
    {
        outtextxy(290,525,"suma = ");
        outtextxy(440,525,str);
    }
    else if (i <= 15)
    {
        outtextxy(290,575,"suma = ");
        outtextxy(440,575,str);
    }
    else if (i <= 20)
    {
        outtextxy(290,625,"suma = ");
        outtextxy(440,625,str);
    }
    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            paginaVectori();
        }
    }
}

void inmultireElV()
{
    int i;
    produs=1;
    char str[50] = "";
    char nr[50] = "";
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showButton(inapoi);
    setcolor(BLACK);
    showMainText("Inmultirea elementelor din vector");
    outtextxy(230,400,"produsul = ");
    if(citireFisier)
        citireFisierVector();
    else
        citireEcranVector();
    for(i=0; i<n; i++)
    {
        afisareV(vec, 5, 4, i);
        setcolor(BLACK);
        setbkcolor(culoare);
        produs = produs * vec[i];
        sprintf(nr, "%d", vec[i]);
        if(i==(n-1))
        {
            if (i < 5)
            {
                outtextxy(500+i*180, 425, nr);
            }
            else if (i < 10)
            {
                outtextxy(500+(i-5)*180, 475, nr);
            }
            else if (i < 15)
            {
                outtextxy(500+(i-10)*180, 525, nr);
            }
            else if (i < 20)
            {
                outtextxy(500+(i-15)*180, 575, nr);

            }
        }
        else
        {
            if (i < 5)
            {
                outtextxy(500+i*180, 425, nr);
                outtextxy(590+i*180, 425, "*");
            }
            else if (i < 10)
            {
                outtextxy(500+(i-5)*180, 475, nr);
                outtextxy(590+(i-5)*180, 475, "*");
            }
            else if (i < 15)
            {
                outtextxy(500+(i-10)*180, 525, nr);
                outtextxy(590+(i-10)*180, 525, "*");
            }
            else if (i < 20)
            {
                outtextxy(500+(i-15)*180, 575, nr);
                outtextxy(590+(i-15)*180, 575, "*");

            }
        }
        delay(500);
    }
    sprintf(str, "%d", produs);
    setbkcolor(COLOR(244, 158, 76));
    if (i <= 5)
    {
        outtextxy(290,475,"produsul = ");
        outtextxy(480,475,str);
    }
    else if (i <= 10)
    {
        outtextxy(290,525,"produsul = ");
        outtextxy(480,525,str);
    }
    else if (i <= 15)
    {
        outtextxy(290,575,"produsul = ");
        outtextxy(480,575,str);
    }
    else if (i <= 20)
    {
        outtextxy(290,625,"produsul = ");
        outtextxy(480,625,str);
    }
    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            paginaVectori();
        }
    }
}

void citireScalar(char cuv[101], int &s)
{
        char c;
        int nrCifre = 0;
        c = (char)getch();

        while(c != 13)
        {
            cuv[nrCifre++] = c;
            c = (char)getch();
        }
        cuv[nrCifre] = NULL;


        s = atoi(cuv);
}

void inmultireScalarV()
{
    int i, s, vec_rez[50]={};
    char sc, scalar[]="";
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showButton(inapoi);
    setcolor(BLACK);
    showMainText("Inmultirea cu scalar a unui vector");
    if(citireFisier)
        citireFisierVector();
    else
        citireEcranVector();
    outtextxy(300,350,"Valoare scalar:");

    char cuv1[] = "";
    citireNrElemente(cuv1, s);
    outtextxy(600, 350, cuv1);

    outtextxy(300,400,"Vectorul inmultit:");

    for(i=0; i<n; i++)
    {
        afisareV(vec, 5, 4, i);
        vec_rez[i] = s * vec[i];
        afisareV(vec_rez, 5, 7, i);
    }

    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            paginaVectori();
        }
    }
}

void shiftareStgV()
{
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showButton(inapoi);
    setcolor(BLACK);
    showMainText("Shiftarea la stanga");
    if(citireFisier)
        citireFisierVector();
    else
        citireEcranVector();
    outtextxy(300,400,"Vectorul obtinut:");
    for(int i = 0; i < n; i++)
    {
        afisareV(vec, 5, 4, i);
    }

    auxV = vec[0];
    for(int i = 0; i < n - 1; i++)
        vec[i] = vec[i + 1];
    vec[n - 1] = auxV;

    for(int i = 0; i < n; i++)
    {
        afisareV(vec, 5, 7, i);
    }

    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            paginaVectori();
        }
    }
}

void shiftareDrV()
{
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showButton(inapoi);
    setcolor(BLACK);
    showMainText("Shiftarea la dreapta");
    if(citireFisier)
        citireFisierVector();
    else
        citireEcranVector();

        outtextxy(300,400,"Vectorul obtinut:");
    for(int i = 0; i < n; i++)
    {
        afisareV(vec, 5, 4, i);
    }

    auxV = vec[n-1];
    for(int i = n - 1; i > 0; i--)
        vec[i] = vec[i-1];
    vec[0] = auxV;

    for(int i = 0; i < n; i++)
    {
        afisareV(vec, 5, 7, i);
    }

    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            paginaVectori();
        }
    }
}

void ordonareCresc()
{
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showButton(inapoi);
    setcolor(BLACK);
    showMainText("Ordonarea crescatoare a elementelor");
    if(citireFisier)
        citireFisierVector();
    else
        citireEcranVector();
    outtextxy(300,400,"Vectorul ordonat:");

    for(int i = 0; i < n; i++)
    {
        afisareV(vec, 5, 4, i);
    }

    for (int i = 0; i < n-1; i++){
    for (int j = i+1; j < n; j++){
        if (vec[i] > vec[j]){
                int auxV = vec[i];
                vec[i] = vec[j];
                vec[j] = auxV;
            }
        }
    }
     for(int i = 0; i < n; i++)
    {
        afisareV(vec, 5, 7, i);
    }

    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            paginaVectori();
        }
    }
}

void ordonareDescresc()
{
    cleardevice();
    setbkcolor(culoare);
    cleardevice();
    showButton(inapoi);
    setcolor(BLACK);
    showMainText("Ordonarea descrescatoare a elementelor");
    if(citireFisier)
        citireFisierVector();
    else
        citireEcranVector();
    outtextxy(300,400,"Vectorul ordonat:");

    for(int i = 0; i < n; i++)
    {
        afisareV(vec, 5, 4, i);
    }

    for (int i = 0; i < n-1; i++){
    for (int j = i+1; j < n; j++){
        if (vec[i] < vec[j]){
                int aux = vec[j];
                vec[j] = vec[i];
                vec[i] = aux;
            }
        }
    }
     for(int i = 0; i < n; i++)
    {
        afisareV(vec, 5, 7, i);
    }


    while (ok == false)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(isInside(x, y, inapoi.x1-1.5, inapoi.y1-12, inapoi.x2, inapoi.y2-12)==true) /// daca am apasat pe butonul inapoi
        {
            if (sound == true){
            PlaySound(TEXT("sfx-pichoop.WAV"), NULL, SND_ASYNC);}
            paginaVectori();
        }
    }
}
