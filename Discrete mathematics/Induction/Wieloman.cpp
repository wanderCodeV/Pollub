#include <iostream>
#include <vector>

using namespace std;

double oblicz_wielomian(double* wspolczynniki, double x, int n) 
{
    double q = 0;
    
    for (int i = n; i >= 0; --i) 
    {
        q = q * x + wspolczynniki[i];
        cout << q << " ";
    }
        
    
    return q;
}

int main() 
{
    int n ;
    cout << "Podaj liczbę n: ";
    cin >> n;

    cout << "Podaj wspolczynniki (n+1: a0, a1 ... an): ";
    double wspolczynniki[10000] = {0};

    for(int i = 0; i <= n; i++)
        cin >> wspolczynniki[i];
    

    cout << "Podaj x: ";
    double x;
    cin >> x;

    double wynik = oblicz_wielomian(wspolczynniki, x, n);
    cout << "Wartość wielomianu dla x = " << x << " wynosi: " << wynik << endl;

    return 0;
}

// Pn(x) = x * Qn-1(x) + a0
// P2(x) = P1(x) + a0

/*
3
3 2 1 4
2
*/