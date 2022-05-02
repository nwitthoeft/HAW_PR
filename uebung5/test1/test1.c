// C program to demonstrate
// example of toupper() function.
#include <ctype.h>
#include <stdio.h>

int diff(int zahl1, int zahl2);
int asciswitch2(char eingabe2);
int buchstabezuAlphabetNummer(char grossbuchstabe);
int quersumme_berechnen(int zahl);
void euroscheinpruefer(char grossbuchstabe, int zahl1, int zahl2, int pruefzahl);

int main() {
	int dd, mm, yy;
	printf("Wann ist ihr GB? (dd.mm.yy)\n");
	int pruef = scanf_s("%d %d %d", &dd, &mm, &yy);
	if (pruef != 3)
	{
		printf("falsche eingabe\n");
	}
	char grossbuchstabe;
	int	zahl1;
	int zahl2;
	int pruefzahl;

	printf("Programm zur Prüfung der Seriennummer eines Geldscheins\n"
		"Bitte geben Sie den Grossbuchstaben ein:\n");
	scanf_s(" %c", &grossbuchstabe, 1);
	printf("Bitte geben Sie die ersten 5 Ziffern ein:\n");
	scanf_s("%d", &zahl1);
	printf("Bitte geben Sie die zweiten 5 Ziffern ein:\n");
	scanf_s("%d", &zahl2);
	printf("Bitte geben Sie die Pruefzahl ein:\n");
	scanf_s("%d", &pruefzahl);
	euroscheinpruefer(grossbuchstabe, zahl1, zahl2, pruefzahl);
}
/*
int main() {
	char eingabe2;
	printf("Geben Sie ein String, dessen Charakaere in von Kleinbuchstaben zu Grossbuchstaben und umgekehrt umgewandelt wird\n");
	scanf_s(" %c", &eingabe2, 1);
	int a = quersumme_berechnen(buchstabezuAlphabetNummer(eingabe2));
	printf("%d\n", a);


}
*/
/*int main()
{
	int zahl = 55;
	int quersumme = 0;
	while( zahl != 0)
	{
		quersumme = quersumme + (zahl % 10);
		zahl = zahl / 10;

	}

	printf("%d", quersumme);
	return;
}
*/

int buchstabezuAlphabetNummer(char grossbuchstabe)
{
	int buchstabe = asciswitch2(grossbuchstabe);
	int alphabetnummer = buchstabe - 64;
	return(alphabetnummer);

}

int asciswitch2(char eingabe2)
{
	int kontrollvar = 1;
	if (eingabe2 >= 65 && eingabe2 <= 90)
	{
		return((int)eingabe2);
	}
	else if (eingabe2 >= 97 && eingabe2 <= 122)
	{
		return((int)eingabe2 - 32);
	}
	else if (eingabe2 != EOF || eingabe2 != '\n' || eingabe2 != '\0')
	{
		kontrollvar = 0;
		return(kontrollvar);
	}

}

int quersumme_berechnen(int zahl)
{
	int quersumme = 0;
	while (zahl != 0)
	{
		quersumme = quersumme + (zahl % 10);
		zahl = zahl / 10;

	}

	return(quersumme);
}

int diff(int zahl1, int zahl2)
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

void euroscheinpruefer(char grossbuchstabe, int zahl1, int zahl2, int pruefzahl)
{
	int gesammtquersumme = quersumme_berechnen(buchstabezuAlphabetNummer(grossbuchstabe)) + quersumme_berechnen(zahl1) + quersumme_berechnen(zahl2);
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