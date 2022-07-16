#pragma once
#define BUFFER_SIZE 512
#define MAX 20

void einlesenText();
int summiereneingabe();
void sum_max(double a[MAX], int n, double* sum, double* max);

enum monat { Januar = 1, Februar, Maerz , April, Mai};

typedef struct sDatum{
	int tag;
	int monat;
	int jahr;
	struct sDatum* next;
	struct sDatum* prev;
}sDatum;

sDatum* datumZuweisen(sDatum * kopf);
void listevonhinten(sDatum* aktuellesDatum, sDatum** kopf);
void vonVorneAusgabe(sDatum* kopf);


typedef union gleicheGroesse {
	int intArr[2];
	short shorArr[4];
	char charArr[8];
} groesse;