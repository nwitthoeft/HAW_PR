/*
Dateiname: begruessung
Autoren: Nicolas Witth�ft
Version: 1.0
Datum: 13.10.2021
Bescheibung: �bung mit einfachen Konsolenanwendungen. In diesem Projekt kann durch die eingabe des Namens eine Begr��ung erstellz werden.
*/

#include <stdio.h>

void main()
{
    printf("Wie ist ihr Name?"); //Erfragung des Namens
    char name[20];
    scanf_s("%s", &name,20);
    printf("Hallo %s.", &name); //Begr��ung
    printf("\n\n%s ich wuensche ihnen viel Spass beim Programmieren.", &name);

}