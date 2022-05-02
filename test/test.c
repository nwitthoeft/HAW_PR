#include <stdio.h>
#include<string.h>
#include <time.h>
#include <stdlib.h>
/*
void main()
{
	int k = 0;
	double x, xn;
	double tat_fehler = 1;

	printf("Geben Sie eine Zahl ein für die, die Wurzel gezogen werden soll\n");
	scanf_s("%lf", &x);
	double xstart = (x + 1) / 2;

	while ( k <= 50 && tat_fehler > 1e-6)
	{
		++k;
		xn = 0.5 * (xstart + (x / xstart));
		tat_fehler = (xn - xstart) / xn;
		if (tat_fehler < 0)
			tat_fehler = -tat_fehler;
		
		xstart = xn;
	}
	printf("Ergebnis ist: %f (nach %d Iterationen)\n", xn, k);
	return 0;
}
*/
/*
int main(void)
{
	int i = 0;
	double x, xneu;
	double rel_fehler = 1.0;
	printf("Wurzel berechnen von: ");
	scanf_s("%lf", &x);
	double xalt = 10;
	while (i <= 50 && rel_fehler > 1e-6)
	{
		++i;
		xneu = .5 * (xalt + x / xalt);
		rel_fehler = (xneu - xalt) / xneu;
		if (rel_fehler < 0) rel_fehler = -rel_fehler;
		xalt = xneu;
	}
	printf("Ergebnis ist: %.10f (nach %d Iterationen)\n", xneu, i);
	printf("Exakter Wert: %.10f\n", sqrt(x));
	return 0;
}
*/
void main()
{
	int zufallszahl; // Vereinbarung einer geheimen Zahl, welche es zu erraten gilt
	int anzahl; // Vereinbarung einer Variablen für die Anzahl der benötigten Versuche
	int eingabe; // ihre Eingaben werden stets als Text (string) eingelesen

	anzahl = 1; // die Variable wird mit dem Wert 1 initialisiert
	srand((unsigned int)time(NULL)); // initialisiert einen Zufallszahlengenerator
	zufallszahl = (rand() % 100) + 1; // generiert eine Zufallszahl zwischen 1 und 1000
	printf("Raten Sie eine Zahl zwischen 1 und 100.\n"); // das ist eine Textausgabe
	do { // der Beginn einer langen Schleife (Wiederholung)
		printf("Geben Sie eine Zahl ein: \n"); // das nennt man Eingabeaufforderung
		scanf_s("%d", &eingabe); // hier wird ihre Eingabe als Text eingelesen

		if (eingabe == zufallszahl) {// das ist ein vergleich, der entweder wahr oder falsch sein kann
			printf("Sie haben gewonnen!!!\n"); // das ist eine Textausgabe
			printf("Und dabei nur %d Versuch(e) benoetigt.\n", anzahl);
			// hier wird Text mit dem Wert einer Variablen ausgegeben
		} // hier endet ein Block (Wiederholung, Verzweigung, ...)

		else { // das 'sonst' gehört immer zu einem 'falls'
			anzahl++; // erhöhe (inkrementiere) den Wert in anzahl um genau 1
			if (eingabe < zufallszahl)
			{ // falls also der versuch kleiner als die zahl ist ...
				printf("Ihre Zahl ist zu klein. Nehmen Sie eine groessere.\n"); // Textausgabe
			} // hier endet ein Block (Wiederholung, Verzweigung, ...)
			else
			{ // das 'sonst' gehört immer zu einem 'falls'
				printf("Ihre Zahl ist zu gross. Nehmen Sie eine kleinere.\n"); // Textausgabe
			} // hier endet ein Block (Wiederholung, Verzweigung, ...)

		} // hier endet ein Block (Wiederholung, Verzweigung, ...)


	} while (eingabe != zufallszahl); // hier endet eine Schleife, welche mit 'do {' begonnen hat
	return 0;
}

 zahlraten(void)
{
	int zufallszahl; // Vereinbarung einer geheimen Zahl, welche es zu erraten gilt
	int anzahl; // Vereinbarung einer Variablen für die Anzahl der benötigten Versuche
	int eingabe; // ihre Eingaben werden stets als Text (string) eingelesen

	anzahl = 1; // die Variable wird mit dem Wert 1 initialisiert
	srand((unsigned int)time(NULL)); // initialisiert einen Zufallszahlengenerator
	zufallszahl = (rand() % 100) + 1; // generiert eine Zufallszahl zwischen 1 und 1000
	printf("Raten Sie eine Zahl zwischen 1 und 100.\n"); // das ist eine Textausgabe
	do { // der Beginn einer langen Schleife (Wiederholung)
		printf("Geben Sie eine Zahl ein: \n"); // das nennt man Eingabeaufforderung
		scanf_s("%d", &eingabe); // hier wird ihre Eingabe als Text eingelesen

		if (eingabe == zufallszahl) {// das ist ein vergleich, der entweder wahr oder falsch sein kann
			printf("Sie haben gewonnen!!!\n"); // das ist eine Textausgabe
			printf("Und dabei nur %d Versuch(e) benoetigt.\n", anzahl);
			// hier wird Text mit dem Wert einer Variablen ausgegeben
		} // hier endet ein Block (Wiederholung, Verzweigung, ...)

		else { // das 'sonst' gehört immer zu einem 'falls'
			anzahl++; // erhöhe (inkrementiere) den Wert in anzahl um genau 1
			if (eingabe < zufallszahl)
			{ // falls also der versuch kleiner als die zahl ist ...
				printf("Ihre Zahl ist zu klein. Nehmen Sie eine groessere.\n"); // Textausgabe
			} // hier endet ein Block (Wiederholung, Verzweigung, ...)
			else
			{ // das 'sonst' gehört immer zu einem 'falls'
				printf("Ihre Zahl ist zu gross. Nehmen Sie eine kleinere.\n"); // Textausgabe
			} // hier endet ein Block (Wiederholung, Verzweigung, ...)

		} // hier endet ein Block (Wiederholung, Verzweigung, ...)


	} while (eingabe != zufallszahl); // hier endet eine Schleife, welche mit 'do {' begonnen hat
	return 0;

}