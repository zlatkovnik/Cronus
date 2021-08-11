#pragma once

class GameObject;
class Camera;

class Renderer
{
private:
	Camera* m_camera;
public:
	Renderer();
	void Render(GameObject *root);

	void SetCamera(Camera *camera);
};

