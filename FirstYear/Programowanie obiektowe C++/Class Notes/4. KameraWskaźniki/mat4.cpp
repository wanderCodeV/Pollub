#include "mat4.h"

mat4::mat4()
{
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			m[row][column] = 0;
		}
	}
}

mat4::mat4(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44)
{
	m[0][0] = a11;
	m[0][1] = a12;
	m[0][2] = a13;
	m[0][3] = a14;

	m[1][0] = a21;
	m[1][1] = a22;
	m[1][2] = a23;
	m[1][3] = a24;

	m[2][0] = a31;
	m[2][1] = a32;
	m[2][2] = a33;
	m[2][3] = a34;

	m[3][0] = a41;
	m[3][1] = a42;
	m[3][2] = a43;
	m[3][3] = a44;
}

mat4 mat4::operator+(const mat4& matrix)
{
	// Obiekt zawierajacy rezultat dodawania.
	// Zostanie wywolany konstruktor bezparametrowy
	mat4 mat;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// samo m[i][j] pochodzi od obiektu, na rzecz
			// ktorego zostal wywolany operator+.
			// mat4 m1;
			// mat4 m2;
			// m1 + m2
			// W tym przypadku operator+ jest wywolywany
			// na rzecz obiektu m1 (obiekt po lewej).
			// Inaczej mozna zapisac:
			// m1.operator+(m2);
			mat.m[i][j] = m[i][j] + matrix.m[i][j];
		}
	}

    return mat;
}
