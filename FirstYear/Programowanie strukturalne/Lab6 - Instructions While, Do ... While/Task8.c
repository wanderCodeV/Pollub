#include <stdio.h>
#include <stdlib.h>
void check(float start, float procent);
int main()
{
    float start, procent;
    printf("Podaj wplate i oprocentowanie: ");
    scanf("%f %f", &start, &procent);
    check(start, procent);
}


void check(float start, float procent)
{
    procent /= 100;
    int time = 0;
    float end_point = 2 * start;
    while(start < end_point)
    {
        start += start * procent;
        time++;
        printf("Po %d roku, kwota wynosi %f\n", time, start);
    }
}
