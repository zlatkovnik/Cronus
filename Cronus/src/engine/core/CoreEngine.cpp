#include "CoreEngine.h"

#include <iostream>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include <core/Scene.h>
#include <vector>
#include <rendering/Shader.h>

CoreEngine::CoreEngine(Scene* scene)
	:m_scene(scene)
{

}

void CoreEngine::Start(int width, int height, const char title[])
{
    m_window.ShowWindow(width, height, title);
    m_scene->Start();

    //TEST CODE
    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };

    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    Shader shader("./res/shaders/basic.vert", "./res/shaders/basic.frag");

    while (!m_window.ShouldClose()) {
        m_window.ClearScreen(0.2f, 0.3f, 0.3f, 1.0f);

        m_scene->Update(0.0f);
        m_scene->Render(nullptr);

        glBindVertexArray(VAO);
        shader.Use();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        m_window.SwapBuffers();
        m_window.PollEvents();
    }
}

void CoreEngine::Stop()
{
}

void CoreEngine::Cleanup()
{
    m_window.Cleanup();
}
