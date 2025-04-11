#include "Kamera.h"

#include <algorithm> // od c++17 mamy std::clamp
#include <iostream>

void Kamera::ProcessMouseScroll(float yOffset)
{
	m_fov -= (float)yOffset;
	m_fov = std::clamp(m_fov, 10.0f, 45.0f);
	
	// inaczej

	/*
	if (m_fov > 45)
		m_fov = 45;

	if (m_fov < 10)
		m_fov = 10;
	*/
}

void Kamera::ProcessMouseMove(float deltaX, float deltaY)
{
	deltaX *= m_sensitivity;
	deltaY *= m_sensitivity;

	m_yaw   += deltaX;
	m_pitch += deltaY;

	m_pitch = std::clamp(m_pitch, -89.0f, 89.0f);

	// Zamiana stopni na radiany
	const auto y = (3.14f/180.0f) * m_yaw;
	const auto p = (3.14f/180.0f) * m_pitch;

	// Przejscie ze wspolrzednych sferycznych na
	// wspolrzedne kartezjanskie.
	vec3 direction;
	direction.x = cos(y) * cos(p);
	direction.y = sin(p);
	direction.z = sin(y) * cos(p);

	// Wywolanie funkcji na rzecz obiektu direction
	direction.normalize();
	m_front = direction;
}

void Kamera::ProcessKeyboardInput(float deltaTime)
{
	float speed = m_speed;
	speed *= deltaTime;
}

mat4 Kamera::GetViewMatrix()const
{
	// Zwracam obiekt typu mat4
	// Tworze obiekt mat4 i odrazu zwracam go z funkcji.
	return mat4();
}

vec3 Kamera::GetPosition()const
{
	return m_position;
}

float Kamera::GetFov()const
{
	return m_fov;
}

 Kamera::Kamera(GLFWwindow* okno)
{
	m_window   = okno;

	m_position = vec3(0, 0, 0);
	m_front    = vec3(0, 0, 1);
	m_up       = vec3(0, 1, 1);

	m_fov   = 45.0f;
	m_pitch = 0.0f;
	m_yaw   = 0.0f;

	m_sensitivity = 1.0f;
	m_speed       = 2.5f;
}

Kamera::~Kamera()
{
	std::cout << "Destruktor klasy Kamera!\n";
}
