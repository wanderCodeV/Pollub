#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void kwadratowe(float a, float b, float c);
int main()
{
    float a, b, c;
    printf("Podaj a, b, c: ");
    scanf("%f %f %f", &a , &b,&c);
    kwadratowe(a, b, c);

}
void kwadratowe(float a, float b, float c)
{
    float delta = b * b - 4 * a * c;
    if (delta > 0)
    {
        float x1 = (-b + sqrt(delta))/(2 * a);
        float x2 = (-b - sqrt(delta))/(2 * a);
        printf("Pierwiastki    %f    %f\n", x1, x2);
    }
    else if (delta == 0)
    {
        float x = (-b)/(2 * a);
        printf("Pierwiastek  %f\n", x);
    }
    else
        printf("Nie ma pierwiastkow\n");


}
