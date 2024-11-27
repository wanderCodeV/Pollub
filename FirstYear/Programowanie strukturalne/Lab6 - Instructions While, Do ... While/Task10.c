#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Podaj ilosc pokojow: ");
    int n, i = 1;
    scanf("%d", &n);
    int cnt_second = (n - 1) / 2;
    while(i <= n)
    {
        printf("Nr pokju %d", i);
        if (i % 2 == 0)
            printf(" dwuosobowy ");
        else
            printf(" jednoosobowy ");
        if(i < n - cnt_second)
            printf(" I pietro\n");
        else
            printf(" II pietro\n");
        i++;
        if ( i == 13) i++;
    }

}
