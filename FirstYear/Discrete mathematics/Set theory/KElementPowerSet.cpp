//Napisz program, który dla zadanej liczby naturalnej n oraz liczy k ∈ {1, . . . , n} wypisze 
// wszystkie podzbiory k-elementowe zbiory {1, . . . , n}.

#include <iostream>
#include <vector>
#define NMAX 100000

using namespace std;

void print_set(int k_element[], int size)
{
    for (int i = 0; i < size; i++)
        cout << k_element[i] << " ";
    cout << "\n";
}
void k_element_power_set(int n, int k, int set_size, int k_element[])
{
    if(k > 0)
    {
        k--;
        while(n > 0)
        {
            k_element[k] = n;
            k_element_power_set(--n, k, set_size, k_element);
        }
    }
    else print_set(k_element, set_size);
}
int main()
{
    int n, k;
    int k_element[NMAX] = {};
    cout << "Wprowadź liczbę n: ";
    cin >> n;

    cout << "Wprowadź liczbę k: ";
    cin >> k;

    k_element_power_set(n, k, k, k_element);
}