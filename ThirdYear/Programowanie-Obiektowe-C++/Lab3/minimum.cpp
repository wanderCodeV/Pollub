#include "minimum.h"
#include <string>
#include <iostream>
using namespace std;

template <typename T>
T min_element(T arr[], int n) {
    T min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

template <>
string min_element(string arr[], int n) {
    cout << "Dla danego typu nie przewidziane";
}

template int min_element<int>(int arr[], int n);
template double min_element<double>(double arr[], int n);