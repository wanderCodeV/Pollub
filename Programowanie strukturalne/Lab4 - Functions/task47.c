#include <stdio.h>
#include <stdlib.h>

void calculate_future_age(int year, int month, int time);

int main()
{
    int year, month, time;
    printf("Podaj wiek(lata i miesiacy):");
    scanf("%d %d", &year, &month);
    printf("Podaj okres(w miesiacach):");
    scanf("%d", &time);

    calculate_future_age(year, month, time);
    return 0;
}


void calculate_future_age(int year, int month, int time)
{
    month += 12*year + time;
    year = month / 12;
    month = month % 12;
    printf("lata %d, miesiacy %d", year, month);

}
