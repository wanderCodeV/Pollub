#include <stdio.h>
#include <stdlib.h>

void check_arythmetic(int n);
int main()
{
    int n;
    printf("Enter count: ");
    scanf("%d", &n);
    check_arythmetic(n);

}

void check_arythmetic(int n)
{
    int a, b;
    printf("Enter number: ");
    scanf("%d", &a);
    printf("Enter number: ");
    scanf("%d", &b);
    int difference = b - a;
    int cnt_correct = 1;
    for(int i = 2; i < n; i++)
    {
        printf("Enter number: ");
        scanf("%d", &a);
        if(a - b == difference)
            cnt_correct++;
        b = a;
    }
    if (n - 1 == cnt_correct)
        printf("This IS arithmetical set");
    else 
        printf("This ISN\'T arithmetical set");
}