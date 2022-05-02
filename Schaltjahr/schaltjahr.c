/*
Dateiname: Schaltjahrbestimmung
Autoren: Nicolas Witthöft
Version: 1.0
Datum: 22.10.2021
Bescheibung: In diesem Projekt kann durch die Eingabe des Benutzers in der Konsole eine Jahreszahl eingegeben werden und bestimmt werden, ob es sich bei dieser Jahreszahl um ein Schaltjahrhandelt.
*/

#include <stdio.h>

void main()
{
	int eingabe;
	char beenden;
	do
	{
		printf("Geben Sie eine Jahreszahl, wenn Sie wissen wollen, ob das Jahr ein Schaltjahr ist. (Die Eingabe von 'b' beendet das Programm.)\n");
		scanf_s("%d", &eingabe);

		if (eingabe % 4 == 0 && eingabe % 100 != 0 || eingabe % 400 == 0) //Überprüfung durch die Bedingungen, die ein Schaltjahr darstellen.
		{
			printf("Die Jahreszahl %d, ist ein Schaltjahr\n ", eingabe); //Ausgabe der Überprüfung
		}
		else
		{
			printf("Die Jahreszahl %d, ist kein Schaltjahr\n ", eingabe); // Wenn Kein Schaltjahr, dann kommt folgender Satz.
		}
	} while ((beenden = getchar()) != 'b'); //Beendigungsgrund

	return;
}