#include "CoreEngine.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <iostream>

#include <components/Camera.h>
#include <core/Scene.h>
#include <core/GameObject.h>
#include <rendering/Renderer.h>
#include <rendering/Shader.h>
#include <rendering/Window.h>

CoreEngine* CoreEngine::m_instance = nullptr;

CoreEngine::CoreEngine(Scene* scene)
	:m_scene(scene)
{
    m_window = new Window(800, 600, "Cronus");
    m_renderer = new Renderer();

    m_instance = this;
}

void CoreEngine::Start(int width, int height, const char title[])
{
    //Izmestiti ovo
    GameObject* cameraObject = new GameObject();
    Camera* cameraComponent = new Camera(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    cameraObject->AddComponent(cameraComponent);
    CoreEngine::GetInstance()->SetMainCamera(cameraComponent);
    Window::GetInstance()->RegisterObserver(cameraComponent);

    m_window->Resize(width, height);
    m_scene->Start();

    m_lastTime = glfwGetTime();

    while (!m_window->ShouldClose()) {
        m_window->ClearScreen(0.2f, 0.3f, 0.3f, 1.0f);
        m_window->ClearBuffers(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float currentTime = glfwGetTime();
        float deltaTime = currentTime - m_lastTime;
        m_lastTime = currentTime;
        m_scene->Update(deltaTime);
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

void CoreEngine::SetMainCamera(Camera* camera)
{
    m_renderer->SetCamera(camera);
}

CoreEngine* CoreEngine::GetInstance()
{
    if (m_instance == nullptr) {
        std::cout << "ENGINE DOES NOT EXIST" << std::endl;
    }
    return m_instance;
}
