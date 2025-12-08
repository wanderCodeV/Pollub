#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x)
{
    return x * exp(2 * x);
}

double simpson_3_8(double a, double b, int n)
{
    if (n % 3 != 0)
    {
        cout << "Blad: liczba podprzedzialow musi byc podzielna przez 3!" << endl;
        return 0;
    }

    double h = (b - a) / n;
    double suma = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;

        if (i % 3 == 0)
            suma += 2 * f(x);
        else
            suma += 3 * f(x);
    }

    return (3 * h / 8) * suma;
}

int main()
{
    double a = 0.0, b = 4.0;
    int n;

    cout << "Podaj liczbe podprzedzialow (podzielna przez 3): ";
    cin >> n;

    if (n % 3 != 0)
    {
        cout << "Blad: n musi byc podzielne przez 3!" << endl;
        return 0;
    }

    double wynik = simpson_3_8(a, b, n);

    cout << fixed << setprecision(2);
    cout << "Wynik calki = " << wynik << endl;

    return 0;
}
