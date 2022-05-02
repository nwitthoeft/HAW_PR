/*
Dateiname:
Auto: Nicolas Witthöft
Version: 1.0
Datum:	01.12.2021
Beschreibung: In diesem Programm wird die Umwandung von Kleinbuchstaben in Großbuchstaben und umgekehrt
*/

#include <stdio.h>
#include<string.h>
#include "myMath.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <CTYPE.H>
#define LENGTH 10
/*

#define _CRT_SECURE_NO_WARNINGS https://stackoverflow.com/questions/22450423/how-to-use-crt-secure-no-warnings

*/
void main()
{
	char eingabe;
	char eingabestrAnz[300];
	//FILE* fp;
	//fp = fopen("file.txt", "r");
	int test1;
	char c;

	char s[300];
	char pruefchar;
	int test;
	int groesse;

	char string1[300], string2[300];

	int i;
	int arr[LENGTH];

	do {
		printf("\nFolgende Funktionen sind verfuegbar:\n\n"
			"U/u: Stinglänge\n"
			"P/p: Zeichensuchen,  \n"
			"O/o: Stringaneinanderhängen\n"
			"M/m: Sortieren\n"
			"B/b: Beenden des Programmes\n\n"
			"Geben Sie einen der oben genannten Operatoren an\n\n"); //Eingabe um den Operator den festzulegen.
		scanf_s(" %c", &eingabe, 1);

		switch (eingabe)
		{
		case 'U':
		case 'u':

			printf("Geben Sie eine Zeichenkette fuer die, die Laenge der Zeichenkaette zurueckgegeben wird. Beachten Sie dabei das Leerzeichen auch als Zeichengelten\n");
			//scanf_s("%c", &temp, 1); // temporäres Statement um den buffer zu löschen.
			while ((c = fgetc(stdin)) != '\n' && c != EOF); //zum loschen des buffers. oder ;while((c=getchar())!='\n' && c!=EOF ); oder rewind(stdin);
			fgets(eingabestrAnz, 300, stdin); //fgets um Leerzeichen einzuspeichern, statt bei scanf_s
			int ausgabe = myStrlen(eingabestrAnz);
			printf("die Laenge der Zeichenkette betraegt %d Zeichen\n", ausgabe);
			break;
		case 'P':
		case 'p':


			// if (erg == NULL) {
			//     printf("Error! memory not allocated.");
			//     exit(0);
			// }


			printf("Geben Sie eine Zeichenkette in dem die Stelle eines Charaktaers gesucht werden soll\n");
			while ((c = fgetc(stdin)) != '\n' && c != EOF);
			fgets(s, 300, stdin);

			printf("Geben Sie den Charakaer ein fuer den die Stelle in Zeichenkette gefunden werden Soll\n");

			test = scanf_s(" %c", &pruefchar, 1);
			//fehlercheckchar(test, pruefchar); //Funktion funktioniert nicht

			int* erg = myStrchr(s, pruefchar, &groesse);


			if (erg == NULL) {
				printf("Fehler beim zuornen des Arrays"); //printf(stderr,"Fehler beim zuornen des Arrays");
				exit(0); //exit(1);

			}

			printf("\nAn den Stellen, ist dieses Zeichen zu finden :");

			for (int i = 0; i < groesse; i++)
			{
				printf(" %d ", erg[i]);
			}

			free(erg);

			break;
		case 'O':
		case 'o':
			printf("\nGeben Sie den ersten String ein: ");
			while ((c = fgetc(stdin)) != '\n' && c != EOF); //Nur einmal sonst wird der restliche string verschluckt
			fgets(string1, 300, stdin);

			printf("\nGeben Sie den zweiten String ein: ");
			fgets(string2, 300, stdin);

			int test2=myStrcat(string1, string2);

			printf("\nDer Zusammengesetzte String ist:%s", string1);

			fehlercheckkeinbockmehr(test2, string1, string2);



			break;
		case 'M':
		case 'm':
			srand(100);
			printf("Vor dem Sortieren\n");
			for (i = 0; i < LENGTH; i++)
			{
				arr[i] = rand();
				printf("%6d", arr[i]);
			}
			printf("\n");
			selectSort(LENGTH, arr);
			printf("Nach dem Sortieren\n");
			for (i = 0; i < LENGTH; i++)
				printf("%6d", arr[i]);
			printf("\n");
			break;
		default:
			printf("Sie haben keinen der oben genannte Operatoren ausgewaehlt. Bitte versuchen Sie es nochmal\n");
			break;
		}


	} while ((eingabe != 'b') && (eingabe != 'B'));
	return;
}

