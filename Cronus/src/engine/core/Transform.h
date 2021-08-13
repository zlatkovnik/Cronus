#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform
{
private:
	glm::vec3 m_position;
	//** Yaw, Pitch, Roll **//
	float m_yaw, m_pitch, m_roll;
	glm::vec3 m_scale;
public:
	Transform();
	void Update();
	void Rotate(glm::vec3 rotation, float angle);

	glm::mat4 GetTransformMatrix();
};

