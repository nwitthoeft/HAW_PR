/*
Dateiname: temperaturumwandlung
Autoren: Nicolas Witthöft
Version: 1.0
Datum: 11.10.2021
Bescheibung: Übung mit einfachen Konsolenanwendungen. Hier gibt das Projekt in der Konsole eine Temperaturumwandlung von Fahrenheit zu Celsius aus.
*/

#include <stdio.h>

int main()
{
    float f, c;

    printf("Fahrenheit - Celsius\n");   //Stellt den Tabellenkopf dar.
    f = 0; 
    while (f <= 300) {                      //Solange die Fahrenheitwerte kleinergleich 300, findet die Umrechnung statt.
        c = 5 * (f - 32) / 9;               //Umrechnung von Fahrenheit auf Celsius (siehe Formel), jedoch darf der Faktor nicht Null werden
        printf("%9.0f  -  %5.1f\n", f, c); 
        f = f + 50;                         // Wird in 50er Fahrenheit schritten ausgeführt
    }

    return 0;
}