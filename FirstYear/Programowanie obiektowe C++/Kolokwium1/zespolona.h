// Mariia Nyzhnyk grupa 1.4/8
//Zadanie 2 - liczby zespolone
#pragma once
#include <iostream>

template <typename Type> 
struct Zespolona
{
	Type x;
	Type iy;

	Zespolona()
	{
		x = 0;
		iy = 0;
	}
	Zespolona(Type input_x, Type input_iy)
	{
		x = input_x;
		iy = input_iy;
	}
	Zespolona operator+(const Zespolona& right)
	{
		Zespolona temp;
		temp.x = x + right.x;
		temp.iy = iy + right.iy;
		return temp;
	}
};

template <typename Type>
Zespolona<Type> operator-(const Zespolona<Type>& left, const Zespolona<Type>& right)
{
	Zespolona<Type> temp;
	temp.x = left.x - right.x;
	temp.iy = left.iy - right.iy;
	return temp;
}