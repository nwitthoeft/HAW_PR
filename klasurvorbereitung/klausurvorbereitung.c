/*
Autor: Nicolas Witthoeft
Beschreinung:
Version:
*/
#pragma once
#include "funktionen.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <CTYPE.H>

void main() {
	char eingabe;
	sDatum* kopf = NULL;

do {
	printf("\nFolgenden Funktionen sind verfuegbar:\n\n"
		"E/e: Eingabe von Daten\n"
		"A/a: Ausgabe der Daten im Heap\n"
		"S/s: Suche einen Flughafen\n"
		"G/g: Flugroute\n"
		"L/l: Flugroute loeschen\n"
		"N/n: Naehester Flughafen\n"
		"B/b: Beendigung des Programmes\n\n"
		"Geben Sie einen der oben genannten Operatoren an\n");
	scanf_s(" %c", &eingabe, 1);
	switch (eingabe) {
	case 'E':
	case 'e':
		einlesenText();
		break;
	case 'A':
	case 'a':
		summiereneingabe();
		break;
	case 'S':
	case 's':
		kopf = datumZuweisen(kopf);
		break;
	case 'G':
	case 'g':
		vonVorneAusgabe(kopf);
	case 'L':
	case 'l':

	case 'N':
	case 'n':

		break;
	case 'B':
	case 'b':
		printf("beenden...\n");
		break;
	default:
		printf("Sie haben keinen der oben genannte Operatoren ausgewaehlt. Bitte versuchen Sie es nochmal\n");
		break;
	}
} while ((eingabe != 'b') && (eingabe != 'B'));

return;
}
