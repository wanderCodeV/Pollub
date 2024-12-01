#include <stdio.h>

int main()
{
    printf("Podaj imie: ");
    char name[1000];
    gets(name);
    printf("Twoje imie: %s\nPodaj wiek: ", name);
    int age;
    scanf("%d", &age);
    if(age >= 18)
        printf("Jestes pewnoletni");
    else
        printf("Twoj wiek: %d", age);
    
}