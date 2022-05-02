/*
Dateiname: begruessung
Autoren: Nicolas Witthöft
Version: 1.0
Datum: 13.10.2021
Bescheibung: Übung mit einfachen Konsolenanwendungen. In diesem Projekt kann durch die eingabe des Namens eine Begrüßung erstellz werden.
*/

#include <stdio.h>

void main()
{
    printf("Wie ist ihr Name?"); //Erfragung des Namens
    char name[20];
    scanf_s("%s", &name,20);
    printf("Hallo %s.", &name); //Begrüßung
    printf("\n\n%s ich wuensche ihnen viel Spass beim Programmieren.", &name);

}