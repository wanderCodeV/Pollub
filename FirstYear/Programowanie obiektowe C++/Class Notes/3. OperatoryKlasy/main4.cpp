#include <iostream>
#include "Matrix.h"


template<typename T>
struct vec3
{
	// Zadanie 2:
	// Napisz funkcje skladowa o nazwie ,,Wyswietl'', ktora
	// wyswietla wspolrzedne wektora w formacie:
	// [X, Y, Z]
	void Wyswietl()
	{
		std::cout << "[ " << x << ", "
			<< y << ", "
			<< z << " ]\n";
	}
	// W strukturze wszystko domyslnie jest dostepne
	// dla kazdego (wszedzie). W klasie wszystko domyslnie
	// jest prywatne (dostepne tylko w obrebie klasy).
	T x;
	T y;
	T z;

// Slowa kluczowe public i private rowniez dzialaja
// w strukturach.
public:

private:
};
// Przyklad przeladowywania operatorow.
// Nazwe funkcji mozna przeladowywac znaczeniami.
// Ta sama nazwa moze miec rozne znaczenia.
// Definicja operator+ dla typu vec3
template <typename T>
vec3<T> operator+(const vec3<T>& lhs, const vec3<T>& rhs)
{
	vec3<T> v;
	v.x = lhs.x + rhs.x;
	v.y = lhs.y + rhs.y;
	v.z = lhs.z + rhs.z;

	return v;
}
// Zadanie 1:
// Zaimplementuj operator*, który realizuje operacje
// iloczynu sklaranego dla dwoch wektorow 3d.
template <typename T>
float operator*(const vec3<T>& lhs, const vec3<T>& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}
int main()
{
	float a = 1;
	float b = 2;
	a + b;

	vec3<float> v1;
	v1.x = 1;
	v1.y = 1;
	v1.z = 1;
	vec3<float> v2;
	v2.x = 1;
	v2.y = 1;
	v2.z = 1;
	
	// slowo kluczowe auto powoduje, ze kompilator
	// sam ustali typ zmiennej.
	auto wynik = v1 + v2;

	wynik.Wyswietl();
	

	Matrix3x3 matrix(1, 2, 3, -1, -2, -3, 0, 10, 100);
	std::cout << "Suma elementow: ";
	std::cout << matrix.SumaElementow() << "\n";
}