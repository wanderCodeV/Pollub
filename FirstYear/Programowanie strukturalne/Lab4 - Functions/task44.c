#include <stdio.h>
#include <stdlib.h>

void calculate_cube(float side1);
void calculate_square_cuboid(float side1, float side2);
void calculate_rectangle_cuboid(float side1, float side2, float side3);

int main()
{

    float side1, side2, side3;

    printf("Szescian\nStrona: ");
    scanf("%f",&side1);
    calculate_cube(side1);

    printf("Prostopadloscian o podstawie kwadratowej\nStrony(wysokosc, postawa): ");
    scanf("%f %f",&side1, &side2);
    calculate_square_cuboid(side1, side2);


    printf("Prostopadloscian o podstawie prostokatnej\nStrony: ");
    scanf("%f %f %f",&side1, &side2, &side3);
    calculate_rectangle_cuboid(side1, side2, side3);

    return 0;
}

void calculate_cube(float side1)
{
    float V = side1 * side1 * side1;
    float P = 6 * side1* side1;
    printf("Objetnosc: %0.3f, Pole powierzchni: %0.3f\n", V, P);
}
void calculate_square_cuboid(float side1, float side2)
{
    float V = side1 * side2 * side2;
    float P = 2*(side2*side2 + 2*side1*side2);
    printf("Objetnosc: %0.3f, Pole powierzchni: %0.3f\n", V, P);
}
void calculate_rectangle_cuboid(float side1, float side2, float side3)
{

    float V = side1 * side2 * side3;
    float P = 3*(side1*side2 + side1*side3 + side2*side3);
    printf("Objetnosc: %0.3f, Pole powierzchni: %0.3f\n", V, P);
}
