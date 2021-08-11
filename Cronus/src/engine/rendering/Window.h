#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

#include <util/WindowCallbackPublisher.h>

class Component;
class Window: public WindowCallbackPublisher
{
private:
	GLFWwindow* m_window;
	int m_width, m_height;

	static Window* m_instance;
public:
	Window(int width, int height, const char title[]);
	Window(Window& other) = delete;
	void operator=(const Window&) = delete;

	bool ShouldClose();
	void Resize(int width, int height);
	void Cleanup();

	void ClearScreen(float r, float g, float b, float a);
	void SwapBuffers();
	void PollEvents();

	static Window* GetInstance();

	void RegisterObserver(WindowCallbackObserver* observer) override;
	void UnregisterObserver(WindowCallbackObserver* observer) override;
};

