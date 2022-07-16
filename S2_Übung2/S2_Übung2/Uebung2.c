/*
Programmname:	Uebung2
Autor:			Peter Fischer
Datum:			28.04.2022
Version:		1.0
Beschreibung:	
*/
// ein film 108 bytes
#include "MyBib.h"

void main()
{
	int k = 3;
	char eingabe;
	struct sFilm filme[50];

	strcpy_s(filme[0].titel, MAXT, "Evil Dead");
	strcpy_s(filme[0].regisseur, MAXR, "Fede Alvarez");
	filme[0].datum.jahr = 2013;
	filme[0].datum.monat = 5;
	filme[0].laenge = 87;
	filme[0].art = BluRay;

	strcpy_s(filme[1].titel, MAXT, "Star Wars: Episode III - Die Rache der Sith");
	strcpy_s(filme[1].regisseur, MAXR, "George Lucas");
	filme[1].datum.jahr = 2005;
	filme[1].datum.monat = 5;
	filme[1].laenge = 140;
	filme[1].art = DVD;

	strcpy_s(filme[2].titel, MAXT, "Indiana Jones und das Koenigreich des Kristallschaedels");
	strcpy_s(filme[2].regisseur, MAXR, "George Lucas");
	filme[2].datum.jahr = 2008;
	filme[2].datum.monat = 5;
	filme[2].laenge = 123;
	filme[2].art = DVD;

	// Diese Schleife hat eine Abbruchbedingung bei der Eingabe von "b" oder "B". Das Programm wird dann beendet.
	do
	{
		// Auswahlmenü, wobei die eingabe in die switch case übergeben wird.
		printf("Welche Operation wollen Sie waehlen?\n"
			"\"F\" oder \"f\", fuer die Filmliste.\n"
			"\"N\" oder \"n\", fuer die Eingabe eines neuen Films.\n"
			"\"S\" oder \"s\", um einen Film zu suchen.\n"
			"\"Z\" oder \"z\", um die Eintraege zu zaehlen\n");
		scanf_s(" %c", &eingabe, 1);

		// switch case, welche Auswahl getroffen wurde.
		switch (eingabe)
		{
		case 'N':
		case 'n':
			do
			{
				neuerFilm(&filme[k]);
				printf("Moechten Sie einen weiteren Film einlesen? \"j\" fuer Ja.\nBeliebige Eingabe fuer Nein.\n");
				scanf_s(" %c", &eingabe, 1);
				k++;
			} 
			while (eingabe == 'j');
			break;
		case 'F':
		case 'f':
			filmbestand(&filme);
			break;
		case 'Z':
		case 'z':
			zaehlefilme(&filme);
				break;
		case 'S':
		case 's':
			suchefilm(&filme);
			break;
		default:
			printf("Sie haben keinen der oben genannten Operatoren ausgewaehlt. Bitte versuchen Sie es nochmal!\n");
			break;
		}
	} while ((eingabe != 'b') && (eingabe != 'B'));
	return;
}
