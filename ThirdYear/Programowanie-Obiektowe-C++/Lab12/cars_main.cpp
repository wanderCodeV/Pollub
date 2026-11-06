#include <algorithm>
#include <vector>

#include "car.h"

using namespace std;
int main() {

    auto show = [](const vector<Car>& cars) {
        int cnt = 1;
        for_each(cars.begin(), cars.end(),
        [&cnt](Car elem) {
            cout << cnt++ << ".";
            elem.show_info();
        });
        cout << endl;
    };

    vector<Car> cars = {
        Car("Toyota Auris", 2016, 1.8),
        Car("Hyundai i20", 2019, 1.2),
        Car("Skoda Fabia", 2014, 1.0),
        Car("Volkswagen Golf", 2021, 2.0)
    };


    sort(cars.begin(), cars.end(),
        [](Car elem1, Car elem2) {
            return elem1.get_year() < elem2.get_year();
        });
    cout << "Po sortowaniu po roku produkcji:\n";
    show(cars);

    sort(cars.begin(), cars.end(),
        [](Car elem1, Car elem2) {
            return elem1.get_capacity() > elem2.get_capacity();
        });
    cout << "Po sortowaniu wzgledem pojemnosci silnika:\n";
    show(cars);
}