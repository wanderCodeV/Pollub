#include <iostream>

using namespace std;

void naiwny(string text, string wzor)
{
    int dw, dt, i, j;
    dw = wzor.size();
    dt = text.size();
    for(int i = 0; i < dt - dw + 1 ; i++)
    {
        int j = 0;
        while(wzor[j] == text[i+j] && j < dw)
            j++;
        if(j == dw)
            cout << "Wzorzec jest od pozycji " << i << endl;
    }
}
void tworzShift_kmp(string wzor, int* s)
{
    int k = 0;
    int dw = wzor.size();
    s[0] = s[1] = 0;
    for(int i = 1; i < dw; i++)
    {
        while (k > 0 && wzor[k]!=wzor[i])
            k = s[k];
        if (wzor[k] == wzor[i])
            k++;
        s[i+1] = k;
    }
}
void kmp ( string text, string wzor)
{
    int dn = text.size();
    int dw = wzor.size();
    int P[dw+1] = {0};
    int i = 0, j = 0;
    tworzShift_kmp(wzor, P);
    while ( i < dn - dw + 1)
    {
        while (j < dw && wzor[j]==text[j+i])
            j++;
        if (j == dw)
            cout<<"Wzorzec jest od pozycji "<<i << endl;
        if (j - P[j] > 1)
            i += j - P[j];
        else i++;

        j = P[j];
    }
}
void tworzShift_bm(string wzor, int tabs[])
{
    int k = 256; //k – liczba elementów w alfabecie
    int i;
    int m = wzor.size();
    for (i = 0; i < k; i++)
        tabs[i] = -1;
    for (i = 0; i < m; i++)
        tabs[wzor[i]] = i;
}

void bm(string text, string wzor)
{
    int tabs[256];
    tworzShift_bm(wzor, tabs);

    int dn = text.size();
    int dw = wzor.size();
    int i = 0;
    int j, x;

    while ( i < dn - dw + 1)
    {
        j = dw - 1;
        while (text[i+j]==wzor[j] && j > -1)
            j--;

        if (j == -1)
        {
            cout<<"Wzorzec od pozycji: " << i << endl;
            i++;
        }
        else
        {
            x = tabs[text[i+j]]; //o ile przesunąć!!!
            if (j - x > 1)
                i += j - x;
            else
                i++;
        }
    }
}

int main()
{
    cout << "Program:" << endl;
    cout << "1) Algorytm naiwny" << endl;
    cout << "2) Algorytm Knutha-Morrisa-Pratta" << endl;
    cout << "3) Algorytm Boyer’a-Moore’a" << endl;
    int option;
    cout << "Podaj opcje: ";
    cin >> option;

    string text, example;
    cout << "Podaj wzorzec: ";

    getline(cin >> ws, example);
    cout << "Podaj tekst w ktorym bedzie szukany podany wzorzec: ";
    getline(cin, text);

    cout << example << "\n" << text << endl;
    switch(option)
    {
    case 1:
        cout << "=== Algorytm naiwny ===\n";
        naiwny(text, example);
    // break;
    case 2:
        cout << "=== Algorytm Knutha-Morrisa-Pratta ===\n";
        kmp(text, example);
    // break;
    case 3:
        cout << "=== Algorytm Boyer’a-Moore’a ===\n";
        bm(text, example);
        break;
    }
}
