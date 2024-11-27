#include <stdio.h>

void print_line(int len, char sym);
int main()
{
    int n;
    char sym;
    printf("Enter len of line: ");
    scanf("%d", &n);
    printf("Enter symbol: ");
    scanf(" %c", &sym);
    print_line(n, sym);
}

void print_line(int len, char sym)
{
    for(int i = 0; i < len; i++)
    {
        printf("%c", sym);
    }
    printf("\n");
}