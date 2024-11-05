#include <stdio.h>
#include <stdlib.h>

float aritmatic_avarege(float num1, float num2);
float geometric_evarage(float num1, float num2);

int main()
{
    float num1, num2;

    printf("Podaj liczby:");
    scanf("%f %f", &num1,&num2);

    printf( "Srednie arytmetyczne: %f\nSrednie geometryczne %f", aritmatic_avarege(num1, num2), geometric_evarage(num1, num2));

    return 0;
}

float aritmatic_avarege(float num1, float num2)
{
    return (num1 + num2) / 2;
}
float geometric_evarage(float num1, float num2)
{
    return sqrt(num1*num2);
}
