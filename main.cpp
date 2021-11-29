#include <iostream>
#include <cstring>
#include <math.h>
#include <stdio.h>
using namespace std;

//variabile matrice
bool douaMatrice = false;
bool fisier = false;
char operatie[21];
char numeFisier[101];
char s[10];
int mat1[11][11], linii1, coloane1, mat2[11][11], linii2, coloane2;
int rez[22][22], linii3, coloane3;

//variabile vectori
char stgSauDr[11];
char crescSauDescresc[11];
int n;
int sum=0;
int produs=1;
int vec[50];
int scalar;

char VsauM[11];

void intro(); //operatie cu vectori sau operatii cu matrice?

//operatii cu matrice
void introM();
void afisareRezultat();
void determinant();
void scadere();
void adunare();
void fileOrKey();
void citireMatrice(int a[11][11], int b[11][11]);
void afisareMat(int a[11][11], int b[11][11]);

//operatii cu vectori
void introV();
void afisareVector(int a[50]);
void citireVector(int a[50]);
void inmultirescalarV();
void adunareElV();
void inmultireElV();
void sortareCrescV();
void sortareDescrescV();
//void shiftareStgV();
//void shiftareDrV();

int main()
{

    intro();
    //afisareMat(mat1, mat2, linii1, coloane1, linii2, coloane2); test123
    return 0;
}

void intro()
{
    cout<<"Doriti sa efectuati o operatie cu vectori sau cu matrice? ";
    cin.getline(VsauM, 10);
    if(strcmp(VsauM, "vectori") == 0 || strcmp(VsauM, "v") == 0)
        introV();
    else if(strcmp(VsauM, "matrice") == 0 || strcmp(VsauM, "m") == 0)
        introM();
}

void determinant() /// deocamdata doar pt matrici de rang 2 sau 3
{
    int det = -9999;
    citireMatrice(mat1, mat2);
    if(linii1 != coloane1)
    {
        cout<<"Numarul de linii nu este egal cu cel de coloane!";
        exit(1);
    }
    if(linii1 > 3 || coloane1 > 3)
    {
        cout<<"Matricea are rang mai mare decat 3";
        exit(1);
    }

    switch (linii1) {
        case 2:
            det = (mat1[1][1] * mat1[2][2]) - (mat1[1][2] * mat1[2][1]);
            break;
        case 3:
            det = (mat1[1][1] * mat1[2][2] * mat1[3][3]) + (mat1[1][3] * mat1[2][1] * mat1[3][2]) + (mat1[1][2] * mat1[2][3] * mat1[3][1]) - (mat1[1][3] * mat1[2][2] * mat1[3][1]) - (mat1[2][1] * mat1[1][2] * mat1[3][3]) - (mat1[3][2] * mat1[2][3] * mat1[1][1]);
            break;
        default:
            cout<<"Matricea nu are nici rang 2, nici 3";
    }
    cout<<det;

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

void introM()
{
    cout<<"Introduceti operatia dorita: ";
    cin.getline(operatie, 20);
    if(strcmp(operatie, "+") == 0 || strcmp(operatie, "plus") == 0 || strcmp(operatie, "adunare") == 0)
        adunare();
    else if(strcmp(operatie, "-") == 0 || strcmp(operatie, "minus") == 0 || strcmp(operatie, "scadere") == 0)
        scadere();
    else if(strcmp(operatie, "det") == 0 || strcmp(operatie, "||") == 0 || strcmp(operatie, "determinant") == 0)
        determinant();
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

void introV()
{
    cout<<"Introduceti operatia dorita: ";
    cin.getline(operatie, 30);
    if(strcmp(operatie, "+") == 0 || strcmp(operatie, "plus") == 0 || strcmp(operatie, "adunare") == 0)
    adunareElV();
    else if(strcmp(operatie, "*") == 0 || strcmp(operatie, "ori") == 0 || strcmp(operatie, "inmultire") == 0)
    inmultireElV();
    /*else if(strcmp(operatie, "shift") == 0 || strcmp(operatie, "shiftare") == 0)
    {
        cout<<"La stanga sau la dreapta?";
        cin.getline(stgSauDr, 10);
        if(strcmp(stgSauDr, "stanga") == 0 || strcmp(stgSauDr, "stg") == 0 || strcmp(stgSauDr, "s") == 0)
            shiftareStgV();
        else if(strcmp(stgSauDr, "dreapta") == 0 || strcmp(stgSauDr, "dr") == 0 || strcmp(stgSauDr, "d") == 0)
            shiftareDrV();
    }*/
    else if(strcmp(operatie, "sortare") == 0)
    {
        cout<<"Crescator sau descrescator? ";
        cin.getline(crescSauDescresc, 10);
        if(strcmp(crescSauDescresc, "crescator") == 0 || strcmp(crescSauDescresc, "cresc") == 0 || strcmp(crescSauDescresc, "c") == 0)
            sortareCrescV();
        else if(strcmp(crescSauDescresc, "descrescator") == 0 || strcmp(crescSauDescresc, "descresc") == 0 || strcmp(crescSauDescresc, "d") == 0)
            sortareDescrescV();
    }
    else if(strcmp(operatie, "citire") == 0)
    {
        citireVector(vec);
        afisareVector(vec);
    }
    else if(strcmp(operatie, "inmultire scalar") == 0 || strcmp(operatie, "* scalar") == 0)
        inmultirescalarV();
}

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

void adunareElV()
{
    citireVector(vec);
    for(int i=0;i<n;i++)
    {
        sum = sum + vec[i];
    }
    cout<<"Suma elementelor este: "<<sum;
}

void inmultireElV()
{
    citireVector(vec);
    for(int i=0;i<n;i++)
    {
        produs = produs * vec[i];
    }
    cout<<"Produsul elementelor este: "<<produs;
}

void sortareCrescV()
{
    citireVector(vec);
    for (int i = 0; i < n-1; i++){
    for (int j = i+1; j < n; j++){
        if (vec[i] > vec[j]){
                int aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
        afisareVector(vec);
}

void sortareDescrescV()
{
    citireVector(vec);
    for (int i = 0; i < n-1; i++){
    for (int j = i+1; j < n; j++){
        if (vec[i] < vec[j]){
                int aux = vec[j];
                vec[j] = vec[i];
                vec[i] = aux;
            }
        }
    }
    afisareVector(vec);
}

void inmultirescalarV()
{
    citireVector(vec);
    cout<<"Introduceti numarul cu care vreti sa inmultiti vectorul: ";
    cin>>scalar;
    for (int i=0; i<n; i++)
    {
        vec[i] = vec [i] * scalar;
    }
    afisareVector(vec);
}
