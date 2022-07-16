#include<stdio.h>
#include<string.h>
#define MAX 100

int main() {
    typedef struct Datum {
        int tag;
        int monat;
        int jahr;
    }Datum;
    typedef struct Student {
        char name[MAX];
        Datum gebdat;
        int mat_num;
    }Student;

    Student student1;

    strcpy_s(student1.name, 5,"nico");
    student1.gebdat.tag = 9;
    student1.gebdat.monat = 9;
    student1.gebdat.jahr = 2001;
    student1.mat_num = 12345;

    printf("Name: %s\n", student1.name);
    printf("Geburtsdatum: %02d.%02d.%4d\n", student1.gebdat.tag,
        student1.gebdat.monat, student1.gebdat.jahr);
    printf("Matrikel_Nummer : %d", student1.mat_num);

    return 0;
}