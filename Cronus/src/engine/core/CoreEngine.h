#pragma once
#include <rendering/Window.h>
class Scene;

class CoreEngine
{
private:
	Scene *m_scene;
	Window m_window;
	int m_width, m_height;
public:
	CoreEngine(Scene *scene);
	void Start(int width, int height, const char title[]);
	void Stop();
	void Cleanup();
};

