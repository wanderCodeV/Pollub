#include "Citizen.h"
#include <iostream>
using namespace std;

Citizen::Citizen() {}

Citizen::Citizen(string name, string surname, int age, char sex, string postal_code) : name(name), surname(surname), age(age), sex(sex), postal_code(postal_code) {}

void Citizen::show() const {
    cout << name << " " << surname << ", wiek: " << age << ", plec: " << sex << ", kod pocztowy: " << postal_code << "\n";
}

string Citizen::getSurname() const {
    return surname;
}

int Citizen::getAge() const {
    return age;
}

char Citizen::getSex() const {
    return sex;
}

string Citizen::getPostalCode() const {
    return postal_code;
}