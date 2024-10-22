#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"");

    char znak; int liczba_c;
    float liczba_rz;
    char imie[20];
    printf("Podaj znak, liczbą całkowita i liczbe rzeczywista\n");
    scanf("%c %d %f", &znak, &liczba_c, &liczba_rz);
    printf("Podales znak: %c, liczbe calkowita: %d, liczbe rzeczywista:%f\n",znak, liczba_c, liczba_rz );
    printf("Podaj imie\n");
    fflush(stdin);
    scanf("%s", imie);
    printf("Witaj %s\n", imie);
}
