#pragma once

class GameObject;
class Renderer;

class Scene
{
private:
	GameObject *m_root;
	GameObject* GetRootObject();
public:
	void Start();
	void Update(float deltaTime);
	void Render(Renderer *renderer);

	void AddObject(GameObject *object);
};

