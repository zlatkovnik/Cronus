#pragma once

#include <core/GameObject.h>
#include <rendering/Renderer.h>

class Scene
{
protected:
	GameObject *m_root;
public:
	virtual void Start() {
		m_root->Start();
	}
	void Update(float deltaTime) {
		m_root->Update(deltaTime);
	};
	void Render(Renderer* renderer) {
		renderer->Render(GetRootObject());
	};

	void AddObject(GameObject *object);
	GameObject* GetRootObject();
};

