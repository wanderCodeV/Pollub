#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

double gauss_chebyshev(int n)
{
    double H = M_PI / (n + 1);
    double result = 0.0;

    for (int j = 0; j <= n; j++)
    {
        double x = cos((2.0 * j + 1.0) * M_PI / (2.0 * (n + 1)));
        result += H * (x * x);  
    }

    return result;
}

long double gauss_legendre_4()
{
    long double x[5] = { -0.906180L, -0.538469L, 0.0L, 0.538469L, 0.906180L };
    long double H[5] = { 0.236927L, 0.478629L, 0.568889L, 0.478629L, 0.236927L };

    long double result = 0.0L;

    for (int i = 0; i < 5; i++)
    {
        long double fx = 1.0L / sqrtl(1.0L + x[i]*x[i]);
        result += H[i] * fx;                     
    }

    return result;
}


double gauss_laguerre_3()
{
    double x[4] = { 0.322548, 1.745761, 4.536620, 9.395071 };
    double H[4] = { 0.603154, 0.357419, 0.038888, 0.000539 };

    double result = 0.0;
    for (int i = 0; i < 4; i++)
    {
        double fx;
        if (fabs(x[i]) < 1e-16) 
            fx = 1.0; 
        else 
            fx = exp(-1*x[i]) * sin(x[i]) / x[i];
        result += H[i] * fx;
    }

    return result;
}


double gauss_hermite_4()
{
    double x[5] = { -2.020183, -0.958572, 0.0, 0.958572, 2.020183 };
    double H[5] = {  0.019953,  0.393619, 0.945309, 0.393619, 0.019953 };

    double result = 0.0;
    for (int i = 0; i < 5; i++)
        result += H[i] * cos(x[i]);   

    return result;
}


int main()
{
    cout << "Wynik Gauss-Chebyshev = " << gauss_chebyshev(3) << endl;
    cout << "Wynik Gauss-Legendre = " << gauss_legendre_4() << endl;
    cout << "Wynik Gauss-Laguerre = " << gauss_laguerre_3() << endl;
    cout << "Wynik Gauss-Hermite = " << gauss_hermite_4() << endl;

    return 0;
}
