#include "GameObject.h"

#include <components/Component.h>

GameObject::GameObject()
{
	m_engine = nullptr;
}

void GameObject::AddChild(GameObject *child)
{
	m_children.push_back(child);
}

void GameObject::AddComponent(Component *component)
{
	m_components.push_back(component);
}

void GameObject::Start()
{
}

void GameObject::Update(float deltaTime)
{
	for (auto component : m_components)
		component->Update(deltaTime);

	for (auto child : m_children)
		child->Update(deltaTime);
}

void GameObject::Render(Shader *shader, Renderer *renderer)
{
	for (auto component : m_components)
		component->Render(shader, renderer);

	for (auto child : m_children)
		child->Render(shader, renderer);
}

Transform* GameObject::GetTransform()
{
	return &m_transform;
}
