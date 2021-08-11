#include "Window.h"

#include <iostream>

#include <core/CoreEngine.h>

void GLAPIENTRY
MessageCallback(GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam)
{
    fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
        (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
        type, severity, message);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    auto observers = Window::GetInstance()->GetObservers();
    for (int i = 0; i < observers.size(); i++) {
        observers[i]->KeyInputUpdate(key);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    auto observers = Window::GetInstance()->GetObservers();
    for (int i = 0; i < observers.size(); i++) {
        observers[i]->FrameBufferSizeUpdate(width, height);
    }
}

void mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
    auto observers = Window::GetInstance()->GetObservers();
    for (int i = 0; i < observers.size(); i++) {
        observers[i]->MouseInputUpdate(xPos, yPos);
    }
}

void scroll_callback(GLFWwindow* window, double xOffset, double yOffset)
{
    auto observers = Window::GetInstance()->GetObservers();
    for (int i = 0; i < observers.size(); i++) {
        observers[i]->ScrollInputUpdate(xOffset, yOffset);
    }
}

Window* Window::m_instance = nullptr;

Window::Window(int width, int height, const char title[])
    :m_width(width), m_height(height)
{
    m_width = width;
    m_height = height;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(m_window);
    //Callbacks
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
    glfwSetCursorPosCallback(m_window, mouse_callback);
    glfwSetScrollCallback(m_window, scroll_callback);
    glfwSetKeyCallback(m_window, key_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    // During init, enable debug output
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, 0);

    m_instance = this;
}


bool Window::ShouldClose()
{
    return glfwWindowShouldClose(m_window);
}

void Window::Resize(int width, int height)
{
    glViewport(0, 0, width, height);
}

void Window::Cleanup()
{
    glfwTerminate();
}

void Window::ClearScreen(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(m_window);
}

void Window::PollEvents()
{
    glfwPollEvents();
}

Window* Window::GetInstance()
{
    if (m_instance == nullptr) {
        std::cout << "NO WINDOW INSTANCE" << std::endl;
    }
    return m_instance;
}

void Window::RegisterObserver(WindowCallbackObserver* observer)
{
    m_observers.push_back(observer);
}

void Window::UnregisterObserver(WindowCallbackObserver* observer)
{
    //No need...
}

