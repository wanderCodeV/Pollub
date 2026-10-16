#ifndef LAB2_DEVELOPER_H
#define LAB2_DEVELOPER_H
#include "Employee.h"


class Developer : public Employee {
public:
    Developer();
    Developer(string surname, int age, int exp, int salary = -1);
    int calculateSalary(int value) override;
};


#endif //LAB2_DEVELOPER_H
