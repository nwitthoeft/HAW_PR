/*
Dateiname:
Auto: Nicolas Witthöft
Version: 1.0
Datum:	01.12.2021
Beschreibung: In diesem Programm wird die Umwandung von Kleinbuchstaben in Großbuchstaben und umgekehrt
*/

#include <stdio.h>
#include<string.h>
#include "myMath.h"



void main()
{
	char eingabe;
	char eingabe2[50];
	char grossbuchstabe;
	int	zahl1;
	int zahl2;
	int pruefzahl;

	do {
		printf("\nFolgende Funktionen sind verfuegbar:\n\n"
					"U/u: Umwandung\n"
					"P/p: Geldpruefung\n"
					"S/s: Sinusfunktion\n"
					"M/m: Einmaleinstabelle\n"
					"B/b: Beenden des Programmes\n\n"
					"Geben Sie einen der oben genannten Operatoren an\n\n"); //Eingabe um den Operator den festzulegen.
		scanf_s(" %c", &eingabe, 1);

		switch (eingabe)
		{
		case 'U':
		case 'u':

			printf("Geben Sie ein String, dessen Charakaere in von Kleinbuchstaben zu Grossbuchstaben und umgekehrt umgewandelt wird\n");
			scanf_s("%s", &eingabe2, 50);
			asciswitch(eingabe2);
			break;
		case 'P':
		case 'p':
			printf("Programm zur Prüfung der Seriennummer eines Geldscheins\n"
				"Bitte geben Sie den Grossbuchstaben ein:\n");
			scanf_s(" %c", &grossbuchstabe, 1);
			printf("Bitte geben Sie die ersten 5 Ziffern ein:\n");
			scanf_s("%d", &zahl1);


			printf("Bitte geben Sie die zweiten 5 Ziffern ein:\n");
			scanf_s("%d", &zahl2);
			printf("Bitte geben Sie die Pruefzahl ein:\n");
			scanf_s("%d", &pruefzahl);
			euroscheinpruefer(grossbuchstabe, zahl1, zahl2, pruefzahl);
			break;
		case 'S':
		case 's':
			break;
		case 'M':
		case 'm':
			break;
		default:
			printf("Sie haben keinen der oben genannte Operatoren ausgewaehlt. Bitte versuchen Sie es nochmal\n");
			break;
		}


	} while ((eingabe != 'b') && (eingabe != 'B'));
	return;
}
