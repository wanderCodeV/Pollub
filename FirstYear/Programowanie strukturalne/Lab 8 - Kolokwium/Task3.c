#include <stdio.h>

void max_in_set(int n)
{
    printf("Podaj n liczb: ");
    int temp;
    scanf("%d", &temp);
    int max_num = temp;
    for(int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        if( temp > max_num)
            max_num = temp;
    }
    printf("Maksymalna liczba = %d", max_num);
}
int main()
{
    printf("Podaj ilosc: ");
    int n;
    scanf("%d", &n);
    max_in_set(n);
}