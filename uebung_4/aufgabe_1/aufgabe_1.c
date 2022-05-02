/*
Dateiname: Mathebib
Auto: Nicolas Witthöft
Version: 1.0
Datum:	20.11.2021
Beschreibung: In diesem Programm wird die Funktion der Potenz-, Fakultätsfunktion, sowie des Sinus verwendet. Außerdem ist eine Einmalseinsfuktion implementiert. Die Eingabe und Ausgabe von Werten geschieht in der main()-Funktion
*/

#include <stdio.h>
#include "myMath.h"


void main()
{
	double ersteZahl;
	char eingabe;

	double basis;
	int exponent;

	double x;
	int genauigkeit;

	int grenzwert;

	do {
	printf("Folgende Funktionen sind verfuegbar\n\n"
			"F/f: Fakulteatfunktion\n"
			"P/p: Potenzfunktion\n"
			"S/s: Sinusfunktion\n"
			"M/m: Einmaleinstabelle\n"
			"B/b: Beenden des Programmes\n\n"
			"Geben Sie einen der oben genannten Operatoren an\n\n"); //Eingabe um den Operator den festzulegen.
	scanf_s(" %c", &eingabe, 1);

	switch (eingabe) {
	case 'F':
	case 'f':
		printf("In diesem Programm wird die Fakultaetfunktion verwendet\n");
		printf("Geben Sie die erste Zahl ein.\n");
		scanf_s("%lf", &ersteZahl);
		double ergebnis = myFakultaet(ersteZahl);
		printf("Die Fakultaet von %lf ist %lf \n", ersteZahl, ergebnis);
		break;
	case 'P':
	case 'p':
		printf("In diesem Programm wird die Potenzfunktion verwendet\n");
		printf("Geben Sie die den Wert fuer die Basis ein.\n");
		scanf_s("%lf", &basis);
		printf("Geben Sie die den Wert fuer die Exponent ein.\n");
		scanf_s("%d", &exponent);
		double ergebnis_1 = myPow(basis, exponent);
		printf("Die Potenz aus der Basis %lf un dem Exponenten %d ist %lf \n", basis, exponent, ergebnis_1);
		break;
	case 'S':
	case 's':
		printf("In diesem Programm wird die Sinusfunktion verwendet\n");
		printf("Geben Sie die Stelle an fuer den der Sinus berechnet werden soll (Geben Sie die Werte in Gradmass an)\n");
		scanf_s("%lf", &x);
		printf("Geben Sie die den Wert fuer die Genauigkeit ein.\n");
		scanf_s("%d", &genauigkeit);
		double ergebnis_2 = mySinus(x, genauigkeit);
		printf("Der Wert des Sinus für den Winkel %lf mit der Genauigkeit (Polynomlänge) %d betraegt sin(%lf°) = %lf\n", x, genauigkeit,x, ergebnis_2);
		break;
	case 'M':
	case 'm':
		printf("In diesem Programm wird eine Tabelle des Einmaleins bis zum gewählten Grenzwert gebildet\n");
		printf("Geben Sie den Grenzwert an.\n");
		scanf_s("%d", &grenzwert);
		kleineseinmaleins(grenzwert);
		break;
	default:
		printf("Sie haben keinen der oben genannte Operatoren ausgewaehlt. Bitte versuchen Sie es nochmal\n");
		break;
	}


	} while ((eingabe != 'b') && (eingabe != 'B'));
	return;
}
