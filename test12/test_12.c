#include <stdio.h>
#include<string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void fehlercheckint(int test1, int* x)
{
	int temp;
	while (test1 != 1)
	{
		printf("Falsche Eingabe, wiederholen Sie die eingabe\n\n");
		while ((temp = fgetc(stdin)) != '\n' && temp != EOF); // or while((temp=getchar()) != EOF && temp != '\n');
		test1 = scanf_s("%d", &x);
		//while ((temp = fgetc(stdin)) != '\n' && temp != EOF); //Um in diedsem Fall das doppelte loopen der restlichen main Funktion zu vermeiden. Damit beim nicht ausführen der Funktion, der Fehler nicht passiert muss nach dem ausführen der Funktion der buffer gelehrt werden
	}
	return;
}

void galgenprint(int versuchBegrenzung)
{
	char galgenArr[][70] =
	{
	"  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n",	//Leben: 7	Speicherplatzindex: 0

	"  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n",	//Leben: 6	Speicherplatzindex: 1

	"  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n",	//Leben: 5	Speicherplatzindex: 2

	"  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n",	//Leben: 4	Speicherplatzindex: 3

	"  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n",	//Leben: 3	Speicherplatzindex: 4

	"  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n",	//Leben: 2	Speicherplatzindex: 5

	"  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n",	//Leben: 1	Speicherplatzindex: 6
	};

	printf("%s", galgenArr[versuchBegrenzung-1]); //-1 Um den Index 6 zu erfassen.
}


void main()
{

	char temp;
	srand(time(NULL)); //Damit nicht immer die gleiche Reihenfolge entsteht, wird die Randomisiereung an die Uhrzeit angepasst.
	char woerterListe[][16] = 
	{
								"Auto", //0
								"Hut",
								"Waschmaschine",
								"Turbolader",
								"Taschenrechner",
								"Turing", //5
	};


	
	int wortAnz = sizeof(woerterListe) / sizeof(woerterListe[0]); //Anzahl der Wörter im Array bestimmen
	//printf(	"  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n");

	//printf(	"  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n");

	//printf(	"  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n");

	//printf(	"  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n");

	//printf(	"  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n");

	//printf(	"  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n");

	//printf(	"  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n");

	
	int zufallsWortIndex = rand() % wortAnz;

	int schleifenIndex = 0;
	int neuVersuch = 0;

	int versuchBegrenzung; //Anzahl der Fehlversuche bis der Galgen fällt.
	int anzahlRichtigGetroffen = 0;
	int tempRichtigGetroffen = 0;

	int wortLaenge = strlen(woerterListe[zufallsWortIndex]);
	//									 0 1 2 3
	//									 A u t o
	//int buchstabenGeratenPruef[14] = { 0,0,1,0,0,0,0,0,0,0,0,0,0,0 };
	int* buchstabenGeratenPruef = calloc(wortLaenge, sizeof(int));	//Resaviert den Speicher mit länge von "wortLaenge", und weist jedem Speicherort des Arrays 0 zu. Jeder Speicherplatz hat die Größe eines Integers.
	if (buchstabenGeratenPruef == NULL) //Wenn der Zeiger auf NULL zeigt wird das Programm beendet
	{
		return 1;
	}
		

	int beenden = 0;
	char geratenerBuchstabe;

	char versuch[16];

	int versuchAnz = 0;
	printf("In diesem Programm wird Galgenraten gespielt\n\n");

	printf("Mit wievielen Fehlversuchen wollen Sie spielen\n");
	int test = scanf_s("%d",&versuchBegrenzung);
	fehlercheckint(test, &versuchBegrenzung);
	while ((temp = fgetc(stdin)) != '\n' && temp != EOF);

	while (anzahlRichtigGetroffen < wortLaenge)
	{
		printf("\n");
		galgenprint(versuchBegrenzung);
		printf("\n\nNeuer Versuch...\nGalgenraten Wort:");

		for (schleifenIndex = 0; schleifenIndex < wortLaenge; schleifenIndex++)
		{
			if (buchstabenGeratenPruef[schleifenIndex] == 1)
			{
				printf("%c ", woerterListe[zufallsWortIndex][schleifenIndex]);
			}
			else
			{
				printf("_ ");
			}

		}
		printf("\n");

		printf("Anzahl der bereits richtig getroffen Buchstaben: %d\n", anzahlRichtigGetroffen);
		printf("Geben sie einen Buchstaben ein:");
		//scanf_s("%s", &versuch, 16);
		fgets(versuch, 16, stdin);
		versuchAnz++;
		if (strcmp(versuch,"beenden") == 0)		//vergleicht zwei strings Zeichen für Zeichen
		{
			beenden = 1;
			break;
		}



		geratenerBuchstabe = versuch[0];
		neuVersuch = 0;

		printf("Ihre eingabe war: %c\n", geratenerBuchstabe);

		tempRichtigGetroffen = anzahlRichtigGetroffen;

		for (schleifenIndex = 0; schleifenIndex < wortLaenge; schleifenIndex++)
		{
			if (buchstabenGeratenPruef[schleifenIndex] == 1)
			{
				if (geratenerBuchstabe == woerterListe[zufallsWortIndex][schleifenIndex])
				{
					neuVersuch = 1;
					break;
				}
				continue;
			}
			if (geratenerBuchstabe == woerterListe[zufallsWortIndex][schleifenIndex])
			{
				buchstabenGeratenPruef[schleifenIndex] = 1;
				anzahlRichtigGetroffen++;
			}
		}

		if (tempRichtigGetroffen == anzahlRichtigGetroffen && neuVersuch == 0)
		{
			versuchBegrenzung--;
			printf("Die geratene Buchstabe ist nicht richtig\n");
			if (versuchBegrenzung == 0)
			{
				break;
			}
		}
		else if (neuVersuch == 1)
		{
			printf("Diesen Buchstaben haben Sie bereits geraten\n");
		}
		else 
		{
					printf("Der geratene Buchstabe < %.*s > ist richtig\n", 1, versuch); // %.*s um das \n nicht mit zu printen.
			

		}
	}

	if (beenden == 1)
	{
		printf("\nDer Benutzer hat das Spiel vorzeitig verlassen.\n");
	}
	else if (versuchBegrenzung == 0)
	{

		printf("\nSie haben das Spiel verloren. Das Wort waere: <%s> \n", woerterListe[zufallsWortIndex]);
	}
	else
	{
		printf("\nSie haben Gewonnen!\n Das Wort waere: <%s>\n Sie haben %d Versuche gebraucht\n", woerterListe[zufallsWortIndex], versuchAnz);
	}
	free(buchstabenGeratenPruef); //Damit keine Speicherlöcher 
	return;
}