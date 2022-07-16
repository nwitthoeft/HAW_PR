#pragma once
#include "funktionen.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <CTYPE.H>

/*
* Beschreibung:
In dieser Funktion werden die Daten pro Zeile aus der Datei in ein Listenelement gespeichert.

Parameter: kopf der Liste, Anzahl der Elemente
Rückgabewert: Element einer Liste des types *sAirport
*/
sAirport* readAirports(char* fname, int* n) {
	sAirport* aktuellesElement = (sAirport*)malloc(sizeof(struct sAirport));
	char* feld = NULL;
	*n += 1;
	int feldLaenge;
	char* next_token = NULL;
	const char* delim = ",";
	if (aktuellesElement == NULL)
	{
		printf("\nSpeicherüberlauf");
	}
	else {
		//printf("%s", fname);
		feld = strtok_s(fname, delim, &next_token);
		//printf("%s", feld);
		feldLaenge = strlen(feld);
		strcpy_s(aktuellesElement->ICAO, feldLaenge + 1, feld);

		feld = strtok_s(NULL, delim, &next_token);
		feldLaenge = strlen(feld);
		strcpy_s(aktuellesElement->flugHafenName, feldLaenge + 1, feld);

		feld = strtok_s(NULL, delim, &next_token);
		aktuellesElement->koordnaten.breitenGrad = atof(feld);

		feld = strtok_s(NULL, delim, &next_token);
		aktuellesElement->koordnaten.laengenGrad = atof(feld);

		feld = strtok_s(NULL, delim, &next_token);
		aktuellesElement->hoehe = atoi(feld);

		feld = strtok_s(NULL, delim, &next_token);
		feldLaenge = strlen(feld);
		feld[feldLaenge - 1] = '\0'; //Das \n aus fgets wird mit \0 ersetzt
		strcpy_s(aktuellesElement->laenderKuerzel, feldLaenge + 1, feld);
	}
	return(aktuellesElement);
}
/*
* Beschreibung:
In dieser Funktion werden die Daten pro Zeile aus der Datei in ein Listenelement gespeichert.

Parameter: kopf der Liste
Rückgabewert: anzahl der Elemente (Flughäfen)
*/
int listeEinsetzen(sAirport** kopf) {
	FILE* fp;
	errno_t err;
	err = fopen_s(&fp, "flughaefen.csv", "r");
	int n = 0;
	sAirport* aktuellesElement, * temporaeresElement;
	aktuellesElement = (struct sAirport*)malloc(sizeof(struct sAirport));
	if (aktuellesElement == NULL)
	{
		printf("\nSpeicherüberlauf");
		return(-1);
	}
	else {


		if ((err != 0) || (fp == NULL)) {
			printf("Die Datei konnte nicht geöffnet werden! \n Das Programm wird beendet...");
			return(-1);
		}
		else {
			//Daten einlesen
			char fname[200];
			aktuellesElement = *kopf;
			while (fgets(fname, 200, fp) != NULL) {
				aktuellesElement = readAirports(fname, &n);
				if (aktuellesElement == NULL) {
					printf("\nSpeicherüberlauf");
					return(-1);
				}
				if (*kopf == NULL) //Im Fall der Leerenliste
				{
					aktuellesElement->next = NULL;
					aktuellesElement->prev = NULL;
					*kopf = aktuellesElement;
				}
				else
				{
					temporaeresElement = *kopf;
					while (temporaeresElement->next != NULL)//Durchlaufen der Liste, bis das ende der Liste erreicht ist.
					{
						temporaeresElement = temporaeresElement->next;
					}
					temporaeresElement->next = aktuellesElement;    //aktuellesElement (mit den Daten) wird am ende der Liste postioniert.
					aktuellesElement->prev = temporaeresElement;    //aktuellesElement zeigt auf das vorderes (zuvor letztes Element) Element
					aktuellesElement->next = NULL;                  //Das aktuelle Elemet muss auf das ende der Liste (= NULL) zeigen
				}
			}
			fclose(fp);
		}

		printf("\nDie Anzhal der Flughaefen betraegt: %d\n", n);
	}
	return(n);
}


/*
* Beschreibung:
In dieser Funktion kann die Liste von vorne oder von hinten ausgegeben werden.

Parameter: kopf der Liste
Rückgabewert: void
*/
void ausgabe(sAirport** kopf) {
	char eingabe;
	char c;

	printf("\nHier koennen Sie Studenten aus der Liste ausgeben. Folgende Funktionen sind verfuegbar:\n\n"
		"V/v: Die Ausgabe von Vorne\n"
		"H/h: Den untersten Studenten aus der Liste ausgeben\n\n"
		"Geben Sie einen der oben genannten Operatoren an\n"); //Eingabe um den Operator den festzulegen.
	scanf_s(" %c", &eingabe, 1);
	while ((c = fgetc(stdin)) != '\n' && c != EOF);
	switch (eingabe) {
	case 'V':
	case 'v':
		vonVorneAusgabe(&kopf);
		break;
	case 'H':
	case 'h':
		vonHintenAusgabe(&kopf);
		break;
	default:
		printf("Sie haben keinen der oben genannte Operatoren ausgewaehlt. Bitte versuchen Sie es nochmal\n");
		break;
	}
	return;
}

/*
* Beschreibung:
In dieser Funktion kann die Liste von vorne ausgegeben werden.

Parameter: kopf der Liste
Rückgabewert: void
*/
void vonVorneAusgabe(sAirport*** kopf)
{
	struct sAirport* aktuellesElement;
	printf("\nFolgenden Flughafendaten sind gespeichert worden...\n");
	aktuellesElement = **kopf;

	if (aktuellesElement == NULL) {
		printf("Die Liste ist Leer");
		return;
	}

	while (aktuellesElement != NULL)
	{
		printf("ICAO: %s\n", aktuellesElement->ICAO);
		printf("Flughafenname: %s\n", aktuellesElement->flugHafenName);
		printf("Laengengrad: %lf\n", aktuellesElement->koordnaten.laengenGrad);
		printf("Breitengrad: %lf\n", aktuellesElement->koordnaten.breitenGrad);
		printf("Hoehe: %d\n", aktuellesElement->hoehe);
		printf("Laenderkuerzel: %s\n\n", aktuellesElement->laenderKuerzel);
		aktuellesElement = aktuellesElement->next;//lauf
	}
	return;
}

/*
* Beschreibung:
In dieser Funktion kann die Liste von hinten ausgegeben werden.

Parameter: kopf der Liste
Rückgabewert: void
*/
void vonHintenAusgabe(sAirport*** kopf) {
	struct sAirport* aktuellesElement;
	printf("\nFolgenden Flughafendaten sind gespeichert worden...\n");
	aktuellesElement = **kopf;
	if (aktuellesElement == NULL) {
		printf("Die Liste ist Leer");
		return;
	}

	while (aktuellesElement->next != NULL) {//Es wird erstaml zum Ende der Liste navigiert
		aktuellesElement = aktuellesElement->next;
	}
	//Dann wird "hochgezählt".
	while (aktuellesElement != NULL) {
		printf("ICAO: %s\n", aktuellesElement->ICAO);
		printf("Flughafenname: %s\n", aktuellesElement->flugHafenName);
		printf("Laengengrad: %lf\n", aktuellesElement->koordnaten.laengenGrad);
		printf("Breitengrad: %lf\n", aktuellesElement->koordnaten.breitenGrad);
		printf("Hoehe: %d\n", aktuellesElement->hoehe);
		printf("Laenderkuerzel: %s\n\n", aktuellesElement->laenderKuerzel);
		aktuellesElement = aktuellesElement->prev;
	}
	return;
}

void loescheListe2(sAirport** kopf) {
	struct sAirport* aktuellesElement, * zuLoeschendeElement = NULL;
	aktuellesElement = *kopf;
	while (aktuellesElement != NULL) {
		zuLoeschendeElement = aktuellesElement;     //temporäres Element, dass den Zeiger zur Adresse Speichert zum Element
		aktuellesElement = aktuellesElement->next;  //Um den Pointer zum nächsten Element nicht zu verlieren
		free(zuLoeschendeElement);
	}
	printf("Die List wurde geloescht");
	return;
}

/*
* Beschreibung:
In dieser Funktion werden die Daten eines Elementes gesucht. Der such Parameter ist der nachname..
Dabei wird vom Benutzer einer Eingabe erwertet, die den Nachnamen erfragt.
Parameter: kopf der Liste
Rückgabewert: void
*/
void suche(sAirport** kopf)
{
	char c;
	char nameTempBuffer[BUFFER_GROESSE];
	int nameLaenge = 0;

	struct sAirport* aktuellesElement;
	int i = 0, Kennzeichnung;
	aktuellesElement = *kopf;
	if (aktuellesElement == NULL)
	{
		printf("\nLeere Liste\n");
	}
	else
	{
		/*Einlesen des Nachnamens*/
		while ((c = fgetc(stdin)) != '\n' && c != EOF);
		printf("\n");

		printf("Geben Sie den ICAO-Kuerzel des Flughafens ein\n");
		fgets(nameTempBuffer, BUFFER_GROESSE, stdin);
		nameLaenge = strlen(nameTempBuffer);

		if (nameLaenge == 1) {
			exit(-1); //Falls Leerzeile -> Abbruch
		}

		nameTempBuffer[nameLaenge - 1] = '\0'; //Das \n aus fgets wird mit \0 ersetzt
		char* name = (char*)malloc(nameLaenge * sizeof(char));
		if (name == NULL) {
			exit(-1);
		}
		strcpy_s(name, nameLaenge, nameTempBuffer);
		printf("Die Eingabe war: %s\n", name);

		while (aktuellesElement != NULL)//es wird gesucht bis das ende der Liste erreicht ist.
		{
			if (strcmp(aktuellesElement->ICAO, name) == 0)
			{
				printf("\n%s ist an Position: %d \n\n", aktuellesElement->flugHafenName, i + 1);
				printf("ICAO: %s\n", aktuellesElement->ICAO);
				printf("Flughafenname: %s\n", aktuellesElement->flugHafenName);
				printf("Laengengrad: %lf\n", aktuellesElement->koordnaten.laengenGrad);
				printf("Breitengrad: %lf\n", aktuellesElement->koordnaten.breitenGrad);
				printf("Hoehe: %d\n\n", aktuellesElement->hoehe);
				printf("Laenderkuerzel: %s\n", aktuellesElement->laenderKuerzel);
				Kennzeichnung = 0;
				break;
			}
			else
			{
				Kennzeichnung = 1;
			}
			i++;
			aktuellesElement = aktuellesElement->next;//Lauf
		}
		if (Kennzeichnung == 1)
		{
			printf("\nFlughafen wurde nicht gefunden\n");
		}
	}
	return;
}

/*
* Beschreibung:
In dieser Funktion werden die Daten eines Elementes gesucht. Der such Parameter ist der nachname..
Dabei wird vom Benutzer einer Eingabe erwertet, die den Nachnamen erfragt.
Parameter: kopf der Liste, string zum Vergleich
Rückgabewert: Element einer Liste
*/
sAirport* suche2(sAirport**** kopf, char* name)
{
	struct sAirport* aktuellesElement, * temporaeresElement;
	temporaeresElement = (struct sAirport*)malloc(sizeof(struct sAirport));

	int i = 0, Kennzeichnung;
	int dataLength;
	aktuellesElement = ***kopf;
	if (temporaeresElement == NULL)
	{
		printf("\nSpeicherueberfluss\n");
		return(NULL);
	}
	else if (aktuellesElement == NULL)
	{
		printf("\nLeere Liste\n");
		return(NULL);
	}
	else
	{

		while (aktuellesElement != NULL)//es wird gesucht bis das ende der Liste erreicht ist.
		{
			if (strcmp(aktuellesElement->ICAO, name) == 0)
			{
				dataLength = strlen(aktuellesElement->ICAO);
				strcpy_s(temporaeresElement->ICAO, dataLength + 1, aktuellesElement->ICAO);
				dataLength = strlen(aktuellesElement->flugHafenName);
				strcpy_s(temporaeresElement->flugHafenName, dataLength + 1, aktuellesElement->flugHafenName);
				temporaeresElement->koordnaten.laengenGrad = aktuellesElement->koordnaten.laengenGrad;
				temporaeresElement->koordnaten.breitenGrad = aktuellesElement->koordnaten.breitenGrad;
				temporaeresElement->hoehe = aktuellesElement->hoehe;
				dataLength = strlen(aktuellesElement->laenderKuerzel);
				strcpy_s(temporaeresElement->laenderKuerzel, dataLength + 1, aktuellesElement->laenderKuerzel);

				Kennzeichnung = 0;
				return(temporaeresElement);
			}
			else
			{
				Kennzeichnung = 1;
			}
			i++;
			aktuellesElement = aktuellesElement->next;//Lauf
		}
		if (Kennzeichnung == 1)
		{
			printf("\nDer Flughafen wurde nicht gefunden wurde nicht gefunden\n");
		}
	}
	return (NULL);
}

/*
* Beschreibung:
In dieser Funktion werden die Daten eines Elementes gesucht. Der such Parameter ist der nachname..
Dabei wird vom Benutzer einer Eingabe erwertet, die den Nachnamen erfragt.
Parameter: kopf der Liste, string zum Vergleich
Rückgabewert: int Prüfvariable
*/
int suche3(sAirport**** kopf, char* name)
{
	struct sAirport* aktuellesElement, * temporaeresElement;
	temporaeresElement = (struct sAirport*)malloc(sizeof(struct sAirport));

	int i = 0, Kennzeichnung;
	aktuellesElement = ***kopf;
	if (temporaeresElement == NULL)
	{
		printf("\nSpeicherueberfluss\n");
		return(1);
	}
	else if (aktuellesElement == NULL)
	{
		printf("\nLeere Liste\n");
		return(1);
	}
	else
	{

		while (aktuellesElement != NULL)//es wird gesucht bis das ende der Liste erreicht ist.
		{
			if (strcmp(aktuellesElement->ICAO, name) == 0)
			{
				Kennzeichnung = 0;
				return(0);
			}
			else
			{
				Kennzeichnung = 1;
			}
			i++;
			aktuellesElement = aktuellesElement->next;//Lauf
		}
		if (Kennzeichnung == 1)
		{
			printf("\nDer Flughafen wurde nicht gefunden wurde nicht gefunden\n");
			return(1);
		}
	}
	return (0);
}

/*
* Beschreibung:
In dieser Funktion werden die Daten eines Elementes gesucht. Der such Parameter ist der nachname..
Dabei wird vom Benutzer einer Eingabe erwertet, die den Nachnamen erfragt.
Parameter: kopf der Liste, string zum Vergleich
Rückgabewert: void
*/
void suche4(sAirport*** kopf, char* name)
{
	struct sAirport* aktuellesElement;

	int i = 0, Kennzeichnung = 0;
	aktuellesElement = **kopf;

	if (aktuellesElement == NULL)
	{
		printf("\nLeere Liste\n");
		return;
	}
	else
	{

		while (aktuellesElement != NULL)//es wird gesucht bis das ende der Liste erreicht ist.
		{
			if (strcmp(aktuellesElement->ICAO, name) == 0)
			{
				printf("\n%s ist an Position: %d \n\n", aktuellesElement->flugHafenName, i + 1);
				printf("ICAO: %s\n", aktuellesElement->ICAO);
				printf("Flughafenname: %s\n", aktuellesElement->flugHafenName);
				printf("Breitengrad: %lf\n", aktuellesElement->koordnaten.breitenGrad);
				printf("Laengengrad: %lf\n", aktuellesElement->koordnaten.laengenGrad);
				printf("Hoehe: %d\n\n", aktuellesElement->hoehe);
				printf("Laenderkuerzel: %s\n", aktuellesElement->laenderKuerzel);
				Kennzeichnung = 0;
				break;
			}
			else
			{
				Kennzeichnung = 1;
			}
			i++;
			aktuellesElement = aktuellesElement->next;//Lauf
		}
		if (Kennzeichnung == 1)
		{
			printf("\nDer Flughafen wurde nicht gefunden wurde nicht gefunden\n");
		}
	}
	return;
}
/*
* Beschreibung:
In dieser Funktion werden die Elemente von den wegpunkten in eine neue Liste sortiert

Parameter: kopf der Liste, kopf der Wegpunktliste, name des Flughafens
Rückgabewert: void
*/
void listeEinsetzen2(sAirport*** kopf, sAirport** kopfWegpunkt, char* name) {
	sAirport* aktuellesElement, * temporaeresElement;

	aktuellesElement = (struct sAirport*)malloc(sizeof(struct sAirport));
	if (aktuellesElement == NULL)
	{
		printf("\nSpeicherüberlauf");
		return;
	}
	else {
		//Daten einlesen
		aktuellesElement = *kopfWegpunkt;

		aktuellesElement = suche2(&kopf, name);
		if (aktuellesElement == NULL) {
			printf("\nSpeicherüberlauf");
			return;
		}
		if (*kopfWegpunkt == NULL) //Im Fall der Leerenliste
		{
			aktuellesElement->next = NULL;
			aktuellesElement->prev = NULL;
			*kopfWegpunkt = aktuellesElement;
		}
		else
		{
			temporaeresElement = *kopfWegpunkt;
			while (temporaeresElement->next != NULL)//Durchlaufen der Liste, bis das ende der Liste erreicht ist.
			{
				temporaeresElement = temporaeresElement->next;
			}
			temporaeresElement->next = aktuellesElement;    //aktuellesElement (mit den Daten) wird am ende der Liste postioniert.
			aktuellesElement->prev = temporaeresElement;    //aktuellesElement zeigt auf das vorderes (zuvor letztes Element) Element
			aktuellesElement->next = NULL;                  //Das aktuelle Elemet muss auf das ende der Liste (= NULL) zeigen
		}
	}
	return;
}

/*
* Beschreibung:
In dieser Funktion werden die Elemente von den wegpunkten in eine neue Liste sortiert

Parameter: kopf der Liste, anzahl der Elemente des gesammte Liste, anzahl der Elemente in der neuen Liste
Rückgabewert: Kopf der nuenen Liste mit den Wegpunkten
*/
sAirport* enterWaypoints(sAirport** kopf, int n, int* m) {
	int anzDerWegpunkte;
	char c;
	char nameTempBuffer[BUFFER_GROESSE];
	int nameLaenge = 0;
	int test;
	sAirport* kopfWegpunkt = NULL;
	sAirport* endeWegpunkt = NULL;


	printf("Wie viele Wegpunkte moechten Sie haben?");
	test = scanf_s("%d", &anzDerWegpunkte);
	fehlercheckint(test, &anzDerWegpunkte);
	*m = anzDerWegpunkte;

	while ((c = fgetc(stdin)) != '\n' && c != EOF);
	for (int i = 0; i <= anzDerWegpunkte; i++) {
		printf("Geben sie den %d. Wegpunkt ein:", i);
		printf("\n");
		fgets(nameTempBuffer, BUFFER_GROESSE, stdin);
		nameLaenge = strlen(nameTempBuffer);

		if (nameLaenge == 1) {
			exit(-1); //Falls Leerzeile -> Abbruch
		}

		nameTempBuffer[nameLaenge - 1] = '\0'; //Das \n aus fgets wird mit \0 ersetzt
		char* name = (char*)malloc(nameLaenge * sizeof(char));
		if (name == NULL) {
			printf("Speicherueberfluss");
			exit(-1);
		}
		strcpy_s(name, nameLaenge, nameTempBuffer);
		fehlerCheckEingabe(&kopf, name, i);
		listeEinsetzen2(&kopf, &kopfWegpunkt, name);
	}

	return(kopfWegpunkt);
}

/*
* Beschreibung:
Diese Funktion dient zur Fehler überprüfung 

Parameter: kopf der Liste, string zum Vergleich, Position des Elemente in der neuen Liste
Rückgabewert: Kopf der nuenen Liste mit den Wegpunkten
*/
void fehlerCheckEingabe(sAirport*** kopf, char *name, int i) {
	char nameTempBuffer[BUFFER_GROESSE];
	int nameLaenge = 0;
	
	while (suche3(&kopf, name) != 0) {
		printf("Falsche Eingabe, wiederholen Sie die Eingabe\n");
		printf("Geben sie den %d. Wegpunkt ein:", i);
		printf("\n");
		fgets(nameTempBuffer, BUFFER_GROESSE, stdin);
		nameLaenge = strlen(nameTempBuffer);

		if (nameLaenge == 1) {
			exit(-1); //Falls Leerzeile -> Abbruch
		}

		nameTempBuffer[nameLaenge - 1] = '\0'; //Das \n aus fgets wird mit \0 ersetzt
		strcpy_s(name, nameLaenge, nameTempBuffer);
	}

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
* Beschreibung:
Werden die Wegpunkte mit den Distanzen ausgedruckt.

Parameter: kopf der Liste, Kopf der nuenen Liste mit den Wegpunkten, Anzahl der Elemente in der neuen Liste
Rückgabewert: void
*/
void printWaypoints(sAirport** kopf, sAirport** kopfWegpunkt, int m) {
	FILE* fp;
	errno_t err;
	err = fopen_s(&fp, "wegpunkte.txt", "w");
	sAirport** k;
	int j;
	double summeDerStrecke = 0;
	double* tempWegpunktDistanz = (double*)calloc(m, sizeof(double));
	
	if ((err != 0) || (fp == NULL)) {
		printf("Funktion nicht möglich...\n");
		return; //alternativ: exit(0);
	}
	if (tempWegpunktDistanz == NULL) {
		printf("Speicherueberfluss");
		exit(-1);
	}
	k = kopfWegpunkt;
	printf("##Flightplan##\n");
	fprintf(fp,"##Flightplan##\n");
	printf("%02d %s | %s | %s, %d ft, %lf km\n", 0, &(*k)->ICAO, &(*k)->laenderKuerzel, &(*k)->flugHafenName, (*k)->hoehe, (double)tempWegpunktDistanz[0]);
	fprintf(fp,"%02d %s | %s | %s, %d ft, %lf km\n", 0, &(*k)->ICAO, &(*k)->laenderKuerzel, &(*k)->flugHafenName, (*k)->hoehe, (double)tempWegpunktDistanz[0]);
	for (j = 0; j < m; j++) {

		sAirport* flughafen1 = *k;
		sAirport* flughafen2 = flughafen1->next;
		double b = acos(sin((((double)flughafen1->koordnaten.breitenGrad) / 360) * 2 * M_PI) * sin((((double)flughafen2->koordnaten.breitenGrad) / 360) * 2 * M_PI) + cos((((double)flughafen1->koordnaten.breitenGrad) / 360) * 2 * M_PI) * cos((((double)flughafen2->koordnaten.breitenGrad) / 360) * 2 * M_PI) * cos((((double)flughafen2->koordnaten.laengenGrad - (double)flughafen1->koordnaten.laengenGrad) / 360) * 2 * M_PI));
		double d = b * (double)ERDRADIUS;
		summeDerStrecke = summeDerStrecke + d;
		//tempWegpunktDistanz[j] = d;
		k = &(*k)->next; //äquivalent zu sAirport* flughafen2.
		printf("%02d %s | %s | %s, %d ft, %lf km\n", j + 1, &(*k)->ICAO, &(*k)->laenderKuerzel, &(*k)->flugHafenName, (*k)->hoehe, summeDerStrecke);
		fprintf(fp,"%02d %s | %s | %s, %d ft, %lf km\n", j + 1, &(*k)->ICAO, &(*k)->laenderKuerzel, &(*k)->flugHafenName, (*k)->hoehe, summeDerStrecke);
	}
	fclose(fp);
}

/*
* Beschreibung:
In dieser Funktion werden die Daten eines Elementes der gesammten Liste gelöscht (Aus dem heap mit anfang un ende).
Parameter: kopf der List
Rückgabewert: void
*/
void loescheListe3(sAirport** kopfWegpunkt)
{
	int i;
	int anzElemente = zaehleAnzListenElemente2(&kopfWegpunkt);
	for (i = 0; i < anzElemente; i++)
	{
		sAirport* zuLoeschendesElement = *kopfWegpunkt;//Aus der Kombination dieser Zeiler 

		if (*kopfWegpunkt == NULL || zuLoeschendesElement == NULL) { //Wenn die Liste leer ist
			return;
		}
		if (*kopfWegpunkt == zuLoeschendesElement) { //Wenn der Kopf gleich dem zu löschendem Element ist, soll der kopf zum nächsten Element in der Liste gehen
			*kopfWegpunkt = zuLoeschendesElement->next;
		}
		if (zuLoeschendesElement->next != NULL) { //Isolierung des zu löschen elementes und das nächste element vom zu löschenden Elementes zeigt mit prev auf NULL 
			zuLoeschendesElement->next->prev = zuLoeschendesElement->prev;
		}
		if (zuLoeschendesElement->prev != NULL) { //Wird verwenden, wenn dass Ende der Liste als Start verwendet wird wird. Dann hat die Funktion die gleiche Funktion.
			zuLoeschendesElement->prev->next = zuLoeschendesElement->next;
		}

		free(zuLoeschendesElement);
	}
	return;
}


/*
* Beschreibung:
In dieser Funktion wird die Anzahl der Listenelementen ausgegeben.

Parameter: kopf der Liste
Rückgabewert: int
*/
int zaehleAnzListenElemente2(sAirport*** kopfWegpunkt) {
	sAirport* aktuellesElement;
	int anzahl = 0;
	aktuellesElement = **kopfWegpunkt;

	while (aktuellesElement != NULL) {
		aktuellesElement = aktuellesElement->next;
		anzahl++;
	}
	return (anzahl);
}


/*
* Beschreibung:
In dieser Funktion wird der näheste Flughafen gesucht,
nach Eingabe von Längen- und Breitengrad

Parameter: kopf der Liste, anzahl der Listen Elemente in der Gesammten Liste
Rückgabewert: void
*/
void naehesterFlughafen(sAirport** kopf, int n) {
	int test1, test2;
	double breitenGrad;
	double laengenGrad;
	double b;
	double d = 0;
	double naehesterFlughafen = 0;
	char* tempICAO = {"0"};
	int tempICAOlaenge;
	double tempNaehesterFlughafen = 0;
	printf("Geben Sie den Breitengrad ein:\n");
	test1 = scanf_s("%lf", &breitenGrad);
	fehlerCheckDouble(test1, &breitenGrad);

	printf("Geben Sie den Laengengrad ein:\n");
	test2 = scanf_s("%lf", &laengenGrad);
	fehlerCheckDouble(test2, &laengenGrad);

	sAirport* aktuellerFlughafen = *kopf;
	while (aktuellerFlughafen != NULL) {

			

			b = acos(sin((((double)breitenGrad) / 360) * 2 * M_PI) * sin((((double)aktuellerFlughafen->koordnaten.breitenGrad) / 360) * 2 * M_PI) + cos((((double)breitenGrad) / 360) * 2 * M_PI) * cos((((double)aktuellerFlughafen->koordnaten.breitenGrad) / 360) * 2 * M_PI) * cos((((double)aktuellerFlughafen->koordnaten.laengenGrad - (double)laengenGrad) / 360) * 2 * M_PI));
			d = b * (double)ERDRADIUS;
			
			if (tempNaehesterFlughafen > d)
			{
				tempICAOlaenge = strlen(aktuellerFlughafen->ICAO);
				tempICAO = (char*)malloc(tempICAOlaenge * sizeof(char));
				if (tempICAO == NULL) {
					printf("Speicherueberlauf");
					return;
				}
				strcpy_s(tempICAO, tempICAOlaenge+1, aktuellerFlughafen->ICAO);
				naehesterFlughafen = d;
			}
			tempNaehesterFlughafen = d;
			aktuellerFlughafen = aktuellerFlughafen->next;
			
		}
	suche4(&kopf, tempICAO);
	printf("Distanz: %lf km\n", naehesterFlughafen);

}

/*
* Beschreibung:
In dieser Funkion wird ein double überprüft.

Parameter: test variable, die zu überprüfenden Variable
Rückgabewert: void
*/
void fehlerCheckDouble(int test1, double* x) {
	char temp;
	while (test1 == 0) {
		printf("Falsche Eingabe, wiederholen Sie die eingabe\n");
		while ((temp = fgetc(stdin)) != '\n' && temp != EOF); // or while((temp=getchar()) != EOF && temp != '\n');
		test1 = scanf_s("%lf", &*x);
	}
	return;
}