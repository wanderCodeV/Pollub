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


double neville_interpolation(vector<XF> &func,  int n, double p)
{
    vector<double> p_ij;

    for(int i = 0; i < n ; i++)
    {
        p_ij.push_back(func[i].f);
        cout << setw(8) << p_ij[i] << " ";
    }

    cout << "| f[i]" << endl;    

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n - i; j++)
        {
            p_ij[j] = ((p-func[j].x)*p_ij[j+1] - (p-func[i+j].x)*p_ij[j]) / (func[i+j].x - func[j].x);
        }

        for(int j = 0; j < n; j++)
        {
            if(j > n - i - 1)
                cout << "         ";
            else
                cout << setw(8) << p_ij[j] << " ";
        }
         cout << "| p[j," << i << "]" << endl;   
    }
    
    return p_ij[0];
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
            double result =  neville_interpolation(func, n, p);
            cout << "WYNIK = " << result << endl;
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


5
-3
-17
-1
9
0
17
2
23
4
25
1
*/