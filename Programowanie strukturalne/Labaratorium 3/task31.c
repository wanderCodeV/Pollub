#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159 //stale
#define AUTOR "Jan Kowalski"
#define KIERUNEK "Informatyka"
int main(int argc, char *argv[])
{
    //deklaracje
    const int ROK=1; //stala
    const float PREMIA=0.20;
    float r, pole, stawka, wyplata;
    int lg;
    //instrukcje
    printf("=========================\n");
    printf("*************************\n");
    printf("=========================\n");
    printf("Programowanie liniowe\n");
    printf("Autor programu: %s, kierunek: %s, rok: %d\n", AUTOR, KIERUNEK, ROK);
    printf("=========================\n");
    printf("*************************\n");
    printf("=========================\n");
    printf("Podaj promien kola\n");
    scanf("%f",&r);
    pole=PI*r*r;
    printf("Pole kola o promieniu %0.2f = %0.2f\n", r,pole);
    printf("=========================\n");
    printf("*************************\n");
    printf("=========================\n");
    printf("Pracownik1\n");
    printf("Podaj liczbe godzin\n");
    scanf("%d",&lg);
    printf("Podaj stawke\n");
    scanf("%f",&stawka);
    wyplata= lg*stawka+ lg*stawka*PREMIA;
    printf("Wyplata = %0.2f\n",wyplata);
    printf("Pracownik2\n");
    printf("Podaj liczbe godzin\n");
    scanf("%d",&lg);
    printf("Podaj stawke\n");
    scanf("%f",&stawka);
    wyplata= lg*stawka+ lg*stawka*PREMIA;
    printf("Wyplata = %0.2f\n",wyplata);
    printf("=========================\n");
    printf("*************************\n");
    printf("=========================\n");
    system("PAUSE");
    return 0;
}
