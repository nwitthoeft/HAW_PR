#pragma once
#include "MyBib.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAXT 60
#define MAXR 30
#define MAXF 50

enum eArt {DVD= 1, BluRay, Bluray3D };

struct sDatum {
	int jahr;
	int monat;
};

struct sFilm {
	char titel[MAXT];
	char regisseur[MAXR];
	struct sDatum datum;
	int laenge;
	enum eArt art;
};

int zaehlefilme(struct sFilm filme[]);
void neuerFilm(struct sFilm filme[]);
void filmbestand(struct sFilm filme[MAXF]);
void suchefilm(struct sFilm filme[MAXF]);