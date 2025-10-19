#include <iostream>
#include <map>

using namespace std;

void task1()
{
    float a1 = 0.567343e+23;
    float b1 = 0.123819e+4;
    if(a1+b1==a1)  cout << "Yes\n";
    else cout << "No\n";

    double a2 = 0.567343e+23;
    double b2 = 0.123819e+4;
    if(a2+b2==a2)  cout << "Yes\n";
    else cout << "No\n";

    long double a3 = 0.567343e+19;
    long double b3 = 0.123819e+4;
    if(a3+b3==a3)  cout << "Yes\n";
    else cout << "No\n";

    cout<< "zmienna typu float zajmuje: " <<sizeof(float) << endl;
    cout<< "zmienna typu double zajmuje: " <<sizeof(double) << endl;
    cout<< "zmienna typu long double zajmuje: " <<sizeof(long double) << endl;
}

void task2()
{
    float s = 0;
    int cnt = 0;
    while(s<=100)
    {
        s+=0.01;
        cnt++;
        cout << cnt <<". s = " << s << endl;
    }
}

void task3(int num, int base)
{
    vector<int> converted;
    map<int, char> symbols {{10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}};

    cout << num << "[10] = ";
    while(num > 0)
    {
        converted.push_back(num%base);
        num /= base;
    }

    for(int i = converted.size() - 1; i >= 0; i-- )
        if (converted[i] > 9)
            cout << symbols[converted[i]];
    else cout << converted[i];
    cout << "[" << base << "]" << endl;
}

void task4a(double a, double b, double c)
{
    if(a != 0)
    {
        int D = b * b - 4 * a * c;
        if(D > 0)
        {
            double sD = sqrt(D);
            cout << "x1 = " << ((-1) * b - sD) / (2 * a) << endl;
            cout << "x2 = " << ((-1) * b + sD) / (2 * a) << endl;
        }
        else if (D == 0)
            cout << "x = " << (-1)*D / (2 * a) << endl;
        else 
            cout << "Brak rozwiazan!" << endl;
        
    }
    else if (b != 0)
        cout << "x = " << (-1) * c / b << endl;
    else 
    {
        if(c == 0) 
            cout << "Nieskonczenie wiele rozwiazan" << endl;
        else 
            cout << "Brak rozwiazan!" << endl;
    }

}

int sign(double x) 
{
    if(x > 0) 
        return 1;
    if(x < 0) 
        return -1;
    return 0;
}

void task4b(double a, double b, double c)
{
    if(a != 0)
    {
        if(b != 0)
        {
            double temp = -b / (2*a);
            double delta = temp*temp - c/a;
            if(delta >= 0) {
                double x1 = temp + sign(temp) * sqrt(delta);
                double x2 = c / (a*x1);
                cout << "x1 = " << x1 << endl;
                cout << "x2 = " << x2 << endl;
            } 
            else
                cout << "Brak rozwiazan!" << endl;
        }
        else
        {
            if(c/a >= 0) {
                double x = sqrt(c/a);
                cout << "x1 = " << x << "\nx2 = -" << x << endl;
            } else {
                cout << "Brak rozwiazan!" << endl;
            }
        }
    }
    else if (b != 0)
        cout << "x = " << -c / b << endl;
    else
    {
        if(c == 0) 
            cout << "Nieskonczenie wiele rozwiazan" << endl;
        else 
            cout << "Brak rozwiazan!" << endl;
    }
}

int main() {
    task3(94211352, 8);
    int a = 1;
    int b = 0;
    int c = -1;
    task4a(a, b, c);
    task4b(a, b, c);

    return 0;
}
