/*
Dateiname:Taschenrechner
Autor: Nicolas Witthöft
Version: 1.0
Datum: 22.10.2021
Bescheibung: In diesem Projekt kann durch die Eingabe des Benutzers in der Konsole, verschiedene Rechenoperationen durchgeführt werden.
*/

#include <stdio.h>


void main()
{
	float erste_zahl;
	float zweite_zahl;
	char eingabe;
	do {
		printf("Rechnung werden nach folgendem Schema vollzogen:\n\n" //Das Schema beschreibt die Funktion.
			"Eingabe bei A(ddition) = erste Zahlen + zweite Zahl\n"
			"Eingabe bei S(ubtraktion) = erste Zahlen -  zweite Zahl\n"
			"Eingabe bei M(ultiplikation) = erste Zahlen *  zweite Zahl\n"
			"Eingabe bei D(ivision) = erste Zahlen / zweite Zahl\n\n"
		);


		printf("Geben die erste Zahlen ein:\n");
		scanf_s("%f", &erste_zahl);



		printf("Geben die zweite Zahlen ein:\n");
		scanf_s("%f", &zweite_zahl);

		printf("Geben Sie einen der oben genannten Operatoren an\n"); //Eingabe um den Operator den festzulegen.
		scanf_s(" %c", &eingabe, 1);

		switch (eingabe) {
		case 'A': //Operation für 'A' & 'a' (Addition)
		case 'a':
			printf("Summe: %g\n", erste_zahl + zweite_zahl);
			break;
		case 'S': //Operation für 'S' & 's' (Subtraktion)
		case 's':
			printf("Differenz: %g\n", erste_zahl - zweite_zahl);
			break;
		case 'M': //Operation für 'M' & 'm' (Multiplikation)
		case 'm':
			printf("Produkt: %g\n", erste_zahl * zweite_zahl);
			break;
		case 'D': //Operation für 'D' & 'd' (Division)
		case 'd':
			if (zweite_zahl != 0) //Überprüfung, ob Divisor ungleich Null ist, denn durch Nullteilen ist nicht erlaubt
			{
				printf("Quotient: %g\n", erste_zahl / zweite_zahl); //konvertierung von int in float und Ergebnis ist der Quotient.
			}
			else
			{
				printf("Geben Sie als zweite Zahl keine Null ein");
			}
			break;
		default:
			printf("Sie haben keinen der oben genannte Operatoren ausgewaehlt. Bitte versuchen Sie es nochmal");
			break;
		}

	} while ((eingabe != 'b') && (eingabe != 'B'));



	return;
}

/*void main() 
{
	char ASCII;
	printf("Please enter a character: ");
	scanf_s("%c", &ASCII);
	printf("%d\n", ASCII);



 

	return;
}
*/