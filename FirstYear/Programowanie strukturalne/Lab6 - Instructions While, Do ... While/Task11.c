#include <stdio.h>
#include <stdlib.h>

int main()
{
    char small = 'a';
    int roz = 'A' - 'a';
    while (small - 1 != 'z')
    {
        printf("Symbol %c = %d ", small, small);
        printf("Symbol %c = %d \n", small + roz, small + roz);
        small++;
    }

}
