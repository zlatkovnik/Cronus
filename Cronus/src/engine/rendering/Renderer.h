#pragma once

class GameObject;
class Camera;
class Shader;

class Renderer
{
private:
	Camera* m_camera;
	Shader* m_ambientShader;
public:
	Renderer();
	void Render(GameObject *root);

	void SetCamera(Camera *camera);
	Camera* GetCamera() const;
};

