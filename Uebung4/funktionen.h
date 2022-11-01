#pragma once
#define BUFFER_GROESSE 512
#define MAXFLUGHAFENNAME 78
#define MAXICAO 6
#define MAXLAENDERKUERZEL 4
#define ERDRADIUS 6378.4
#define _USE_MATH_DEFINES

typedef struct  sKoordinaten {
	double breitenGrad;
	double laengenGrad;
}sKoordinaten;

typedef struct sAirport {
	char ICAO[MAXICAO];
	char flugHafenName[MAXFLUGHAFENNAME];
	sKoordinaten koordnaten;
	int hoehe;
	char laenderKuerzel[MAXLAENDERKUERZEL];
	struct sAirport* next;
	struct sAirport* prev;
}sAirport;

sAirport* readAirports(char* fname, int* n);
void ausgabe(sAirport** kopf);
void vonVorneAusgabe(sAirport** kopf);
void vonHintenAusgabe(sAirport** kopf);
int listeEinsetzen(sAirport** kopf);

void loescheListe2(sAirport** kopf);
void suche(sAirport** kopf);
sAirport* suche2(sAirport** kopf, char* name);
int suche3(sAirport** kopf, char* name);
void fehlerCheckEingabe(sAirport** kopf, char* name, int i);
void fehlercheckint(int test1, int* x);
void listeEinsetzen2(sAirport** kopf, sAirport** kopfWegpunkt, char* name);

sAirport* enterWaypoints(sAirport** kopf, int n, int* m);
void printWaypoints(sAirport** kopf, sAirport** kopfWegpunkt, int m);

void loescheListe3(sAirport** kopfWegpunkt);
int zaehleAnzListenElemente2(sAirport** kopfWegpunkt);

void naehesterFlughafen(sAirport** kopf, int n);
void fehlerCheckDouble(int test1, double* x);
void suche4(sAirport** kopf, char* name);