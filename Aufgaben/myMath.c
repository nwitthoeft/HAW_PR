#include "myMath.h"
#include <stdio.h>
#include<string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define PI 3.14159265359

double myFakultaet(double val)
{
	if (val > 1) {
		return val * myFakultaet(val - 1);									// reursion mit dekrementieren des vorwertes
	}
	else {
		return 1;
	}
}

double myPow(double x, int i)
{
	if (i == 0 && x == 0)
	{
		printf("undefiniert\n");											// O hoch O ist undefiniert
		return;
	}
	else
	{
		double erg = 1;
		for (i; i > 0; i--)													//ist der Exponent, wenn die Schleife durchgelaufen ist veringert sich die Anzahl der zu multiplizierenden Basen
		{
			erg = erg * x;													//Basis wird mit dem Produkt aus multiplikation vorherigen Basen ausmultipliziert
		}
		return erg;
	}
	return;
}

double mySinus(double x, int genauigkeit)
{
	double summe = 0;
	//x = x*PI/180; //Für Gradmaß
	int k = 0;																// inkrement für die alternierende Funktion der Teylorreihe des Sinus.
	for (int i = 1; i <= genauigkeit; i += 2)								// Anzahl der Monome in der Polynomfunktion spiegelt die Genauigkeit dar. Diese Scheife wird so lange ausgeführt bis der Genauigkeitswert erreicht ist. Außerdem wird mit 2 inkrementiert, um die Funktion des Sinus in der Taylorreihe zu erreichen
	{

		summe = summe + (myPow(-1, k) * myPow(x, i) / myFakultaet(i));		//Taylorreihe des Sinus. Siehe Internet als Errinerung
		k++;																//einselne Inkrementation des Alternierendes Ausdruckes
	}
	return(summe);
}

/*Damit folgende Erklärungen besser verstanden werden, ist es empfehlenswert die Funktion vorher auszuprobieren*/
void  kleineseinmaleins(int grenzwert)
{
	printf("   |");							//In der ersten Zeile bis zum ersten Strich
	for (int i = 1; i <= grenzwert; i++)	//In der erste Zeile wird bis zu dem Genzwert in der ersten Zeile Zahlen mit abstand "%4d" aufgelistet.
	{
		printf("%4d", i);
	}
	printf("\n");							//Zweite Zeile beginnt
	printf("---+");							//Wie bei printf("   |"); wird bis zum + der horinzontaler Strich begonnen
	for (int i = 0; i < grenzwert; i++)		//Die Auflistung der Zeilenstiche wird ausgeführt und ist vom Grenzwert abhängig.
	{
		printf("----");
	}
	printf("-\n");							//Dadurch, dass der Zeilenstrich in der zuvor generierten Schleife proportional zum Grenzwert ist, muss ein '-' vor dem Zeilenumbruch gedruckt werden.
	for (int i = 1; i <= grenzwert; i++)	//Das i entspricht dem Zeilenwert in der Tabelle
	{

		printf("%2d |", i);					// Zeilenwert mit %2d abstand von links
		for (int k = 1; k <= grenzwert; k++)//Das k entspricht dem Spalten wert der in der Obersten Zeile aufgelistet wurde
		{
			printf("%4d", i * k);			//Hier wird das Produkt aus dem Zeilenwert der Zeile und dem korrespondierenden Spaltenwert gebildet und ausgegeben
		}
		printf("\n");						//nachdem die Zeile druchgelaufen ist, wird mit der nächsten Zeile begonnen bis der Grenzwert in den Scheifen erreicht ist.
	}
}
/*
Hier beginnen Funktionen zur Übung 5
*/
void asciswitch(char eingabe2[50])
{
	int i;
	int kontrollvar = 1;
	for (i = 0; i < strlen(eingabe2); i++)					//Position des Charakters
	{
		if (eingabe2[i] >= 65 && eingabe2[i] <= 90)			//Prüfung, ob ein Großbuchstabe ist(Prüfung wird pro Charakter des String durchgeführt).
		{
			eingabe2[i] = eingabe2[i] + 32;					//Wenn Großbuchstabe, dann wird zu Kleinbuchstabe umgewandelt.
		}
		else if (eingabe2[i] >= 97 && eingabe2[i] <= 122)	//Prüfung, ob ein Kleinbuchstabe ist(Prüfung wird pro Charakter des String durchgeführt).
		{
			eingabe2[i] = eingabe2[i] - 32;					//Wenn Kleinbuchstabe, dann wird zu Großbuchstabe umgewandelt.
		}
		/*else if (eingabe2[i] == EOF || eingabe2[i] == '\n' || eingabe2[i] == '\0')	//Wenn der Letzte Charakter ein new line Zeichen ist soll trotzdem Umwandlung durchgeführt werden
		{
			kontrollvar = 1;														//Kontrollvariable bleibt auf 1
			break;
		}*/
		/*
		else if (eingabe2[i] != EOF || eingabe2[i] != '\n' || eingabe2[i] != '\0')	//Wenn kein gültiger Charakter eingegeben wurde, wird die Kontrollvariable auf Null gesetzt, sodass im swich unter Richtiger und Falscher eingabe unterschieden werden kann.
		{
			kontrollvar = 0;
			break;
		}
		*/
		else {
			kontrollvar = 0;
			break;
		}

	}
	switch (kontrollvar)
	{
	case 1:
		printf("\nSwitcherooooo!!!!: %s\n", eingabe2);
		break;
	case 0:
		printf("\nGeben Sie einen der 26 generischen Klein und Grossbuchstaben ein. Bitte versuchen Sie es nochmal\n");
		break;
	}
}

int asciswitch2(char eingabe2) //In dieser Funktion werden nur Kleinbuchstaben in Großbuchstaben, nach dem Prinzip in der Funktion "asciswitch", umgewandelt.
{
	if (eingabe2 >= 65 && eingabe2 <= 90)
	{
		return((int)eingabe2);
	}
	else if (eingabe2 >= 97 && eingabe2 <= 122)
	{
		return((int)eingabe2 - 32);
	}
	else
	{
		return(0);
	}

}

int quersumme_berechnen(int zahl)
{
	int quersumme = 0;
	while (zahl != 0)							//Wenn die Zahl die in den Folgenden Zeilen weiter verarbeitet wird Null wird, wird die Schleife geschlossen
	{
		quersumme = quersumme + (zahl % 10);	//Durch die Modulo-Funktion werden die Nullen entfernt, die keinen einfluss auf die Quersumme haben. Übrich bleibt die Einerstelle
		zahl = zahl / 10;						//Die höheren Stellen werden hier aufgefangen.

	}

	return(quersumme);
}

int diff(int zahl1, int zahl2)					//Differenz zwischen zwei Zahlen wird gebildet.
{
	int diff;
	if (zahl1 >= zahl2)
	{
		diff = zahl1 - zahl2;
	}
	else
	{
		diff = zahl2 - zahl1;
	}
	return(diff);
}



int buchstabezuAlphabetNummer(char grossbuchstabe)
{
	int buchstabe = asciswitch2(grossbuchstabe);	//Der Buchstabe der eingelesen wurde, wird nun der ASCII-Wert ausgegeben.
	int alphabetnummer = buchstabe - 64;			//Der Buchstabe-ASCII-Wert, wird auf den Wert im Alphabet umgewandelt, z.B A entspricht 1 und Z entsprcht 26	
	return(alphabetnummer);

}

void euroscheinpruefer(char grossbuchstabe, int zahl1, int zahl2, int pruefzahl)
{
	if (asciswitch2(grossbuchstabe) == 0)
	{
		printf("Geben Sie bitte einen geeigneten Charakter an. Beitte versuchen Sie es erneut\n");
		return;
	}

	int gesammtquersumme = quersumme_berechnen(buchstabezuAlphabetNummer(grossbuchstabe)) + quersumme_berechnen(zahl1) + quersumme_berechnen(zahl2); //Quersumme der Eingaben wird gebildet
	int rest = gesammtquersumme % 9;
	int result = 8 - rest;
	if (result == pruefzahl || (result == 0 && pruefzahl == 9))
	{
		printf("Der Euroschein ist echt\n");
	}
	else
	{
		printf("Der Euroschein ist gefaelscht\n");
	}

	return;
}

/*
Hier beginnen Funktionen zur Übung 6
*/

void mySqrt(double x, int genauigkeit, double fehler, int nachkommastellen)
{
	double xn1;
	double  tat_fehler = 1;
	int k = 0;
	double xstart = (x + 1) / 2; //vorgegeben aus der Aufgabe.

	for (k; k <= genauigkeit && tat_fehler > fehler; k++)
	{
		xn1 = 0.5 * (xstart + (x / xstart));	//Eigentliche Algorythmus, der nach dem Heronsches Näherungsverfahren sich pro Durchlauf dem eigentlichen Wurzelwert annährt
		tat_fehler = (xn1 - xstart) / x;		//Berechnung des Relativen Fehlers zum vorherigen Durchlauf
		if (tat_fehler < 0)						//der relative Fehler ist eine absolute Größe, deshalb Ausgabe immer positv
		{
			tat_fehler = -tat_fehler;			//negativer Wert wird negiert zu positiven Wert
		}
		xstart = xn1;
	}
	printf("Die Wurzel von %lf betraegt %.*lf (nach %d Iterationen)\n", x, nachkommastellen, xn1, k);
	printf("Exakter Wert: %f\n", sqrt(x));
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

 int myZufallszahl()
 {
	 srand((unsigned int)time(NULL));
	 int zufall = (rand() % 100) + 1;
	 return zufall;
 }

 int myOperationen()
 {
	 int x = 1, y = 1, erg;
	 erg = 5 != 6 || 1;		//Ergebnis: 1
	 printf("1. Ergebnis: %d\n", erg);
	 erg = x++ || y++;		//Ergebnis: 1, weil der Inkrement-Operaator("++"), nach dem Oder-Operator geschieht.
	 printf("2. Ergebnis: %d\n", erg);
	 x = 1, y = 1;
	 erg = (x--) - (--y);	//Ergebnis: 1, weil y vor der Operation auf 0 reduziert und x erst nach der operation erhöht wird
	 printf("3. Ergebnis: %d\n", erg);
	 erg = ~12345 ^ 12345;	//Ergebnis: -1 ,weil 12345 = 11000000111001, ~12345 = 00111111000110,    00111111000110 xor 11000000111001 = 11111111111111
	 printf("4. Ergebnis: %d\n", erg);
	 erg = 1 ? 2 : 3;		//Ergebnis: 2, weil 1 als wahr betrachtet wird
	 printf("5. Ergebnis: %d\n", erg);
	 erg = ~0 == -1 ? -2 : -3;	//Ergebnis: -2,weil  0=00000000,  ~0=11111111,  1 = 00000001,  -1 = 11111111,  ~0 == -1  => true
	 printf("6. Ergebnis: %d\n", erg);
	 erg = -1 ^ ~0 ? 1 : 2;		//Ergebnis: 2, 0=00000000,  ~0=11111111,  1 = 00000001,  -1 = 11111111, ~0 ^(xor) -1  => 00000000 = 0(dec) => false
	 printf("7. Ergebnis: %d\n", erg);

	 return 0;
 }

 void groessereZahl(int eingabe1, int eingabe2)
 {
	 eingabe1 > eingabe2 ? printf("%d", eingabe1) : printf("%d", eingabe2);
	 printf("%d", eingabe1 > eingabe2 ? eingabe1 : eingabe2); //Beispiel für ein printf
 }

 //Für double Check
 void fehlercheckdouble(int test1, double* x)
 {
	 int temp;
	 while (test1 != 1)
	 {

		 printf("Falsche Eingabe, wiederholen Sie die eingabe\n\n");
		 while ((temp = fgetc(stdin)) != '\n' && temp != EOF); // or while((temp=getchar()) != EOF && temp != '\n');
		 test1 = scanf_s("%lf", x);

	 }
	 return;
 }

 // FÜr integer Test
 void fehlercheckint(int test1, int *x)
 {
	 int temp;
	 while (test1 != 1)
	 {

		 printf("Falsche Eingabe, wiederholen Sie die eingabe\n\n");
		 while ((temp = fgetc(stdin)) != '\n' && temp != EOF); // or while((temp=getchar()) != EOF && temp != '\n');
		 test1 = scanf_s("%d", x); 

	 }
	 return;
 }