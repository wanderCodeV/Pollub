//
// Kod napisany w MS Visual Studio 2022
// C++20


#include <iostream>
#include "darray.h"

struct vec3
{
	vec3()
	{
		x = y = z = 0;
	}
	vec3(float xx, float yy, float zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}
	float x;
	float y;
	float z;
};

int main()
{
	vec3 wektor;
	int liczba = 5;
	// Powyzsze zmienne (wektor, liczba) sa umieszczone
	// na stosie (obszar pamieci). Zarzadzanie cyklem
	// zycia obiektow na stosie jest realizowane
	// automatycznie przez program.

	// Przyklad dynamicznej alokacji pamieci.
	// Wartosc 7 zostanie umieszczona w komorce pamieci
	// nalezacej do obszaru pamieci o dostepie swobodnym 
	// (RAM - random access memory).
	int* nazwa = new int(7);
	// Jezeli zostal zarezerwowany obszar pamieci na stercie
	// zawsze nalezy dokonac zwolnienia tego obszaru.
	// W innym wypadku wystapi: memory leak (wyciek pamieci),
	// czyli pewien obszar pamieci bedzie niedostepny, az
	// do wylaczenia komputera (moment czyszczeni pamieci typu RAM)
	delete nazwa;
	
	// operator new zwraca adres pamieci, dlatego
	// po lewej stronie = mamy zawsze wskaznik
	vec3* wsk = new vec3;
	delete wsk;

	// Rezerwacja obszaru pamieci, ktory pomiesci
	// 7 liczb typu int
	int* tablica = new int[7];
	// tablica to wskaznik na pierwszy element / na
	// poczatek obszaru pamieci.

	tablica[0] = -15;

	// Mozemy poslugiwac sie notacja []
	tablica[1] = 34;
	// albo korzystac z arytmetyki wskaznikowej.
	// Przesun wskaznik na adres komorki pamieci tuz obok,
	// nastepnie przejdz w to miejsce (operator *)
	*(tablica + 1) = 34;
	
	// Zwroc uwage, ze tablice usuwamy (zwalniamy)
	// innym operatorem niz pojedyncze zmienne
	delete[] tablica;

	// Moja dynamiczna tablica
	darray<float> tablicaDynamiczna(3);
	tablicaDynamiczna.push_back(5.5f);
	tablicaDynamiczna.push_back(7.5f);
	tablicaDynamiczna.push_back(10.5f);
	tablicaDynamiczna.push_back(13.5f);
	tablicaDynamiczna.push_back(15.5f);
}