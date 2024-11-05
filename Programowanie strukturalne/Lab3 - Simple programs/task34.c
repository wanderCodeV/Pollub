#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"");

    float side1, side2, side3, V, P;

    printf("Sześcian\nStrona: ");
    scanf("%f",&side1);
    V = side1 * side1 * side1;
    P = 6 * side1* side1;
    printf("Objętność: %0.3f, Pole powierzchni: %0.3f\n", V, P);

    printf("Prostopadłościan o podstawie kwadratowej\nStrony(wysokość, postawa): ");
    scanf("%f %f",&side1, &side2);
    V = side1 * side2 * side2;
    P = 2*(side2*side2 + 2*side1*side2);
    printf("Objętność: %0.3f, Pole powierzchni: %0.3f\n", V, P);

    printf("Prostopadłościan o podstawie prostokątnej\nStrony: ");
    scanf("%f %f %f",&side1, &side2, &side3);
    V = side1 * side2 * side3;
    P = 3*(side1*side2 + side1*side3 + side2*side3);
    printf("Objętność: %0.3f, Pole powierzchni: %0.3f\n", V, P);

    return 0;
}
