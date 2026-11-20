#include "City.h"
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

City::City(string city_name) : city_name(city_name) {}

void City::addCitizen(const Citizen& c) {
    citizens.push_back(c);
}

void City::deleteCitizen(string surname, int age) {
    citizens.erase(remove_if(citizens.begin(), citizens.end(), [&](const Citizen& c) {
        return c.getSurname() == surname && c.getAge() == age;
    }), citizens.end());
}

void City::show_citizens() const {
    for(const auto& c : citizens)
        c.show();
}

void City::show_city() const {
    cout << "Miasto: " << city_name << "\n";
}

int City::women() const {
    return count_if(citizens.begin(), citizens.end(), [](const Citizen& c) {
        return c.getSex() == 'K' || c.getSex() == 'k';
    });
}

int City::city_citizens() const {
    return citizens.size();
}

int City::adults() const {
    return count_if(citizens.begin(), citizens.end(), [](const Citizen& c) {
        return c.getAge() >= 18;
    });
}

void City::postal_codes() const {
    vector<Citizen> sorted_citizens = citizens;
    sort(sorted_citizens.begin(), sorted_citizens.end(), [](const Citizen& a, const Citizen& b) {
        return a.getPostalCode() < b.getPostalCode();
    });
    auto it = sorted_citizens.begin();
    while (it != sorted_citizens.end()) {
        string code = it->getPostalCode();
        auto range = equal_range(it, sorted_citizens.end(), Citizen("", "", 0, ' ', code), [](const Citizen& a, const Citizen& b) {
            return a.getPostalCode() < b.getPostalCode();
        });
        int count = distance(range.first, range.second);
        cout << code << " -> " << count << " mieszkancow\n";
        it = range.second;
    }

    // map<string, int> stats;
    // for(const auto& c : citizens)
    //     stats[c.getPostalCode()]++;
    // for(const auto& pair : stats)
    //     cout << pair.first << " -> " << pair.second << " mieszkancow\n";
}