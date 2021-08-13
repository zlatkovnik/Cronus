#include "Renderer.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


#include <components/Camera.h>
#include <core/GameObject.h>
#include <rendering/Shader.h>
#include <rendering/Window.h>

Renderer::Renderer()
	:m_camera(nullptr)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	m_ambientShader = new Shader("./res/shaders/basic.vert", "./res/shaders/basic.frag");
}

void Renderer::Render(GameObject* root)
{
	if (m_camera == nullptr) {
		std::cout << "ERROR: Camera not set!" << std::endl;
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_ambientShader->Use();

	root->Render(m_ambientShader, this);
}

void Renderer::SetCamera(Camera* camera)
{
	m_camera = camera;
}

Camera* Renderer::GetCamera() const
{
	return m_camera;
}
