#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void trygonometric(float angle)
{
    angle *= M_PI / 180;
    printf("sin: %f, cos: %f, tg: %f", sin(angle), cos(angle), tan(angle));
}
int main()
{
    float angle;
    printf("Podaj kat:");
    scanf("%f", &angle);
    trygonometric(angle);
    return 0;
}
