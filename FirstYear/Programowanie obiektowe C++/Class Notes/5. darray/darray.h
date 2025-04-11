#pragma once

//
// Kod napisany w MS Visual Studio 2022
// C++20


// Implementacja funkcji skladowych klasy szablonowej musi
// znajdowac sie w pliku .h, albo wewnatrz klasy.

// Dla klas szablonowych nie ma potrzeby generowania plikow .cpp

// Poniewa funkcja some_function przyjmuje obiekt
// klasy darray oraz jest zadeklarowana przed klasa darray,
// to nalezy okreslic wczesniej czym jest darray.
// Odbywa sie to poprzez typ niekompletny, czyli
// sama deklaracja bez ciala klasy. Teraz kompilator rozumie
// czy jest nazwa darray.
template <typename T>
class darray;

// darray to szablon, stad some_function tez musi byc szablonem
template <typename T>
int some_function(darray<T> array)
{
	return array.elements;
}



template <typename T>
class darray
{
public:
	darray(int numElem);

    // Funkcje skladowe mozna implementowac wewnatrz klasy.
	// Konstruktor/Destruktor to rowniez funkcje skladowe.
	darray()
	{
		data = nullptr;
		size = 0;
		capacity = 0;
		elements = 0;
	}

	// Destruktor - funkcja, ktora jest wywolywana automatycznie
	// podczas usuwania obiektu.
	~darray()
	{
		if (data != nullptr)
		{
		   delete[] data;
		}
	}
	void push_back(T element);

	// Dodanie const oznacza, ze funkcja nie modyfikuje
	// obiektu, czyli nie modyfikuje zadnej zmiennej skladowej.
	int numElements()const
	{
		// Blad kompilacji
		//elements++;
		return elements;
	}

	// Slowo kluczowe friend oznacza, ze dana funkcja lub
	// klasa ma dostep do pol/zmiennych prywatnych.
	// Klasa darray deklaruje przyjazn z funkcja some_function.
	// Zatem w ciele funkcji some_function mozemy odwolywac sie
	// do pol prywatnych klasy darray.
	template <typename K>
	friend void some_function(darray<K> array);

	// darray to szablonowa klasa, dlatego some_function to funkcja szablonowa,
	// dlatego powyzej mamy zapis z wykorzystaniem template (gdzie litera T jest juz zajeta).

private:
	T* data;
	int elements; // Aktualna liczba elementow
	int size;     // Maksymalna liczba elementow
	int capacity; // Rozmiar w bajtach
};




template <typename T>
darray<T>::darray(int numElem)
{
	data = new T[numElem];
	elements = 0;
	size = numElem;
	// sizeof zwraca rozmiar w bajtach
	// argumentem jest nazwa typu
	sizeof(int); // zwraca 4
	sizeof(float); // zwraca 4
	sizeof(double); // zwraca 8
	sizeof(darray<float>); 
	capacity = numElem * sizeof(T);
}

template <typename T>
void darray<T>::push_back(T element)
{
	// Jezeli liczba elementow w tablicy jest mniejsza
	// od maksymalnej liczby elementow w tablicy.
	if (elements < size)
	{
		// indeksujemy od 0
		data[elements] = element;
		elements++;
	}
	else
	{
		if (size == 0)
			size = 15;
		else
			size = size * 2;

		// Allokujemy nowy wiekszy obszar pamieci (dwa razy wiekszy)
		T* newData = new T[size];

		// Zwykle kopiowanie danych
		for (int i = 0; i < elements; i++)
		{
			newData[i] = data[i];
		}

		// Dodanie nowego elementu do tablicy (teraz mamy miejsce)
		newData[elements] = element;
		elements++;

		// Zwalniamy stary (za maly) obszar pamieci
		delete[] data;
		// Dostep do obszaru pamieci, gdzie zapisane sa dane, odbywa sie
		// zawsze poprzez wskaznik data.
		data = newData;

		capacity = size * sizeof(T);
	}
}



