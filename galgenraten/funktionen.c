#pragma once
#include "funktionen.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <CTYPE.H>

/*
Die Funktion "galgenraten" ist die Funktion, der die wesentliche Logik des gesammten Programmes steckt.
"galgenraten" ist die einzige selbst geschriebene Funktion in der main-Funktion.
Wenn die Funktion fehlerfrei durchlaufen wurde, hat die Funktion den Rückgabewert "0".
Wenn bei der Verwendung calloc ein Fehler entsteht,
dann wird die Funktion "galgenraten" den Rückgabewert "1" haben und die Funktion beendet.
In der main-Funktion wird Daraufhin das komplette Programm mit einer Fehlermeldung beendet.
*/
int galgenraten() {
	char temp;

	/*
	Damit nicht immer die gleiche Reihenfolge entsteht,
	wird die Randomisiereung an die Uhrzeit gebunden.
	*/
	srand((unsigned int)time(NULL));									
	char woerterListe[][16] = {
								"Auto",		//0
								"Hut",
								"Waschmaschine",
								"Turbolader",
								"Taschenrechner",
								"Turing",	//5
	};



	int wortAnz = sizeof(woerterListe) / sizeof(woerterListe[0]);		//Anzahl der Wörter im Array bestimmen

	/*
	Ein Wort aus "wörterListe" wird ausgesucht. Es gilt rand() % n => Ausgabe [0,n-1].
	Somit wird im Berecht der Derfinierten Indices gearbeitet.
	*/
	int zufallsWortIndex = rand() % wortAnz;

	int schleifenIndex = 0;
	int neuVersuch = 0;

	int versuchBegrenzung;												//Anzahl der Fehlversuche bis der Galgen fällt.
	int anzahlRichtigGetroffen = 0;
	int tempRichtigGetroffen = 0;

	int wortLaenge = myStrlen(woerterListe[zufallsWortIndex]);

	/*
	Wenn der Zeiger auf NULL entspricht wird das Programm beendet,
	da wenn zum Beispiel die Wortlänge (wortLaenge) == 0 entspircht,
	dann kann auch kein Speicherort mit "0" initialisiert werden.
	*/
	if (wortLaenge == 0) {
		return(1);
	}

	/*
	Resaviert den Speicher mit länge von "wortLaenge", und weist jedem Speicherort
	des Arrays 0 zu. Jeder Speicherplatz hat die Größe eines Integers.
	Im Zweifelsfall kann auch statt calloc, die Zuweisung der Nullen manuel geschehen.
	Dabei muss die Anzhal der Nullen größer gleich des größten Wortes
	aus der Wörterliste entsprechen: z.B: int buchstabenGeratenPruef = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	*/
	//									 0 1 2 3
	//									 A u t o
	//int buchstabenGeratenPruef[3] =	{0,0,1,0};
	int* buchstabenGeratenPruef = calloc(wortLaenge, sizeof(int));

	/*
	Wenn der Zeiger auf NULL entspricht wird das Programm beendet,
	da wenn zum Beispiel die Wortlänge (wortLaenge) == 0 entspircht,
	dann kann auch kein Speicherort mit "0" initialisiert werden.
	*/
	if (buchstabenGeratenPruef == NULL) {
		return(1);
	}


	int beenden = 0;
	char geratenerBuchstabe;

	char versuch[16];
	int versuchAnz = 0;

	printf("In diesem Programm wird Galgenraten gespielt. Um das Programm zu beenden, tippen Sie beim Buchstabenraten \"beenden\" ein.\n\n");
	printf("Mit wievielen Fehlversuchen wollen Sie spielen. (Fuer das beste Erlebnis geben Sie '7' ein)\n");			//Anzahl der Leben wird erfragt.

	do {																		//Eingabe für die Anzahl der erlaubten Fehler.
		printf("Geben Sie eine positive Ganzzahl ein.\n");
		int test = scanf_s("%d", &versuchBegrenzung);
		fehlercheckint(test, &versuchBegrenzung);
	} while (versuchBegrenzung <= 0);

	while ((temp = fgetc(stdin)) != '\n' && temp != EOF);						//buufer clear

	/*
	Muss unterhalb der Wortlänge bleiben, sonst wird außerhalb der Grenzen gearbeitet.
	Es gilt, dass die Wortlänge um ein größer ist, als der größte definierte Grenze.
	*/
	while (anzahlRichtigGetroffen < wortLaenge) {

		printf("\n");
		galgenprint(versuchBegrenzung);											//Galgenmännchen wird in dei Konsole gedruckt.
		printf("\n\nNeuer Versuch...\nGalgenraten Wort:");

		for (schleifenIndex = 0; schleifenIndex < wortLaenge; schleifenIndex++) {//Schleife zum Prüfen, ob der Buchstabe richtig geraten wurde.
			if (buchstabenGeratenPruef[schleifenIndex] == 1) {					//Wenn richtig geraten wurde...
				printf("%c ", woerterListe[zufallsWortIndex][schleifenIndex]);	//...dann wird der Buchstabe an allen Stellen des Wortes ausgegeben, bis letzendlich, das ganze Wort ausgegeben wurde
			}
			else {
				printf("_ ");													//Die noch nicht richtig getroffen Buchstaben werden als Leerestelle ("_ ") ausgegeben.
			}
		}

		printf("\n");
		printf("Anzahl der bereits richtig getroffen Buchstaben: %d\n", anzahlRichtigGetroffen);
		printf("Geben Sie einen Buchstaben ein:");
		scanf_s("%s", &versuch, 16);
		stringbuchstabentest(versuch);												//Filtert auf falsche Eingabe.
		versuchAnz++;

		/*
		vergleicht zwei strings Zeichen für Zeichen.
		Wenn der Nutzer das Programm beenden möchte, kann über die Eingabe "beenden" das Programm beendet werden.
		Bei fgets muss "/n" berücksichtigt werden.
		*/
		if (stringVergleich(versuch, "beenden") == 0) {
			beenden = 1;
			break;
		}



		geratenerBuchstabe = versuch[0];									//Der erste Buchstabe aus dem oben eingelesenen string, wird als Versuch verwertet.
		neuVersuch = 0;

		printf("Ihre eingabe war: %c\n", geratenerBuchstabe);

		/*
		anzahlRichtigGetroffen wird um 1 erhöht, wenn der Buchstabe richtig getroffen wurde.
		Somit ist anzahlRichtigGetroffen um 1 größer als tempRichtigGetroffen.
		Dadurch kann nach der folgenden Schleife eine Fallunterscheidung getroffen werden, ob der Buchstabe richtig getroffen oder nicht richtig wurde.
		Wenn die tempRichtigGetroffen ungleich anzahlRichtigGetroffen, dann wurde der Buchstabe richtig geraten.
		Wenn tempRichtigGetroffen gleich anzahlRichtigGetroffen, dann ist der Buchstabe Falsch geraten.
		*/
		tempRichtigGetroffen = anzahlRichtigGetroffen;

		for (schleifenIndex = 0; schleifenIndex < wortLaenge; schleifenIndex++) {
			if (buchstabenGeratenPruef[schleifenIndex] == 1) {
				if (geratenerBuchstabe == woerterListe[zufallsWortIndex][schleifenIndex]) {
					neuVersuch = 1;											//Für die Abfrage, ob der Buchstabe schon eingegeben wurde.
					break;
				}
				continue;
			}

			/*
			geratenerBuchstabe == tolower(woerterListe[zufallsWortIndex][schleifenIndex]) || geratenerBuchstabe == toupper(woerterListe[zufallsWortIndex][schleifenIndex],
			um bei der Eingabe von Großbuchstaben oder Kleinbuchstaben, die Eingabe als richtig anzuerkennnen.
			*/
			if (geratenerBuchstabe == woerterListe[zufallsWortIndex][schleifenIndex] || geratenerBuchstabe == tolower(woerterListe[zufallsWortIndex][schleifenIndex]) || geratenerBuchstabe == toupper(woerterListe[zufallsWortIndex][schleifenIndex])) {
				
				/*
				Wenn der geraten Buchstabe richtig geraten wurde,
				dann wird am Index des geraten Buchstaben von dem Wort der gleiche Index
				von buchstabenGeratenPruef[] von 0 auf 1 gesetzt.
				
				*/
				buchstabenGeratenPruef[schleifenIndex] = 1;
				/*
				Jeder Index des Wortes wird auf den Buchstaben überprüft.
				Erst dannach wird der nächste geratene Buchstabe überprüft.
				*/
				anzahlRichtigGetroffen++; 
			}
		}

		if (tempRichtigGetroffen == anzahlRichtigGetroffen && neuVersuch == 0) {
			versuchBegrenzung--;
			printf("Die geratene Buchstabe < %.*s > ist nicht richtig\n", 1, versuch); // %.*s um das \n nicht mit zu printen. Somit wird nur das erste zeichen des Strings einglesen
			if (versuchBegrenzung == 0) {
				break;
			}
		}
		else if (neuVersuch == 1) {
			printf("Diesen Buchstaben < %.*s > haben Sie bereits geraten\n", 1, versuch);
		}
		else {
			printf("Der geratene Buchstabe < %.*s > ist richtig\n", 1, versuch);
		}
	}

	if (beenden == 1) {															//Spiel wurde beendet
		printf("\nDer Benutzer hat das Spiel vorzeitig verlassen.\n");
	}
	else if (versuchBegrenzung == 0) {											//Der Spieler hat keine Leben mehr
		printf("\nSie haben das Spiel verloren. Das Wort waere: <%s> \n", woerterListe[zufallsWortIndex]);
	}
	else {
		printf("\nSie haben Gewonnen!\n Das Wort ist: <%s>\n Sie haben %d Versuche gebraucht\n", woerterListe[zufallsWortIndex], versuchAnz);
	}
	free(buchstabenGeratenPruef);												//Damit keine Speicherlöcher entstehen
	return(0);
}

/*
Die Funktion "fehlercheckint" überprüft, ob die Eingabe eines Integers richtig war.
Wenn die Eingabe Falsch ist, dann wird solange auf eine auf eine richtige Eingabe gewartet,
bis die Eingabe richtig ist.
*/
void fehlercheckint(int test1, int* x) {
	int temp;
	while (test1 != 1) {
		printf("Falsche Eingabe, wiederholen Sie die eingabe\n\n");
		while ((temp = fgetc(stdin)) != '\n' && temp != EOF); // or while((temp=getchar()) != EOF && temp != '\n');
		test1 = scanf_s("%d", &*x);
	}

	return;
}

/*
Die Funktion "galgenprint" ist für die Ausgabe des Galgenmännchen zuständig.
*/
void galgenprint(int versuchBegrenzung) {
	char galgenArr[][70] = {
	"  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n",	//Leben: 7	Speicherplatzindex: 0

	"  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n",	//Leben: 6	Speicherplatzindex: 1

	"  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n",	//Leben: 5	Speicherplatzindex: 2

	"  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n",	//Leben: 4	Speicherplatzindex: 3

	"  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n",	//Leben: 3	Speicherplatzindex: 4

	"  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n",	//Leben: 2	Speicherplatzindex: 5

	"  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n",	//Leben: 1	Speicherplatzindex: 6
	};
	if (versuchBegrenzung > 7) {
		printf("%s", galgenArr[versuchBegrenzung - abs(versuchBegrenzung - 6)]); //Sodass bei Index 6 beginnt.
	}
	else {
		printf("%s", galgenArr[versuchBegrenzung - 1]); //-1 Um den Index 6 zu erfassen.
	}
	return;
}
/*
Die Funktion "myStrlen" hat die Länge des übergeben strings als Rückgabewert.
*/
int myStrlen(char s[]) { //einlesen von string mit fgets(eingabestrAnz, 100, stdin);
	int i = 0;

	while (s[i] != '\0' && s[i] != '\n') {
		++i;
	}

	return(i);
}

/*
Die Funktion "stringVergleich" vergleicht jedes Zeichen an jeweils gleichen Index der beiden strings.
Der Rückgabe ist "1" und "0".
Bei Rückgabewert "1", ist ungleichheit von den strings vorhanden. Bei Rückgabewert "0",
ist gleichheit von den strings vorhanden.
*/
int stringVergleich(char string1[], char string2[]) {
	if (myStrlen(string1) != myStrlen(string2)) {		//länge der strings wird verglichen.
		return(1);
	}

	for (int i = 0; i < myStrlen(string1); i++) {
		if (string1[i] != string1[i]) {				//Jedes Zeichen wird miteienader verglichen
			return(1);
		}
	}

	return(0);
}

/*
Die Funktion "stringbuchstabentest" überprüft keine alphanumerische Zeichen im string vorhanden sind.
In dem Fall, dass keine alphanumerischen Zeichen eingeben wurden, wird die Aufforderung zur Eingabe wiederholt.
*/
void stringbuchstabentest(char eingabe[]) {
	int laenge = myStrlen(eingabe);
	char temp;

	for (int i = 0; i < laenge; i++) {
		while (isalnum(eingabe[i]) == 0) {							//Zahlen und Buchstaben werden geprüft. Mit isalpha kann der Filter nur auf Buchstaben gesetzt werden.
			printf("Falsche Eingabe, wiederholen Sie die Eingabe\n");
			while ((temp = fgetc(stdin)) != '\n' && temp != EOF); // oder while((temp=getchar()) != EOF && temp != '\n');
			scanf_s("%s", eingabe, 16);
		}

	}
	return;
}

