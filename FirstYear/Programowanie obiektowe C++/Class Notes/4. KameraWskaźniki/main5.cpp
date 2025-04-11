//
// Kod napisany w MS Visual Studio 2022
// C++20

#include <iostream>
#include "Kamera.h"

// GLFWwindow to typ niekompletny, poniewaz
// zostal zadeklarowany (kompilator rozumie co oznacza
// nazwa GLFWwindow), ale nie zostal zdefiniowany (brak
// tresci/ciala klasy). Nie jest mozliwe tworzenie obiektow
// typow niekompletnych, ale wskaznik mozna utworzyc.
class GLFWwindow;

struct vec2
{
	float x;
	float y;
};

int main()
{
	// Wskaznik to obiekt, ktory przechowuje
	// adres komorki pamieci. Moze byc to rowniez
	// poczatek obszaru pamieci, gdzie jest zapisany
	// duzy obiekt.
	// Adres pamieci to liczba, dlatego kazdy wskaznik
	// (bez znaczenia na co wskazuje)
	// ma rozmiar 4 bajtow (jak typ int).
	
	// wsk to wskaznik, ktory pozwala wskazac obszar pamieci,
	// gdzie zapisana jest liczba typu int. Inaczej,
	// ciag bitow wskazywany przez wsk jest interpretowany
	// jako liczba typu int.
	int* wsk = nullptr;
  
	// nullptr - specjalna wartosc do inicjalizacji
	// wskaznikow, ktore nie wskazuja niczego.

	// wsk2 to wskaznik, ktory pozwala wskazac obszar
	// pamieci, gdzie zapisana jest obiekt typu vec3.
	vec2* wsk2 = nullptr;

	int liczbaA = 7;
	// wsk to wskaznik wskazujacy obszar STALY/NIEZMIENNY.
	const int* wsk_na_staly_obszar = nullptr;
	wsk_na_staly_obszar = &liczbaA;
	// Blad!
	// wsk_na_staly_obszar = 88;

	int liczbaB = 7;
	// wsk to staly wskaznik. Nie mozna go przesuwac!
	int* const staly_wsk = &liczbaB;
	// Blad!
	// staly_wsk = &liczbaA;
	
	vec2 v;
	v.x = 4;
	v.y = 2;

	// & w tym kontekscie oznacza pobranie adresu.
	wsk2 = &v;

	// Wyswietlenie zawartosci wskaznika, czyli
	// wyswietlenie adresu zmiennej v.
	std::cout << wsk2 << std::endl;

	int a = 5;
	int b = 7;

	wsk = &a;
	std::cout << wsk << std::endl;
	// Przesuniecie wskaznika / Zmiana miejsca, ktore
	// jest wskazywane
	wsk = &b;
	std::cout << wsk << std::endl;
	// U mnie jest tak:
	// 00000080AE4FF634
	// 00000080AE4FF654
	// Adresy roznia sie o 32, czyli
	// miedzy zmienna a i b jest odstep o wielkosci
	// 32 bitow.

	// Referencja to przezwisko.
	int& moja_referencja = a;
	// Od teraz do zawartosci zmiennej ,,a'' mozna 
	// odwolywac sie poprzez nazwe moja_referencja.
	moja_referencja = 79;
	// Referencji nie mozna przesuwac.

	std::cout << a << std::endl;


	MOJA_WLASNA_PRZESTRZEN_NAZW::vec3 moj_wektor(4, 2, 0);
	moj_wektor.normalize();

	// {} oznaczaja lokalny blok kodu
	{
		int jestem_tylko_tutaj = 5;
		GLFWwindow* okno = nullptr;
		Kamera moja_kamera(okno);

	}// W tym miejscu wszystkie zmienne zadeklarowane pomiedzy
	// {} sa usuwane! Dotyczy to funkcji, petli i innych konstrukcji,
	// ktore zawieraja {}

	// Blad
	// jestem_tylko_tutaj = 7;
	std::cout << "Koniec programu\n";
}