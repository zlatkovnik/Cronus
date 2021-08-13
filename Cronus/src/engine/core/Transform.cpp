#include "Transform.h"

Transform::Transform()
{
	m_position.x = 0.0f;
	m_position.y = 0.0f;
	m_position.z = 0.0f;

	m_yaw = 0.0f;
	m_pitch = 0.0f;
	m_roll = 0.0f;

	m_scale.x = 1.0f;
	m_scale.y = 1.0f;
	m_scale.z = 1.0f;
}

void Transform::Update()
{
}

void Transform::Rotate(glm::vec3 rotation, float angle)
{
	if (rotation.x > 0.001f) {
		m_pitch += angle;
	}
	if (rotation.y > 0.001f) {
		m_yaw += angle;
	}
	if (rotation.z > 0.001f) {
		m_roll += angle;
	}
}

glm::mat4 Transform::GetTransformMatrix()
{
	glm::mat4 transformation = glm::rotate(glm::mat4(1.0f), glm::radians(m_pitch), glm::vec3(1.0f, 0.0f, 0.0f));
	return transformation;
}
