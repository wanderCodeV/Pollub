#include <stdio.h>
#include <stdlib.h>
float sredniaWhile();
float sredniaDoWhile();
int main()
{
    float srednia = sredniaWhile();
    printf("Srednia %f", srednia);

}


float sredniaWhile()
{
    int n;
    float x, sum = 0;
    printf("Podaj ilosc liczb:");
    scanf("%d", &n);
    int i = 0;
    while(i < n)
    {
        printf("Podaj liczbe:");
        scanf("%f", &x);
        sum += x;
        i++;
    }
    return sum / n;
}

float sredniaDoWhile()
{
    int n;
    float x, sum = 0;
    printf("Podaj ilosc liczb:");
    scanf("%d", &n);
    int i = 0;
    do
    {
        printf("Podaj liczbe:");
        scanf("%f", &x);
        sum += x;
        i++;
    }while(i < n);
    return sum / n;
}
