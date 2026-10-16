#include "Developer.h"

Developer::Developer() : Employee() {}

Developer::Developer(string surname, int age, int exp, int salary)
    : Employee(surname, age, exp, salary) {}

int Developer::calculateSalary(int value) {
    return value+0.2*value*(getAge() + getExperience());
}
