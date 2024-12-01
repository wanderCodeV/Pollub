#include <stdio.h>

void print_iloraz(float a, float b)
{
    if(b == 0)
        printf("Nie mozna dzielic przez 0!");
    else
        printf("Iloraz: %.2f", a/b);
}
int main()
{
    float a, b;
    printf("Podaj liczby: ");
    scanf("%f %f", &a, &b);
    print_iloraz(a, b);

}