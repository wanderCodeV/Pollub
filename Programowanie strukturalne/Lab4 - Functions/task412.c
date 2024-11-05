 #include <stdio.h>
#include <stdlib.h>

void code_askii(char ch);
void wielki_sybmol(char ch);
int main()
{
    char ch;
    printf("Podaj symbol: ");
    scanf("%c", &ch);

    code_askii(ch);
    wielki_sybmol(ch);

    return 0;
}

void wielki_sybmol(char ch)
{
    if( ch >= 'a' && ch <= 'z')
        ch += 'A' - 'a';
    printf("Welki symbol %c", ch);
}
void code_askii(char ch)
{
    printf("ASCII %d\n", ch);
}
