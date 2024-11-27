#include <stdio.h>
#include <stdlib.h>
int check();
int main()
{
    int ciag = check();
    printf("Wynik %d", ciag);

}


int check()
{
    int n;
    float x, prev_x = -1000;
    printf("Podaj ilosc liczb:");
    scanf("%d", &n);
    int i = 0, wynik = 1;
    while(i < n)
    {
        printf("Podaj liczbe:");
        scanf("%f", &x);
        if(x < prev_x)
            wynik = 0;
        prev_x = x;
        i++;
    }
    return wynik;
}

