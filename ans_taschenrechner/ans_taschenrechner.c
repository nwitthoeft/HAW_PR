/*
Dateiname: Taschenrechner
Autor: Nicolas Witthöft
Version:1.0
Datum: 30.10.2021
Kurze Beschreibung des Programms: Das Programm ist ein einfacher Taschenrechner für die vier Grundrechenarten
*/

#include <stdio.h>

void main()
{
    float zahl1, zahl2; //Es werden drei floats (Gleitkommazahlen) definiert
    char eingabe1; //Es wird ein char definiert
    printf("Geben Sie bitte eine erste Zahl ein:");
    scanf_s("%f", &zahl1);
    do
    {
        printf("\nGeben Sie bitte eine zweite Zahl ein:");
        scanf_s("%f", &zahl2);
        printf("\nGeben Sie bitte ein, welche rechnung durchgefuehrt werden soll:\n"
            "\"A\" feur Addition von Zahl 1 + Zahl 2, \n"
            "\"S\" feur Subtraktion von Zahl 1 - Zahl 2,\n"
            "\"M\" feur Multiplikation von Zahl 1 * Zahl 2,\n"
            "\"D\" feur Division von Zahl 1 / Zahl 2:");
        scanf_s(" %c", &eingabe1, 1);                //Es werden die Zahlen und die Rechenopertation vom Benutzer abgefragt

        switch (eingabe1)                        //Ein switch der sich auf eingabe1 bezieht
        {
        case 'a':                                //Für den Fall, dass eingabe1 a oder A ist
        case 'A':
            zahl1 = zahl1 + zahl2;                //werden die beiden Zahlen addiert
            printf("\nDas Ergebnis der Rechnung ist:%g\n\n", zahl1); //danach wird das Ergebnis ausgegeben
            break;
        case 's':                                //Für den Fall, dass eingabe1 s oder S ist
        case 'S':
            zahl1 = zahl1 - zahl2;                //Die beiden Zahlen werden subtrahiert
            printf("\nDas Ergebnis der Rechnung ist:%g\n\n", zahl1);
            break;
        case 'm':                                //Für den Fall, dass eingabe m oder M ist
        case 'M':
            zahl1 = zahl1 * zahl2;                //Die beiden Zahlen werden multipliziert
            printf("\nDas Ergebnis der Rechnung ist:%g\n\n", zahl1);
            break;
        case 'd':                                //Für den Fall, dass eingabe1 d oder D ist
        case 'D':
            if (zahl2 != 0)                        //Die zweite Zahl wird überprüft, ob sie ungleich Null ist
            {
                zahl1 = zahl1 / zahl2;            //Die Zahlen werden dividiert
                printf("\nDas Ergebnis der Rechnung ist:%g\n\n", zahl1);
                break;
            }
            else                                //Falls die zweite Zahl 0 ist
            {
                printf("\nTeilen durch Null nicht moeglich\n\n"); //Wird ausgegeben, dass teilen durch null nicht möglich ist
                break;
            }
        default:                                //Standartausgabe wenn die vorherigen case nicht zutreffen
            if (eingabe1 != 'b' && eingabe1 != 'B') //Da dies der Fall zum beenden ist, soll hier der Standart nicht ausgegeben werden
            {
                printf("\nFalsche Eingabe\n\n"); //Es wird Falsche Eingabe ausgegeben
                break;
            }
        }
    } while (eingabe1 != 'b' && eingabe1 != 'B'); //Der Rechner wird ausgeführt bis der Benutzer b oder B eingibt
    return;
}