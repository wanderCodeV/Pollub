#ifndef CITY_H
#define CITY_H
#include "Citizen.h"
#include <vector>
#include <string>
using namespace std;

class City {
private:
    vector<Citizen> citizens;
    string city_name;
public:
    City(string city_name);
    void addCitizen(const Citizen& c);
    void deleteCitizen(string surname, int age);
    void show_citizens() const;
    void show_city() const;
    int women() const;
    int city_citizens() const;
    int adults() const;
    void postal_codes() const;
};
#endif