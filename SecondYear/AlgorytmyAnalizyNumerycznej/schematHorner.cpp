#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

double HornerMethod(int power, int point, vector<int> &coeff)
{
    double w = coeff[0];
    for (int i = 1; i <= power; i++)
        w = w * point + coeff[i];
    return w;
}

void HornerU(int power, int point, vector<int> &coeff)
{
    for (int i = 0; i < power; i++)
    {
        for(int k = 0; k <= power - i; k++)
            cout << "------";
        cout << "\n" << setw(4) << coeff[0] << " |";
        for (int k = 1; k <= power - i; k++)
        {
            coeff[k] += coeff[k - 1] * point;
            cout << setw(4) << coeff[k] << " |";
        }
        cout << endl;
    }        
}

int main()
{
    int power, point;
    vector <int> coeff;

    cout << "Podaj stopien wielomianu: ";
    cin >> power;
    cout << "Podaj wspolczynniki wielomianu:\n";
    int temp;
    for(int i = 0; i <= power; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> temp;
        coeff.push_back(temp);
    }
    cout << "Podaj punkt, w ktorym liczona bedzie wartosc wielomianu: ";
    cin >> point;
    HornerU(power, point, coeff);
    cout << "----------------------------------------------------------\n";
    cout << "Wartosc podanego wielomianu w punkcie p = " << point << " wynosi:\n";
    cout << coeff[power] << endl;
    // cout << HornerMethod(power, point, coeff) << endl;
    cout << "----------------------------------------------------------\n";
    cout << "Wartosc pochodnych wielomianu w punkcie p = " << point << " wynosi:\n";
    
    int fact = 1;
    for(int i = 1; i <= power; i++)
    {
        fact *= i;
        cout << i << " pochodna = " << coeff[power - i]*fact << endl;
    }
    
}