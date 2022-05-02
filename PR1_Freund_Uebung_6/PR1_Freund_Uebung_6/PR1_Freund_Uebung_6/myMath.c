#include "myMath.h"

double mySqrt(double zahl, int genauigkeit)
{
	double x;
	x = (zahl + 1) / 2;
	for (int n=1; n <= genauigkeit; n++)
	{
		x=(0.5 * (x + zahl / x));
	}
	return x;
}

int myZufallszahl()
{
	srand((unsigned int)time(NULL));
	int zufall = (rand() % 100) + 1;
	return zufall;
}

int myAusgabe(int zufall, int zahl)
{
	if (zahl < zufall)
	{
		printf("Falsche Zahl, geben Sie bitte eine groessere Zahl ein:");
	}
	else if (zahl > zufall)
	{
		printf("Falsche Zahl, geben Sie bitte eine kleinere Zahl ein:");
	}
	else
	{
		printf("Richtige Antwort, die Zahl war: %d",zufall);
	}
	return 0;
}

int myOperationen()
{
	int x = 1, y = 1, erg;
	erg = 5 != 6 || 1;
	printf("1. Ergebnis: %d\n", erg);
	erg = x++ || y++;
	printf("2. Ergebnis: %d\n", erg);
	x = 1, y = 1;
	erg = (x--) - (--y);
	printf("3. Ergebnis: %d\n", erg);
	erg = ~12345 ^ 12345;
	printf("4. Ergebnis: %d\n", erg);
	erg = 1 ? 2 : 3;
	printf("5. Ergebnis: %d\n", erg);
	erg = ~0 == -1 ? -2 : -3;
	printf("6. Ergebnis: %d\n", erg);
	erg = -1 ^ ~0 ? 1 : 2;
	printf("7. Ergebnis: %d\n", erg);

	return 0;
}