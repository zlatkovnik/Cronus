#pragma once

class Renderer;

class Component {
private:
	GameObject *m_parent;
public:
	//Component(GameObject* parent) : m_parent(parent) {}
	virtual void Input(float delta) = 0;
	virtual void Update(float delta) = 0;
	virtual void Render(Shader* shader, Renderer* renderingEngine) = 0;
};