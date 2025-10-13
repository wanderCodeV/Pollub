#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void wyswietl1D(int *tab, int n)
{
    for (int i = 0; i < n; i++)
        cout << tab[i] << " ";
    cout << endl;
}

int sort_two_parts(int* tab, int n)
{
    int st = 0, fn = n-1;
    while(st < fn)
    {
        while(st < fn && tab[st] % 3 == 0) st++;
        while(st < fn && tab[fn] % 3 != 0) fn--;
        if(st < fn)
        {
            swap(tab[st], tab[fn]);
            st++;
            fn--;
        }
    }
    if(tab[st] % 3 == 0)
        return st;
    else
        return st-1;
}

int main()
{
    int tab[] = {90, 11, 12, 33, 18, 17, 45, 21, 110, 6, 3};
    int n = 11;
    sort_two_parts(tab, n);
    wyswietl1D(tab, n);
}