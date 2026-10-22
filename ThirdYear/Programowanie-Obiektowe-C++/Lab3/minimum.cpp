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


int main() {

    int n = 10;
    int arr1[n];
    double arr2[n];
    double lower = 0, upper = 100;
    srand(time(0));

    cout << "First array: ";
    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 100;
        cout << arr1[i] << " ";
    }
    cout << endl << "Min element: " << min_element(arr1, n) << endl;

    cout << "Second array: ";
    for (int i = 0; i < n; i++) {
        arr2[i] = lower + (upper - lower) * rand() / RAND_MAX;
        cout << arr2[i] << " ";
    }
    cout << endl << "Min element: " << min_element(arr2, n) << endl;
}