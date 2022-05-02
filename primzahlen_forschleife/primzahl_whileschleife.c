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
	do
	{
		printf("Was ist die Obergrenze? (Um das Projekt zu beenden geben sie 0 ein)");
		scanf_s("%d", &eingabe);

		if (eingabe > 0)
		{
			k = 2;
			while (k <= eingabe)
			{
				i = 2;
				while (i <= k)
				{
					if (k % i == 0) //i ist ein Ganzzahligerteiler von k
					{
						break;
					}
					i++;
				}
				if (k == i)
				{
					printf("%d Ist eine Primzahl.\n", k);
				}
				k++;
			}
		}
		else
		{
			printf("Geben Sie eine positive Zahl ein");
		}
	} while (eingabe != 0); //Beendigungsgrund
	return;
}