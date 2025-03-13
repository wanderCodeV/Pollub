// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>

using namespace std;
template <typename Type>

struct Vec3 {
    Type y;
    Type x;
    Type z;

};
int main()
{
    int n = 3;

    Vec3 <double> arr[3];
    vector <Vec3 <double>> dynArr;

    cout << "Podaj trzy wektory [dla kazdego x y z]:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
    }
    for (int i = n - 1; i >= 0; i--)
        dynArr.push_back(arr[i]);

    cout << "Rozmiar tablicy dynamicznej: " << dynArr.size() << endl;
}

/* Task 1
Vec3 <float> arr[4];
cout << "Podaj cztery wektory [dla kazdego x y z]:\n";
for (int i = 0; i < 4; i++)
{
    cin >> arr[i].x >> arr[i].y >> arr[i].z;
}
cout << "Pierwszy wektor: " << arr[0].x << " " << arr[0].y << " " << arr[0].z << endl;
*/