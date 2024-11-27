#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void obliczenia(float a, float b, float c);
int main()
{
    float a, b, c;
    printf("Podaj liczby:");
    scanf("%f %f %f", &a , &b,&c);
    stypendia(a, b, c);
}

void obliczenia(float a, float b, float c)
{
    if( a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
        printf("Suma %d: ", a+b+c);
    else if (a == 1 || b == 1 || c == 1)
        printf("Iloczyn %d: ", a*b*c);
    else printf("-1")
}
