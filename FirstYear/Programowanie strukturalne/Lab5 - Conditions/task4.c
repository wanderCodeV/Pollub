#include <stdio.h>
#include <stdlib.h>

void check_in_square(float x, float y);
int main()
{
    float x, y;
    printf("Podaj wspolrzedne punktu: ");
    scanf("%f %f", &x , &y);
    check_in_square(x, y);

}
void check_in_square(float x, float y)
{
    if ((x >= -1 && x <= 1) && ( y >= -1 && y <= 1))
        printf("Nalezy do zamalowanego obszaru!!!");
    else
        printf("NIE nalezy do zamalowanego obszaru!!!");

}

