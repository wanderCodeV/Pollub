#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
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
            cout << setw(4) << tab[i][j] << " ";
        cout << endl;
    }
}
bool compare(int a, int b, int tryb)
{
    if(tryb == 2)
        return a > b;
    return a < b;
}

void sortowanieBabelkowe(int* tab, int n, int tryb)
{
    for(int i = n - 1; i > 0; i--)
    {
        int key = 1;
        for(int j = 0; j < i; j++)
            if (compare(tab[j], tab[j+1], tryb))
            {
                swap(tab[j], tab[j+1]);
                key = 0;
            }
        if(key == 1)
            break;
    }
}

void sortowaniePrzezWybor(int* tab, int n, int tryb)
{
    for(int i = n - 1; i > 0; i--)
    {
        int ind = 0;
        for(int j = 1; j <= i; j++)
            if (compare(tab[j], tab[ind], tryb))
                ind = j;
        swap(tab[i], tab[ind]);
    }
}


void sortowaniePrzezWstawianie(int* tab, int n, int tryb)
{
    for(int i = n - 2; i >= 0; i--)
    {
        int j = i;
        int temp = tab[j];
        while(j < n-1 && compare(temp, tab[j+1], tryb))
        {
            tab[j] = tab[j+1];
            j++;
        }
        tab[j] = temp;
    }

}
void sortowanieBabelkowe2D(int** tab, int w, int k, int tryb, int nrKol)
{
    for(int i = w - 1; i > 0; i--)
    {
        int check = 1;
        for(int j = 0; j < i; j++)
            if (compare(tab[j][nrKol], tab[j+1][nrKol], tryb))
            {
                swap(tab[j], tab[j+1]);
                check = 0;
            }
        if(check == 1)
            break;
    }
}
int main()
{
    cout << "Program:" << endl;
    cout << "1) Zadanie 2.2" << endl;
    cout << "2) Zadanie 2.3" << endl;
    cout << "3) Zadanie 2.4" << endl;
    cout << "4) Zadanie 2.5" << endl;
    cout << "5) Exit" << endl;
    int option;

    while(option != 5)
    {
        cout << "Podaj opcje: ";
        cin >> option;
        switch (option)
        {
            case 1:
            {
                int *tab = nullptr;
                int n, a, b, mode = 0;
                cout << "Podaj rozmiar tablicy jednowymiarowej: ";
                cin >> n;
                cout << "Podaj przedzial <a,b>: ";
                cin >> a >> b;
                cout << "Tryb sortowania [1)malejco 2)rosnaco]: ";
                cin >> mode;
                przydzielPamiec1D(tab, n);
                wypelnijTablice1D(tab, n, a, b);
                cout << "Przed: ";
                wyswietl1D(tab, n);
                sortowanieBabelkowe(tab, n, mode);
                cout << "Po: ";
                wyswietl1D(tab, n);
                usunTablice1D(tab);
                break;
            }
            case 2:
            {
                int *tab = nullptr;
                int n, a, b, mode = 0;
                cout << "Podaj rozmiar tablicy jednowymiarowej: ";
                cin >> n;
                cout << "Podaj przedzial <a,b>: ";
                cin >> a >> b;
                cout << "Tryb sortowania [1)malejco 2)rosnaco]: ";
                cin >> mode;
                przydzielPamiec1D(tab, n);
                wypelnijTablice1D(tab, n, a, b);
                cout << "Przed: ";
                wyswietl1D(tab, n);
                sortowaniePrzezWybor(tab, n, mode);
                cout << "Po: ";
                wyswietl1D(tab, n);
                usunTablice1D(tab);
                break;
            }
            case 3:
            {
                int *tab = nullptr;
                int n, a, b, mode = 0;
                cout << "Podaj rozmiar tablicy jednowymiarowej: ";
                cin >> n;
                cout << "Podaj przedzial <a,b>: ";
                cin >> a >> b;
                cout << "Tryb sortowania [1)malejco 2)rosnaco]: ";
                cin >> mode;
                przydzielPamiec1D(tab, n);
                wypelnijTablice1D(tab, n, a, b);
                cout << "Przed: ";
                wyswietl1D(tab, n);
                sortowaniePrzezWstawianie(tab, n, mode);
                cout << "Po: ";
                wyswietl1D(tab, n);
                usunTablice1D(tab);
                break;
            }
            case 4:
            {
                int** tab = nullptr;
                int w, k, a, b, mode, numCol;
                cout << "Podaj rozmiar tablicy dwuwymiarowej: ";
                cin >> w >> k;
                cout << "Podaj przedzial <a,b>: ";
                cin >> a >> b;
                cout << "Tryb sortowania [1)malejco 2)rosnaco]: ";
                cin >> mode;
                cout << "Numer kolumny wzgledem ktorej odbedzie sie sortowanie[<" << k<< "]: ";
                cin >> numCol;
                przydzielPamiec2D(tab, w, k);
                wypelnijTablice2D(tab, w, k, a, b);
                cout << "Przed:" << endl;
                wyswietl2D(tab, w, k);
                sortowanieBabelkowe2D(tab, w, k, mode, numCol);
                cout << "Po:" << endl;
                wyswietl2D(tab, w, k);
                usunTablice2D(tab, w);
                break;
            }
            default :
                cout << "Blad!\n Nie prawidlowa opcja" << endl;
                break;
        }
    }

    return 0;
}
