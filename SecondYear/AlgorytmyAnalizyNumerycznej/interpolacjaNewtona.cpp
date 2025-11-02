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


vector<double> newton_interpolation(vector<XF> &func,  int n)
{
    vector<double> il_roz;

    for(int i = 0; i < n ; i++)
    {
        il_roz.push_back(func[i].f);
        //cout << setw(5) << il_roz[i] << " ";
    }
    //cout << "| f[i]" << endl;    

    for(int i = 1; i < n; i++)
    {
        for(int j = n - 1; j >= i; j--)
            il_roz[j] = (il_roz[j] - il_roz[j-1]) / (func[j].x - func[j - i].x);

        /*for(int j = 0; j < n; j++)
        {
            if(j < i)
                cout << "      ";
            else
                cout << setw(5) << il_roz[j] << " ";
        }
         cout << "| f[x_i ... x_i+" << i << "]" << endl;    */
    }
    
    return il_roz;
}

double calculate_newton_interpolation(vector<XF> &func,  int n, double p)
{
    vector<double> il_roz = newton_interpolation(func, n);
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

void show_wielomian(vector<XF> &func,  int n)
{
    vector<double> il_roz = newton_interpolation(func, n);
    vector<double> result(n, 0.0);
    result[0] = il_roz[0];
    for(int i = 1; i < n; i++)
    {
        vector<double> Li = {il_roz[i]};
        for(int j = 0; j < i; j++)
        {
            vector<double> term = { -func[j].x, 1 };
            Li = multiplyPolynomials(Li, term);
        }
        for (int k = 0; k < Li.size(); k++) 
        {
            result[k] += Li[k];
        }
    }
    print_welomian(result);
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
            double w_p = calculate_newton_interpolation(func, n, p);
            cout << "WYNIK = " << w_p << endl;
            show_wielomian(func, n);
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