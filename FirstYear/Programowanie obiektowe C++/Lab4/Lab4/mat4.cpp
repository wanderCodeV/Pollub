#include "mat4.h"

mat4::mat4()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			elem[i][j] = 0;
}

mat4 mat4::operator+(const mat4& rhs)
{
	mat4 sum;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			sum.elem[i][j] = elem[i][j] + rhs.elem[i][j];
	return sum;
}
