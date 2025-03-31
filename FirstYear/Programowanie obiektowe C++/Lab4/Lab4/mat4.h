#pragma once
class mat4
{
public:
	mat4();
	mat4 operator+(const mat4& rhs);
private:
	float elem[4][4];
};