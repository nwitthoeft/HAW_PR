#pragma once
#include "funktionen.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <CTYPE.H>

void einlesenText() {
	char c;
	//int anzText;
	char buffer[BUFFER_SIZE] = "0";
	int textLaenge = 0;
	char* text = "0";

	int anzText;
	char *concat=(char*)calloc(BUFFER_SIZE, sizeof(char));
	int gesammteTextLaenge = 0;
	//printf("Wie viele Texte möchten sie einlesen\n");
	//scanf_s("%d", anzText);

	printf("Wie viele Texte möchten sie einlesen\n");
	scanf_s("%d", &anzText);
	while ((c = fgetc(stdin)) != '\n' && c != EOF);

	for (int i = 0; i < anzText; i++) {

		printf("Geben Sie eine Zeichenkette ein\n");
		
		fgets(buffer, BUFFER_SIZE, stdin);
		textLaenge = strlen(buffer);
		buffer[textLaenge - 1] = '\0'; //Das \n aus fgets wird mit \0 ersetzt
		text = (char*)malloc(textLaenge * sizeof(char));

		if (text == NULL) {
			printf("Fehler zu viele Zeichen\n");
			exit(-1);
		}
		strcpy_s(text, textLaenge, buffer);
		gesammteTextLaenge += textLaenge;
		if (gesammteTextLaenge < BUFFER_SIZE) {
			if (text == 0) {
				return;
			}
			strcat_s(concat, BUFFER_SIZE, text);
		}
		else {
			printf("Zeichenkette zu groß!\n");
			return;
		}
	}
	printf("%s", concat);
	return;
}

int summiereneingabe() {
	int i, n;
	double a[MAX], sum, max;
	printf("Wieviele Zahlen wollen Sie einlesen, 1 <= n <= %d, n=", MAX);
		scanf_s("%d", &n);
			printf("\n Geben Sie nun die Zahlen einzeln ein:\n");
	for (i = 0; i < n; i++)
	{
		printf("  a[%2d] = ", i);
		scanf_s("%lf", &a[i]);
	}
	sum_max(a, n, &sum, &max);

	printf("Die Summe der Komponenten lautet, sum = %f\n", sum);
	printf("Die maximale Komponente lautet, max = %f\n", max);
	return 0;

}

void sum_max(double a[MAX], int n, double* sum, double* max) {
	*sum = 0;
	for (int i = 0; i < n; i++) {
		*sum += a[i];
		if (*max < a[i]) {
			*max = a[i];
		}
	}
}

sDatum* datumZuweisen(sDatum * kopf) {
	sDatum datum1;
	datum1.tag = 5;
	datum1.monat = Mai;
	datum1.jahr = 2002;
	
	printf("%d.%d.%d\n", datum1.tag, datum1.monat, datum1.jahr);
	printf("%d\n", sizeof(sDatum));
	sDatum* aktuellesDatum = (sDatum*)malloc(sizeof(sDatum));
	if (aktuellesDatum == 0) {
		printf("Speierüberlauf\n");
		return(NULL);
	}
	
	printf("Wie ist der Geburtstag. Geben Sie den Tag des Monats ein lol xD:\n");
	scanf_s("%d", &(aktuellesDatum->tag));
	printf("Die Eingabe war: %d\n", aktuellesDatum->tag);
	printf("Geben Sie den Monat ein:\n");
	scanf_s("%d", &(aktuellesDatum->monat));
	printf("Die Eingabe war: %d\n", aktuellesDatum->monat);
	printf("Geben Sie das Jahr ein:\n");
	scanf_s("%d", &(aktuellesDatum->jahr));
	printf("Die Eingabe war: %d\n", aktuellesDatum->jahr);
	
	
	listevonhinten(aktuellesDatum, &kopf);

	return(kopf);
}

void listevonhinten(sDatum* aktuellesDatum, sDatum** kopf) {
	sDatum* temporaeresElement;

	if (*kopf == NULL) {
		aktuellesDatum->next = NULL;
		aktuellesDatum->prev = NULL;
		*kopf = aktuellesDatum;
	}
	else
	{
		temporaeresElement = *kopf;
		while (temporaeresElement->next != NULL)//Durchlaufen der Liste, bis das ende der Liste erreicht ist.
		{
			temporaeresElement = temporaeresElement->next;
		}
		temporaeresElement->next = aktuellesDatum;    //aktuellesElement (mit den Daten) wird am ende der Liste postioniert.
		aktuellesDatum->prev = temporaeresElement;    //aktuellesElement zeigt auf das vorderes (zuvor letztes Element) Element
		aktuellesDatum->next = NULL;                  //Das aktuelle Elemet muss auf das ende der Liste (= NULL) zeigen
	}

	return;
}

void vonVorneAusgabe(sDatum* kopf)
{
	struct sDatum* aktuellesDatum;
	printf("\nFolgenden Studenten Daten sind gespeichert worden...\n");
	aktuellesDatum = kopf;

	if (aktuellesDatum == NULL) {
		printf("Die Liste ist Leer");
		return;
	}

	while (aktuellesDatum != NULL)
	{
		printf("%d\n", aktuellesDatum->tag);
		printf("%d\n", aktuellesDatum->monat);
		printf("%d\n", aktuellesDatum->jahr);
		aktuellesDatum = aktuellesDatum->next;//lauf
	}
	return;
}