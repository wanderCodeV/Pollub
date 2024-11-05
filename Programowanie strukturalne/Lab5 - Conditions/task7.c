#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void kwartal(int n);
int main()
{
    int n;
    printf("Podaj numer miesiacu:");
    scanf("%d", &n);
    kwartal(n);
}

void kwartal(int n)
{
    switch(n)
    {
    case 1: case 2: case 3:
        printf("Nalezy do kwartalu 1");
        break;
    case 4: case 5: case 6:
        printf("Nalezy do kwartalu 2");
        break;
    case 7: case 8: case 9:
        printf("Nalezy do kwartalu 3");
        break;
    case 10: case 11: case 12:
        printf("Nalezy do kwartalu 4");
        break;
    default:
        printf("Nie ma takiego miesiaca");

    }
}
