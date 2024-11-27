#include <stdio.h>
#include <stdlib.h>

void srednia();
int main()
{
    srednia();
}

void srednia()
{
    int n, x;
    float p_sum = 0, n_sum = 0, p_n = 0, n_n = 0;
    printf("Podaj ilosc liczb:");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Podaj liczbe:");
        scanf("%d", &x);
        if (x % 2 == 0)
        {
            p_sum += x;
            p_n++;
        }
        else
        {
            n_sum += x;
            n_n++;
        }
    }
    printf("Srednia liczb parzystych %f, niparzystych %f", p_sum / p_n, n_sum / n_n);
}
