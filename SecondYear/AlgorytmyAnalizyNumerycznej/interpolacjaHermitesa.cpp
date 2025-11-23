#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Podaj liczbe wezlow: ";
    cin >> n;

    vector<double> x(n), f(n);

    cout << "Podaj wartosci wezlow (z powtorzeniami):\n";
    for (int i = 0; i < n; i++) cin >> x[i];

    cout << "Podaj wartosci funkcji i pochodnych:\n";
    for (int i = 0; i < n; i++) cin >> f[i];

    cout << "\nIlorazy roznicowe pierwszego rzedu:\n";

    int st_x = 1;
    for (int i = 0; i < n - 1; i++) {
        if (x[i] == x[i+1]) 
        {
            cout << f[st_x] << endl;
        } 
        else 
        {
            cout << (f[i+1] - f[st_x-1]) / (x[i+1] - x[i]) << endl;
            st_x = i + 2;
        }
    }

    return 0;
}
