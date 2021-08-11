#pragma once

class Scene;
class Window;
class Renderer;
class Camera;

class CoreEngine
{
private:
	Scene *m_scene;
	Window *m_window;
	Renderer* m_renderer;
	int m_width, m_height;

	static CoreEngine* m_instance;
public:
	CoreEngine(Scene *scene);
	void Start(int width, int height, const char title[]);
	void Stop();
	void Cleanup();

	void SetMainCamera(Camera* camera);

	static CoreEngine* GetInstance();
};

