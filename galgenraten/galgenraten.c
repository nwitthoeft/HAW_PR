/*
Dateiname: galgenraten
Autor: Nicolas Witthöft
Version: 1.5
Datum:	17.02.2022
Beschreibung:
			Bedienung:

						In diesem Programm wird Galgenraten gespielt.
						In der main Funktion kann über ein switch-Befehl das Spiel mit "g/G" auswahlen oder das Programm mit "b/B" beenden.
						Die Abfrage geschieht so lange,
						bis einer der Operatoren ausgewählt wurde oder das Programm beendet wurde.

						Wenn der Operator "g/G" ausgewählt wurde, dann wird die galgenraten-Funktion ausgeführt.
						In Array woerterListe können die Wörter mit einer Länge von bis zu 17 Zeichen verwendet werden.
						Wenn diese Länge geändert werden soll,
						kann der zweite eckigen Klammerausdruck ([16]) geändert werden.

						Der Benutzer wird nach der Lebensanzahl gefragt.
						Die Eingabe sollte eine positive Ganzzahl sein.
						Für die beste Erfahrung sind sieben Leben einzugeben,
						da es 7 Galgen-Grafiken gibt für jeden Fehlversuch.
						Danach wird der Benutzer für den zu ratenden Buchstaben gefragt.
						Die Eingabe sollte ein Buchstabe oder eine positive Ganzzahl sein. Sonderzeichen sind nicht erlaubt

						Zeichenketten können auch eingegeben werden, dabei verwertet das Programm zum Vergleich nur das erste Zeichen der Zeichenkette.
						Wenn die Zeichenkette "beenden" eingegeben wird,
						dann wird die galgenraten-Funktion beendet un der Benutzer befindet sich wieder in der Menüansicht der main-Funktion.
						Nach jedem Versuch bekommt der Benutzer Feedback,
						ob der Benutzer richtig oder falsch geraten hatgeraten hat.

						Das Spiel ist gewonnen, wenn alle Buchstaben richtig geraten wurden.
						Das Spiel ist verloren, wenn die Leben des Spielers, durch falsch geratene Buchstaben aufgebraucht sind.
						Nachdem das Spiel durchgespielt ist,
						befindet sich der Benutzer wieder im Menü,
						dort kann das Spiel von vorne gestartet werden oder das Programm beendet werden.

				Funktion von der galgenraten-Funktion:

						In der Länge von dem zufällig ausgewählten Wortes wird die Variable "buchstabenGeratenPruef" mit Nullen definiert.
						Nachdem die Abfrage für die Lebensanzahl geschehen ist, wird mit der while-Schleife begonnen,
						in der verglichen wird, ob der geratene Buchstabe in dem String vom Wort aus der Wörterliste im Wort vorhanden ist.
						Wenn der Buchstabe richtig geraten ist, 
						dann wird in "buchstabenGeratenPruef" an den Stellen (Indices) wo der Buchstabe vorhanden ist, von "0" auf "1" gesetzt.
						An den Stellen wo jetzt eine "1" steht wird der Buchstabe an der Stelle ausgegeben. Dort wo eine "0" steht wird "_ " ausgegeben.
						So kann der Benutzer sehen, welche Stellen richtig getroffen wurden.

						Mit den Integer-Variablen "tempRichtigGetroffen" und "anzahlRichtigGetroffen" wird überprüft,
						ob richtig geraten wurde oder falsch geraten wurde.
						Dadurch das "anzahlRichtigGetroffen" um eine Schleife vorläuft kann die Abfrage geschehen,
						ob der Buchstabe richtig geraten wurde.

						Auf diesem System wurde aufgebaut, sodass weitere Abfragen, wie die Kontrolle, ob doppelte Eingaben geschen sind.
						Die Funktionen werden in der funktionen.c weiter erklärt.
*/

#include <stdio.h>
#include <string.h>
#include "funktionen.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>


void main()
{
	char eingabe;
	int kontroll;

	do {
		printf("\nFolgende Funktionen sind verfuegbar:\n\n"
			"G/g: Galgenraten\n"
			"B/b: Beendigung des Programms\n\n"
			"Geben Sie einen der oben genannten Operatoren an\n"); //Eingabe um den Operator den festzulegen.
		scanf_s(" %c", &eingabe, 1);

		switch (eingabe) {
		case 'G':
		case 'g':
			kontroll = galgenraten();
			if (kontroll == 1) {
				printf("Es ist ein Fehler aufgetreten. Überprüfen Sie ob bei der Wörterliste kein leeres Wort vorhanden ist ");
				return;
			}
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

	return;
}