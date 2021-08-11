#pragma once
#include <vector>

#include <core/Transform.h>

class Shader;
class Scene;
class CoreEngine;
class Transform;
class Component;
class Renderer;

class GameObject
{
private:
	std::vector<GameObject*> m_children;
	std::vector<Component*> m_components;
	Transform m_transform;
	CoreEngine *m_engine;
public:
	GameObject();
	void AddChild(GameObject* child);
	void AddComponent(Component* component);

	void Start();
	void Update(float deltaTime);
	void Render(Shader* shader, Renderer* renderer);

	Transform* GetTransform();
};

