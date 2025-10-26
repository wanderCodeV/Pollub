#include <bits/stdc++.h>

using namespace std;

typedef struct {
    double x;
    double f;
} XF;

void input_data(vector<XF> &func, int &n, double &p)
{
    cout << "Podaj liczbe wezlow: ";
    cin >> n;

    double xi, fi;
    for(int i = 0; i < n; i++)
    {
        cout << "Podaj x" << i << ": ";
        cin >> xi;
        cout << "Podaj f" << i << ": ";
        cin >> fi;
        func.push_back({xi, fi});
    }

    cout << "Podaj punkt p: ";
    cin >> p;
}

bool cmp(XF a, XF b)
{
    return a.x > b.x;
}

bool check_interpolacja(vector<XF> &func, int &n)
{
    sort(func.begin(), func.end(), cmp);
    for(int i = 1; i < n; i++)
        if(func[i].x == func[i-1].x)
            return false;
    return true; 
}

double lagrange_interpolation(vector<XF> &func,  int n, double p)
{
    double result = 0.0;
    for (int i = 0; i < n ; i++)
    {
        double f1 = 1.0;
        double f2 = 1.0;
        for (int j = 0; j < n ; j++)
        {
            if (i != j)
            {
                f1 *= p - func[j].x;
                f2 *= func[i].x - func[j].x;
            }
        }
        result += func[i].f * f1 / f2;
    }
    return result;
}


int main()
{
    vector<XF> func;
    int n;
    double p;
    input_data(func, n, p);
    if(check_interpolacja(func, n))
    {
        cout << "Zalozenie interpolacji = TRUE" << endl;
        if(p > func[n-1].x && p || func[0].x)
            cout << "Punkt nie nalezy do przedzialu [" << func[0].x << ", " <<  func[n-1].x  << "]" << endl;
        else
            cout << "Przyblizona wartosc funkcji w punkcie (p = " << p << ") = " << lagrange_interpolation(func, n, p);
    }
    else
        cout << "Niespelnione zalozenia interpolacyjne\n";
   
}

/*
5
-2
-240
0
24
1
18
2
-16
3
-60
5
*/