#include <stdio.h>
#include <stdlib.h>

int find_max_element();
int main()
{
    float max_elem = find_max_element();
    printf("Najwieksza liczba %0.2f", max_elem);
}

int find_max_element()
{
    float x;
    float max_elem = -1;
    do
    {
        printf("Podaj liczbe:");
        scanf("%f", &x);
        if (x > max_elem)
            max_elem = x;
    } while(x != -1);

    return max_elem;

}
