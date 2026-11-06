#include <iostream>
#include <string>

using namespace std;

auto showConvertingFromGrams(auto elem, auto divider) {
    return elem / divider;
}

int main() {
    cout << showConvertingFromGrams(250, 10.0) << endl;
    cout << showConvertingFromGrams(4500.5, 1000.0) << endl;

    return 0;
}

//
// #include <iostream>
// #include <string>
//
// void showConvertingFromGrams(double elem, double divider) {
//     std::cout << elem / divider << std::endl;
// }
//
// void showConvertingFromGrams(int elem, double divider) {
//     std::cout << elem / divider << std::endl;
// }
//
// void showConvertingFromGrams(auto elem, double divider) {
//     std::cout << "Dla podanego typu brak specjalizacji" << std::endl;
// }