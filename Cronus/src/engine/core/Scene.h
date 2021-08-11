#pragma once

class GameObject;
class Renderer;

class Scene
{
protected:
	GameObject *m_root;
public:
	virtual void Start() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(Renderer *renderer) = 0;

	void AddObject(GameObject *object);
	GameObject* GetRootObject();
};

