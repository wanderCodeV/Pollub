#ifndef LAB2_EMPLOYEE_H
#define LAB2_EMPLOYEE_H
#include <iostream>
using namespace std;

class Employee {
private:
    string surname;
    int age;
    int experience;
    int salary;
public:
    Employee();
    Employee(string surname, int age, int exp, int salary);
    virtual ~Employee() {};
    virtual void show() const;
    virtual int calculateSalary(int value) = 0; //czysto wirtualna metoda
    int ageEmloyment() const;

    int getAge() const;
    int getExperience() const;
    int getSalary() const;
    void setSalary(int newSalary);

};


#endif //LAB2_EMPLOYEE_H
