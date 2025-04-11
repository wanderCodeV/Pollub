#include "vec3.h"
#include <cmath>

// Klasa vec3 znajduje sie w przestrzeni nazw
// MOJA_WLASNA_PRZESTRZEN_NAZW
MOJA_WLASNA_PRZESTRZEN_NAZW::vec3::vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void MOJA_WLASNA_PRZESTRZEN_NAZW::vec3::normalize()
{
	float l = sqrt(x * x + y * y + z * z);

	if (l != 0)
	{
		x = x / l;
		y = y / l;
		z = z / l;
	}
}

MOJA_WLASNA_PRZESTRZEN_NAZW::vec3::vec3()
{
	x = 0;
	y = 0;
	z = 0;
}