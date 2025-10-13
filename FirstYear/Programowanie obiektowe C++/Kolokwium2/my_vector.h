//Mariia Nyzhnyk grupa 1.4.8

#pragma once
#include <cmath>

template<typename Type>
class vector4
{
public:
	vector4();
	vector4(Type auto_x, Type auto_y, Type auto_z, Type auto_w);
	~vector4();
	float length() const;
private:
	Type x;
	Type y;
	Type z;
	Type w;
};


class Quaternion : private vector4<int>
{

};


template<typename Type>
vector4<Type>::vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

template<typename Type>
vector4<Type>::vector4(Type auto_x, Type auto_y, Type auto_z, Type auto_w)
{
	x = auto_x;
	y = auto_y;
	z = auto_z;
	w = auto_w;
}

template<typename Type>
vector4<Type>::~vector4()
{

}

template<typename Type>
float vector4<Type>::length() const

{
	return sqrt(x * x + y * y + z * z + w * w);
}
