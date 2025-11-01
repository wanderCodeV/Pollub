#include <bits/stdc++.h>

using namespace std;

typedef struct {
    double x;
    double f;
} XF;

void input_data(vector<XF> &func, int &n, double &p)
{
    cout << "Podaj liczbe wezlow (n>=1): ";
    do
    {
        cin >> n;
    } while(n < 1);
        

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


double newton_interpolation(vector<XF> &func,  int n, double p)
{
    vector<double> il_roz;

    for(int i = 0; i < n ; i++)
    {
        il_roz.push_back(func[i].f);
        cout << setw(5) << il_roz[i] << " ";
    }
    cout << "| f[i]" << endl;    

    for(int i = 1; i < n; i++)
    {
        for(int j = n - 1; j >= i; j--)
            il_roz[j] = (il_roz[j] - il_roz[j-1]) / (func[j].x - func[j - i].x);

        for(int j = 0; j < n; j++)
        {
            if(j < i)
                cout << "      ";
            else
                cout << setw(5) << il_roz[j] << " ";
        }
         cout << "| f[x_i ... x_i+" << i << "]" << endl;    
    }
    
    double result = 0;
    for(int i = 0; i < n; i++)
    {
        int temp = il_roz[i];
        for(int j = 0; j < i; j++)
        {
            temp *= (p - func[j].x);
        }
        result += temp;
    }
    return result;
    
}

bool check_interpolacja(vector<XF> &func, int &n)
{
    for(int i = 1; i < n; i++)
        if(func[i].x <= func[i-1].x)
            return false;
    return true; 
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
        if(p > func[n-1].x || p < func[0].x)
            cout << "Punkt nie nalezy do przedzialu [" << func[0].x << ", " <<  func[n-1].x  << "]" << endl;
        else
        {
            cout << "Punkt nalezy do przedzialu [" << func[0].x << ", " <<  func[n-1].x  << "]" << endl;
            double w_p = newton_interpolation(func, n, p);
            cout << "WYNIK = " << w_p << endl;
        }  
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
1

5
-4
1008
-2
420
0
-240
3
-420
5
630
1

5
-5
1120
-3
-160
-1
-144
2
-630
5
2880
1
*/