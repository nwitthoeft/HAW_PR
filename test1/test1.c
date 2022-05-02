#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <CTYPE.H>

int myStrlen(char s[]) //einlesen von string mit fgets(eingabestrAnz, 100, stdin);
{
    int i = 0;
    while (s[i] != '\0' && s[i] != '\n') {
        ++i;
    }

    return(i);
}

void fehlercheckchar(char* c)
{
    int temp;
    while (isalpha(*c) != 1)
    {

        printf("Falsche Eingabe, wiederholen Sie die eingabe\n\n");
        while ((temp = fgetc(stdin)) != '\n' && temp != EOF); // or while((temp=getchar()) != EOF && temp != '\n');
        scanf_s(" %c", &c, 1);

    }
    return;
}



void stringbuchstabentest(char eingabe[50])
{
    int laenge = myStrlen(eingabe);

    for (int i = 0; i < laenge; i++) {
        char temp;
        while (isalpha(eingabe[i]) == 0)
        {

            printf("Falsche Eingabe, wiederholen Sie die eingabe\n\n");
            while ((temp = fgetc(stdin)) != '\n' && temp != EOF); // or while((temp=getchar()) != EOF && temp != '\n');
            scanf_s("%s", &*eingabe, 50);

        }
        
    }
    return;
}

/*void concat(char[], char[]);
int main() {
    char s1[50], s2[30];
    printf("\nEnter String 1 :");
    gets(s1);
    printf("\nEnter String 2 :");
    gets(s2);
    concat(s1, s2);
    printf("\nConcated string is :%s", s1);
    return (0);
}
void concat(char s1[], char s2[]) {
    int i, j;
    i = strlen(s1);
    for (j = 0; s2[j] != '\0'; i++, j++) {
        s1[i] = s2[j];
    }
    s1[i] = '\0';
}
*/
/*
int myStrlen(char s[300]) //einlesen von string mit fgets(eingabestrAnz, 100, stdin);
{
    int i = 0;

    while (s[++i] != '\n'); //fge´ts ließt dem kompleten String ein und packt dahinter ein '\n', statt '\0' bei scan_f("%s", vaiable) https://www.includehelp.com/c/c-program-to-read-string-with-spaces-using-scanf-function.aspx

    return(i);
}

void fehlercheckchar(int test1, char* c)
{
    int temp;
    while (test1 != 1)
    {

        printf("Falsche Eingabe, wiederholen Sie die eingabe\n\n");
        while ((temp = fgetc(stdin)) != '\n' && temp != EOF); // or while((temp=getchar()) != EOF && temp != '\n');
        test1 = scanf_s(" %c", c, 1);

    }
    return;
}


int *getarray(char a[300], char c, int* mallocgroesse)
{
    int laenge = myStrlen(a); //strlen(a)
    int i;
    int groesse = 0;
    int l = 0;
    for (i = 0; i < laenge; i++)
	{
        
        if (a[i] == c)
        {
            groesse++;
        }
 
        
	}
   int * ergfunk = (int*)malloc(groesse * sizeof(int));
   *mallocgroesse = groesse;
   if (ergfunk == NULL) {
       exit(ergfunk);
    }

    for (i = 0;  i< laenge; i++)
    {

        if (a[i] == c)
        {
            ergfunk[l] = i + 1;
            l++;
        }


    }
    return ergfunk;
}

int main()
{
    char a[300];
    char c;
    int test;
    int groesse;

   // if (erg == NULL) {
   //     printf("Error! memory not allocated.");
   //     exit(0);
   // }


    printf("Geben Sie eine Zeichenkette in dem die Stelle eines Charaktaers gesucht werden soll\n");
    fgets(a, 300, stdin);

    printf("Geben Sie den Charakaer ein fuer den die Stelle in Zeichenkette gefunden werden soll\n");

    test = scanf_s(" %c", &c, 1);
    fehlercheckchar(test, c);

    int* erg = getarray(a, c, &groesse);


   if (erg == NULL) {
       printf("Fehler beim zuornen des Arrays"); //printf(stderr,"Fehler beim zuornen des Arrays");
       exit(0); //exit(1);

   }

    printf("\nAn den Stellen, ist dieses Zeichen zu finden :");

    for (int i = 0; i <groesse; i++)
    {
        printf(" %d ", erg[i]);
    }

    free(erg);

    return 0;
}
*/

void main()
{
    char temp;
    char stringos[50];

    printf("Eingabe:");
    scanf_s("%s", &stringos, 50);

    stringbuchstabentest(&stringos);

    printf("%s", stringos);

    return;
}