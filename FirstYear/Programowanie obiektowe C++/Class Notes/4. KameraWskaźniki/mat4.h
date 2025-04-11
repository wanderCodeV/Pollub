#pragma once

class mat4
{
public:
	mat4();
	mat4(
		float a11, float a12, float a13, float a14,
		float a21, float a22, float a23, float a24,
	    float a31, float a32, float a33, float a34,
		float a41, float a42, float a43, float a44
		);
	
	// Poniewaz operator+ jest funkcja skladowa, to
	// zawsze obiekt, na rzecz ktorego wywolywany
	// jest operator+, jest przekazywany do tej funkcji.
	// Kazda funkcje skladowa mozna wywolac tylko
	// na rzecz jakiego obiektu. 
	// nazwa_obiektu.nazwa_funkcji
	mat4 operator+(const mat4& matrix);
private:
	float m[4][4];
};

