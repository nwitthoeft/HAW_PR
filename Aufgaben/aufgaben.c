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
#include <math.h>
#include <time.h>
#include <stdlib.h>


void main()
{
	char eingabe;

	double x;
	int nachkommastellen;
	double 	fehler;
	int genauigkeit;

	int eingabe1, eingabe2;

	int test1;


	do {
		printf("\nFolgende Funktionen sind verfuegbar:\n\n"
			"U/u: Wurzelziehen\n"
			"P/p: Zahlenraten,  \n"
			"O/o: Operatoren\n"
			"M/m: Groessere Zahl ausgabe\n"
			"B/b: Beenden des Programmes\n\n"
			"Geben Sie einen der oben genannten Operatoren an\n\n"); //Eingabe um den Operator den festzulegen.
		scanf_s(" %c", &eingabe, 1);

		switch (eingabe)
		{
		case 'U':
		case 'u':
			printf("Geben Sie eine Zahl ein fuer die, die Wurzel gezogen werden soll\n");
			test1 = scanf_s("%lf", &x);
			fehlercheckdouble(test1, &x);
			printf("Geben Sie einen Genauigkeitswert an\n");
			test1 = scanf_s("%d", &genauigkeit);
			fehlercheckint(test1, &genauigkeit);
			printf("Geben Sie den relativen tatsaechlichen Fehler an, um den die Zahl nach dem Komma streut. Zum Beispiel 0.0000001 fuer  0.00001 Prozent \n");
			scanf_s("%lf", &fehler);
			printf("Wie viele Nachkommastellen sollen ausgegeben werden\n");
			scanf_s("%d", &nachkommastellen);
			mySqrt(x, genauigkeit, fehler, nachkommastellen);
			break;
		case 'P':
		case 'p':
			zahlraten();
			break;
		case 'O':
		case 'o':
			myOperationen();
			break;
		case 'M':
		case 'm':
			printf("In diesem Programm werden zwei Ganzzahlen eingelesen und die größere wird wieder ausgegeben\n");
			printf("Geben Sie dei erste Zahl ein\n");
			scanf_s("%d", &eingabe1);
			printf("Geben Sie die zweite Zahl ein\n");
			scanf_s("%d", &eingabe2);
			groessereZahl(eingabe1, eingabe2);
			break;
		default:
			printf("Sie haben keinen der oben genannte Operatoren ausgewaehlt. Bitte versuchen Sie es nochmal\n");
			break;
		}


	} while ((eingabe != 'b') && (eingabe != 'B'));
	return;
}

