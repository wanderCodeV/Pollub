//
// Kod napisany w MS Visual Studio 2022
// C++20


#include <iostream>


template<typename T>
struct vec3
{
	// Konstruktor:
	// Funkcja, ktora automatycznie uruchamia sie
	// ,,po'' utworzeniu zmiennej/obiektu.
	// Konstruktor to funkcja nazywajaca sie identycznie
	// jak nazwa klasy/struktury. Ponadto konstruktor
	// nie zwraca niczego, ale moze przyjmowac dowolne
	// parametry.
	// Ponizszy konstruktor (dekorator), dla nowopowstalych
	// obiektow, ustawia wszystkie pola/zmienne na wartosc 0
	vec3() : x(0), y(0), z(0)
	{
		// Skladnia : x(0), y(0), z(0) oznacza liste
		// inicjalizacyjna. Instrukcje zawarte w liscie
		// inicjalizacyjnej sa wykonywane PODCZAS tworzenia
		// obiektu. Natomiast cialo konstruktora (zawartosc miedzy{})
		// jest wykonywane PO utworzeniu obiektu.
		// Jezeli obiekt zawiera pola stale (const), to jedyny
		// sposob inicjalizacji takiej skladowej jest poprzez
		// liste inicjalizacyjna.
		//x = 0;
		//y = 0;
		//z = 0;
	}
	
	// Konstruktor przyjmujacy 3 parametry
	vec3(T xx, T yy, T zz)
	{
		// Przypisz do skladowej struktury wartosc
		// przekazanego argumentu.
		x = xx;
		y = yy;
		z = zz;
	}

	// Klasy/struktury moga rowniez zawierac funkcje, zwane
	// metodami lub funkcjami skladowymi.
	// Funkcje skladowe tworzy sie jak zwykle funkcje.
	// norm to funkcja normalizujaca wektor, ktora zmienia
	// wektor w wektor o dlugosci 1.
	void norm()
	{
		float l = sqrt(x * x + y * y + z * z);
		
		if (l != 0)
		{
			x = x / l;
			y = y / l;
			z = z / l;
		}
		
	}

	// Pola/zmienne skladowe
	T x;
	T y;
	T z;
};

// ZADANIE 1:
// Funkcja obliczajaca iloczyn skalarny.
// Poniewaz vec3 jest struktura szablonowa, to
// najlepiej funkcje dot rowniez uczynic szablonem.
// C++ domyslnie przesyla argumenty funkcji do funkcji
// poprzez proces kopiowania. Kopiowanie zuzywa cykle procesora.
// Stad C++ umozliwa przekazanie argumentow poprzez referencje, czyli
// przekazanie oryginalnej wartosci.
// Symbol & oznacza przekazanie oryginalu. Ale!
// Funkcja dot nie powinna modyfikowac zadnego ze swoich
// parametrow. Dot oblicza iloczyn skalarny, a do tego nie jest
// potrzebna modyfikacja parametrow.
// Zatem, zgodnie z zasadami pisania czystego kodu, nalezy
// dodac slowo kluczone ,,const'', ktore oznacza, ze dana
// zmienna/obiekt/referencja jest stala. Kompilator bedzie pilnowa
// tej stalosci i nie dopusci do zmodyfikowania zawartosci
// zmiennej/obiektu/referencji.
template<typename T>
float dot(const vec3<T>& lhs, 
	      const vec3<T>& rhs)
{
	return (lhs.x * rhs.x +
		    lhs.y * rhs.y +
		    lhs.z * rhs.z);
}

// ZADANIE 1:
// Napisz funkcje o nazwie ,,dot'',
// ktora oblicza iloczyn sklarny
// miedzy dwoma wektorami 3D.
// W tym celu utworz strukture
// szablonowa vec3.
// Przetestuj dzialanie funkcji
// dla wektorow [1,1,1], [4,5,-1]

// ZADANIE 2:
// Napisz funkcje szablonowa
// o nazwie ,,cross'',
// ktora oblicza iloczyn wektorowy
// miedzy dwoma wektorami 3D.
// Przetestuj dzialanie funkcji
// dla wektorow [1,1,1], [4,5,-1]

// To samo co w przypadku ,,dot''. Przy czym
// iloczyn wektorowy zwraca wektor, a iloczyn skalarny
// zwraca liczbe.
template<typename T>
vec3<T> cross(const vec3<T>& lhs,
	          const vec3<T>& rhs)
{
	vec3<T> v;
	v.x = lhs.y * rhs.z - lhs.z * rhs.y;
	v.y = lhs.z * rhs.x - lhs.x * rhs.z;
	v.z = lhs.x * rhs.y - lhs.y * rhs.z;
	return v;
}

int main()
{
	// Dzieki konstruktorowi przyjmujacemu
	// trzy parametry zamiast
	// vec3<float> v1;
	//v1.x = 1;
	//v1.y = 1;
	//v1.z = 1;
	// mozna napisac
	vec3<float> v1{1,1,1};
	
	// Wywolanie funkcji skladowej norm, na obiekcie
	// v1. Zwroc uwage na skladnie z kropka. Zawsze, gdy
	// chcemy odniesc sie do czegos w obiekcie uzywamy
	// kropki.
	v1.norm(); 
	// kompilator zamienia na _fs3wgs2norm(v1)

	vec3<float> v2;
	v2.x =  5;
	v2.y =  4;
	v2.z = -1;

	std::cout << "Zadanie 1\n";
	std::cout << "Iloczyn skalarny: " << dot(v1, v2) << "\n";

	std::cout << "Zadanie 2\n";
	// Nasz program jest w stanie wyswietlic tylko
	// typy wbudowane (int, float, string itd..).
	// Typu vec3 program nie potrafi wyswietlic, musimy
	// go nauczyc; musimy pokazac naszemu kompilatorowi
	// jak nalezy wyswietlac typ vec3.
	//std::cout << "Iloczyn wektorowy: " << cross(v1, v2) << "\n";

}









