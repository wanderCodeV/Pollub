#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class A {
public:
    A()
    {
        cout << "konstruktor A\n";
    }
    ~A()
    {
        cout << "destruktor A\n";
    }
};
class Animal
{
public:
    virtual void voice()
    {
        cout << " -------- \n";
    }
};
class Dog: public Animal
{
public:
    void voice()
    {
        cout << "HauHau\n";
    }
};
class Cow : public Animal
{
public:
    void voice()
    {
        cout << "Muuuuu\n";
    }
};
class Cat : public Animal
{
public:
    void voice()
    {
        cout << "MrauMrau\n";
    }
};
int main()
{
    vector<Dog> vec_dogs;
    vector<Cat> vec_cats;
    vector<Cow> vec_cows;

    for (int i = 0; i < 10; i++)
    {
        vec_dogs.push_back(Dog());
        vec_cats.push_back(Cat());
        vec_cows.push_back(Cow());
    }

    Dog dog;
    Cow cow;
    Cat cat;
    vector<Animal*> zoo;
    zoo.push_back(&dog);
    zoo.push_back(&cat);
    zoo.push_back(&cow);
    for (auto& obj: zoo)
    {
        obj->voice();
    }

    {
        /* można zamienić za pomocą zasobów std w memory
        A* ptrA = new A();
        delete ptrA;*/

        unique_ptr<A> nowy_ptrA( new A() );
        unique_ptr<A> nowy_ptrA2{ new A() };
    }

    vector<unique_ptr<Animal>> betterZoo;
    betterZoo.emplace_back(new Dog());
    betterZoo.emplace_back(new Cat());
    betterZoo.emplace_back(new Cow());
    betterZoo.emplace_back(new Dog());
    betterZoo.emplace_back(new Cat());

    for (auto& i : betterZoo)
    {
        i->voice();
    }

}
