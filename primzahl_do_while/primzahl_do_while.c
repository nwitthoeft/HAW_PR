/*
Dateiname: Primzahlesucher
Autoren: Nicolas Witth�ft
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
		eingabe = 0; // Die Eingabe wird gecleared, damit der Rest der Schleife nicht nochmal ausgef�hrt wird. Frage Prof ob es bessere m�glichkeiten gibt?
		anzahl = 0; // Anzahl wird vor jedem kompletten Schleifen durchlauf auf 0 resetet.
		printf("Was ist die Obergrenze? (Um das Projekt zu beenden geben sie 0 ein)");
		scanf_s("%d", &eingabe);
		if (eingabe > 0) //Pr�fung ob die Eingabe positv ist.
		{
			k = 2;
			do 	
			{
				i = 2;
				do 
				{
					if (eingabe == k)//Wenn alle Zahlen des Intervalls durchgelaufen sind und die eingabe gleich k ist, dann wird die Anzahl der Primzahlen ausgeben.
					{
						printf("Es gibt zwischen 0 und %d, %d Primzahlen.\n", eingabe, anzahl); //Anzhal der Primzahlen werden ausgegeben.
					}
					if (k % i == 0) //i ist ein Ganzzahligerteiler von k
					{
						break;
					}
					i++;
				} while (i <= k); //z�hlt bis zur hochgez�hlten variable hoch.
				if (k == i) //Wenn alle Zahlen des Intervalls durchgelaufen sind und die eingabe gleich k ist, dann wird die Anzahl der Primzahlen ausgeben.
				{
					printf("%d Ist eine Primzahl.\n", k);//Die Primzahl wird ausgegeben.
					anzahl++; //Z�hler f�r Anzahl von Primzahl.
				}
				k++;
			} while (k <= eingabe);//z�hlt bis zur Eingabe hoch.
		}
		else if (eingabe < 0)
		{
			printf("Geben Sie eine positive Zahl ein");
		}
	} while ((beenden = getchar()) != 'b'); //Beendigungsgrund
	return;
}