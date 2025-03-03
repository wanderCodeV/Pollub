#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void przydzielPamiec1D(int *&tab, int n) 
{
    tab = new int[n];
}

void przydzielPamiec2D(int **&tab, int w, int k)
 {
    tab = new int *[w];
    for (int i = 0; i < w; i++)
        tab[i] = new int[k];
}

void wypelnijTablice1D(int *tab, int n, int a, int b) 
{
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
        tab[i] = a + rand() % (b - a + 1);
}

void wypelnijTablice2D(int **tab, int w, int k, int a, int b) 
{
    srand(time(nullptr));
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            tab[i][j] = a + rand() % (b - a + 1);
}

void usunTablice1D(int *&tab) 
{
    delete[]tab;
}

void usunTablice2D(int **&tab, int w) 
{
    for (int i = 0; i < w; i++)
        delete[]tab[i];
    delete[]tab;
}

void wyswietl1D(int *tab, int n) 
{
    for (int i = 0; i < n; i++)
        cout << tab[i] << " ";
    cout << endl;  
}

void wyswietl2D(int **tab, int w, int k)
{
    for (int i = 0; i < w; i++) 
    {
        for (int j = 0; j < k; j++)
            cout << tab[i][j] << " ";
        cout << endl;
    }
}

bool check_prime(int a) 
{
    if (a < 2) return false;
    if (a == 2) return true;
    for (int i = 3; i * i <= a; i += 2)
        if (a % i == 0) return false;
    return true;
}

int sum_digit(int a)
{
    int sum = 0;
    while (a > 0)
    {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}
int main() 
{
    cout << "Program:" << endl;
    cout << "1) Task 1.2" << endl;
    cout << "2) Zadanie 1.3" << endl;
    cout << "3) Zadanie 1.4" << endl;
    cout << "4) Zadanie 1.5" << endl;
    cout << "5) Exit" << endl;
    int option;
    cout << "Podaj opcje: ";
    cin >> option;
    
    switch (option) 
    {
        case 1:
        {
            int *tab = nullptr;
            int n, a, b;
            cout << "Podaj rozmiar tablicy jednowymiarowej: ";
            cin >> n;
            cout << "Podaj przedzial <a,b>: ";
            cin >> a >> b;
            przydzielPamiec1D(tab, n);
            wypelnijTablice1D(tab, n, a, b);
            wyswietl1D(tab, n);
            int min_elem = tab[0];
            for (int i = 1; i < n; i++) 
            {
                if (tab[i] < min_elem)
                    min_elem = tab[i];
            }
            cout << "Najmniejsza liczba: " << min_elem << " - ";
            if (check_prime(min_elem)) cout << "Jest pierwsza";
            else cout << "NIE jest pierwsza";
            usunTablice1D(tab);
            break;
        }
        case 2:
        {
            int *tab = nullptr;
            int n;
            cout << "Podaj rozmiar tablicy jednowymiarowej: ";
            cin >> n;
            przydzielPamiec1D(tab, n);
            wypelnijTablice1D(tab, n, 0, 9);
            wyswietl1D(tab, n);
            int* index_arr = new int[10];
            for(int i = 0; i < 10; i++)
                index_arr[i] = 0;
            for (int i = 0; i < n; i++) 
            {
                index_arr[tab[i]]++;
            }
            cout << "Ilosc:" << endl;
            for(int i = 0; i < 10; i++)
            {
                cout << i << ": " << index_arr[i] << endl;
            }
            usunTablice1D(index_arr);
            usunTablice1D(tab);
            break;
        }
        case 3:
        {
            int** tab = nullptr;
            int w, k, a, b;
            cout << "Podaj rozmiar tablicy dwuwymiarowej: ";
            cin >> w >> k;
            cout << "Podaj przedzial <a,b>: ";
            cin >> a >> b;
            przydzielPamiec2D(tab, w, k);
            wypelnijTablice2D(tab, w, k, a, b);
            wyswietl2D(tab, w, k);
            int max_elem = tab[0][0];
            for (int i = 0; i < w; i++) 
            {
                for(int j = 0 ; j < k; j++)
                    if (tab[i][j] > max_elem)
                        max_elem = tab[i][j];
            }
            cout << "Najwieksza liczba: " << max_elem << endl;
            cout << "Suma cyfr = " << sum_digit(max_elem) << endl;
            usunTablice2D(tab, w);
            break;
        }
        case 4:
        {
            int** tab = nullptr;
            int w, k;
            cout << "Podaj rozmiar tablicy dwuwymiarowej: ";
            cin >> w >> k;
            przydzielPamiec2D(tab, w, k);
            wypelnijTablice2D(tab, w, k, 7, 122);
            wyswietl2D(tab, w, k);
            int max_elem = tab[0][0];
            double cnt = (w * k - max(w, k)) / 2;
            int sum_under = 0, sum_above = 0;
            for (int i = 0; i < w; i++) 
            {
                for(int j = 0 ; j < k; j++)
                {
                    if (j > i)
                        sum_above += tab[i][j];
                    else if (j < i)
                        sum_under += tab[i][j];
                }
            }
            cout << "Srednia pod przekatna =  " << sum_under / cnt << endl;
            cout << "Srednia nad przekatna =  " << sum_above / cnt << endl;
            
            usunTablice2D(tab, w);
            break;
        }
        default :
            cout << "Blad!\n Nie prawidlowa opcja";
            break;
    }
    return 0;
}
