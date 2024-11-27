#include <stdio.h>
#include <stdlib.h>

int cnt_of_symbol(char sym);
int main()
{
    char sym;
    printf("Podaj litere, dla ktorej trzeba obliczyc ile razy wystapila: ");
    scanf("%c", &sym);
    printf("Litera %c wystapila %d razy", sym,  cnt_of_symbol(sym));
}

int cnt_of_symbol(char sym)
{
    int cnt = 0;
    char curr_sym;
    printf("Podaj zdanie:");
    do
    {
        scanf("%c", &curr_sym);
        if(curr_sym == sym)
            cnt++;
    } while(curr_sym != '.');

    return cnt;

}
