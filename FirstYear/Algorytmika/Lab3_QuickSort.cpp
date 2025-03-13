#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
using namespace std;

struct TStudent {
    string name;
    string surname;
    int punkty;
};

void przydzielPamiec1D(TStudent *&tab, int n)
{
    tab = new TStudent[n];
}

void usunTabliceStudentow(TStudent *&tab)
{
    delete[]tab;
}

void wyswietlStudentow(TStudent *tab, int n)
{
    for (int i = 0; i < n; i++)
        cout << tab[i].name << " " << tab[i].surname << " " << tab[i].punkty << endl;
}
void wczytajStudentow(TStudent *&tab, int &n)
{
    ifstream plik;
    plik.open("studenci.csv");

    char sredniki;
    plik >> n;
    przydzielPamiec1D(tab, n);
    for(int i = 0; i < 2; i++)
        plik >> sredniki;
    cout << "Read count " << n << endl;
    string linia, pomoc;
    for(int i = 0; i < n; i++)
    {
        plik >> linia;
        stringstream ss(linia);
        getline(ss, tab[i].name, ';');
        getline(ss, tab[i].surname, ';');
        getline(ss, pomoc);
        tab[i].punkty = atoi(pomoc.c_str());
    }
    wyswietlStudentow(tab, n);
}
bool compare(TStudent a, TStudent b, int tryb)
{
    if(tryb == 1)
        return a.punkty > b.punkty;
    return a.punkty < b.punkty;
}

void sortowanieQuickSort(TStudent *tab, int lewy, int prawy, int tryb)
{
    int mid = (int)(lewy+prawy)/2;
    TStudent piwot  = tab[mid];
    tab[mid] = tab[prawy];
    int border = lewy;
    for(int i = lewy; i < prawy; i++)
    {
        if(compare(tab[i],piwot, tryb) )
        {
            swap(tab[i], tab[border]);
            border++;
        }
    }
    tab[prawy] = tab[border];
    tab[border] = piwot;
    if(lewy < border - 1)
        sortowanieQuickSort(tab, lewy, border - 1, tryb);
    if(border + 1 < prawy)
        sortowanieQuickSort(tab, border + 1, prawy, tryb);

}
int main()
{
    TStudent* tab = nullptr;
    int n;
    int mode;
    wczytajStudentow(tab, n);
    cout << "Tryb sortowania [1)malejco 2)rosnaco]: ";
    cin >> mode;
    sortowanieQuickSort(tab, 0, n-1, mode);
    wyswietlStudentow(tab, n);
    usunTabliceStudentow(tab);

    return 0;
}
