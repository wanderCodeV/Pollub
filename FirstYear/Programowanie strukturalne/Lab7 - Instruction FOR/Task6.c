#include <stdio.h>
#include <stdlib.h>

void calculate_sin(float x, int k);

int main() 
{
    float angle;
    int k;
    printf("Enter angle (in radians): ");
    scanf("%f", &angle);
    printf("Enter k (number of terms): ");
    scanf("%d", &k);

    if (k <= 0) 
    { 
        printf("Number of terms (k) must be greater than 0.\n");
        return 1;
    }

    calculate_sin(angle, k);
    return 0;
}

void calculate_sin(float x, int k)
{
    float sinus = 0;
    float sign = 1;  
    float term = x;  
    
    for (int i = 1; i <= k; i++) {
        sinus += sign * term;  
        
        sign *= -1; 
        term *= x * x / (2 * i * (2 * i + 1)); 
    }

    printf("Sinus: %f\n", sinus);
}
