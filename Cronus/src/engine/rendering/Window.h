#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
class Window
{
private:
	GLFWwindow* m_window;
	int m_width, m_height;
public:
	Window(int width, int height, const char title[]);

	bool ShouldClose();
	void Resize(int width, int height);
	void Cleanup();

	void ClearScreen(float r, float g, float b, float a);
	void SwapBuffers();
	void PollEvents();
};

