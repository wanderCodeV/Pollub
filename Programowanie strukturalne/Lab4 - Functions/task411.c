 #include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculate_circumference(int x1, int y1, int x2, int y2);
int main()
{
    int x1, y1, x2, y2;
    printf("Podaj punkt A: ");
    scanf("%d %d", &x1, &y1);
    printf("Podaj punkt B: ");
    scanf("%d %d", &x2, &y2);

    printf("Obwod: %f", calculate_circumference(x1, y1, x2, y2));

    return 0;
}

float calculate_circumference(int x1, int y1, int x2, int y2)
{
    float r = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    return 2 * M_PI * r;
}
