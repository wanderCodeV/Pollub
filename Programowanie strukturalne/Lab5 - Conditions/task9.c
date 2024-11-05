#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculate_payment(int salary, int work_years);
int main()
{
    int salary, work_years;
    printf("Podaj pensje: ");
    scanf("%d", &salary);
    printf("Podaj staz: ");
    scanf("%d", &work_years);

    printf("Wypalata: %0.0f", calculate_payment(salary, work_years));
}

float calculate_payment(int salary, int work_years)
{
    float payment = 0;
    if(work_years < 5)
        payment = salary;
    else if(work_years < 10)
        payment = (100 + work_years)*salary/100;
    else
        payment = 1.15*work_years;
    
    return payment;
}
