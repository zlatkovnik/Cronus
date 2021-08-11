#include "Scene.h"

#include <core/GameObject.h>

GameObject* Scene::GetRootObject()
{
	if (m_root == nullptr) {
		m_root = new GameObject();
	}
	return m_root;
}

void Scene::Start()
{
	GetRootObject()->Start();
}

void Scene::Update(float deltaTime)
{
}

void Scene::Render(Renderer *renderer)
{
}

void Scene::AddObject(GameObject *object)
{
}
