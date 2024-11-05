#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void pole(float a, float b, float c);
int main()
{
    float a, b, c;
    printf("Podaj wartosci stron:");
    scanf("%f %f %f", &a , &b,&c);
    pole(a, b, c);
}

void pole(float a, float b, float c)
{
    if ( a  < b + c && b < a + c && c < a + b)
    {
        int p = (a + b + c) / 2;
        float pole_tr = sqrt(p * (p - a) * (p - b) * ( p - c));
        printf("Pole %f", pole_tr);
    }
    else
        printf("Nie sa stronami trojkata");
}
