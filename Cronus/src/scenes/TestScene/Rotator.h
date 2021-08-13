#pragma once
#include <core/GameObject.h>
#include <components/Component.h>

class Rotator : public Component {
	virtual void Update(float deltaTime) {
		m_parent->GetTransform()->Rotate(glm::vec3(1.0f, 0.0f, 0.0f), deltaTime * 100.0f);
	};
	virtual void Render(Shader* shader, Renderer* renderer) {};
};