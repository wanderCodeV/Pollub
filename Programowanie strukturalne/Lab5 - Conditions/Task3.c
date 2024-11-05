#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float function1(float angle, int t);
float function2(float angle, int t);
int main()
{
    int t;
    float angle;
    printf("Podaj warunek t i kat\n");
    scanf("%d %f", &t , &angle);
    printf("Funkcja z instrukcja warunkowa: %f\n", function1(angle, t) );
    printf("Funkcja z instrukcja wyboru: %f\n", function2(angle, t) );
}

float function1(float angle, int t)
{
    if(t == 8)
        return 1 - sin(angle);
    else if (t == 4 || t == 6 || t == 7)
        return sqrt(pow(angle, 2) + 1);
    else if (t == 0 || t == 1 || t == 2 || t == 3)
        return (1  + cos(angle))/2;
    else
    {
        printf("\tNieprawidlowe dane wejsciowe\n");
        return 0;
    }
}
float function2(float angle, int t)
{
    switch(t)
    {
    case 0: case 1: case 2: case 3:
        return (1  + cos(angle))/2;
    case 4: case 6: case 7:
        return sqrt(pow(angle, 2) + 1);
    case 8:
        return 1 - sin(angle);
    default:
        printf("\tNieprawidlowe dane wejsciowe\n");
        return 0;

    }
}
