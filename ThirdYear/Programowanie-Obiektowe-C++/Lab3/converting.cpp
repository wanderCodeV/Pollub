#include <iostream>
#include <string>

template <int divider, typename T>
void showConvertingFromGrams(T elem) {
    std::cout << "Dla podanego typu brak specjalizacji\n";
}

// dekagram i int
template <>
void showConvertingFromGrams<10, int>(int elem) {
    std::cout << elem << " g = " << elem / 10 << " dag\n";
}

// kilogam i int
template <>
void showConvertingFromGrams<1000, int>(int elem) {
    std::cout << elem << " g = " << elem / 1000 << " kg\n";
}

template <>
void showConvertingFromGrams<1000000, int>(int elem) {
    std::cout << elem << " g = " << elem / 1000000 << " t\n";
}

template <>
void showConvertingFromGrams<10, float>(float elem) {
    std::cout << elem << " g = " << elem / 10.0f << " dag\n";
}

template <>
void showConvertingFromGrams<1000, float>(float elem) {
    std::cout << elem << " g = " << elem / 1000.0f << " kg\n";
}

template <>
void showConvertingFromGrams<1000000, float>(float elem) {
    std::cout << elem << " g = " << elem / 1000000.0f << " t\n";
}

int main() {
    int wagaInt = 5000;
    float wagaFloat = 3500.5f;

    showConvertingFromGrams<10, int>(wagaInt);
    showConvertingFromGrams<1000, int>(wagaInt);
    showConvertingFromGrams<1000000, int>(wagaInt);

    showConvertingFromGrams<10, float>(wagaFloat);
    showConvertingFromGrams<1000, float>(wagaFloat);
    showConvertingFromGrams<1000000, float>(wagaFloat);


    showConvertingFromGrams<10, std::string>("5000");

    double wagaDouble = 100.0;
    showConvertingFromGrams<10, double>(wagaDouble);

    return 0;
}