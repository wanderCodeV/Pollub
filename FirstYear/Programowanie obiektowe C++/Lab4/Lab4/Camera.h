#pragma once
#include "vec3.h"
#include "mat4.h"

class GLFWindow;

class Camera {
private:
	vec3 m_position;
	vec3 m_up;
	vec3 m_front;
	float pitch;
	float yaw;
	float fov;
	GLFWindow* m_window;
public:
	Camera();
	Camera(GLFWindow* okno);
	~Camera();
	void ProcessMouseScroll(float yOffset);
	void ProcessMouseMove(float deltaX, float deltaY);
	void ProcessKeyboardInput(float deltaTime);
	mat4 GetViewMatrix();
	vec3 GetPosition();
	float GetFov();
};