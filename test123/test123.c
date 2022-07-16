#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void main(int argc, char* argv[])
{
	char* zeigervektor[16];
			printf("Anzahl der Argumente: %d\n", argc); //Es wird 1 eins ausgegeben, weil das Betriebssystem immer als erstes Argument den Namen des ausgeführten Programmes mit der gesamten Pfadangabe mit der das Programm aufgerufen wurde übergibt.
			printf("Pfad: %s\n", argv[0]);			// Erstes Argument ausgeben, Dateipfad
			for (int i = 1; i < argc; i++) {		//Um den Pfad nicht anzeigen zu lassen muss bei 1 begonnen werden
				printf("Parameter %d: %s \n", i, argv[i]);
				zeigervektor[i] = argv[i];			//In String speichern
			}
			//Rückwertsausgabe
			for (int i = (argc - 1); i > 0; i--) {		//Um den Pfad nicht anzeigen zu lassen muss bei 1 begonnen werden
				printf("Zeigervektor %d: %s \n", i, zeigervektor[i]);

			}
	return;
}