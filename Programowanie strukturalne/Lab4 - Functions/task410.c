#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void swap_first_last_digits(int *a);
int main()
{
    int a = 123, b = 581;
    printf("Liczby: %d % d\n", a, b);
    swap(&a, &b);
    printf("Liczby po zmiany: %d % d\n", a, b);

    swap_first_last_digits(&a);
    swap_first_last_digits(&b);

    printf("Liczby po zmiany: %d % d\n", a, b);
    return 0;
}
void swap(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}
void swap_first_last_digits(int *a)
{
    int setki = *a / 100, jednostki = *a % 10;
    *a += (jednostki - setki) * 100 ;
    *a += (setki - jednostki) ;
}
