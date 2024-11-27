#include <stdio.h>
#include <stdlib.h>

void salary_raise(int n);
int main()
{
    int n;
    printf("Enter employee count: ");
    scanf("%d", &n);
    salary_raise(n);

}

void salary_raise(int n)
{
    float salary = 0;
    for(int i = 0; i < n; i++)
    {
        printf("Enter salary of employee %d: ", i+1);
        scanf("%f", &salary);
        if (salary <= 5000)
            salary *= 1.1;
        else
            salary *= 1.05;

        printf("Raised salary: %f\n", salary);
    }
}