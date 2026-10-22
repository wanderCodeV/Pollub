#include <iostream>

#include "Employee.h"
#include "Developer.h"
#include "TeamLeader.h"

using namespace std;

void whoWorkMoreThan5Years (Employee** emp, int cnt) {
    cout << "Pracownicy pracujacy wiecej niz 5 lat " << endl;
    for (int i = 0; i < cnt; ++i) {
        if (emp[i]->getExperience() > 5) {

            cout << "=================\n";
            emp[i]->show();
        }
    }
}

int howManyEarnLessThanMean(Employee** emp, int size) {
    if (size == 0) return 0;

    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += emp[i]->getSalary();
    }

    double mean = sum / size;
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (emp[i]->getSalary() < mean) {
            count++;
        }
    }
    return count;
}

int main() {

    int cnt_emp = 4;
    Employee** team = new Employee*[cnt_emp];

    team[0] = new Developer("Kowalski", 25, 2);
    team[1] = new Developer("Nowak", 35, 10);
    team[2] = new TeamLeader("Zielinski", 45, 15);
    team[3] = new Developer("Kaminski", 28, 6);

    cout << "=== Wyliczenia i informacje o pracownikach ===" << endl;
    for (int i = 0; i < cnt_emp; ++i) {
        int calculated = team[i]->calculateSalary(1000);
        team[i]->setSalary(calculated);
    }

    whoWorkMoreThan5Years(team, cnt_emp);
    cout << "\nLiczba pracownikow zarabiajacych ponizej sredniej = " << howManyEarnLessThanMean(team, cnt_emp);
    for (int i = 0; i < cnt_emp; ++i) {
        delete team[i];
    }
    delete[] team;

    return 0;
}