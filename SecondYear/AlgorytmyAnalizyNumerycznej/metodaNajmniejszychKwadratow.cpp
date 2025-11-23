#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct parametr_func{
    double a;
    double b;
};

parametr_func aproksymacja_liniowa(vector<double>& xi, vector<double>& fi)
{
    double a00, a01, a10, a11, b0, b1;
    a00 = a01 = a10 = a11 = b0 = b1 = 0;
    a00 = xi.size();
    for(int i = 0; i < xi.size(); i++)
    {
        a01 += xi[i];
        a11 += xi[i]*xi[i];
        b0 += fi[i];
        b1 += xi[i]*fi[i];
    }
    a10 = a01;

    double W = a00 * a11 - a01 * a10;
    double W1 = b0 * a11 - b1 * a01;
    double W2 = b1 * a00 - b0 * a10;

    //cout << "W = " << W << "\nW1 = " << W1 << "\nW2 = " << W2 << endl;
    return {W2/W, W1/W};  
}

parametr_func aproksymacja_hiperboliczna(vector<double> xi, vector<double>& fi)
{
    for(int i = 0; i < xi.size(); i++)
    {
        xi[i] = 1 / xi[i];
    }
    return aproksymacja_liniowa(xi, fi);
}

parametr_func aproksymacja_wykladnicza(vector<double>& xi, vector<double> fi)
{
    for(int i = 0; i < xi.size(); i++)
    {
        fi[i] =  log(fi[i]);
    }
    return aproksymacja_liniowa(xi, fi);
}

void print_function(int option, parametr_func answer)
{
    switch(option)
    {
        case 1:
            cout << "g(x) = " << answer.a << "x + " << answer.b << endl;
            break;
        case 2:
            cout << "g(x) = " << answer.a << "/x + " << answer.b << endl;
            break;
        case 3:
            cout << "g(x) = " << log(answer.b) << " * " << log(answer.a) << "^x" << endl;
            break;
    }
}

int main()
{
    int n;

    cout << "Podaj liczbe wezlow: ";
    cin >> n;

    vector<double> xi;
    xi.resize(n);
    vector<double> fi;
    fi.resize(n);

    cout << "Podaj wartosci wezlow: ";
    for(int i = 0; i < n; i++)
        cin >> xi[i];

    cout << "Podaj wartosci funkcji w tych wezlach: ";
    for(int i = 0; i < n; i++)
        cin >> fi[i];

    int option;
    cout << "Podaj opcje:\n1 - g(x) = ax+b\n2 - g(x) = a/x+b\n3 - g(x) = b*a^x\nPodaj opcje: ";
    cin >> option;

    parametr_func ans;

    switch(option)
    {
        case 1:
            ans = aproksymacja_liniowa(xi, fi);
            break;
        case 2:
            ans = aproksymacja_hiperboliczna(xi, fi);
            break;
        case 3:
            ans = aproksymacja_wykladnicza(xi, fi);
            break;
        default: 
            cout << "Wybor jest niepoprawny!\n";
            return 0;
    }
    print_function(option, ans);
   
}