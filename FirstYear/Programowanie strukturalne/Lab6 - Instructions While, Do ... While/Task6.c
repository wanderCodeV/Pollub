#include <stdio.h>
#include <stdlib.h>

float sredniaWhile();
int find_max_element();
int main()
{
    int wybor = -1;
    while (1)
    {

        printf("Menu\n1 - znalesc maksymalnie\n2 - znalesc srednia\n0 - koiec\nWybor: ");
        scanf("%d", &wybor);
        if (wybor == 1)
        {
            float max_elem = find_max_element();
            printf("Najwieksza liczba %0.2f\n", max_elem);
        }
        else if(wybor == 2)
        {
            float srednia = sredniaWhile();
            printf("Srednia %f\n", srednia);
        }
        else break;


    }

}

int find_max_element()
{
    float x;
    float max_elem = -1;
    do
    {
        printf("Podaj liczbe:");
        scanf("%f", &x);
        if (x > max_elem)
            max_elem = x;
    } while(x != -1);

    return max_elem;

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
