#include "MyBib.h"

int zaehlefilme(struct sFilm filme[])
{
	int anzahl = 0;
	return anzahl;
}

void neuerFilm(struct sFilm filme[])
{
	char puffer;
	printf("Geben Sie den Titel des Films an:\t\t");
	scanf_s("%s", &(filme->titel), 60);
	printf("Geben Sie den Namen des Regisseurs ein: \t");
	while ((puffer = fgetc(stdin)) != '\n' && puffer != EOF);
	gets(&(filme->regisseur));
	printf("Geben Sie das Jahr der Veroeffentlichung ein:\t");
	scanf_s("%d", &(filme->datum.jahr));
	printf("Geben Sie den Monat der Veroeffentlichung ein:\t");
	scanf_s("%d", &(filme->datum.monat));
	printf("Geben Sie die Laenge des Films in Minuten an:\t");
	scanf_s("%d", &(filme->laenge));
	printf("Geben Sie das Medium an:\t\t\t");
	scanf_s("%d", &(filme->art));
	return;
}

void filmbestand(struct sFilm filme[MAXF])
{
	printf("Filmliste\n");
	printf("Art: 1 = DVD, 2= Blu-Ray, 3= 3D-Blu-Ray\n\n");
	for (int i = 0; i < 4; i++)
	{
		printf("Film Nr.%d:\n\tTitel:\t\t%s\n\tRegisseur:\t%s\n\tJahr:\t\t%d\n\tMonat:\t\t%d\n\tlaenge(min):\t%d\n\tArt:\t\t%d\n\n",i+1, filme[i].titel, filme[i].regisseur, filme[i].datum.jahr, filme[i].datum.monat, filme[i].laenge, filme[i].art);
	}
	return;
}
void suchefilm(struct sFilm filme[MAXF])
{
	char suche[MAXT];
	printf("Bitte geben Sie den Film ein, nachdem Sie suchen wollen\n");
	scanf_s(" %s", suche);
	printf(" %s", suche);
	return;
}