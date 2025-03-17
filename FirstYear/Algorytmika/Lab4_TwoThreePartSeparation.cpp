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

void wyswietlStudentow(TStudent *tab, int st, int fn)
{
    for (int i = st; i <= fn; i++)
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
    plik.close();
}

int sort_two_parts(TStudent* &tab, int n)
{
    int st = 0, fn = n-1;
    while(st < fn)
    {
        while(st < fn && tab[st].punkty <= 10) st++;
        while(st < fn && tab[fn].punkty > 10) fn--;
        if(st < fn)
        {
            swap(tab[st], tab[fn]);
            st++;
            fn--;
        }
    }
    if(tab[st].punkty <= 10)
        return st;   
    else
        return st-1;	
}

void sort_three_part(TStudent* &tab, int n, int &p1, int &p2)
{
    int st = -1, mid = 0, fn = n-1;
    while(mid < fn)
    {
        if(tab[mid].punkty % 3 == 0)
        {
            st++;
            swap(tab[st], tab[mid]);
            mid++;
        }
        else
        {
            if(tab[mid].punkty % 3 == 2)
            {
                fn--;
                swap(tab[fn], tab[mid]);
            }
            else
                mid++;
        }
    }
    p1 = st;
    p2 = fn; 	
}
int main()
{
    TStudent* tab = nullptr;
    int n;
    int mode;
    wczytajStudentow(tab, n);

    cout << "Program:" << endl;
    cout << "1) Podzial zbioru na dwie czesci" << endl;
    cout << "2) Podzial zbioru na trzy czesci" << endl;
    int option;
    cin >> option;
    switch (option)
    {
        case 1:
        {
            cout << "Przed:\n";
            wyswietlStudentow(tab, 0, n-1);
            int first_group = sort_two_parts(tab, n);
            cout << "\nPo:\nStudenci, ktorzy otrzymali <= 10 punktow:\n";
            wyswietlStudentow(tab, 0, first_group);
            cout << "\nStudenci, ktorzy otrzymali > 10 punktow:\n";
            wyswietlStudentow(tab, first_group + 1, n-1);

        }
        case 2:
        {
            cout << "Przed:\n";
            wyswietlStudentow(tab, 0, n-1);
            int first_group, second_group;
            sort_three_part(tab, n, first_group, second_group);
            cout << "\nPo:\nStudenci, ktorzy otrzymali liczbe punktow podzielnych przez 3:\n";
            wyswietlStudentow(tab, 0, first_group);
            cout << "\nStudenci, ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 1:\n";
            wyswietlStudentow(tab, first_group + 1, second_group - 1);
            cout << "\nStudenci, ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 2:\n";
            wyswietlStudentow(tab, second_group, n -1);
        }
        default:
            break;
    }

    usunTabliceStudentow(tab);
    return 0;

}
