#pragma once

#include <core/GameObject.h>
#include <components/Component.h>

class Translator : public Component {
private:
	float m_acc = 0.0f;
public:
	virtual void Update(float delta) {
		m_acc += delta;
		this->m_parent->GetTransform()->Move(glm::vec3(cos(m_acc) * 2.0f, sin(m_acc) * 2.0f, 0.0f));
	}
	virtual void Render(Shader* shader, Renderer* renderer) {

	}
};