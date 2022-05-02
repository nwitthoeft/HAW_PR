#pragma once
#include "funktionen.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <CTYPE.H>

int prosumUndEingabe() {
	int n;
	float pro = 1; //Initialisierung mit neutralen Element, bei Produkt = 1;
	float sum = 0;		//Initialisierung mit neutralen Element, bei Summe = 0;

	int test;
	int test2;

	printf("In diesem Programm koennen Sie Zahlen eingeben. Aus den Zahlen wird die Summe und das Produkt gebiltet\n");
	printf("Wie viele Zahlen wollen Sie eingeben?\n");


	test = scanf_s("%d", &n);
	fehlercheckint(test, &n);

	float* zahlen = (float*)malloc(n * sizeof(float)); //Dynamische Länge des Vektors


	/*
	Wenn der Zeiger auf NULL entspricht wird das Programm beendet,
	da wenn zum Beispiel die Wortlänge (wortLaenge) == 0 entspircht,
	dann kann auch kein Speicherort mit "0" initialisiert werden.
	*/
	if (zahlen == NULL) {
		return(1);
	}

	printf("Geben Sie die erste Zahl ein\n");
	for (int k = 0; k < n; k++) {

		test2 = scanf_s("%f", &zahlen[k]);
		fehlercheckfloat(test2, &zahlen[k]);
		printf("Geben Sie die naechste Zahl ein\n");
	}

	prosum(n, zahlen, &pro, &sum);

	printf("Das Produkt des Zahlenvektors ist %f\n", pro);
	printf("Das Summe des Zahlenvektors ist %f\n", sum);

	return(0);
}

void prosum(int n, float* zahlen, float* pro, float* sum) {
	for (int k = 0; k < n; k++) {
		*sum += *(zahlen + k);
		*pro *= *(zahlen + k);
	}
	return;
}

void fehlercheckint(int test1, int* x) {
	int temp;
	while (test1 != 1) {
		printf("Falsche Eingabe, wiederholen Sie die eingabe\n");
		while ((temp = fgetc(stdin)) != '\n' && temp != EOF); // or while((temp=getchar()) != EOF && temp != '\n');
		test1 = scanf_s("%d", &*x);
	}
	return;
}

void fehlercheckfloat(int test1, float* x) {
	int temp;
	while (test1 != 1) {
		printf("Falsche Eingabe, wiederholen Sie die eingabe\n");
		while ((temp = fgetc(stdin)) != '\n' && temp != EOF); // or while((temp=getchar()) != EOF && temp != '\n');
		test1 = scanf_s("%f", &*x);
	}
	return;
}

//Aufgabe 2


void selectSortUndEingabe() {
	int i;
	int arr[LENGTH];

	srand(100);
	printf("Vor dem Sortieren\n");

	for (i = 0; i < LENGTH; i++)
	{
		arr[i] = rand();
		printf("%6d", arr[i]);
	}

	printf("\n");
	selectSort(LENGTH, arr);

	printf("Nach dem Sortieren\n");
	for (i = 0; i < LENGTH; i++)
		printf("%6d", arr[i]);
	printf("\n");
}

void selectSort(int n, int* arr) {
	int j = 0;
	while (j < n - 1)
	{
		int min = j;
		int	i = j + 1; //Dadurch wird der nächste Wert im Arrey mit dem vorherigen verglichen

		while (i < n)
		{
			if (arr[i] < arr[min]) //Wenn der nächste Wert im array kleiner ist als der vorherige kleinste Wert wird dieser der kleinste Wert.
			{
				min = i;
			}
			i++;
		}
		int b = arr[j]; //Hier findet die Vertauschen der Werte statt.
		arr[j] = arr[min];
		arr[min] = b;
		j++;
	}

	return;
}
/*
int vokoleString(char* str) {


}
*/

int myStrlen(char s[300]) { //einlesen von string mit fgets(eingabestrAnz, 100, stdin);

	int i = 0;

	while (s[++i] != '\n'); //fgets ließt dem kompleten String ein und packt dahinter ein '\n', statt '\0' bei scan_f("%s", vaiable) https://www.includehelp.com/c/c-program-to-read-string-with-spaces-using-scanf-function.aspx

	return(i);
}

int myStrlen2(char s[300]) { //scanf_s

	int i = 0;

	while (s[++i] != '\0');

	return(i);
}

int suchBuchstabeEingabe() {

	char c;
	//char s[300];
	//char pruefchar;
	int test;
	//int groesse;
	int groessevokale = 0;

	char buchstabenListe[] = {'a','e','i','o','u','A','E','I','O','U'};

	int buchstabenListeAnzahl = sizeof(buchstabenListe) / sizeof(buchstabenListe[0]); //Anzahl der Elemente in buchstabenListe
	int summmeDerVokale = 0;

	char** woerterListe;
	int anzahlDerZeichenketten;
	char tempBuffer[BUFFER_GROESSE];
	int wortLaenge = 0;

	// if (erg == NULL) {
	//     printf("Error! memory not allocated.");
	//     exit(0);
	// }
	printf("Wie viele Zeichenketten wollen Sie testen:\n");

	do {
		printf("Geben Sie eine positive Ganzzahl ein.\n");
		test = scanf_s("%d", &anzahlDerZeichenketten);
		fehlercheckint(test, &anzahlDerZeichenketten);
	} while (anzahlDerZeichenketten == 0); //Es darf keine '0' eingegeben werden sonst gibt es bie malloc ein Problem
		

	woerterListe = malloc(anzahlDerZeichenketten * sizeof(char*)); //Dynamische Zuweisung der Wortanzahl
	
	
	while ((c = fgetc(stdin)) != '\n' && c != EOF);

	printf("\n");
	/*
	Einlesen der Wörter
	*/
	for (int n = 0; n < anzahlDerZeichenketten; n++) {
		printf("Geben Sie die Zeichenkatte %d ein\n", n+1);
		fgets(tempBuffer, BUFFER_GROESSE, stdin);

		wortLaenge = strlen(tempBuffer);
		tempBuffer[wortLaenge - 1] = '\0'; //Das \n aus fgets wird mit \0 ersetzt
		

		woerterListe[n] = (char*) malloc(wortLaenge * sizeof(char));
		if (woerterListe[n] == NULL) {
			return(1);
		}
		strcpy_s(woerterListe[n], wortLaenge, tempBuffer);
		
	}


	/*
	Auslesen der Postion der Buchstaben im Wort aus der Wörterliste. Und Ausgabe der Gesammten gefundene Buchstaben in den Wörtern. 
	*/

	for(int m=0; m < anzahlDerZeichenketten; m++)
	for (int k = 0; k < buchstabenListeAnzahl; k++) {

		int* erg = myStrchr2(woerterListe[m], buchstabenListe[k], &groessevokale);

		if (groessevokale != 0) {
		printf("Stellen des Vokals %c in der (%d.) Zeichenkette %s : ", buchstabenListe[k], m + 1, woerterListe[m]);
		}
		else {
			continue;
		}

		for (int i = 0; i < groessevokale; i++)
		{
			if (groessevokale != 0) {
				printf(" %d ", erg[i]);
			}
			else {
				continue;
			}
		}
		printf("\n\n");
		summmeDerVokale += groessevokale;
		free(erg);
	}

	printf("\n Anzahl der Vokale insgesamt: %d \n", summmeDerVokale);

	return(0);
}



int* myStrchr2(char *s1, char c, int* mallocgroesse){
	int laenge = strlen(s1); //länge des strings
	int i;
	int groesse = 0;
	int l = 0;

	for (i = 0; i < laenge; i++) {	//Hier wird die Länge des Strings rausgefunden für den integer array "ergfunk" mit variablen Speicherplatz.

		if (s1[i] == c)				//ergfunk benötigt dei Größe von der Anzahl der gefundenen Charaktären im String.
		{
			groesse++;
		}

	}

	int* ergfunk = (int*)malloc(groesse * sizeof(int)); //Der integer array bekommt die benötigte Größe, herausgefunden wurde.

	*mallocgroesse = groesse;

	if (ergfunk == NULL) { //Bei Fehler Soll die Variable zurückgegeben werden "return(-1)" ist auch stattdessen möglich.
		return(ergfunk);
	}

	if (groesse == 0) { //groesse darf nicht gleich '0' sein sonst gibt es Probleme bei malloc
		return(ergfunk);
	}

	for (i = 0; i < laenge; i++) {// Hier wird auf die passende Länge des String, seine Speicherplätze ein integer Wert zugeordnet, der die Stelle des Charaktärs im String darstellt.

		if (s1[i] == c)
		{
			ergfunk[l] = i + 1; //Hier findet Zuordnung statt
			l++;
		}

	}
	return ergfunk;
}
