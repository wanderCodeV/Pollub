#include <iostream>
#include "City.h"
using namespace std;

int main() {
    City c("Lublin");
    
    c.addCitizen(Citizen("Anna", "Kowalska", 25, 'K', "20-389"));
    c.addCitizen(Citizen("Jan", "Nowak", 17, 'M', "20-389"));
    c.addCitizen(Citizen("Piotr", "Ziele", 40, 'M', "30-678"));
    
    c.show_city();
    c.show_citizens();
    
    cout << "Kobiety: " << c.women() << "\n";
    cout << "Pelnoletni: " << c.adults() << "\n";
    cout << "Wszyscy mieszkancy: " << c.city_citizens() << "\n";
    
    cout << "\nStatystyka kodow pocztowych:\n";
    c.postal_codes();
    
    cout << "\nUsuwanie Jana Nowaka (17 lat)\n";
    c.deleteCitizen("Nowak", 17);
    c.show_citizens();
    
    return 0;
}