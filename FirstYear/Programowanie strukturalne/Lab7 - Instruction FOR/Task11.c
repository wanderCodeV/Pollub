#include <stdio.h>

void pythagoreanTriples (int start, int finish)
{
    printf("Pythagorean triples in order: ");
    for(int a = start; a < finish; a++)
    {
        for(int b = start; b < finish; b++)
        {
            for(int c = start; c < finish; c++)
            {
                if (a*a + b*b == c*c)
                    printf("(%d, %d, %d) ", a, b, c);
            }
        }
    }
}

int isPrime(int num)
{
   
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; ++i) 
        if (num % i == 0) return 0;
    
    return 1;
    
}

int printPrime(int finish)
{
    int cnt = 0, cntNotPrime = 0;
    printf("Found prime numbers in order: ");
    for(int i = 1; cnt < finish; i++)
    {
        if(isPrime(i))
        {
            cnt++;
            printf("%d ", i);
        }
        else cntNotPrime++;
    }
    printf("\nNumber of non-prime numbers: %d", cntNotPrime);
}

int isAutomorphic(int a)
{
    int cntDigit = 10;
    for (int temp = a; temp > 9; temp /= 10) {
        cntDigit *= 10;
    }

    return ((a * a) % cntDigit == a);
}

int printAutomorphic(int finish)
{
    int cnt = 0;
    printf("Found automorphic numbers in order: ");
    for(int i = 1; cnt < finish; i++)
    {
        if(isAutomorphic(i))
        {
            cnt++;
            printf("%d ", i);
        }
    }
}

int main()
{
    int option, n, m;
    printf("MENU\n1 - pythagorean triples\n2 - simple numbers\n3 - automorphic numbers\n");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        printf("Enter the interval: ");
        scanf("%d %d", &n, &m);
        pythagoreanTriples(n, m);
        break;
    case 2:
        printf("Enter the number of numbers: ");
        scanf("%d", &n);
        printPrime(n);
        break;
    case 3:
    printf("Enter the number of numbers: ");
        scanf("%d", &n);
        printAutomorphic(n);
        break;
    default:
        break;
    }

}