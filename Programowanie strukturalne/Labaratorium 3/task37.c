#include <stdio.h>
#include <stdlib.h>


int main()
{
    int year, month, time;
    printf("Podaj wiek(lata i miesiacy):");
    scanf("%d %d", &year, &month);
    printf("Podaj okres(w miesiacach):");
    scanf("%d", &time);

    month += 12*year + time;
    year = month / 12;
    month = month % 12;
    printf("lata %d, miesiacy %d", year, month);

    return 0;
}
