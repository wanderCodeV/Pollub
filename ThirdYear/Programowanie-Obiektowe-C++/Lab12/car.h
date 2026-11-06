#ifndef LAB12_CAR_H
#define LAB12_CAR_H
#include <iostream>

using std::string;

class Car {
private:
    string model;
    int year;
    float capacity;
public:
    Car();
    Car(string model, int year, float capacity);

    string get_model() const;
    int get_year() const;
    float get_capacity() const;

    void set_model(string model);
    void set_year(int year);
    void set_capacity(float capacity);

    void show_info() const;
};

#endif //LAB12_CAR_H
