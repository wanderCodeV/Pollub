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
    return a.x < b.x;
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
    double result = 0;
    for (int i = 0; i < n; i++) 
    {
        double l = 1;
        for (int k = 0; k < n; k++) 
        {
            if (i!=k) 
                l *= (p - func[k].x) / (func[i].x - func[k].x);
        }
        result += func[i].f*l;
   }
  return result;
}

vector<double> multiplyPolynomials(const vector<double>& A, const vector<double>& B) {
    vector<double> result(A.size() + B.size() - 1, 0.0);
    for (size_t i = 0; i < A.size(); i++)
        for (size_t j = 0; j < B.size(); j++)
            result[i + j] += A[i] * B[j];
    return result;
}

void print_welomian(vector<double> &result)
{
    bool first = true;
    for (int i = result.size() - 1; i >= 0; i--) 
    {
        if (fabs(result[i]) < 1e-9) continue;

        if (!first) 
            cout << (result[i] >= 0 ? " + " : " - ");
        else if (result[i] < 0) 
            cout << "-";

        first = false;

        double coef = fabs(result[i]);
        if (!(coef == 1 && i > 0)) cout << coef;
        if (i > 0) cout << "x";
        if (i > 1) cout << "^" << i;
    }
}
void show_lagrange(vector<XF> &func,  int n)
{
    vector<double> result(n, 0.0);

    for (int i = 0; i < n; i++) 
    {
        vector<double> Li = {1.0};
        double denom = 1.0;

        for (int j = 0; j < n; j++) 
        {
            if (i != j) 
            {
                vector<double> term = { -func[j].x, 1 };
                Li = multiplyPolynomials(Li, term);
                denom *= (func[i].x - func[j].x);
            }
        }
        cout << "L" << i << "(x) = ";
        print_welomian(Li);
        cout << endl;

        for (int k = 0; k < Li.size(); k++) 
        {
            result[k] += Li[k]*func[i].f / denom;
        }
            
    }
    cout << "\nWielomian interpolacyjny Lagrange'a:" << endl;
    cout << "w(x) = ";
    print_welomian(result);

    
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
            cout << "Przyblizona wartosc funkcji w punkcie (p = " << p << ") = " << lagrange_interpolation(func, n, p) << endl;
            show_lagrange(func, n);
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