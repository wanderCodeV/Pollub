#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float angle;
    printf("Podaj kat:");
    scanf("%f", &angle);
    angle *= M_PI / 180;
    printf("sin: %f, cos: %f, tg: %f", sin(angle), cos(angle), tan(angle));
    return 0;
}
