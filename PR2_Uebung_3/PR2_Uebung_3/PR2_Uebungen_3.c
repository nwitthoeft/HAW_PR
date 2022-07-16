#pragma once
#include "funktionen.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <CTYPE.H>
void main()
{
	char eingabe;
	element* kopf = NULL;
	element* ende = NULL;

	
	do {
		printf("\nFolgende Funktionen sind verfuegbar:\n\n"
			"E/e: Eingabe von Studenten Daten\n"
			"A/a: Ausgabe der Liste\n"
			"S/s: Studenten suche\n"
			"L/l: Loeschen von Studenten Daten\n"
			"Z/z: Anzahl der der Studeneten in der Liste\n"
			"K/k: Liste einfach sortieren\n"
			"B/b: Beendigung des Programms\n\n"
			"Geben Sie einen der oben genannten Operatoren an\n"); //Eingabe um den Operator den festzulegen.
		scanf_s(" %c", &eingabe, 1);
		switch (eingabe) {
		case 'E':
		case 'e':
			einlesenVonDaten(&kopf, &ende);
			break;
		case 'A':
		case 'a':
			ausgabe(&kopf);
			break;
		case 'S':
		case 's':
			suche(&kopf);
			break;
		case 'L':
		case 'l':
			loeschenStudenten(&kopf);
			break;
		case 'Z':
		case 'z':
			printf("Die Anzahl der Studenten beträgt: %d", zaehleAnzListenElemente(&kopf));
			break;
		case 'K':
		case 'k':
			meineSortierungNichtVerschachtelterZeiger(&kopf, &ende);
			break;
		case 'B':
		case 'b':
			printf("beenden...\n");
			break;
		default:
			printf("Sie haben keinen der oben genannte Operatoren ausgewaehlt. Bitte versuchen Sie es nochmal\n");
			break;
		}
	} while ((eingabe != 'b') && (eingabe != 'B')); //Beendigungsgrund
	loescheListe2(&kopf);
	return;
}