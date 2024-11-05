#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void check_happy_tiket(int n);
int main()
{
    int n;
    printf("Podaj numer miesiacu:");
    scanf("%d", &n);
    check_happy_tiket(n);
}

void check_happy_tiket(int n)
{
    int s1 = n / 100000 + n % 100000 / 10000 + n % 10000 / 1000 ;
    int s2 = n % 1000 / 100 + n % 100 / 10 + n % 10;
    if ( s1 == s2)
        printf("Szczesczliwy bilet");
    else
        printf("Nie szczesczliwy bilet");
}
