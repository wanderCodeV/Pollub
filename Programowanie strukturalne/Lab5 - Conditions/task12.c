#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void check_symbol_dictionary(char symbol);
int main()
{
    char symbol;
    printf("Podaj znak: ");
    scanf("%c", &symbol);
    check_symbol_dictionary(symbol);
}

void check_symbol_dictionary(char symbol)
{
    if (symbol == '$')
        printf("Znak dolara\n");
    else if ( symbol >= 'a' && symbol <= 'z')
        printf("Mala angielska litera\n");
    else if ( symbol >= 'A' && symbol <= 'Z')
        printf("Duza angielska litera\n");
    else if( symbol >= '0' && symbol <= '9')
        printf("Cyfra\n");
    else if(symbol == '=' || symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*')
        printf("Operacja arytmetyczna\n");
    else 
        printf("Zadna z podanych\n");
}
