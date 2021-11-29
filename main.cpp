#include <iostream>
#include <cstring>
#include <math.h>
#include <stdio.h>
using namespace std;

bool douaMatrice = false;
bool fisier = false;
char operatie[21];
char numeFisier[101];
char s[10];
int mat1[11][11], linii1, coloane1, mat2[11][11], linii2, coloane2;
int rez[22][22], linii3, coloane3;

void afisareRezultat();
void scadere();
void adunare();
void fileOrKey();
void citireMatrice(int a[11][11], int b[11][11]);
void intro();
void afisareMat(int a[11][11], int b[11][11]);

int main()
{

    intro();
    //afisareMat(mat1, mat2, linii1, coloane1, linii2, coloane2);
    return 0;
}

void scadere()
{
    douaMatrice = true;
    citireMatrice(mat1, mat2);
    if(linii1 != linii2 || coloane1 != coloane2)
    {
        cout<<"Matricele nu au acelasi numar de linii / coloane!";
        exit(1);
    }
    linii3 = linii1;
    coloane3 = coloane1;
    for(int i = 1; i <= linii1; i++)
        for(int j = 1; j <= coloane1; j++)
            rez[i][j] = mat1[i][j] - mat2[i][j];
    afisareRezultat();
}

void adunare()
{
    douaMatrice = true;
    citireMatrice(mat1, mat2);
    if(linii1 != linii2 || coloane1 != coloane2)
    {
        cout<<"Matricele nu au acelasi numar de linii / coloane!";
        exit(1);
    }
    linii3 = linii1;
    coloane3 = coloane1;
    for(int i = 1; i <= linii1; i++)
        for(int j = 1; j <= coloane1; j++)
            rez[i][j] = mat1[i][j] + mat2[i][j];
    afisareRezultat();
}

void fileOrKey()    /// verificare daca sa citeasca dintr-un fisier sau de la tastatura
{
    cout<<"Citire din fisier sau tastatura?"<<endl;
    cin.getline(s, 10);
    if(strcmp(s, "fisier") == 0 || strcmp(s, "f") == 0)
    {

        cout<<"Introduceti numele fisierului aici:"<<endl;
        cin.getline(numeFisier, 100);
        fisier = true;
    }
}

void citireMatrice(int a[11][11], int b[11][11])
{
    fileOrKey();

    if(!douaMatrice) {
        cout<<"Introduceti numarul de linii: ";
        cin>>linii1;
        cout<<"Introduceti numarul de coloane: ";
        cin>>coloane1;
    }
    else {
        cout<<"Introduceti numarul de linii pentru prima matrice: ";
        cin>>linii1;
        cout<<"Introduceti numarul de coloane pentru prima matrice: ";
        cin>>coloane1;
        cout<<"Introduceti numarul de linii pentru a doua matrice: ";
        cin>>linii2;
        cout<<"Introduceti numarul de coloane pentru a doua matrice: ";
        cin>>coloane2;
    }


    if(fisier) {
        FILE *f = fopen(numeFisier, "r");
        if(f == NULL) {
            cout<<"Fisierul nu a fost gasit!"<<endl;
            exit(1);
        }
        if(!douaMatrice) {
            for(int i = 1; i <= linii1; i++)
                for(int j = 1; j <= coloane1; j++)
                    fscanf(f, "%d", &a[i][j]);
        }
        else {
            for(int i = 1; i <= linii1; i++)
                for(int j = 1; j <= coloane1; j++)
                    fscanf(f, "%d", &a[i][j]);
            for(int i = 1; i <= linii2; i++)
                for(int j = 1; j <= coloane2; j++)
                    fscanf(f, "%d", &b[i][j]);
        }


        fclose(f);
    }
    else {
        for(int i = 1; i <= linii1; i++)
            for(int j = 1; j <= coloane1; j++)
                cin>>a[i][j];
        for(int i = 1; i <= linii2; i++)
            for(int j = 1; j <= coloane2; j++)
                cin>>b[i][j];
    }
}

void intro()
{
    cout<<"Introduceti operatia dorita: ";
    cin.getline(operatie, 20);
    if(strcmp(operatie, "+") == 0 || strcmp(operatie, "plus") == 0 || strcmp(operatie, "adunare") == 0)
        adunare();
    else if(strcmp(operatie, "-") == 0 || strcmp(operatie, "minus") == 0 || strcmp(operatie, "scadere") == 0)
        scadere();
//    else if(strcmp(operatie, "*") == 0 || strcmp(operatie, "ori") == 0 || strcmp(operatie, "inmultire") == 0)
//        inmultire();
//    else if(strcmp(operatie, "^") == 0 || strcmp(operatie, "putere") == 0 || strcmp(operatie, "ridicare la putere") == 0)
//        putere();
    else if(strcmp(operatie, "citire1") == 0 || strcmp(operatie, "c1") == 0) /// pt citirea si afisarea unei singure matrice
    {
        citireMatrice(mat1, mat2);
        afisareMat(mat1, mat2);
    }
    else if(strcmp(operatie, "citire2") == 0 || strcmp(operatie, "c2") == 0) /// pt citirea si afisarea a doua matrice
    {
        douaMatrice = true;
        citireMatrice(mat1, mat2);
        afisareMat(mat1, mat2);
    }
}

void afisareMat(int a[11][11], int b[11][11]) /// afiseaza matricele introduse
{
    if(!douaMatrice)
    {
        cout<<"Matricea este: "<<endl;
        for(int i = 1; i <= linii1; i++)
        {
            for(int j = 1; j <= coloane1; j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
    else {
        cout<<"Prima matrice este: "<<endl;
        for(int i = 1; i <= linii1; i++)
        {
            for(int j = 1; j <= coloane1; j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
        cout<<"A doua matrice este: "<<endl;
        for(int i = 1; i <= linii2; i++)
        {
            for(int j = 1; j <= coloane2; j++)
                cout<<b[i][j]<<" ";
            cout<<endl;
        }
    }
}

void afisareRezultat()
{
    for(int i = 1; i <= linii3; i++)
    {
        for(int j = 1; j <= coloane3; j++)
            cout<<rez[i][j]<<" ";
        cout<<endl;
    }
}