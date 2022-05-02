#include "myMath.h"
#include <stdio.h>
#include<string.h>
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
			 return((int) eingabe2 - 32);
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
	}else
	{
		printf("Der Euroschein ist gefaelscht\n");
	}

	return;
}