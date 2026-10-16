#include "TeamLeader.h"

TeamLeader::TeamLeader() : Employee() {}

TeamLeader::TeamLeader(string surname, int age, int exp, int salary):
    Employee(surname, age, exp, salary) {}

int TeamLeader::calculateSalary(int value) {
    return value*(1 + getAge() + getExperience());
}

void TeamLeader::show() const {
    Employee::show();
    cout << "Jestem Team Leader z " << getExperience() << " letnim doswiadczeniem"<< endl;
}


