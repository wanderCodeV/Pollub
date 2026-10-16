#include "Employee.h"

#include <iostream>

Employee::Employee() {
    surname = "";
    age = 0;
    experience = 0;
    salary = 0;
}

Employee::Employee(string surname, int age, int exp, int salary) :
    surname(surname), age(age), experience(exp), salary(salary) {}

void Employee::show() const {
    cout << "Surname: " << surname << endl;
    cout << "Age: " << age << endl;
    cout << "Experience: " << experience << endl;
    cout << "Salary: " << salary << endl;
}

int Employee::ageEmloyment() const {
    return age - experience;
}

int Employee::getAge() const {
    return age;
}

int Employee::getExperience() const {
    return experience;
}

int Employee::getSalary() const {
    return salary;
}

void Employee::setSalary(int newSalary) {
    salary = newSalary;
}
