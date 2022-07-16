#include <stdio.h>
#include <string.h>
#include "funktionen.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>

void main(int argc, char* argv[])
{
	char eingabe;
	int kontroll;
	int kontroll2;

	char* zeigervektor[16];



	do {
		printf("\nFolgende Funktionen sind verfuegbar:\n\n"
			"P/p: Produkt und Summe mit Vektoren\n"
			"S/s: selectSort\n"
			"K/k: Vokale suchen\n"
			"M/m: Komandozeile ausgabe\n"
			"B/b: Beendigung des Programms\n\n"
			"Geben Sie einen der oben genannten Operatoren an\n"); //Eingabe um den Operator den festzulegen.
		scanf_s(" %c", &eingabe, 1);

		switch (eingabe) {
		case 'P':
		case 'p':
			kontroll = prosumUndEingabe();
			if (kontroll == 1) {
				printf("Es ist ein Fehler aufgetreten. Überprüfen Sie ob bei der Woerterliste kein leeres Wort vorhanden ist ");
				return;
			}
			break;
		case 'S':
		case 's':
			selectSortUndEingabe();
			break;
		case 'k':
		case 'K':
			kontroll2 = suchBuchstabeEingabe();
			if (kontroll2 == 1) {
				printf("Es ist ein Fehler aufgetreten. Überprüfen Sie ob bei der Wörterliste kein leeres Wort vorhanden ist ");
				return;
			}
			break;
		case 'M':
		case 'm':
			
			printf("Anzahl der Argumente: %d\n", argc); //Es wird 1 eins ausgegeben, weil das Betriebssystem immer als erstes Argument den Namen des ausgeführten Programmes mit der gesamten Pfadangabe mit der das Programm aufgerufen wurde übergibt.
			printf("Pfad: %s\n", argv[0]);			// Erstes Argument ausgeben, Dateipfad
			for (int i = 1; i < argc; i++) {		//Um den Pfad nicht anzeigen zu lassen muss bei 1 begonnen werden
				printf("Parameter %d: %s \n", i, argv[i]);
				zeigervektor[i] = argv[i];
			}
			//Rückwertsausgabe
			for (int i = (argc-1); i > 0; i--) {		//Um den Pfad nicht anzeigen zu lassen muss bei 1 begonnen werden
				printf("Zeigervektor %d: %s \n", i, zeigervektor[i]);
				
			}

			break;
		default:
			printf("Sie haben keinen der oben genannte Operatoren ausgewaehlt. Bitte versuchen Sie es nochmal\n");
			break;
		}


	} while ((eingabe != 'b') && (eingabe != 'B')); //Beendigungsgrund

	return;
}