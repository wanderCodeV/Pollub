#include "vec3.h"
#include <cmath>

vec3::vec3()
{
    x = 0;
    y = 0;
    z = 0;
}

vec3::vec3(float auto_x, float auto_y, float auto_z)
{
    x = auto_x;
    y = auto_y;
    z = auto_z;
}

void vec3::normalize()
{
    float len = sqrt(x * x + y * y + z * z);
    x /= len;
    y /= len;
    z /= len;
}