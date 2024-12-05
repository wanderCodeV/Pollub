#include <stdio.h>
#include <string.h>

void Reverese(char str[]);
int main()
{
    char str[1000];
    printf("Podaj wyraz: ");
    gets(str);
    Reverese(str);
    return 0;
}

void Reverese(char str[])
{
    int n = strlen(str);
    int i = 0;
    while(i < n/2)
    {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
        i++;
    }
    puts(str);
}
