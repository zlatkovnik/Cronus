#pragma once

#include <components/Component.h>

class Mesh;
class Shader;
class Renderer;

class MeshRenderer: public Component
{
private:
	Mesh* m_mesh;
public:
	MeshRenderer(Mesh* mesh);
	void Update(float deltaTime) override;
	void Render(Shader* shader, Renderer* renderer) override;
};