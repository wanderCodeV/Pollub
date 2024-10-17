#include <iostream>
#include <cmath>

using namespace std;

double calculatePower(double a, int n) 
{
    double result = 1.0;
    int power_of_two = 1; 

    while (n > 0) 
    {
        if (n % 2 == 1) 
            result *= pow(a, power_of_two);
        n /= 2; 
        power_of_two *= 2; 
    }

    return result;
}

int main() 
{
    double a;
    int n;

    cout << "Podaj wartość a: ";
    cin >> a;
    cout << "Podaj wartość n (nieujemna liczba całkowita): ";
    cin >> n;

    if (n < 0)
    {
        cout << "n musi być nieujemną liczbą całkowitą!" << endl;
        return 0;
    }

    double result = calculatePower(a, n);
    cout << "Wartość a^" << n << " wynosi: " << result << endl;

    return 0;
}
