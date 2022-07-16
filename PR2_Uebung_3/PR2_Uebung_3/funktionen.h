#pragma once
#define BUFFER_GROESSE 512

#define MAXVN	50
#define MAXNN	50
#define MAXMAIL 254

typedef struct name {
	char vorname[MAXVN];
	char nachname[MAXNN];
}name;

typedef struct person {
	name nameDerPerson;
	char email[MAXMAIL];
	unsigned long handynummer;
}person;

/* strukturierter Datentyp element aus dem Beispiel*/
typedef struct element {
	person student;
	struct element* prev;
	struct element* next;
}element;


void einlesenVonDaten(element** kopf, element** ende);
void fehlerCheckUnsingedLong(int test1, unsigned long* x);
int sucheDoppelt(element* anfang, char* vorname, char* nachname);

void vonVorneEinsetzten(element ***kopf, char nachname[], char vorname[], char eMail[], unsigned long telefonNummer, int nachnameLaenge, int vornameLaenge, int eMailLaenge);
void vonHintenEinsetzen(element ***kopf, char nachname[], char vorname[], char eMail[], unsigned long telefonNummer, int nachnameLaenge, int vornameLaenge, int eMailLaenge);
void spezifischEinsetzen(element ***kopf, char nachname[], char vorname[], char eMail[], unsigned long telefonNummer, int nachnameLaenge, int vornameLaenge, int eMailLaenge);

void loeschenStudenten(element** kopf);
void vonVorneLoeschen(element*** kopf);
void vonHintenLoeschen(element*** kopf);
void spezifischLoeschen(element*** kopf);

void vonVorneAusgabe(element*** kopf);
void vonHintenAusgabe(element*** kopf);
void ausgabe(element** kopf);

void suche(element** kopf);

struct element* zusammenfuegen(struct element* liste1, struct element* liste2);
struct element* zusammenfuegenSortieren(struct element* np);
void sortieren(element*** kopf, element*** ende);

void loescheListe1(element*** kopf);
void loescheListe2(element** kopf);
void loescheListe3(element*** kopf);

element* tausche( element* element1, element* element2);
void bubbleSort( element**** kopf, int anzElemente);
void meineSortierung(element*** kopf, element*** ende);


void bubbleSortNichtVerschachtelterZeiger(element*** kopf, int anzElemente);
void meineSortierungNichtVerschachtelterZeiger(element** kopf, element** ende);

int zaehleAnzListenElemente(element** kopf);
int zaehleAnzListenElemente2(element*** kopf);
int zaehleAnzListenElemente3(element**** kopf);