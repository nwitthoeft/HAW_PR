#include "funktionen.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <CTYPE.H>

/*
* Beschreibung:
Die Funktion dient zum Einlesen der Daten der Studenten/innen.
Außerdem kann die Form des Einfügens gewählt werden.
Parameter: kopf der List und Ende der Liste
Rückgabewert: void
*/
void einlesenVonDaten(element** kopf, element **ende) {

    char eingabe;
    char c;
    char nachnameTempBuffer[BUFFER_GROESSE];
    char vornameTempBuffer[BUFFER_GROESSE];
    char eMailTempBuffer[BUFFER_GROESSE];
    int nachnameLaenge = 0;
    int vornameLaenge = 0;
    int eMailLaenge = 0;
    unsigned long telefonNummer;
    int test;

    /*Einlesen des Nachnamens*/
    while ((c = fgetc(stdin)) != '\n' && c != EOF);
    printf("\n");

    printf("Geben Sie den Nachnamen der Person ein\n");
    fgets(nachnameTempBuffer, BUFFER_GROESSE, stdin);
    nachnameLaenge = strlen(nachnameTempBuffer);

    if (nachnameLaenge == 1) {
        exit(-1); //Falls Leerzeile -> Abbruch
    }

    nachnameTempBuffer[nachnameLaenge - 1] = '\0'; //Das \n aus fgets wird mit \0 ersetzt
    char *nachname = (char*)malloc(nachnameLaenge * sizeof(char));
    if (nachname == NULL) {
        exit(-1);;
    }
    strcpy_s(nachname, nachnameLaenge, nachnameTempBuffer);
    printf("Die Eingabe war: %s\n", nachname);

    printf("Geben Sie den Vornamen der Person ein\n");
    fgets(vornameTempBuffer, BUFFER_GROESSE, stdin);
    vornameLaenge = strlen(vornameTempBuffer);

    if (vornameLaenge == 1) {
        exit(-1); //Falls Leerzeile -> Abbruch
    }
    vornameTempBuffer[vornameLaenge - 1] = '\0'; //Das \n aus fgets wird mit \0 ersetzt
    char *vorname = (char*)malloc(vornameLaenge * sizeof(char));
    if (vorname == NULL) {
        exit(-1);;
    }
    strcpy_s(vorname, vornameLaenge, vornameTempBuffer);
    printf("Die Eingabe war: %s\n", vorname);

    /*Einlesen der E-Mail*/
    /*
    while ((c = fgetc(stdin)) != '\n' && c != EOF);
    printf("\n");
    */
    printf("Geben Sie fuer %s %s, die E-Mail ein\n", vorname, nachname);
    fgets(eMailTempBuffer, BUFFER_GROESSE, stdin);
    eMailLaenge = strlen(eMailTempBuffer);

    if (eMailLaenge == 1) {
        exit(-1); //Falls Leerzeile -> Abbruch
    }
    eMailTempBuffer[eMailLaenge - 1] = '\0'; //Das \n aus fgets wird mit \0 ersetzt
    char  *eMail = (char*)malloc(eMailLaenge * sizeof(char));
    if (eMail == NULL) {
        exit(-1);
    }
    strcpy_s(eMail, eMailLaenge, eMailTempBuffer);
    printf("Die Eingabe war: %s\n", eMail);
    /*Einlesen der Telefonnummer*/
    printf("Geben Sie fuer %s %s, die Telefonnummer ein\n", vorname, nachname);
    test = scanf_s("%lu", &telefonNummer);
    fehlerCheckUnsingedLong(test, &telefonNummer);

    /*Abfrage, ob Name doppelt eingelesen wurde
    sucheDoppelt wurde hier nicht wie sonst der Kopf mit call by referecence, sondern der Zeiger ansich übergeben,
    daraus folgt, dass in dem Funktion prototypen nicht mehr vielfache * vorkommen wie int sucheDoppelt(element*** anfang, char* vorname, char* nachname) => int sucheDoppelt(element* anfang, char* vorname, char* nachname)
     */

   
    if (*kopf != NULL && sucheDoppelt(*kopf, vorname, nachname) == -1) {
        printf("\nDer Eintrag existiert schon!\n");
    }
    else{
        printf("\nWo moechten Sie den Namen einspeichern.Folgende Funktionen sind verfuegbar:\n\n"
            "O/o: Von oben in der Liste\n"
            "u/U: Von unten in der Liste\n"
            "S/s: Bestimmte Stelle die Daten einspeichern\n"
            "A/a: Alphabetisch Sortieren\n\n"
            "Geben Sie einen der oben genannten Operatoren an\n"); //Eingabe um den Operator den festzulegen.
        scanf_s(" %c", &eingabe, 1);
        while ((c = fgetc(stdin)) != '\n' && c != EOF); //damit nicht in der mail funktion ein zweiter Buchstabe direkt eingelesen wird.
        switch (eingabe) {
        case 'O':
        case 'o':
            vonVorneEinsetzten(&kopf, nachname, vorname, eMail, telefonNummer, nachnameLaenge, vornameLaenge, eMailLaenge);
            break;
        case 'U':
        case 'u':
            vonHintenEinsetzen(&kopf, nachname, vorname, eMail, telefonNummer, nachnameLaenge, vornameLaenge, eMailLaenge);
            break;
        case 'S':
        case 's':
            spezifischEinsetzen(&kopf, nachname, vorname, eMail, telefonNummer, nachnameLaenge, vornameLaenge, eMailLaenge);
            break;
        case 'A':
        case 'a':
            vonVorneEinsetzten(&kopf, nachname, vorname, eMail, telefonNummer, nachnameLaenge, vornameLaenge, eMailLaenge);
            meineSortierung(&kopf, &ende);
            break;
        default:
            printf("Sie haben keinen der oben genannte Operatoren ausgewaehlt. Bitte versuchen Sie es nochmal\n");
            break;
        }

    }
    return;

}

/*
* Beschreibung:
Mit dieser Funktion kann überprüft werden, ob eine Person 
Parameter: testvaraible und adresse der zu modfizierenden variable
Rückgabewert: void
*/
/*
int sucheDoppelt(element*** anfang, char* vorname, char* nachname)
{
    element* aktuellesElement = **anfang;
    while (aktuellesElement != NULL)
    {
        if (strcmp(vorname, aktuellesElement->student.nameDerPerson.vorname) == 0 && strcmp(nachname, aktuellesElement->student.nameDerPerson.nachname) == 0)
            return -1;
        aktuellesElement = aktuellesElement->next;
    }
    return 0;
}
*/

int sucheDoppelt(element* anfang, char* vorname, char* nachname)
{
    element* aktuellesElement = anfang;
    while (aktuellesElement != NULL)
    {
        if (strcmp(vorname, aktuellesElement->student.nameDerPerson.vorname) == 0 && strcmp(nachname, aktuellesElement->student.nameDerPerson.nachname) == 0)
            return -1;
        aktuellesElement = aktuellesElement->next;
    }
    return 0;
}
/*
* Beschreibung:
Fehlercheck für das Einlesen von unsigned long
Parameter: testvaraible und adresse der zu modfizierenden variable
Rückgabewert: void
*/
void fehlerCheckUnsingedLong(int test1, unsigned long* x) {
    char temp;
    while (test1 == 0 ) {
        printf("Falsche Eingabe, wiederholen Sie die eingabe\n");
        while ((temp = fgetc(stdin)) != '\n' && temp != EOF); // or while((temp=getchar()) != EOF && temp != '\n');
        test1 = scanf_s("%lu", &*x);
    }
    return;
}

/*
* Beschreibung:
In dieser Funktion werden die Daten jedes Elementes von vorne in die Liste einsortiert.
Parameter: kopf der List und Daten der Person.
Rückgabewert: void
*/
void vonVorneEinsetzten(element*** kopf, char nachname[], char vorname[], char eMail[], unsigned long telefonNummer, int nachnameLaenge, int vornameLaenge, int eMailLaenge)
{
    struct element* aktuellesElement;

    aktuellesElement = (struct element*)malloc(sizeof(struct element));
    if (aktuellesElement == NULL)
    {
        printf("\nSpeicherüberlauf");
    }
    else
    {
        
        if (**kopf == NULL)//Im Fall der Leeren Liste
        {
            aktuellesElement->next = NULL;
            aktuellesElement->prev = NULL;
            strcpy_s(aktuellesElement->student.nameDerPerson.nachname, nachnameLaenge, nachname);
            strcpy_s(aktuellesElement->student.nameDerPerson.vorname, vornameLaenge, vorname);
            strcpy_s(aktuellesElement->student.email, eMailLaenge, eMail);
            aktuellesElement->student.handynummer = telefonNummer;
            **kopf = aktuellesElement;
        }
        else //Im Fall, dass Elemente schon gespeichert worden.
        {
            strcpy_s(aktuellesElement->student.nameDerPerson.nachname, nachnameLaenge, nachname);
            strcpy_s(aktuellesElement->student.nameDerPerson.vorname, vornameLaenge, vorname);
            strcpy_s(aktuellesElement->student.email, eMailLaenge, eMail);
            aktuellesElement->student.handynummer = telefonNummer;
            aktuellesElement->prev = NULL;
            aktuellesElement->next = **kopf;
            (**kopf)->prev = aktuellesElement;
            **kopf = aktuellesElement;
        }
        printf("\nSchueler gespeichert\n");
    }
    return;
}

/*
* Beschreibung:
In dieser Funktion werden die Daten jedes Elementes von hinten in die Liste einsortiert.
Parameter: kopf der List und Daten der Person.
Rückgabewert: void
*/
void vonHintenEinsetzen(element*** kopf, char nachname[], char vorname[], char eMail[], unsigned long telefonNummer, int nachnameLaenge, int vornameLaenge, int eMailLaenge)
{
    struct element* aktuellesElement, * temporaeresElement;
    aktuellesElement = (struct element*)malloc(sizeof(struct element));
    if (aktuellesElement == NULL)
    {
        printf("\nSpeicherüberlauf");
    }
    else
    {
       
        strcpy_s(aktuellesElement->student.nameDerPerson.nachname, nachnameLaenge, nachname);
        strcpy_s(aktuellesElement->student.nameDerPerson.vorname, vornameLaenge, vorname);
        strcpy_s(aktuellesElement->student.email, eMailLaenge, eMail);
        aktuellesElement->student.handynummer = telefonNummer;
        if (**kopf == NULL) //Im Fall der Leerenliste
        {
            aktuellesElement->next = NULL;
            aktuellesElement->prev = NULL;
            **kopf = aktuellesElement;
        }
        else
        {
            temporaeresElement = **kopf;
            while (temporaeresElement->next != NULL)//Durchlaufen der Liste, bis das ende der Liste erreicht ist.
            {
                temporaeresElement = temporaeresElement->next;
            }
            temporaeresElement->next = aktuellesElement;    //aktuellesElement (mit den Daten) wird am ende der Liste postioniert.
            aktuellesElement->prev = temporaeresElement;    //aktuellesElement zeigt auf das vorderes (zuvor letztes Element) Element
            aktuellesElement->next = NULL;                  //Das aktuelle Elemet muss auf das ende der Liste (= NULL) zeigen
        }

    }
    printf("\nSchueler gespeichert\n");
    return;
}

/*
* Beschreibung:
In dieser Funktion werden die Daten eines Elementes an einer bestimmten Stelle in die Liste einsortiert.
Parameter: kopf der List und Daten der Person.
Rückgabewert: void
*/
void spezifischEinsetzen(element*** kopf, char nachname[], char vorname[], char eMail[], unsigned long telefonNummer, int nachnameLaenge, int vornameLaenge, int eMailLaenge)
{
    struct element* aktuellesElement, * temporaeresElement;
    int stelleInDerListe, i;
    aktuellesElement = (struct element*)malloc(sizeof(struct element));
    if (aktuellesElement == NULL)
    {
        printf("\n Speicherüberlauf");
    }
    else
    {
        temporaeresElement = **kopf;
        printf("Gebe die Position an\n");
        scanf_s("%d", &stelleInDerListe);

        /*Startwert i = 2, weil bei Listen bei 1 begonenen wird zu zählen(Nicht wie bei arrays),
        dammit entsteht der 1 Offset im Vergleich zu den Arrays. 
        Außerdem kommt noch hinzu,dass das erstes element der Kopf als NULL(void pointer) deklariert wurde.*/
        for (i = 2; i < stelleInDerListe; i++)  
        {
            temporaeresElement = temporaeresElement->next;
            if (temporaeresElement == NULL)
            {
                printf("\n There are less than %d elements", stelleInDerListe);
                return;
            }
        }
        strcpy_s(aktuellesElement->student.nameDerPerson.nachname, nachnameLaenge, nachname);
        strcpy_s(aktuellesElement->student.nameDerPerson.vorname, vornameLaenge, vorname);
        strcpy_s(aktuellesElement->student.email, eMailLaenge, eMail);
        aktuellesElement->student.handynummer = telefonNummer;

        /*Einfügen an der Position*/
        aktuellesElement->next = temporaeresElement->next;  
        aktuellesElement->prev = temporaeresElement;
        temporaeresElement->next = aktuellesElement;
        temporaeresElement->next->prev = aktuellesElement;
        printf("\nnode inserted\n");
    }
    return;
}

/*
* Beschreibung:
In dieser Funktion werden die Daten eines Elementes an einer bestimmten Stelle in die Liste gelöscht.
Parameter: kopf der List
Rückgabewert: void
*/
void loeschenStudenten(element** kopf) {
    char eingabe;
    char c;

    printf("\nHier koennen Sie Studenten aus der Liste Löschen. Folgende Funktionen sind verfuegbar:\n\n"
        "O/o: Den obersten Studenten aus der Liste loeschen\n"
        "u/U: Den untersten Studenten aus der Liste loeschen\n"
        "S/s: Bestimmte Stelle die Daten loeschen\n"
        "G/g: gesammte Liste loeschen\n\n"
        "Geben Sie einen der oben genannten Operatoren an\n"); //Eingabe um den Operator den festzulegen.
    scanf_s(" %c", &eingabe, 1);
    while ((c = fgetc(stdin)) != '\n' && c != EOF);
    switch (eingabe) {
    case 'O':
    case 'o':
        vonVorneLoeschen(&kopf);
        break;
    case 'U':
    case 'u':
        vonHintenLoeschen(&kopf);
        break;
    case 'S':
    case 's':
        spezifischLoeschen(&kopf);
        break;
    case 'G':
    case 'g':
        loescheListe3(&kopf);
        break;
    default:
        printf("Sie haben keinen der oben genannte Operatoren ausgewaehlt. Bitte versuchen Sie es nochmal\n");
        break;
    }
    return;
}

/*
* Beschreibung:
In dieser Funktion werden die Daten eines Elementes der gesammten Liste gelöscht (Aus dem heap mit anfang un ende).
Parameter: kopf der List
Rückgabewert: void
*/
void loescheListe1(element*** kopf) {
    struct element* aktuellesElement, * zuLoeschendeElement = NULL;
    aktuellesElement = **kopf;
    while (aktuellesElement != NULL) {
        zuLoeschendeElement = aktuellesElement;     //temporäres Element, dass den Zeiger zur Adresse Speichert zum Element
        aktuellesElement = aktuellesElement->next;  //Um den Pointer zum nächsten Element nicht zu verlieren
        free(zuLoeschendeElement);
    }
    printf("Die List wurde geloescht");
    return;
}

/*
* Beschreibung:
In dieser Funktion werden die Daten eines Elementes der gesammten Liste gelöscht (Aus dem heap mit anfang un ende).
Parameter: kopf der List
Rückgabewert: void
*/
void loescheListe2(element** kopf) {
    struct element* aktuellesElement, * zuLoeschendeElement = NULL;
    aktuellesElement = *kopf;
    while (aktuellesElement != NULL) {
        zuLoeschendeElement = aktuellesElement;     //temporäres Element, dass den Zeiger zur Adresse Speichert zum Element
        aktuellesElement = aktuellesElement->next;  //Um den Pointer zum nächsten Element nicht zu verlieren
        free(zuLoeschendeElement);
    }
    printf("Die List wurde geloescht");
    return;
}

/*
* Beschreibung:
In dieser Funktion werden die Daten eines Elementes der gesammten Liste gelöscht (Aus dem heap mit anfang un ende).
Parameter: kopf der List
Rückgabewert: void
*/
void loescheListe3(element*** kopf)
{
    int i;
    int anzElemente = zaehleAnzListenElemente3(&kopf);
    for (i = 0; i < anzElemente; i++)
    {
        element* zuLoeschendesElement = **kopf;//Aus der Kombination dieser Zeiler 

        if (**kopf == NULL || zuLoeschendesElement == NULL) { //Wenn die Liste leer ist
            return;
        }
        if (**kopf == zuLoeschendesElement) { //Wenn der Kopf gleich dem zu löschendem Element ist, soll der kopf zum nächsten Element in der Liste gehen
            **kopf = zuLoeschendesElement->next;
        }
        if (zuLoeschendesElement->next != NULL) { //Isolierung des zu löschen elementes und das nächste element vom zu löschenden Elementes zeigt mit prev auf NULL 
            zuLoeschendesElement->next->prev = zuLoeschendesElement->prev;
        }
        if (zuLoeschendesElement->prev != NULL) { //Wird verwenden, wenn dass Ende der Liste als Start verwendet wird wird. Dann hat die Funktion die gleiche Funktion.
            zuLoeschendesElement->prev->next = zuLoeschendesElement->next;
        }

        free(zuLoeschendesElement);
    }
    return;
}


/*
* Beschreibung:
In dieser Funktion werden die Daten eines Elementes von vorne in die Liste gelöscht.
Parameter: kopf der Liste
Rückgabewert: void
*/
void vonVorneLoeschen(element*** kopf)
{
    struct element* aktuellesElement;
    if (**kopf == NULL)
    {
        printf("\nLeereliste, es sind keine Elemente vorhanden zum loeschen");
    }
    else if ((**kopf)->next == NULL) //Liste mit einem Element
    {
        **kopf = NULL;
        free(**kopf);
        printf("\nDie Daten der Liste wurden geloescht\n");
    }
    else
    {
        aktuellesElement = **kopf;  
        **kopf = (**kopf)->next; //Es wird zum nächsten Element gespungen
        (**kopf)->prev = NULL;  //Das nächste Element zeigt mit prev auf NULL (neues erstes Element)
        printf("\nDaten vom Studeneten %s %s wurden geloescht\n", aktuellesElement->student.nameDerPerson.vorname, aktuellesElement->student.nameDerPerson.nachname);
        free(aktuellesElement); //loeschen des aktelles Elementes, dass abgeschnitten wurde von der liste;
    }
    return;
}

/*
* Beschreibung:
In dieser Funktion werden die Daten eines Elementes von hinten in die Liste gelöscht.
Parameter: kopf der Liste
Rückgabewert: void
*/
void vonHintenLoeschen(element*** kopf)
{
    struct element* aktuellesElement;
    if ((**kopf) == NULL)
    {
        printf("\n Leereliste, es sind keine Elemente vorhanden zum loeschen");
    }
    else if ((**kopf)->next == NULL)//Liste mit einem Element
    {
        **kopf = NULL;
        printf("\nDie Daten der Liste wurden geloescht\n");
        free(**kopf);
    }
    else
    {
        aktuellesElement = **kopf;
        if (aktuellesElement->next != NULL)//Durch zählen
        {
            aktuellesElement = aktuellesElement->next;
        }
        aktuellesElement->prev->next = NULL;
        printf("\nDaten vom Studeneten %s %s wurden geloescht\n", aktuellesElement->student.nameDerPerson.vorname, aktuellesElement->student.nameDerPerson.nachname);
        free(aktuellesElement);
    }
    return;
}

/*
* Beschreibung:
In dieser Funktion werden die Daten eines Elementes von einer bestimmenten Stelle gelöscht.
Dabei wird vom Benutzer einer Eingabe erwertet, die den Nachnamen erfragt? 
Parameter: kopf der Liste
Rückgabewert: void
*/
void spezifischLoeschen(element*** kopf)
{
    char c;
    char nachnameTempBuffer[BUFFER_GROESSE];
    int nachnameLaenge = 0;

    struct element* aktuellesElement, * temp = NULL;
    aktuellesElement = **kopf;
    printf("Welchen Student möchten Sie loeschen?(Geben Sie den Nachnamen ein): ");
    /*Einlesen des Nachnamens*/
    while ((c = fgetc(stdin)) != '\n' && c != EOF);
    printf("\n");

    printf("Geben Sie den Nachnamen der Person ein\n");
    fgets(nachnameTempBuffer, BUFFER_GROESSE, stdin);
    nachnameLaenge = strlen(nachnameTempBuffer);

    if (nachnameLaenge == 1) {
        exit(-1); //Falls Leerzeile -> Abbruch
    }

    nachnameTempBuffer[nachnameLaenge - 1] = '\0'; //Das \n aus fgets wird mit \0 ersetzt
    char* nachname = (char*)malloc(nachnameLaenge * sizeof(char));
    if (nachname == NULL) {
        exit(-1);;
    }
    strcpy_s(nachname, nachnameLaenge, nachnameTempBuffer);
    printf("Die Eingabe war: %s\n", nachname);

    
    while (strcmp(aktuellesElement->student.nameDerPerson.nachname, nachname) != 0) { //Bis der Nachname der Person in der liste gefundfen wurde.
        aktuellesElement = aktuellesElement->next;
    }

    /*
    Ab hier muss noch gefixt werden ...
    */
    aktuellesElement = aktuellesElement->prev; //wichtig, sonst wird nicht das Richtige gelöscht.

    
    if (aktuellesElement->next == NULL)
    {
        printf("\nDie Daten dieses Studenten konnten nicht geloescht werden\n");
    }
    else if (aktuellesElement->next->next == NULL)
    {
        aktuellesElement->next = NULL;
    }
    else
    {
        temp = aktuellesElement->next;
        aktuellesElement->next = temp->next;
        temp->next->prev = aktuellesElement;
        free(temp);
        printf("\nDaten vom Studeneten %s %s wurden geloescht\n", aktuellesElement->student.nameDerPerson.vorname, aktuellesElement->student.nameDerPerson.nachname);
    }
    return;
}

/*
Die nächsten drei Funktionen gehören zu einem alternativen Sortieralgorithmus der nach Nachnamen, jedoch nicht nach Nachnamen und Vornamen sortieren kann.
*/

/* zwei sortierte Listen werden zusammengefuegt. p1 und p2 müssen != NULL */
struct element* zusammenfuegen(struct element* liste1, struct element* liste2) {
    struct element* kopf, ** aktuellesElement;
    aktuellesElement = &kopf;
    for (;;) {
        if (strcmp(liste1->student.nameDerPerson.nachname, liste2->student.nameDerPerson.nachname) <= 0) { //int strcmp(const char* s1, char const s2) vergleicht die beiden strings Character zu Character. Begonnen zu vergleichen beginnt beim ersten Character jeden Wortes. Wenn der s1<s1 in ASCII ist wird ein Wert kleiner als 0 zurückgegeben. Wenn ein die Beiden Charactäre gleich groß sind, wird 0 zurückgegeben. Wenn s1>s2 dann wird ein Wert größer 0 zurückgegeben.
            *aktuellesElement = liste1;
            aktuellesElement = &liste1->next;
            liste1 = liste1->next;
            if (liste1 == NULL) {
                *aktuellesElement = liste2;
                break;
            }
        }
        else {
            *aktuellesElement = liste2;
            aktuellesElement = &liste2->next;
            liste2 = liste2->next;
            if (liste2 == NULL) {
                *aktuellesElement = liste1;
                break;
            }
        }
    }
    return kopf;
}

/* Rekursives von-oben zusammengefuegtes sortieren */
struct element* zusammenfuegenSortieren(struct element* kopf) {
    struct element* p1, * p2;
    /* Leere Liste werden nicht sortiert */
    if (kopf == NULL || kopf->next == NULL)
        return kopf;
    /* Den Mittelpunkt finden*/
    for (p1 = kopf, p2 = kopf->next; p2 && p2->next; p2 = p2->next->next)
        p1 = p1->next;
    /* Liste in der Mitte Teilen */
    p2 = p1->next;
    p1->next = NULL;
    p1 = kopf;
    /* rekursiv sortieren */
    p1 = zusammenfuegenSortieren(p1);
    p2 = zusammenfuegenSortieren(p2);
    return zusammenfuegen(p1, p2);
}

void sortieren(element*** kopf, element*** ende) {
    struct element* p1, * p2;
    /* sort the list as a singly linked list */
    **kopf = zusammenfuegenSortieren(**kopf); //hier muss der Anfang also der head verwendet werden.
    /* Rekonstruktion der backlinks */
    p1 = NULL;
    for (p2 = **kopf; p2; p2 = p2->next) {
        p2-> prev = p1;
        p1 = p2;
    }
    **ende = p1;
}

/*
* Beschreibung:
In dieser Funktion werden die Daten eines Elementes gesucht. Der such Parameter ist der nachname..
Dabei wird vom Benutzer einer Eingabe erwertet, die den Nachnamen erfragt.
Parameter: kopf der Liste
Rückgabewert: void
*/
void suche(element** kopf)
{
    char c;
    char nachnameTempBuffer[BUFFER_GROESSE];
    int nachnameLaenge = 0;

    struct element* aktuellesElement;
    int i = 0, Kennzeichnung;
    aktuellesElement = *kopf;
    if (aktuellesElement == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        /*Einlesen des Nachnamens*/
        while ((c = fgetc(stdin)) != '\n' && c != EOF);
        printf("\n");

        printf("Geben Sie den Nachnamen der Person ein\n");
        fgets(nachnameTempBuffer, BUFFER_GROESSE, stdin);
        nachnameLaenge = strlen(nachnameTempBuffer);

        if (nachnameLaenge == 1) {
            exit(-1); //Falls Leerzeile -> Abbruch
        }

        nachnameTempBuffer[nachnameLaenge - 1] = '\0'; //Das \n aus fgets wird mit \0 ersetzt
        char* nachname = (char*)malloc(nachnameLaenge * sizeof(char));
        if (nachname == NULL) {
            exit(-1);;
        }
        strcpy_s(nachname, nachnameLaenge, nachnameTempBuffer);
        printf("Die Eingabe war: %s\n", nachname);

        while (aktuellesElement != NULL)//es wird gesucht bis das ende der Liste erreicht ist.
        {
            if (strcmp(aktuellesElement->student.nameDerPerson.nachname, nachname) == 0)
            {
                printf("\n%s %s ist an Position: %d \n\n",aktuellesElement->student.nameDerPerson.vorname, aktuellesElement->student.nameDerPerson.nachname, i + 1);
                printf("%s\n", aktuellesElement->student.nameDerPerson.nachname);
                printf("%s\n", aktuellesElement->student.nameDerPerson.vorname);
                printf("%s\n", aktuellesElement->student.email);
                printf("%u\n\n", aktuellesElement->student.handynummer);
                Kennzeichnung = 0;
                break;
            }
            else
            {
                Kennzeichnung = 1;
            }
            i++;
            aktuellesElement = aktuellesElement->next;//Lauf
        }
        if (Kennzeichnung == 1)
        {
            printf("\nStudent wurde nicht gefunden\n");
        }
    }
    return;
}

/*
* Beschreibung:
In dieser Funktion kann die Liste von vorne oder von hinten ausgegeben werden.

Parameter: kopf der Liste
Rückgabewert: void
*/
void ausgabe(element** kopf) {
    char eingabe;
    char c;

    printf("\nHier koennen Sie Studenten aus der Liste ausgeben. Folgende Funktionen sind verfuegbar:\n\n"
        "V/v: Die Ausgabe von Vorne\n"
        "H/h: Den untersten Studenten aus der Liste ausgeben\n\n"
        "Geben Sie einen der oben genannten Operatoren an\n"); //Eingabe um den Operator den festzulegen.
    scanf_s(" %c", &eingabe, 1);
    while ((c = fgetc(stdin)) != '\n' && c != EOF);
    switch (eingabe) {
    case 'V':
    case 'v':
        vonVorneAusgabe(&kopf);
        break;
    case 'H':
    case 'h':
        vonHintenAusgabe(&kopf);
        break;
    default:
        printf("Sie haben keinen der oben genannte Operatoren ausgewaehlt. Bitte versuchen Sie es nochmal\n");
        break;
    }
    return;
}

/*
* Beschreibung:
In dieser Funktion kann die Liste von vorne ausgegeben werden.

Parameter: kopf der Liste
Rückgabewert: void
*/
void vonVorneAusgabe(element*** kopf)
{
    struct element* aktuellesElement;
    printf("\nFolgenden Studenten Daten sind gespeichert worden...\n");
    aktuellesElement = **kopf;

    if (aktuellesElement == NULL) {
        printf("Die Liste ist Leer");
        return;
    }

    while (aktuellesElement != NULL)
    {
        printf("%s\n", aktuellesElement->student.nameDerPerson.nachname);
        printf("%s\n", aktuellesElement->student.nameDerPerson.vorname);
        printf("%s\n", aktuellesElement->student.email);
        printf("%lu\n\n", aktuellesElement->student.handynummer);
        aktuellesElement = aktuellesElement->next;//lauf
    }
    return;
}

/*
* Beschreibung:
In dieser Funktion kann die Liste von hinten ausgegeben werden.

Parameter: kopf der Liste
Rückgabewert: void
*/
void vonHintenAusgabe(element*** kopf){
    struct element* aktuellesElement;
    printf("\nFolgenden Studenten Daten sind gespeichert worden...\n");
    aktuellesElement = **kopf;
    if (aktuellesElement == NULL) {
        printf("Die Liste ist Leer");
        return;
    }
    
    while (aktuellesElement->next != NULL){//Es wird erstaml zum Ende der Liste navigiert
        aktuellesElement = aktuellesElement->next;
    }
    //Dann wird "hochgezählt".
    while (aktuellesElement != NULL) {
        printf("%s\n", aktuellesElement->student.nameDerPerson.nachname);
        printf("%s\n", aktuellesElement->student.nameDerPerson.vorname);
        printf("%s\n", aktuellesElement->student.email);
        printf("%lu\n\n", aktuellesElement->student.handynummer);
        aktuellesElement = aktuellesElement->prev;
    }
    return;
}


/*
* Beschreibung:
In dieser Funktion wird die Anzahl der Listenelementen ausgegeben.

Parameter: kopf der Liste
Rückgabewert: int
*/
int zaehleAnzListenElemente(element** kopf) {
    element* aktuellesElement;
    int anzahl = 0;
    aktuellesElement = *kopf;

    while (aktuellesElement != NULL) {
        aktuellesElement = aktuellesElement->next;
        anzahl++;
    }
    return (anzahl);
}

/*
* Beschreibung:
In dieser Funktion wird die Anzahl der Listenelementen ausgegeben.

Parameter: kopf der Liste
Rückgabewert: int
*/
int zaehleAnzListenElemente2(element*** kopf) {
    element* aktuellesElement;
    int anzahl = 0;
    aktuellesElement = **kopf;

    while (aktuellesElement != NULL) {
        aktuellesElement = aktuellesElement->next;
        anzahl++;
    }
    return (anzahl);
}

/*
* Beschreibung:
In dieser Funktion wird die Anzahl der Listenelementen ausgegeben.

Parameter: kopf der Liste
Rückgabewert: int
*/
int zaehleAnzListenElemente3(element**** kopf) {
    element* aktuellesElement;
    int anzahl = 0;
    aktuellesElement = ***kopf;

    while (aktuellesElement != NULL) {
        aktuellesElement = aktuellesElement->next;
        anzahl++;
    }
    return (anzahl);
}

/*
* Beschreibung:
In dieser Funktionen werden nur die next zeiger vertauscht, die prev zeiger werden in der meine Sortieren Funktion rekonstruiert

Parameter: zwei der zu verlauschenden elemente 
Rückgabewert: element* (Das Oberer Element in diesem Fall)
*/
element* tausche(element* element1, element* element2)
{
    element* tmp = element2->next;
    element2->next = element1;
    element1->next = tmp;
    return element2;
}

/*
* Beschreibung:
In dieser Funktion wird ein bubble sort algorithmus auf die Liste angewendet. Die Liste wird alphabetisch nach Nachnamen sortiert. Wenn der Nachname gleich ist wird nach Vornamen sortiert.

Parameter: kopf der Liste und die Anzahl der Elemente
Rückgabewert: void
*/
void bubbleSort(element**** kopf, int anzElemente)
{
    element** k;
    int i, j, vertauscht;

    for (i = 0; i <= anzElemente; i++) {    //Die Schleife wird solange durchlaufen, bis die anzElemente erreicht wurde.

        k = **kopf;
        vertauscht = 0;//dient zur überfprüfung, ob alles durch sortiert wurde

        for (j = 0; j < anzElemente - i - 1; j++) { //-i, damit nicht von doppelt verglichen wird, -1, weil nicht auf den NULL pointer gezeigt werden soll.

            element* element1 = *k;
            element* element2 = element1->next;//element2 läuft dem element1 vor, daurch kann der vergleich in den if Abfragen geschehen

            /* Wenn Rückwertssort werden möchte muss in der if abfrage "<" statt ">" stehen*/
            if (strcmp(element1->student.nameDerPerson.nachname, element2->student.nameDerPerson.nachname) > 0) { //strcmp vergleich den string charakter bei charakter wenn ein buchstabe vom ersten string größer ist (In ASCII), dann hat strcmp den Rückgabewert 1 aus, wenn vom ersten String kleiner, dann -1 und wenn gleich 0.
                *k = tausche(element1, element2);   //Wenn element1 größer (In ASCII) ist, dann werden die Elemente vertauscht, sodass das kleinere Elemente nach vorne gerückt wird.
                vertauscht = 1; //wird 1 gesetzt, damit erkannt wird ob noch sortiert wird.
            }

            if (strcmp(element1->student.nameDerPerson.nachname, element2->student.nameDerPerson.nachname) == 0) {//Wenn der Nachname gleich ist ....
                 /* Wenn Rückwertssort werden möchte muss in der if abfrage "<" statt ">" stehen*/
                if (strcmp(element1->student.nameDerPerson.vorname, element2->student.nameDerPerson.vorname) > 0) {//..dann wird mit dem Vornamen verglichen...
                    *k = tausche(element1, element2); //... und dann sortiert
                    vertauscht = 1; //wird 1 gesetzt, damit erkannt wird ob noch sortiert wird.
                }
            }

            k = &(*k)->next;    //Addresse des oberen getauschen nächsten Elementes wird übergeben, sodass der mit dem Vergleich des nächsten Elementes in dem darauffolgenden Schleifendurchlaufes, weiter verglichen werden kann.
        }

        /* Die Loop wird gestoppt wenn nichts mehr vertauscht werden konnte*/
        if (vertauscht == 0)
            break;
    }
    return;
}

/*
* Beschreibung:
In dieser Funktion wird ein bubble sort algorithmus auf die Liste angewendet. Die Liste wird alphabetisch nach Nachnamen sortiert. Wenn der Nachname gleich ist wird nach Vornamen sortiert.
Außerdem werden die rückwerts Verknüpfungen mit prev realiert.

Parameter: kopf der Liste und ende der Liste.
Rückgabewert: void
*/
void meineSortierung(element *** kopf, element *** ende) {

    element* element1, * element2;

    int anzElemente = zaehleAnzListenElemente3(&kopf);
    bubbleSort(&kopf, anzElemente);
    /*rückwerts Verknüpfungen der prev Zeiger*/
    element1 = NULL;
    for (element2 = **kopf; element2; element2 = element2->next) {
        element2->prev = element1; //nachlaufendes Element (element1) zeigt auf vorlaufendes element (element2) mit prev
        element1 = element2;       //gleichsetzung des vorlaufenden elementes (element2) mit dem nachlaufenden (element1) Elementes. In dem nächsten Schleifendurchlauf läuft element2 wieder vor (element2 = element2->next). 
    }
    **ende = element1;
    
}

/*
* Beschreibung:
In dieser Funktion wird ein bubble sort algorithmus auf die Liste angewendet. Die Liste wird alphabetisch nach Nachnamen sortiert. Wenn der Nachname gleich ist wird nach Vornamen sortiert.

Parameter: kopf der Liste und die Anzahl der Elemente
Rückgabewert: void
*/
void bubbleSortNichtVerschachtelterZeiger( element*** kopf, int anzElemente)
{
    element** k;
    int i, j, vertauscht;

    for (i = 0; i <= anzElemente; i++) {

        k = *kopf;
        vertauscht = 0;

        for (j = 0; j < anzElemente - i - 1; j++) {

            element* element1 = *k;
            element* element2 = element1->next;

            if (strcmp(element1->student.nameDerPerson.nachname, element2->student.nameDerPerson.nachname) > 0) {
                *k = tausche(element1, element2);
                vertauscht = 1;
            }

            if (strcmp(element1->student.nameDerPerson.nachname, element2->student.nameDerPerson.nachname) == 0) {

                if (strcmp(element1->student.nameDerPerson.vorname, element2->student.nameDerPerson.vorname) > 0) {
                    *k = tausche(element1, element2);
                    vertauscht = 1;
                }
            }

            k = &(*k)->next;
        }

        /* Die Loop wird gestoppt wenn nichts mehr vertauscht werden konnte*/
        if (vertauscht == 0)
            break;
    }
}


/*
* Beschreibung:
In dieser Funktion wird ein bubble sort algorithmus auf die Liste angewendet. Die Liste wird alphabetisch nach Nachnamen sortiert. Wenn der Nachname gleich ist wird nach Vornamen sortiert.
Außerdem werden die rückwerts Verknüpfungen mit prev realiert.

Parameter: kopf der Liste und ende der Liste.
Rückgabewert: void
*/
void meineSortierungNichtVerschachtelterZeiger(element** kopf, element** ende) {

    element* element1, * element2;

    int anzElemente = zaehleAnzListenElemente2(&kopf);
    bubbleSortNichtVerschachtelterZeiger(&kopf, anzElemente);

    element1 = NULL;
    for (element2 = *kopf; element2; element2 = element2->next) {
        element2->prev = element1;
        element1 = element2;
    }
    *ende = element1;

}





