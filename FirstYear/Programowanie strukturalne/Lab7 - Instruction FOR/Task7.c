#include<stdio.h>

int factorail_rec(int n);
int factorial(int n);
int main()
{
    int n;
    printf("Podaj liczbe: ");
    scanf("%d", &n);
    printf("Factorial recursion: %d, Iterative factorial: %d ", factorail_rec(n), factorial(n));
}

int factorail_rec(int n)
{
    if(n == 0 || n == 1) 
        return 1;
    return n*factorail_rec(n-1);
}

int factorial(int n)
{
    int fact = 1;
    for(int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}
