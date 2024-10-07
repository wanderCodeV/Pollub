//Napisz program, który dla zadanej liczy naturalnej n wypisze wszystkie podzbiory zbioru {1, 2, . . . , n}.

#include <iostream>
#include <vector>
#define NMAX 100000

using namespace std;

vector<bool> bitset_of_number(int num)
{
    vector <bool> bits;
    while(num != 0)
    {
        bits.push_back(num % 2);
        num /= 2;
    }
    return bits;
}
void print_power_set(int * arr, int n)
{
    cout << "Zbiór potęgowy:\n";
    cout << "1) pusty zbiór\n";
    vector <bool> current_bitset;
    for(int i = 1; i < 1<<n; i++)
    {
        cout << i + 1 << ") ";
        current_bitset = bitset_of_number(i);
        int start_number = n + 1 - current_bitset.size();
        for(int i = 0 ; i < current_bitset.size(); i++)
        {
            if(current_bitset[i])
            {
                cout << i + 1 << " ";    
            }
        }
        cout << "\n";
    }
}
int main()
{
    int n;
    cout << "Wprowadź liczbę n: ";
    cin >> n;
    int arr[NMAX];
    for(int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    print_power_set(arr, n);
}