// #pragma once oraz #ifndef.... sa to
// tzw. straznicy naglowka (include guard)
// W C++ moze istniec tylko jedna definicja klasy/struktury.
// Gdy dolaczymy rozne biblioteki lub pliki, czesc
// z nich moze (bardzo czesto) zawiera definicje
// tych samych typow, np. kazdy z 10 plikow wlacza
// std::vector. Dzieki ,,include guard'' (prosty trik z 
// makrem preprocesora) tylko pierwsze wystapienie
// np. std::vector, zostanie wlaczone, pozostale
// zostana pominiete.

// Przyklad:
//struct vec2
//{
//	float x;
//};
//
//struct vec2
//{
//	float x;
//};
// Taka tresc w jakims pliku .cpp spowoduje blad
// kompilacji o tresci: Redefinicja typu vec2.

#pragma once // Jezeli korzystamy z #pragma once
// powinna to byc pierwsza instrukcja w pliku.

// Jezeli korzystamy z #ifndef.... caly kod piszemy
// pomiedzy #define a #endif.
#ifndef MATRIX
#define MATRIX

// Klasa jest tym samym co struktura. Jednak zasady
// czystego kodu wskazuja, ze struct to zwykla paczka
// danych, bez jakichkolwiek funkcji. Natomiast class
// to dane + logika (funkcje).
class Matrix3x3
{
public:
	// Konstruktor domyslny/domniemany.
	Matrix3x3();
	// Zadanie 3: Dokoncz implementacje konstrutkora
	Matrix3x3(
		float a11, float a12, float a13,
		float a21, float a22, float a23,
		float a31, float a32, float a33);

	void Wyswietl();
	// Zadanie 4: Napisz implementacjie funkcji 
	// SumaElementow w pliku Matrix.h
	float SumaElementow();
private:
	// Trzy tablice, ktore zawieraja trzy tablice
	float m[3][3];

	// Do zmiennej ,,m'' nie mozna odwolac sie
	// nigdzie indziej, niz w funkcjach skladowych.
	// W main() instrukcja:
	// Matrix3x3 matrix;
	// matrix.m
	// spowoduje blad kompilacji
};


#endif

