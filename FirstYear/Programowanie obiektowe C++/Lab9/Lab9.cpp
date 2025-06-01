#include <iostream>
#include <memory>


using namespace std;

class ISound
{
public: 
    //pure virtual function
    virtual void makeSound() = 0; 
    //virtual - polimorfizm
    // = 0 funkcja czysto virtualna
    //Teraz class jest interfejsem
    virtual void noPureVirtualFunction ()
    {
        cout << "Hello from noPureVirtualFunction" << endl;
    }
};

class IMove
{
public:
    //pure virtual function
    virtual void makeMove() = 0;
};

class Cat : public ISound, public IMove // uruchamia proces dziedzicenia
{
public:
    virtual void makeSound()
    {
        cout << "Mrau Mrau" << endl;
    }
    virtual void makeMove()
    {
        //...
    }
};



int main()
{
    Cat cat;
    cat.noPureVirtualFunction();
    cat.makeSound();

    unique_ptr<IMove> ptr;
}

