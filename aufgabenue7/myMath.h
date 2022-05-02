#pragma once
double myFakultaet(double val);
double myPow(double x, int i);
double mySinus(double x, int genauigkeit);
void  kleineseinmaleins(int grenzwert);
/*
Hier beginnen Funktionen zur Übung 5
*/
void asciswitch(char eingabe2[50]);
int asciswitch2(char eingabe2);
int quersumme_berechnen(int zahl);
int diff(int zahl1, int zahl2);
int buchstabezuAlphabetNummer(char grossbuchstabe);
void euroscheinpruefer(char grossbuchstabe, int zahl1, int zahl2, int pruefzahl);

/*
Hier beginnen Funktionen zur Übung 6
*/
void mySqrt(double x, int genauigkeit, double fehler, int nachkommastellen);
zahlraten(void);
int myZufallszahl();
int myOperationen();
void groessereZahl(int eingabe1, int eingabe2);
/*
Hier beginnen Funktionen zur Übung 7
*/
int myStrlen(char s[300]);
int* myStrchr(char s1[300], char c, int* mallocgroesse);
int myStrcat(char s1[300], char s2[300]);
void selectSort(int n, int arr[]);
void fehlercheckdouble(int test1, double* x);
void fehlercheckint(int test1, int* x);
void fehlercheckchar(char* c);
void fehlercheckkeinbockmehr(int test1, char* string1[300], char* string2[300]);
void stringbuchstabentest(char eingabe[50]);
void fehlercheckfloat(int test1, float* x);