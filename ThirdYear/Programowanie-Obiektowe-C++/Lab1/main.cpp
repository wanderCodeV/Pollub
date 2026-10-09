#include <iostream>
#include "Person.h"
#include "Teacher.h"
#include "Student.h"
#include <vector>
using namespace std;

int main() {
    /*cout << endl << "Obiekty klasy Person" << endl;
    Person o1("Grazyna", "Nowak", 45);
    o1.showInfoPerson();
    cout << "Czy pelnoletnia?: " << o1.is_18() << endl;
    o1.setAge(16);
    cout << endl << "Obiekty klasy Teacher" << endl;
    Teacher n1("Barbara", "Kowalska", 56, 30, "Phd");
    n1.showInfoTeacher();
    cout << "Czy ma Phd?: " << n1.is_Phd() << endl;
    n1.setAge(34);

    Person p1[3];
    Person *p2;
    Person *p3[3];
    Person **p4;
    for (int i = 0; i < 3; i++) {
        p1[i].init("Anna", "Nowak", 20 + i);
        p1[i].showInfoPerson();
    }
    p2 = new Person[3];
    for (int i = 0; i < 3; i++) {
        p2[i].init("Ola", "Adamek", 20 + i);
        p2[i].showInfoPerson();
    }
    for (int i = 0; i < 3; i++) {
        p3[i] = new Person("Kasia", "Kowalska", 20 + i);
        p3[i]->showInfoPerson();
    }
    p4 = new Person *[3];
    for (int i = 0; i < 3; i++) {
        p4[i] = new Person("Pawel", "Wojcik", 20 + i);
        p4[i]->showInfoPerson();
    }
    for (int i = 0; i < 3; i++) {
        delete p3[i];
    }
    for (int i = 0; i < 3; i++) {
        delete p4[i];
    }
    delete [] p4;

    Student s1[3]; //statyczną tablicę statycznych obiektów klasy Student
    Student *s2; // dynamiczną tablicę statycznych
    Student *s3[3]; //statyczną tablicę dynamicznych
    Student **s4; //dynamiczną tablicę dynamicznych

    for (int i = 0; i < 3; i++) {
        s1[i].init("Sofia", "Gra", 20 + i);
        s1[i].setIndex("10407" + to_string(i));
        s1[i].showInfoStudent();
    }
    s2 = new Student[3];
    for (int i = 0; i < 3; i++) {
        s2[i].init("Olena", "Zaiats", 18 + i);
        s2[i].setIndex("10501" + to_string(i));
        s2[i].showInfoStudent();
    }
    for (int i = 0; i < 3; i++) {
        s3[i]->init("Mariia", "Nyzhnyk", 20 + i);
        s3[i]->setIndex("10325" + to_string(i));
        s3[i]->showInfoStudent();
    }
    s4 = new Student *[3];
    for (int i = 0; i < 3; i++) {
        s4[i]->init("Gabriel", "Wojcik", 20 + i);
        s4[i]->setIndex("8575" + to_string(i));
        s4[i]->showInfoStudent();
    }
    for (int i = 0; i < 3; i++) {
        delete p3[i];
    }
    for (int i = 0; i < 3; i++) {
        delete p4[i];
    }
    delete [] p4;*/

    //tablica ktora pokaze dzialanie polimorfizma
    std::vector<Person *> poli;
    poli.push_back(new Student("Mariia", "Grazyna", 20, "909090"));
    poli.push_back(new Person("Mariia2", "Grazyna1", 21));
    poli.push_back(new Teacher("Mariia2", "Grazyna2", 21, 8, "magister"));

    for (auto obj: poli) {
        cout << "Objekt: ";
        obj->show();
        cout << endl;
    }
    return 0;
}
