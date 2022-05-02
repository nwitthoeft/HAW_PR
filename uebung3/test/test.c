#include <stdio.h>
int kupfermuenze(int m);

void main(void) {
	int eingabe;
	scanf_s("%d", &eingabe);
	int ruck = kupfermuenze(eingabe);
	printf("Die Anzahl der Münzen ist %d", ruck);
	return 0;
}

//umfang berechnet den Umfang eines Kreises mit Radius r
int kupfermuenze(int betrag)
{
	int muenzen = 0;
	muenzen += betrag / 5;
	betrag = betrag % 5;
	muenzen += betrag / 2;
	betrag = betrag % 2;
	muenzen += betrag;
	return muenzen;
}
