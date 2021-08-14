#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <core/GameObject.h>
#include <components/Component.h>

class Rotator : public Component {
private:
	glm::vec3 m_axis;
public:
	Rotator(glm::vec3 axis) {
		m_axis = axis;
	}
	virtual void Update(float deltaTime) {
		m_parent->GetTransform()->Rotate(m_axis, deltaTime * 100.0f);
	};
	virtual void Render(Shader* shader, Renderer* renderer) {};
};