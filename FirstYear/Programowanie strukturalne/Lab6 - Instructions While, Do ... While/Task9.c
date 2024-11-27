#include <stdio.h>
#include <stdlib.h>
int check();
int main()
{
    int od = check();
    if (od == 1)
        printf("Wynik Tak");
    else
        printf("Wynik Nie");

}


int check()
{
    int n;
    float x;
    printf("Podaj ilosc studentow:");
    scanf("%d", &n);
    int i = 0, wynik = 1;
    while(i < n)
    {
        printf("Podaj osene:");
        scanf("%f", &x);
        if(x < 3)
            wynik = 0;
        i++;
    }
    return wynik;
}

