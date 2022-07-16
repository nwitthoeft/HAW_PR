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
	char eingabe2;
	sAirport* kopf = NULL;
	sAirport* ende = NULL;
	int m;
	int n = 0;
	sAirport* kopfWegpunkt = NULL;
	int kontrollvar = 0;

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
			if (kontrollvar != 1) {
				n = listeEinsetzen(&kopf);
				kontrollvar = 1;
			}
			break;
		case 'A':
		case 'a':
			do {
				printf("\nFolgenden Funktionen sind verfuegbar:\n\n"
					"E/e: Ausgabe der gesammten Flughaefen\n"
					"A/a: Ausgabe der Wegpunktliste\n"
					"B/b: Beendigung der Programmschleife\n\n"
					"Geben Sie einen der oben genannten Operatoren an\n");
				scanf_s(" %c", &eingabe2, 1);
				switch (eingabe2) {
				case 'E':
				case 'e':
					ausgabe(&kopf);
					break;
				case 'A':
				case 'a':
					ausgabe(&kopfWegpunkt);
					break;
				case 'B':
				case 'b':
					printf("beenden...\n");
					break;
				default:
					printf("Sie haben keinen der oben genannte Operatoren ausgewaehlt. Bitte versuchen Sie es nochmal\n");
					break;
				}
			} while ((eingabe2 != 'b') && (eingabe2 != 'B'));
			break;
		case 'S':
		case 's':
			suche(&kopf);
			break;
		case 'G':
		case 'g':
			if (kontrollvar != 1) {
				n = listeEinsetzen(&kopf);
				kontrollvar = 1;
			}
			kopfWegpunkt = enterWaypoints(&kopf, n, &m);
			ausgabe(&kopfWegpunkt);
			printWaypoints(&kopf, &kopfWegpunkt, m);
			break;
		case 'L':
		case 'l':
			loescheListe3(&kopfWegpunkt);
			printf("Die Liste wurde geloescht");
			break;
		case 'N':
		case 'n':
			if (kontrollvar != 1) {
				n = listeEinsetzen(&kopf);
				kontrollvar = 1;
			}
			naehesterFlughafen(&kopf, n);
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
	loescheListe2(&kopf);
	loescheListe2(&kopfWegpunkt);
	//system("pause"); //für klausur
	return;
}