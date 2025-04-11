#ifndef KAMERA_H
#define KAMERA_H

#include "mat4.h"
#include "vec3.h"

using namespace MOJA_WLASNA_PRZESTRZEN_NAZW;

class GLFWwindow;

class Kamera
{
public:
	// Konstruktor
	Kamera(GLFWwindow* okno);
	// Destruktor
	~Kamera();
	
	void ProcessMouseScroll(float yOffset);
	void ProcessMouseMove(float deltaX, float deltaY);
	void ProcessKeyboardInput(float deltaTime);
	mat4 GetViewMatrix()const;
	vec3 GetPosition()const;
	float GetFov()const;

private:
	// Jedna z konwencji pisania kodu, sugeruje aby
	// nazwy zmiennych, ktore naleza do klasy, mialy
	// prefix m_
	// m - od angielskiego slowa member
	vec3 m_position;
	vec3 m_front;
	vec3 m_up;

	float m_pitch;
	float m_yaw;
	float m_fov;

	float m_speed;
	float m_sensitivity;
	GLFWwindow* m_window;
};

#endif // !KAMERA_H
