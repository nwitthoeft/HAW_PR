#include <stdio.h>
#include <string.h>
/*
int main()
{
    for (int i = 8; i >= 1; i--)
    {
        for (int j = 65; j <= 72; j++)
        {
            printf("%c %d \t", j ,i);
        }
        printf("\n");
    }
    return 0;
}
*/



/*
int main(void) {
int blzahl = 20, sternzahl = 1, i, zeile;
char b[4] = "UU";

 for (zeile = 0; zeile < 10; zeile++)
{
for (i = 0; i < blzahl; i++)
printf(" ");
for (i = 0; i < sternzahl; i++)
printf("*");
blzahl--;
sternzahl += 2;
printf("\n");
}
printf("%*s\n",blzahl, b);
printf("%*s\n",blzahl, b);
}
*/

/*
void main() {
    char b[3] = "UU";
    int hoeheBaum = 21;
    int mitte = 40;
    char zeichenBaum = '*';
    for (int i = 1; i <= hoeheBaum; i++) {
        printf("%*c", mitte - i + 1, zeichenBaum);
        for (int j = 1; j <= 2 * i - 2; j++)
            printf("%c", zeichenBaum);
        printf("\n");
    }
    printf("%*s\n", mitte, b);
    printf("%*s\n", mitte, b);
}
*/
/*
void main() {
    int mitte = 60;
    int hoeheBaum = 10;
    char zeichenBaum = '*';
    int breiteStamm = 2;
    int hoeheStamm = 2;
    char zeichenStamm = 'U';
    for (int i = 1; i <= hoeheBaum; i++) {
        printf("%*c", mitte - i + 1, zeichenBaum);
        for (int j = 1; j <= 2 * i - 2; j++)
            printf("%c", zeichenBaum);
        printf("\n");
    }
    for (int i = 1; i <= hoeheStamm; i++) {
        printf("%*c", mitte - breiteStamm / 2, zeichenStamm);
        for (int j = 1; j < breiteStamm; j++)
            printf("%c", zeichenStamm);
        printf("\n");
    }
    return;
}
*/
/*
int main() {
    char name[10] = "";
    printf("Geben Sie einen Namen in Grossbuchstaben ein (Ihr Name darf nicht länger las 5 Zeichen lnag sein): \n");
    scanf_s("%5[A-Z]\n", name, 9);
    printf("Der Name lautet %s\n", name);
    return 0;
}
*/
/*

int main() {
    printf("Oberfl%cche \n", 132);
    printf("Oberfl\x84 \bche \n");
    printf("Oberfl\204che \n ");
    return 0;
}
*/

int main(void) {
    char auswahl[20];
    printf("\nGeben C f\201r Celsius oder F f\201r Fahrenheit ein: ");
    scanf_s("%s", &auswahl, 20);
    printf("%s Celsius.\n", auswahl);
    int length = strlen(auswahl);
    printf("Name length: %u", length);
    return 0;
}