#include <stdio.h>
#include <stdlib.h>


int main()
{
    float num1, num2;

    printf("Podaj liczby:");
    scanf("%f %f", &num1,&num2);

    float arytmetyczna = (num1 + num2) / 2;
    float geometryczna = sqrt(num1*num2);

    printf( "Srednie arytmetyczne: %f\nSrednie geometryczne %f", arytmetyczna, geometryczna);

    return 0;
}
