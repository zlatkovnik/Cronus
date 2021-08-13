#include "GameObject.h"

#include <components/Component.h>
#include <rendering/Renderer.h>
#include <components/Camera.h>
#include <rendering/Window.h>
#include <rendering/Shader.h>

GameObject::GameObject()
{
	m_transform = new Transform();
}

void GameObject::AddChild(GameObject *child)
{
	m_children.push_back(child);
}

void GameObject::AddComponent(Component *component)
{
	m_components.push_back(component);
	component->SetParent(this);
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
	glm::mat4 model = m_transform->GetTransformMatrix();
	glm::mat4 view = renderer->GetCamera()->GetViewMatrix();
	int width, height;
	Window::GetInstance()->GetSize(&width, &height);
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)(width / height), 0.1f, 100.0f);
	glm::mat4 mvp = projection * view * model;
	shader->SetMat4("mvp", mvp);

	for (auto component : m_components)
		component->Render(shader, renderer);

	for (auto child : m_children)
		child->Render(shader, renderer);
}

Transform* GameObject::GetTransform()
{
	return m_transform;
}
