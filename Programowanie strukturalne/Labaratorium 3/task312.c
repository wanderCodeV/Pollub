 #include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("Podaj symbol: ");
    scanf("%c", &ch);

    printf("ASCII %d\n", ch);

    if( ch >= 'a' && ch <= 'z')
        ch += 'A' - 'a';
    printf("Welki symbol %c", ch);

    return 0;
}
