#ifndef LAB2_TEAMLEADER_H
#define LAB2_TEAMLEADER_H
#include "Employee.h"


class TeamLeader : public Employee {
public:
    TeamLeader();
    TeamLeader(string surname, int age, int exp, int salary = -1);
    int calculateSalary(int value) override;
    void show() const override;
};


#endif //LAB2_TEAMLEADER_H
