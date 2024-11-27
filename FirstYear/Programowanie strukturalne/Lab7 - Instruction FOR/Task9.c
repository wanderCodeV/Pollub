#include <stdio.h>

int isPrime(int num)
 {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; ++i) 
        if (num % i == 0) return 0;
    
    return 1;
}
int main()
{
    int n;
    printf("Enter a number:");
    scanf("%d", &n);
    int cnt = 0, i, cntNotPrime = 0;
    printf("Found prime numbers in order: ");
    for(i = 1; cnt < n; i++)
    {
        if(isPrime(i))
        {
            cnt++;
            printf("%d ", i);
        }
        else cntNotPrime++;
    }

    printf("\nNumber of non-prime numbers: %d\nFound prime numbers in reverse order: ", cntNotPrime);
    for(; i > 0; i--)
    {
        if(isPrime(i))
        {
            printf("%d ", i);
        }
    }


    
    

}