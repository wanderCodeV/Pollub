#ifndef CITIZEN_H
#define CITIZEN_H
#include <string>
using namespace std;

class Citizen {
private:
    string name;
    string surname;
    int age;
    char sex;
    string postal_code;
public:
    Citizen();
    Citizen(string name, string surname, int age, char sex, string postal_code);
    void show() const;
    string getSurname() const;
    int getAge() const;
    char getSex() const;
    string getPostalCode() const;
};
#endif