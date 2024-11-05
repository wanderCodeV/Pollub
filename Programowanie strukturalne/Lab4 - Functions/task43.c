#include <stdio.h>
#include <stdlib.h>
#define STATUS "student"
#define SREDNIA 4.8


void print_student_data()
{
    char name[20], surname[20], plec[20];
    int age;
    printf("Dane studenta\nImie: ");
    scanf("%s",name);
    printf("Nazwisko:");
    scanf("%s",surname);
    printf("Wiek:");
    scanf("%d",&age);
    printf("Plec:");
    scanf("%s",plec);
    printf("%s %s %d %s\n%s %f", name, surname, age, plec, STATUS, SREDNIA);
}
int main()
{
    print_student_data();
    return 0;
}
