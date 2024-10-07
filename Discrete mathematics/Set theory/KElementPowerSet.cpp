//Napisz program, który dla zadanej liczby naturalnej n oraz liczy k ∈ {1, . . . , n} wypisze 
// wszystkie podzbiory k-elementowe zbiory {1, . . . , n}.

#include <iostream>
#include <vector>
#define NMAX 100000

using namespace std;

struct bitset{
    vector <bool> bits; //reversed bitset
    int count_ones = 0;
};

bitset bitset_of_number(int num)
{
    bitset number;
    while(num != 0)
    {
        if(num%2) number.count_ones++;
        number.bits.push_back(num % 2);
        num /= 2;
        
    }
    return number;
}
void print_k_element_power_set(int n, int k)
{
    cout << "K-elementowy zbiory potęgowy:\n";
    if(k == 0)
    {
        cout << "pusty zbiór\n";
        return;
    }

    bitset current_bitset;
    for(int i = 1; i < 1<<n; i++)
    {
        current_bitset = bitset_of_number(i);
        if(current_bitset.count_ones == k)
        {
            for(int i = 0 ; i < current_bitset.bits.size(); i++)
                if(current_bitset.bits[i])
                    cout << i + 1 << " ";
            cout << "\n";
        }
    }
}
int main()
{
    int n, k;
    cout << "Wprowadź liczbę n: ";
    cin >> n;

    cout << "Wprowadź liczbę k: ";
    cin >> k;

    print_k_element_power_set(n, k);
}