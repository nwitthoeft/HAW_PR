#include "myMath.h"
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

		summe = summe + (myPow(-1, k) * myPow(x, i)/ myFakultaet(i));		//Taylorreihe des Sinus. Siehe Internet als Errinerung
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