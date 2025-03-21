#pragma once

#ifndef MATRIX
#define MATRIX

class Matrix3x3
{
public:
	//Task 3 - dokoncz implemenetacje konstruktora
	Matrix3x3(float a11,float a12, float a13, 
		float a21, float a22, float a23, 
		float a31, float a32, float a33);
	void Wyswietl();
	//Task 4 - napisz implemenetacje funkcji w pliku cpp
	float SumaElementow();
private:
	// Tzy tablice, ktore zawieraja trzy tablicy
	float elem[3][3];
};

#endif // !Matrix
