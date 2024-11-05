#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void stypendia(float a, float b, float c);
int main()
{
    float a, b, c;
    printf("Podaj oceny:");
    scanf("%f %f %f", &a , &b,&c);
    stypendia(a, b, c);
}

void stypendia(float a, float b, float c)
{
    if( a >= 3 && b >= 3 && c >= 3)
    {
        float sr = (a + b + c) / 3;
        if(sr <= 4)
            printf("Stypendium 300zl");
        else
            printf("Stypendium 500zl");
    }
    else
        printf("Nie spelniasz warunku stypendium");
}
