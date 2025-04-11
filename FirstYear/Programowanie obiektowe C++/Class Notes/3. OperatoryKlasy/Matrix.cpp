#include "Matrix.h"

// Funkcja o nazwie Matrix3x3 pochodzi z klasy
// o nazwie Matrix3x3
Matrix3x3::Matrix3x3()
{
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			m[row][column] = 0;
		}
	}
}

Matrix3x3::Matrix3x3(
	float a11, float a12, float a13,
	float a21, float a22, float a23,
	float a31, float a32, float a33)
{
	m[0][0] = a11;
	m[0][1] = a12;
	m[0][2] = a13;
	
	m[1][0] = a21;
	m[1][1] = a22;
	m[1][2] = a23;
	
	m[2][0] = a31;
	m[2][1] = a32;
	m[2][2] = a33;
}
// Funkcja skladowa zdefiniowana po za klasa, musi
// miec skladnie:
// TYP NAZWA_KLASY::NAZWA(PARAMETRY) { CIALO/TRESC }
void Matrix3x3::Wyswietl()
{

}
// Nalezy wskazac skad pochodzi nazwa SumaElementow,
// dlatego trzeba dodac Matrix3x3::
float Matrix3x3::SumaElementow()
{
	float suma = 0;
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			suma = suma + m[row][column];
			// inaczej
			//suma += m[row][column];
		}
	}

	return suma;
}