#include <iostream>
#include <vector>
#include <memory> // dla std::unique_ptr

// ISound to interfejs, poniewaz posiada przynajmniej
// jedna funkcje czysto wirtualna (pure virtual function).
// Nie mozna tworzyc obiektow klas, ktore sa interfejsami.
class ISound
{
public:
	// pure virtual function
	virtual void makeSound() = 0;

	// Interfejs jest w pewnym sensie kontraktem, umowa.
	// Kazda zwyczajna klasa, ktora dziedziczy po ISound jest zobowiazana
	// dostarczyc implementacje funkcji makeSound().

	// Klasa bedaca interfejsem moze rowniez zawierac rowniez zwykle funkcje.
	virtual void noPureVirtualFunction()
	{
		std::cout << "Hello from noPureVirtualFunction\n";
	}

	int regularFunction(int param)
	{
		return param * 2;
	}
};

class IMove
{
public:
	// pure virtual function
	virtual void makeMove() = 0;
};

// Klasa Cat implementuje interfejsy: ISound, IMove. 
// W przypadku interfejsow mowimy, ze klasa IMPLEMENTUJE interfejs, 
// zamiast DZIEDZICZY po interfejsie.

// Interfejsy informuja o konkretnych cechach danej klasy.
// Na podstawie ponizszej lini kodu, mozna wywnioskowac, ze obiekty
// typu Cat sa w stanie wydawac dzwiek oraz sa zdolne do przesuwania.
class Cat : public ISound, public IMove
{
public:
	// Klasa Cat musi implementowac funkcje czysto wirtualne, pochodzace
	// z interfejsow. Inaczej kod nie skompiluje sie.
	virtual void makeSound()
	{
		std::cout << "Mrau Mrau\n";
	}
	virtual void makeMove()
	{

	}
};

class Dog : public ISound, public IMove
{
public:
	virtual void makeSound()
	{
		std::cout << "Hau Hau\n";
	}
	virtual void makeMove()
	{

	}
};

class Sword
{
public:
	Sword(int _id, std::string _name, int _dmg, int _price)
	{
		id = _id;
		name = _name;
		dmg = _dmg;
		price = _price;
	}
private:
	int id;
	std::string name;
	int dmg;
	int price;
};

int main()
{
	Cat cat;
	cat.noPureVirtualFunction();
	cat.makeSound();

	std::vector<std::unique_ptr<ISound>> soundables;
	soundables.emplace_back(new Cat{});
	soundables.emplace_back(new Cat);
	soundables.emplace_back(new Dog);

	// emplace_back dziala bardzo podobnie do push_back.
	// Obie funkcje dodaja element na koncu tablicy, tylko
	// push_back oczekuje, ze przekazemy, jako argument, obiekt.
	// Przekazany obiekt nastepnie jest kopiowany na koniec tablicy.

	// emplace_back konstruuje obiekt na koncu tablicy. Do emplace_back
	// przekazujemy wartosci parametrow konstruktora obiektu, ktory ma
	// zostac dodany.

	std::vector<Sword> swords;
	swords.emplace_back(2, "full moon sword", 35, 10000);
	swords.emplace_back(5, "red iron blade", 33,  9900);

	Sword s1{ 4, "poison sword", 87, 60764 };
	swords.push_back(s1);


	for (auto& o : soundables)
	{
		o->makeSound();
		o->noPureVirtualFunction();
	}
}

