// 
// Kod napisany w Microsoft Visual Studio 2022 Community
//

// input output stream
// strumien wejscia wyjscia
#include <iostream> // Tutaj znajduje sie cout i cin

//#include - dyrektywa preprocesora oznaczajaca ,,wklej zawartosc pliku tutaj''.

// Typ std::string sluzy do przechowywania ciagow znakow (napisow)
#include <string>

// W C++ tablica o dynamicznym rozmiarze
// nazywa sie std::vector.
// Dziwna nazwa...
// Nie mylic z matematycznym obiektem
#include <vector> 

using namespace std;

// W C++ produktem koncowym jest plik o rozszerzeniu .exe
// Kompilator zawsze przeglada/czyta kod od gory do dolu
//
// Wyrozniamy trzy glowne etapy procesu generowania pliku .exe:
// 1. Faza preprocesora (np. zastosowanie dyrektyw #include)
// 2. Faza kompilacji -> kazdy plik .cpp jest przeksztalcany na plik .o lub .obj (object)
// 3. Faza linkowania -> wszystkie pliki .o/.obj laczone sa w jeden plik .exe

// Jak definiowac funkcje w C++
// TYP_ZWRACANY NAZWA (PARAMETRY)
// {
//
// }

// Wlasne funkcje definiujemy poza main()
float suma(float a, float b)
{
	// W tym miejscu zostanie 
	// zarezerwowany (zajety) obszar
	// 4 bajtow (32 bitow) (float = 32b)
	// w pamieci komputera (procesu)
	float wynik = a + b;
	// Zwracamy wartosc zapisana w 
	// obszarze pamieci o nazwie ,,wynik''
	return wynik;
}

// Podejscie do tworzenia obiektow w jezyku C
// vec3f to nowy typ zdefiniowany przez programiste, ktory
// zawiera trzy pola typu float o nazwie x,y,z.
struct vec3f
{
	float x;
	float y;
	float z;
};
// Jezeli zaistnieje potrzeba 
// odmiennych typow wartosci to nalezy
// utworzyc nowa strukture.
// Nazwy typow definiowanych przez programiste nie moga
// sie powtarzac, tak samo jak nazwy zmiennych.
struct vec3d
{
	double x;
	double y;
	double z;
};


// Struktura szablonowa < - Pozwala uproscic kod
// template - szablon
// typename - nazwa typu
// typename T - oznacza, ze literka ,,T'' to nazwa typu,
// poniewaz kompilator sam sie tego nie domysli.
// ,,T'' - moze byc dowolna inna nazwa
// np typename K
template <typename T>
struct vec3
{
	T x;
	T y;
	T z;
}; // Koniec struktury vec3 (srednik!!)


// Glowna funkcja kazdego programu w c++.
// Inaczej punkt wejscia programu.
// Moze byc tylko jedna funkcja main()
int main()
{
	float d = suma(4, 5);
	// Kazda funkcja z biblioteki standardowej
	// (biblioteki wbudowanej)
	// znajduje sie w katlogu std
	// dlatego piszemy std::cout
	// W C mamy printf
	printf("Wartosc = %.2f \n\n", d);
	// W C++ mamy cout z katalogu std
	std::cout << "Wartosc = " << d << std::endl;
	// cout - console output
	// endl - wstaw nowa linie

	// std::cout to obiekt klasy/typu ostream, ktory
	// ma przeladowany operator << (przesuniecie bitowe)

	// Zawsze nalezy okreslic typ zmiennej
	int x1 = 0;
	int x2 = 0;

	// Tablica (statyczna) 5 wartosci typu double
	// Tablica tego typu przez caly czas ma ten sam rozmiar,
	// ustalony podczas kompilacji
	// C++ indeksuje od 0!
	double tablica[5];
	

	// Petla for w C/C++
	// int i = 0 (zmienna bedaca indeksem) (startujemy od 0)
	// i < 5 (warunek wykonywnia petli)
	// i++ (co kazdy obrot petli indeks zwieksza sie o 1)
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Podaj liczbe numer " << i+1 << ": ";
		// W C++ indeksujemy od zera!!
		// cin - console input
		// cin wczytuje pojedyncza liczbe
		// std::cin to obiekt klasy/typu istream, ktory
		// ma przeladowany operator >> (przesuniecie bitowe)
		std::cin >> tablica[i];
	}

	100.0f; // <-- liczba typu float,  zajecie 4 bajtow
	100.0;  // <-- liczba typu double, zajecie 8 bajtow
	100;    // <-- liczba typu int,    zajecie 4 bajtow


	// Przyklad dotyczacy sposobu tworzenia obiektow
	// bedacych instancjami struktur/klas szablonowych.

	vec3<float>  q1;  // 3 * 4 = 12 bajtow
	vec3<double> q2;  // 3 * 8 = 24 bajty
	vec3<int>    q3;  // 3 * 4 = 12 bajtow

	// W C++ nazwy nie moga sie powtarzac. Kazda
	// zmienna,funkcja,struktura,klasa powinna miec inna nazwe.
	// v1 = [1 , -2, 0 ]
	vec3<float> v1;
	v1.x = 1;
	v1.y = -2;
	v1.z = 0;

	// ZADANIE 1:
	// Utwórz dwie zmienne typu vec3 
	// z konkretyzacja na typ float.
	// Nastepnie napisz program, ktory
	// pozwala pobrac od uzytkownika
	// wspolrzedne tych dwóch wektorow.
	// Nastepnie wyswietl drugi wprowadzony wektor
	// w formacie [ X, Y, Z ]

	vec3<float> w1;
	vec3<float> w2;
	
	cout << "------ ZADANIE 1 ------\n";
	cout << "Wektor " << 1 << "\n";
	cout << "Podaj wspol. X: ";
	cin >> w1.x;
	cout << "Podaj wspol. Y: ";
	cin >> w1.y;
	cout << "Podaj wspol. Z: ";
	cin >> w1.z;

	cout << "Wektor " << 2 << "\n";
	cout << "Podaj wspol. X: ";
	cin >> w2.x;
	cout << "Podaj wspol. Y: ";
	cin >> w2.y;
	cout << "Podaj wspol. Z: ";
	cin >> w2.z;

	std::cout << "[" << w2.x << "," << w2.y << "," << w2.z << "]\n";

	// Zadanie 2:
	// Utworz tablice statyczna, ktora przechowuje
	// trzy obiekty typu vec3<double>. Nastepnie
	// za pomoca petli for wczytaj
	// od uzytkownika 3 matematyczne
	// wektory. Nastepnie utworz
	// tablice dynamiczna i przekopiuj
	// wektory z tablicy statycznej
	// w odwrotej kolejnosci.
	// Wyswietl rozmiar tablicy dynm.

	cout << "------ ZADANIE 2 ------\n";
	vec3<double> tablicaStatyczna[3];
	// Instrukcja tablicaStatyczna[i] zwraca obiekt wektora.
	// Dokladnie to zwraca dostep do obiektu wektora przechowywanego
	// pod indeksem i.

	// Instrukcja tablicaStatyczna[i].x jest to odwolanie sie do
	// zmiennej o nazwie ,,x'' w zwroconym obiekcie wektora.
	for (int i = 0; i < 3; ++i)
	{
		cout << "Wektor " << i+1 << "\n";
		cout << "Podaj wspol. X: ";
		cin >> tablicaStatyczna[i].x;
		cout << "Podaj wspol. Y: ";
		cin >> tablicaStatyczna[i].y;
		cout << "Podaj wspol. Z: ";
		cin >> tablicaStatyczna[i].z;
	}

	std::vector<vec3<double>> tablicaDynamiczna;
	for (int i = 2; i >= 0; i--)
	{
		// Funkcja push_back dodaje element na koniec tablicy.
		// Jezeli rozmiar jest niewystarczajacy, to zostanie on
		// automatycznie zwiekszony. Inaczej zostanie zarezerwowany
		// wiekszy obszar pamieci.
		tablicaDynamiczna.push_back(tablicaStatyczna[i]);
		// W tym miejscu odbylo sie kopiowanie elementu do tablicaDynamiczna.
		// C++ zazwyczaj wykonuje operacje kopiowania
	}

	std::cout << "Rozmiar tablicy dynamicznej: " << tablicaDynamiczna.size() << "\n";

	// Aby okno aplikacji nie ulegalo natychmiastowemu zamknieciu
	system("PAUSE"); 
	return 0;
}