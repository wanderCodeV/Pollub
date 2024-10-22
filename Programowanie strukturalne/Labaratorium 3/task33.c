#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define STATUS "student"
#define SREDNIA 4.8

int main()
{
    setlocale(LC_ALL, "");


    char name[20], surname[20], plec[20];
    int age;

    printf("Dane studenta\nImię: ");
    scanf("%s",name);
    printf("Nazwisko:");
    scanf("%s",surname);
    printf("Wiek:");
    scanf("%d",&age);
    printf("Płeć:");
    scanf("%s",plec);
    printf("%s %s %d %s\n%s %f", name, surname, age, plec, STATUS, SREDNIA);
    return 0;
}
