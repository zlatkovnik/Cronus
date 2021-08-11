#include "Scene.h"

#include <core/GameObject.h>

GameObject* Scene::GetRootObject()
{
	if (m_root == nullptr) {
		m_root = new GameObject();
	}
	return m_root;
}

void Scene::AddObject(GameObject *object)
{
	GetRootObject()->AddChild(object);
}
