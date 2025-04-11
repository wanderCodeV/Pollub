//#pragma once

// albo

#ifndef VEC3_H
#define VEC3_H

// Definicja wlasnej przestrzeni nazw
namespace MOJA_WLASNA_PRZESTRZEN_NAZW
{
	class vec3
	{
	public:
		vec3();
		vec3(float _x, float _y, float _z);

		void normalize();

		float x;
		float y;
		float z;
	};
};
#endif