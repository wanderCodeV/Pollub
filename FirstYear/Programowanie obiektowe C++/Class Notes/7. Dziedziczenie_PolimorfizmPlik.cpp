#include <iostream>
#include <vector>
#include <memory> // dla std::unique_ptr


class Sword
{
public:
	Sword()
	{
		std::cout << "Konstruktur klasy Sword\n";
	}	
	~Sword()
	{
		std::cout << "Destruktur klasy Sword\n";
	}
};

class Liczba
{
	// public - dostepne dla kazdego
public:
	int publ = 5;
	// protected - dostepne dla klasy i dla klas dziedziczacych
	// (dla mnie i dla rodziny)
protected:
	int prot = 8;
	// private - dostepne wylacznie dla tej klasy
	// (tylko dla mnie)
private:
	int priv = -2;
};

// Skladnia umozliwiajaca dziedziczenie : [typ dziedziczenia] [nazwa klasy]
// typ dziedziczenia:
// ***public:
// public    -> public
// protected -> protected
// privte    -> private (ale i tak nie ma dostepu w klasie dziedziczacej)
//
// ***protected:
// public    -> protected
// protected -> protected
// privte    -> private (ale i tak nie ma dostepu w klasie dziedziczacej)
//
// ***private:
// public    -> private
// protected -> private
// privte    -> private (ale i tak nie ma dostepu w klasie dziedziczacej)
class LiczbaZespolona : public Liczba
{
public:

protected:

private:

};

class LiczbaZespolonaPriv : private Liczba
{
public:

protected:

private:

};

// Uwaga! Polimorfizm dziala tylko wtedy gdy sygnatury funkcji w klasie
// bazowej i w klasie pochodnej sa identyczne (nawet const ma znaczenie).
class Animal
{
public:
	// Polimorfizm dotyczy wywolan funkcji. Aby aktywowac polimorfizm
	// dla danej funkcji nalezy dodac slowo kluczowe ,,virtual'' na poczatku
	// deklaracji.
	virtual void Voice()const
	{
		// usun const i zobacz efekt!
		std::cout << " -------- \n";
	}
};

class Dog : public Animal
{
public:
	// Slowo kluczowe ,,override'' wymusza sprawdzenie, czy sygnatura danej
	// funkcji zgadza sie z sygnatura funkcji z klasy nadrzednej, czyli
	// czy zachodzi polimorfizm. Slowo ,,override'' nie jest wymagane, ale
	// zwieksza szanse na wylapanie bledu.
	void Voice()const override
	{
		std::cout << "HauHau\n";
	}
};

class Cat : public Animal
{
public:
	// Slowo kluczowe ,,override'' wymusza sprawdzenie, czy sygnatura danej
    // funkcji zgadza sie z sygnatura funkcji z klasy nadrzednej, czyli
    // czy zachodzi polimorfizm. Slowo ,,override'' nie jest wymagane, ale
    // zwieksza szanse na wylapanie bledu.
	void Voice()const override
	{
		std::cout << "MrauMrau\n";
	}
};

class Cow : public Animal
{
public:
	// Slowo kluczowe ,,override'' wymusza sprawdzenie, czy sygnatura danej
    // funkcji zgadza sie z sygnatura funkcji z klasy nadrzednej, czyli
    // czy zachodzi polimorfizm. Slowo ,,override'' nie jest wymagane, ale
    // zwieksza szanse na wylapanie bledu.
	void Voice()const override
	{
		std::cout << "Muuuuuu\n";
	}
};
int main()
{
	Liczba liczba;
	// .prot jest w sekcji protected, wiec nie jest w tym miejscu dostepne.
	//liczba.prot;

	LiczbaZespolona liczba_z;
	liczba_z.publ;

	LiczbaZespolonaPriv liczba_zp;
	// .publ jest w sekcji private z powodu typu dziedziczenia (private).
	//liczba_zp.publ;

	Dog dog1;
	Dog dog2;
	Dog dog3;

	Cat cat1;
	Cat cat2;
	Cat cat3;

	Cow cow1;
	Cow cow2;
	Cow cow3;

	dog1.Voice();
	dog2.Voice();
	cat1.Voice();
	cow3.Voice();

	std::vector<Dog> dogs;
	std::vector<Cat> cats;
	std::vector<Cow> cows;
	for (int i = 0; i < 10; i++)
	{
		dogs.push_back(Dog());
		cats.push_back(Cat{});
		cows.push_back(Cow{});
	}

	// Petla - zakresowe for
	// Petla po wszystkich elementach kontenera/tablicy.
	for (auto& d : dogs)
	{
		d.Voice();
	}

	// Polimorfizm dziala w oparciu o wskaznik na klase bazowa.
	std::vector<Animal*> zoo;
	zoo.push_back(&dog1);
	zoo.push_back(&cat1);
	zoo.push_back(&cow1);

	for (auto& i : zoo)
	{
		// Jezeli mamy wskaznik na obiekt to stosujemy -> (strzalka) zamiast . (kropka).
		i->Voice();
	}



	{
		//A* ptr_a = new A();
		//delete ptr_a;

		// std::unique_ptr to inteligentny wskaznik.
		// Gdy tworzymy obiekt std::unique_ptr podejmy mu obszar pamieci
		// do zarzadania.
		// Gdy std::unique_ptr jest usuwany (np. wyjscie z zakresu, koniec funkcji)
		// std::unique_ptr usuwa/zwalnia zarzadzany obszar pamieci.
		std::unique_ptr<Sword> inteli_ptr_a(new Sword());
	}
	std::cout << "Hello!\n";

	std::vector<std::unique_ptr<Animal>> better_zoo;
	better_zoo.emplace_back(new Dog{});
	better_zoo.emplace_back(new Cat{});
	better_zoo.emplace_back(new Cow{});
	better_zoo.emplace_back(new Cat{});

	for (const auto& animal : better_zoo)
	{
		animal->Voice();
	}
}    