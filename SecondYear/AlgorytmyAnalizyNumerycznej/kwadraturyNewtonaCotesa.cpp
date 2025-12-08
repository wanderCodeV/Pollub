#include <iostream>
#include <cmath>

using namespace std;

// 1) f(x) = sqrt(1 + x)
double f1(double x) {
    return sqrt(1.0 + x);
}

// 2) f(x) = sin^2(x) + 2
double f2(double x) {
    return pow(sin(x), 2) + 2.0;
}

// 3) f(x) = e^x * 2x^3
double f3(double x) {
    return exp(x) * 2.0 * pow(x, 3);
}

double trapezy(double (*f)(double), double a, double b, int m) {
    double h = (b - a) / m;
    double suma = 0.0;

    for (int i = 1; i < m; i++) {
        suma += f(a + i * h);
    }

    return h * ((f(a) + f(b)) / 2.0 + suma);
}

double simpson(double (*f)(double), double a, double b, int m) {
    double h = (b - a) / m;
    double suma1 = 0.0, suma2 = 0.0;

    for (int i = 1; i < m; i += 2) {
        suma1 += f(a + i * h);
    }

    for (int i = 2; i < m; i += 2) {
        suma2 += f(a + i * h);
    }

    return (h / 3.0) * (f(a) + f(b) + 4.0 * suma1 + 2.0 * suma2);
}

int main()
{
    int option_func;
    cout << "Wybierz calke:\n";
    cout << "1) calka[0,1] sqrt(1 + x) dx\n";
    cout << "2) calka[0,2π] (sin^2(x) + 2) dx\n";
    cout << "3) calka[0,2] e^x * 2x^3 dx\n";
    cout << "Wybor: ";
    cin >> option_func;

    char option_meth;
    cout << "Wybierz metode:\n";
    cout << "T - trapezy\n";
    cout << "S - Simpson\n";
    cout << "Wybor: ";
    cin >> option_meth;

    int m;
    cout << "Podaj liczbe podprzedzialow m (m > 1): ";
    cin >> m;

    if (m <= 1) {
        cout << "Blad: m musi byc > 1!\n";
        return 0;
    }

    double a, b;
    double (*fun)(double);

    switch (option_func) {
        case 1:
            a = 0.0;
            b = 1.0;
            fun = f1;
            break;
        case 2:
            a = 0.0;
            b = 2 * M_PI;
            fun = f2;
            break;
        case 3:
            a = 0.0;
            b = 2.0;
            fun = f3;
            break;
        default:
            cout << "Niepoprawny wybor calki!\n";
            return 0;
    }

    double wynik;

    if (option_meth == 'T' || option_meth == 't') {
        wynik = trapezy(fun, a, b, m);
        cout << "Wynik (metoda trapezow): " << wynik << endl;
    } 
    else if (option_meth == 'S' || option_meth == 's') {
        if (m % 2 != 0) {
            cout << "Blad: option_meth Simpsona wymaga parzystej liczby podprzedzialow!\n";
            return 0;
        }
        wynik = simpson(fun, a, b, m);
        cout << "Wynik (metoda Simpsona): " << wynik << endl;
    } 
    else {
        cout << "Niepoprawny wybor metody!\n";
    }

    return 0;
}