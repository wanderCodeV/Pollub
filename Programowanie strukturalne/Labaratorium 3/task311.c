 #include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x1, y1, x2, y2;
    printf("Podaj punkt A: ");
    scanf("%d %d", &x1, &y1);
    printf("Podaj punkt B: ");
    scanf("%d %d", &x2, &y2);

    float r = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    float obwod = 2 * M_PI * r;

    printf("Obwod: %f", obwod);

    return 0;
}
