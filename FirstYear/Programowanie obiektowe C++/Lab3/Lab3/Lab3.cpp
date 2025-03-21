// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include "matrix.h"

using namespace std;

template <typename Type>
struct Vec3 {
    Type x;
    Type y;
    Type z;


    Vec3()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    Vec3(Type auto_x, Type auto_y, Type auto_z)
    {
        x = auto_x;
        y = auto_y;
        z = auto_z;
    }
    //Task 2 - wypisywanie wspolrzednych wektora
    void wyswietl()
    {
        cout << '[' << x << ", " << y << ", " << z << ']' << endl;
    }
};

template <typename Type>
Vec3<Type> operator+(const Vec3<Type>& lhs, const Vec3<Type>& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

//Task 1 - operator* - iloczyn skalarny
template <typename Type>
Type operator*(const Vec3<Type>& lhs, const Vec3<Type>& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}
int main()
{

    Vec3 <float> a(1, 1, 1);
    Vec3 <float> b(4, 5, -1);
    Vec3 <float> c = a + b;
    float ans = a * b;
    cout << "Suma: ";
    c.wyswietl();
    cout << "Iloczyn: " << ans << endl;
}

