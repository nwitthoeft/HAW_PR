/*
Dateiname: galgenraten
Autor: Nicolas Witth�ft
Version: 1.5
Datum:	17.02.2022
Beschreibung:
			Bedienung:

						In diesem Programm wird Galgenraten gespielt.
						In der main Funktion kann �ber ein switch-Befehl das Spiel mit "g/G" auswahlen oder das Programm mit "b/B" beenden.
						Die Abfrage geschieht so lange,
						bis einer der Operatoren ausgew�hlt wurde oder das Programm beendet wurde.

						Wenn der Operator "g/G" ausgew�hlt wurde, dann wird die galgenraten-Funktion ausgef�hrt.
						In Array woerterListe k�nnen die W�rter mit einer L�nge von bis zu 17 Zeichen verwendet werden.
						Wenn diese L�nge ge�ndert werden soll,
						kann der zweite eckigen Klammerausdruck ([16]) ge�ndert werden.

						Der Benutzer wird nach der Lebensanzahl gefragt.
						Die Eingabe sollte eine positive Ganzzahl sein.
						F�r die beste Erfahrung sind sieben Leben einzugeben,
						da es 7 Galgen-Grafiken gibt f�r jeden Fehlversuch.
						Danach wird der Benutzer f�r den zu ratenden Buchstaben gefragt.
						Die Eingabe sollte ein Buchstabe oder eine positive Ganzzahl sein. Sonderzeichen sind nicht erlaubt

						Zeichenketten k�nnen auch eingegeben werden, dabei verwertet das Programm zum Vergleich nur das erste Zeichen der Zeichenkette.
						Wenn die Zeichenkette "beenden" eingegeben wird,
						dann wird die galgenraten-Funktion beendet un der Benutzer befindet sich wieder in der Men�ansicht der main-Funktion.
						Nach jedem Versuch bekommt der Benutzer Feedback,
						ob der Benutzer richtig oder falsch geraten hatgeraten hat.

						Das Spiel ist gewonnen, wenn alle Buchstaben richtig geraten wurden.
						Das Spiel ist verloren, wenn die Leben des Spielers, durch falsch geratene Buchstaben aufgebraucht sind.
						Nachdem das Spiel durchgespielt ist,
						befindet sich der Benutzer wieder im Men�,
						dort kann das Spiel von vorne gestartet werden oder das Programm beendet werden.

				Funktion von der galgenraten-Funktion:

						In der L�nge von dem zuf�llig ausgew�hlten Wortes wird die Variable "buchstabenGeratenPruef" mit Nullen definiert.
						Nachdem die Abfrage f�r die Lebensanzahl geschehen ist, wird mit der while-Schleife begonnen,
						in der verglichen wird, ob der geratene Buchstabe in dem String vom Wort aus der W�rterliste im Wort vorhanden ist.
						Wenn der Buchstabe richtig geraten ist, 
						dann wird in "buchstabenGeratenPruef" an den Stellen (Indices) wo der Buchstabe vorhanden ist, von "0" auf "1" gesetzt.
						An den Stellen wo jetzt eine "1" steht wird der Buchstabe an der Stelle ausgegeben. Dort wo eine "0" steht wird "_ " ausgegeben.
						So kann der Benutzer sehen, welche Stellen richtig getroffen wurden.

						Mit den Integer-Variablen "tempRichtigGetroffen" und "anzahlRichtigGetroffen" wird �berpr�ft,
						ob richtig geraten wurde oder falsch geraten wurde.
						Dadurch das "anzahlRichtigGetroffen" um eine Schleife vorl�uft kann die Abfrage geschehen,
						ob der Buchstabe richtig geraten wurde.

						Auf diesem System wurde aufgebaut, sodass weitere Abfragen, wie die Kontrolle, ob doppelte Eingaben geschen sind.
						Die Funktionen werden in der funktionen.c weiter erkl�rt.
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
				printf("Es ist ein Fehler aufgetreten. �berpr�fen Sie ob bei der W�rterliste kein leeres Wort vorhanden ist ");
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