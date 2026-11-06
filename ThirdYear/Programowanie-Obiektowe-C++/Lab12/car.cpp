#include "car.h"
#include <iomanip>

using std::cout, std::setw, std::left;
Car::Car() {
    model = "null";
    year = -1;
    capacity = -1;
}

Car::Car(string model, int year, float capacity) {
    this->model = model;
    this->year = year;
    this->capacity = capacity;
}

string Car::get_model() {
    return model;
}

int Car::get_year() {
    return year;
}

float Car::get_capacity() {
    return capacity;
}

void Car::set_model(string model) {
    this->model = model;
}

void Car::set_year(int year) {
    this->year = year;
}

void Car::set_capacity(float capacity) {
    this->capacity = capacity;
}

void Car::show_info() {
    cout << "Informacja o samochodzie: ";
    cout << "m: " << left << setw(18) << model << " ";
    cout << "y: " << year << " ";
    cout << "c: " << capacity << "\n";
}
