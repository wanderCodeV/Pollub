#include <iostream>

using namespace std;

double metodaEulera(double n, double b)
{
    double h = b / n;
    double x = 0, y = 3;
    for(int i = 1; i <= n; i++)
    {
        y += h * (y*y / (x+1));
        x += h;
    }
    return y;
}

double metodaHeuna(double n, double b)
{
    double h = (b - 1) / n;
    double x = 1, y = 2;
    for(int i = 1; i <= n; i++)
    {
        double f_x_y = y / (x*x);
        double f = ((y + h * f_x_y) / ((x+h) * (x+h)));
        y += h * (f_x_y + f) / 2;
        x += h;
    }
    return y;
}

double metodaZmEulera(double n, double b)
{
    double h = b / n;
    double x = 0, y = 1;
    for(int i = 1; i <= n; i++)
    {
        double f_x_y = 2*x*y;
        y += h * 2*(x + h/2) * (y + h * f_x_y / 2);
        x += h;
    }
    return y;
}
int main()
{
    double n, b;
    cout << "Laboratorium 14" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Przyklad 14.1 - Metoda Eulera" << endl;
    cout << "y'=y^2/(x+1)\ny(0)=3\n" << endl;
    cout << "WE n = ";
    cin >> n;
    cout << "   b = ";
    cin >> b;
    cout << "WY f(" << b << ")= " << metodaEulera(n, b) << endl;
    cout << "\n---------------------------------------------------" << endl;
    cout << "Przyklad 14.2 - Metoda Heuna" << endl;
    cout << "y'=y/x^2\ny(1)=2\n" << endl;
    cout << "WE n = ";
    cin >> n;
    cout << "   b = ";
    cin >> b;
    cout << "WY f(" << b << ")= " << metodaHeuna(n, b) << endl;
    cout << "\n---------------------------------------------------" << endl;
    cout << "Przyklad 14.2 - Metoda Heuna" << endl;
    cout << "y'=2xy\ny(0)=1\n" << endl;
    cout << "WE n = ";
    cin >> n;
    cout << "   b = ";
    cin >> b;
    cout << "WY f(" << b << ")= " << metodaZmEulera(n, b) << endl;

}

/* INPUT
5
1
2
1.5
2
0.5
*/