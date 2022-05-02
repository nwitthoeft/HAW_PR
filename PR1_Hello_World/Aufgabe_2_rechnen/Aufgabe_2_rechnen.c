/*
Dateiname: temperaturumwandlung
Autoren: Nicolas Witthöft
Version: 1.0
Datum: 11.10.2021
Bescheibung: Übung mit einfachen Konsolenanwendungen. In diesem Projekt kann durch die eingabe von zwei Intege aus.
*/

#include <stdio.h>

void main()
{
    int a;
    int b;
    printf("Rechnung werden nach folgendem Schema vollzogen:\n\n" //Das Schema beschreibt die Funktion
                "summe = erste Zahlen + zweite Zahl\n"
                "differenz = erste Zahlen -  zweite Zahl\n"
                "produkt = erste Zahlen *  zweite Zahl\n"
                "quotient = erste Zahlen / zweite Zahl\n\n"
                "(Druecken Sie \"Enter\" um weiter zu kommen\n\n");

    printf("Geben die erste Zahlen ein:");
    scanf_s("%d", &a);

    printf("Geben Sie eine weitere Zahlen ein:");
    scanf_s("%d", &b);
   
    printf("Summe: %d\n", a + b);  // Für "%d" wird die entsprechende Variable eingesetzt
    printf("Differenz: %d\n", a - b);
    printf("Produkt: %d\n", a * b);
    if (b != 0) 
    {
        printf("Quotient: %f\n", (float)a / (float)b); //konvertierung von int in float
    }
    else
    {
        printf("Geben sie als zweite Zahl kein Null ein");
    }
    return;
}