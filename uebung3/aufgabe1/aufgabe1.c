/*
Dateiname: Euklidischer Algorithmus
Auto: Nicolas Witthöft
Version: 1.0
Datum: 05.11.2021
Beschreibung: In diesem Programm wird die Funktion des Euklidischer Algorithmus in iterativ und rekusiv geschrieben. Die Eingabe und Ausgabe von Werten geschieht in der main()-Funktion
*/
#include <stdio.h>
#include "ggt.h"

void main()
{
	char beenden;
	int ersteZahl;
	int zweiteZahl;

	printf("In diesem Programm wird der groesste gemeinsame Teiler aus zwei Ganzzahlen gebildet\n");
	
	do {
		printf("Geben Sie die erste Zahl ein.\n");
		scanf_s("%d", &ersteZahl);

		printf("Geben Sie die zweite Zahl ein.\n");
		scanf_s("%d", &zweiteZahl);
		int primfaktorzerleugung_ersteZahl = primfaktoren(ersteZahl);
		int primfaktorzerleugung_zweiteZahl = primfaktoren(zweiteZahl);
		int ergebnis = euklidischer_algorithmus_iterativ(ersteZahl, zweiteZahl);

			printf("Der ggt von %d und %d ist %d \n", ersteZahl, zweiteZahl, ergebnis);
		
	} while ((beenden = getchar()) != 'b');
	return;
}



