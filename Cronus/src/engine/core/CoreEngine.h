#pragma once

class Scene;
class Window;
class Renderer;

class CoreEngine
{
private:
	Scene *m_scene;
	Window *m_window;
	Renderer* m_renderer;
	int m_width, m_height;
public:
	CoreEngine(Scene *scene);
	void Start(int width, int height, const char title[]);
	void Stop();
	void Cleanup();
};

