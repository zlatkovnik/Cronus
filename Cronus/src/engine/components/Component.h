#pragma once

class Renderer;
class GameObject;
class Shader;

class Component {
protected:
	GameObject *m_parent;
public:
	//Component(GameObject* parent) : m_parent(parent) {}
	//virtual void Input(float delta) = 0;
	virtual void Update(float delta) = 0;
	virtual void Render(Shader* shader, Renderer* renderer) = 0;

	void SetParent(GameObject* parent) {
		m_parent = parent;
	}
};