/*
Dateiname: Wurzel-Rechner
Autor: Simon Freund
Version: 1.0
Datum: 31.12.2021
Kurze Beschreibung des Programms: 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "myMath.h"

void main ()
{
	char auswahl;
	double zahl_w;
	double ergebnis_w = 0;
	int genauigkeit_w, stellen_w, zufall_z, eingabe_z, zahl1_g, zahl2_g;

	do
	{
		printf("Geben Sie ein was Sie machen moechten:\n");
		printf("W/w: fuer wurzelziehen,\nZ/z: fuer Zufallszahl,\nO/o fuer Operationen anzeigen,\nG/g fuer groesser/kleiner, B/b fuer Beenden:\n");
		scanf_s(" %c", &auswahl, 1);
		switch (auswahl)
		{
		case 'W':
		case 'w':
			printf("Bitte Zahl eingeben, deren Wurzel berechnet werden soll:");
			scanf_s("%lf", &zahl_w);
			printf("Bitte Anzahl der Genauigkeit fuer die Berechnung der Quadratwurzel angeben:");
			scanf_s("%d", &genauigkeit_w);
			printf("Bitte Stellen hinter dem Komma angeben:");
			scanf_s("%d", &stellen_w);
			if (zahl_w < 0)
			{
				printf("Wurzel von negativen Zahlen nicht im Reellen moeglich!\n");
				break;
			}
			else
			{
				ergebnis_w = mySqrt(zahl_w, genauigkeit_w);


				printf("Die Wurzel von %lf betraegt: %.*lf\n", zahl_w, stellen_w, ergebnis_w);
				break;
			}
		case 'Z':
		case 'z':
			zufall_z = myZufallszahl();
			printf("Geben Sie bitte eine Zahl zwischen 1 und 100 ein:");
			scanf_s("%d", &eingabe_z);
			int i = 1;
			do
			{
				myAusgabe(zufall_z, eingabe_z);
				scanf_s("%d", &eingabe_z);
				i++;
			} while (eingabe_z != zufall_z && i < 6);
			if (i == 6)
			{
				printf("Sie haben leider keine Versuche mehr. Die Zahl waere %d gewesen.\n", zufall_z);
			}
			break;
		case 'O':
		case 'o':
			myOperationen();
			break;
		case 'G':
		case 'g':
			printf("Geben Sie eine erste Zahl ein:");
			scanf_s("%d", &zahl1_g);
			printf("Geben Sie eine zweite Zahl ein:");
			scanf_s("%d", &zahl2_g);
			zahl1_g > zahl2_g ? printf("Die groesser Zahl ist: %d", zahl1_g) : printf("Die groessere Zahl ist: %d", zahl2_g);
			break;
		default:
			if (auswahl != 'b' && auswahl != 'B')
			{
				printf("Falsche Eingabe");
			}
			break;
		}
	} while (auswahl != 'b' && auswahl != 'B');
	return;
}