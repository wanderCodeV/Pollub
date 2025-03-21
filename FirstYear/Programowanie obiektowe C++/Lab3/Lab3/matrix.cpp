#include <iostream>
#include "matrix.h"

Matrix3x3::Matrix3x3(float a11, float a12, float a13,
	float a21, float a22, float a23,
	float a31, float a32, float a33)
{
	elem[0][0] = a11;
	elem[0][1] = a12;
	elem[0][2] = a13;

	elem[1][0] = a21;
	elem[1][1] = a23;
	elem[1][2] = a23;

	elem[2][0] = a31;
	elem[2][1] = a33;
	elem[2][2] = a33;
			
}

void Matrix3x3::Wyswietl()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << elem[i][j] << " ";
		std::cout << std::endl;
	}
		
}

float Matrix3x3::SumaElementow()
{
	float sum = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			sum += elem[i][j];
	return sum;
}
