#include "CoreEngine.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <iostream>

#include <core/Scene.h>
#include <rendering/Renderer.h>
#include <rendering/Shader.h>
#include <rendering/Window.h>

CoreEngine::CoreEngine(Scene* scene)
	:m_scene(scene)
{
    m_window = new Window(800, 600, "Cronus");
    m_renderer = new Renderer();
    //m_renderer->SetCamera();

}

void CoreEngine::Start(int width, int height, const char title[])
{
    m_window->Resize(width, height);
    m_scene->Start();

    while (!m_window->ShouldClose()) {
        m_window->ClearScreen(0.2f, 0.3f, 0.3f, 1.0f);

        m_scene->Update(0.0f);
        m_scene->Render(m_renderer);

        m_window->SwapBuffers();
        m_window->PollEvents();
    }
}

void CoreEngine::Stop()
{
}

void CoreEngine::Cleanup()
{
    m_window->Cleanup();
}
