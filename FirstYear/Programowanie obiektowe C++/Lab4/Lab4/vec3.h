#pragma once

class vec3
{
public:
	float x;
	float y;
	float z;
    vec3();
    vec3(float auto_x, float auto_y, float auto_z);
    void normalize();
};