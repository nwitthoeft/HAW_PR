/*
Dateiname: Primzahlesucher
Autoren: Nicolas Witthöft
Version: 1.0
Datum: 22.10.2021
Bescheibung: In diesem Projekt kann durch die eingabe des Benutzers in der Konsole eine Obergrenze definiert werden, im Intervall von 2 bis Obergrenze werden alle Primzahlen ausgegeben. von zwei Intege aus.
*/

#include <stdio.h>

void main()
{
	int eingabe;
	int i, k; // Kontrollvariablen
	int anzahl = 0;
	char beenden;
	do
	{
		eingabe = 0; // Die Eingabe wird gecleared, damit der Rest der Schleife nicht nochmal ausgeführt wird. Frage Prof ob es bessere möglichkeiten gibt?
		anzahl = 0; // Anzahl wird vor jedem kompletten Schleifen durchlauf auf 0 resetet.
		printf("Was ist die Obergrenze? (Um das Projekt zu beenden geben sie 0 ein)");
		scanf_s("%d", &eingabe);

		if (eingabe > 0) //überprüfung, ob die eingabe postiv ist.
		{
			k = 2;
			while (k <= eingabe) //zählt bis zur Eingabe hoch.
			{
				i = 2;
				while (i <= k) //zählt bis zur hochgezählten variable hoch.
				{
					if (eingabe == k)//Wenn alle Zahlen des Intervalls durchgelaufen sind und die eingabe gleich k ist, dann wird die Anzahl der Primzahlen ausgeben.
					{
						printf("Es gibt zwischen 0 und %d, %d Primzahlen.\n", eingabe, anzahl); //Anzhal der Primzahlen werden ausgegeben.
					}
					if (k % i == 0) //Wenn i ein ganzzahliger Teiler von k ist,...
					{
						break;
					}
					i++;
				}
				if (k == i)//...dann liegt eine Primzahl vor.
				{
					printf("%d Ist eine Primzahl.\n", k); //Die Primzahl wird ausgegeben.
					anzahl++; //Zähler für Anzahl von Primzahl.
				}
				k++;
			}
		}
		else if (eingabe < 0)
		{
			printf("Geben Sie eine positive Zahl ein");
		}
	} while ((beenden = getchar()) != 'b'); //Beendignungsgrund
	return;
}