// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>

using namespace std;

template <typename Type>
struct Vec3 {
    Type x;
    Type y;
    Type z;

    //Vec3(Type x, Type y, Type z): x(x), y(y), z(z) {}
    
    Vec3()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    //task 3 - konstruktor z trzema wartosciami
    Vec3(Type auto_x, Type auto_y, Type auto_z)
    {
        x = auto_x;
        y = auto_y;
        z = auto_z;
    }
    //Task 4 - normalizacja wektora
    void norm()
    {
        float len = sqrt(x * x + y * y + z * z);
        x /= len;
        y /= len;
        z /= len;
    }
};

//task 1 - iloczyn skalarny
float dot(Vec3 <float> a, Vec3 <float> b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

//task 2 - iloczyn wektorowy
template <typename Type>
Vec3<Type> cross(const Vec3 <Type> &a, const Vec3 <Type> &b)
{
    Vec3<Type> ans;
    ans.x = a.y * b.z - a.z * b.y;
    ans.y = a.z * b.x - a.x * b.z;
    ans.z = a.x * b.y - a.y * b.x;
    return ans;
}
int main()
{

    Vec3 <float> a ( 1, 1, 1 );
    Vec3 <float> b ( 4, 5, -1 );
    Vec3 <float> ans = cross(a, b);

    cout << "Iloczyn skalarny = " << dot(a, b)<< endl;
    cout << "Iloczyn wektorowy = [" << ans.x << "," << ans.y << "," << ans.z << "]" << endl;

    a.norm();
    b.norm();
    cout << "Wektor A: " << a.x << " " << a.y << " " << a.z << endl;
    cout << "Wektor B: " << b.x << " " << b.y << " " << b.z << endl;
}