#include "Camera.h"
#include <cmath>

Camera::Camera()
{
}

Camera::Camera(GLFWindow* okno)
{
}

Camera::~Camera()
{
}

void Camera::ProcessMouseScroll(float yOffset)
{
	float temp_fov = fov - yOffset;
	if (temp_fov < 10)
		fov = 10;
	else if (temp_fov > 45)
		fov = 45;
	else fov = temp_fov;	
}

void Camera::ProcessMouseMove(float deltaX, float deltaY)
{
	float temp_yaw = yaw - deltaX;
	if (temp_yaw < -89)
		yaw = -89;
	else if (temp_yaw > 89)
		yaw = 89;
	else yaw = temp_yaw;

	float temp_pitch = pitch - deltaY;
	if (temp_pitch < -89)
		pitch = -89;
	else if (temp_pitch > 89)
		pitch = 89;
	else pitch = temp_pitch;

	float p = pitch * 3.14 / 180;
	float y = yaw * 3.14 / 180;

	vec3 direction;
	direction.x = cos(y) * cos(p);
	direction.y = sin(p);
	direction.z = sin(y) * cos(p);

	direction.normalize();
	m_front = direction;

}

void Camera::ProcessKeyboardInput(float deltaTime)
{
	
}

mat4 Camera::GetViewMatrix()
{
	return mat4();
}

vec3 Camera::GetPosition()
{
	return m_front;
}

float Camera::GetFov()
{
	return fov;
}

