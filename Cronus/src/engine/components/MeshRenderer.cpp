#include "MeshRenderer.h"

#include <rendering/Shader.h>
#include <rendering/Mesh.h>

MeshRenderer::MeshRenderer(Mesh* mesh)
{
	m_mesh = mesh;
}

void MeshRenderer::Render(Shader* shader, Renderer* renderer)
{
	shader->Use();
	//SET UNIFORMS
	m_mesh->Draw();
}

void MeshRenderer::Update(float deltaTime)
{
}
