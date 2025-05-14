// Mariia Nyzhnyk grupa 1.4/8

#include <iostream>
#include "radio.h"
#include "zespolona.h"

using namespace std;

//Zadanie 1 - funkcjs Dziwna
float DziwnaOperacja(int p1, float p2, float p3)
{
    float wynik = p1 + 2 * p2;
    if (p3 > 0)
        return wynik / p3; //iloraz - dzielenie
    else
        return wynik * p3; // iloczyn - mnozenie
}


//Zadanie 4 - struktura vec3
template <typename Type>
struct vec3
{
    Type x;
    Type y; 
    Type z;
};

template <typename Type>
Type dot(vec3<Type> a, vec3<Type> b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}


//Glowna funckcja
int main()
{
    cout << "=== Zadanie 1 ===\nWynik: " << DziwnaOperacja(3, -2.5, 4.1) << endl;


    cout << "=== Zadanie 2 ===\n";
    Zespolona<float> z1(1, 2);
    Zespolona<float> z2(1, 0);
    Zespolona<float> z3;
    auto z = z1 + z3 - z2;
    cout << "Wynik: " << z.x << "+" << z.iy << "i\n";

    cout << "=== Zadanie 3 ===\n";
    Radio test;
    test.Info();
    test.DodajStacje(1, 153.23f);
    test.ZmienStacje(1);
    test.Wlacz(true);
    test.Info();
    test.DodajStacje(3, 97.5f);
    test.ZmienStacje(3);
    test.Wlacz(true);
    test.Info();

    cout << "=== Zadanie 4 ===\n";
    vec3<float> a = { 1, 2, 3 };
    vec3<float> b = { -4, 0, 2 };
    cout << "Wynik: " << dot(a, b);


}

//== = Zadanie 1 == =
//Wynik: -0.487805
//== = Zadanie 2 == =
//Wynik : 0 + 2i
//== = Zadanie 3 == =
//Radio jest wylaczone
//Radio jest wlaczone
//Aktualna stacja 1 : 153.23 Hz
//Radio jest wlaczone
//Aktualna stacja 3 : 97.5 Hz
//== = Zadanie 4 == =
//Wynik : 2