#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number:");
    scanf("%d", &n);
    int a, b, c;
    printf("Pythagorean triples in order: ");
    for(a = 1; a < n; a++)
    {
        for(b = 1; b < n; b++)
        {
            for(c = 1; c < n; c++)
            {
                if (a*a + b*b == c*c)
                    printf("(%d, %d, %d) ", a, b, c);
            }
        }
    }
     printf("\nPythagorean triples in reverse order: ");
    for(a = n - 1; a > 0; a--)
    {
        for(b = n - 1; b > 0; b--)
        {
            for(c = n - 1; c > 0; c--)
            {
                if (a*a + b*b == c*c)
                    printf("(%d, %d, %d) ", a, b, c);
            }
        }
    }

}