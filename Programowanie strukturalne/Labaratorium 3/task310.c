#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 123, b = 581;
    printf("Liczby: %d % d\n", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("Liczby po zmiany: %d % d\n", a, b);

    int setki = a / 100, jednostki = a % 10;
    a += (jednostki - setki) * 100 ;
    a += (setki - jednostki) ;

    setki = b / 100, jednostki = b % 10;
    b += (jednostki - setki) * 100 ;
    b += (setki - jednostki) ;

    printf("Liczby po zmiany: %d % d\n", a, b);
    return 0;
}
