#include <stdio.h>

int main()
{
    int n;
    printf("Enter a three-digit number:");
    scanf("%d", &n);

    if( n < 100 || n > 999)
        printf("Invalid input\n");
    else
    {
        int sum = 0, target = n;
        for(int i = 0; i < 3; i++)
        {
            int dig = n%10;
            sum += dig*dig*dig;
            n /= 10;
        }
        if (sum == target)
            printf("A number EQUAL to the sum of the cubes of its digits\n");
        else 
            printf("A number NOT EQUAL to the sum of the cubes of its digits\n");
    }
    
    

}