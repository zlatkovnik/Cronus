#pragma once

#include <components/Component.h>
#include <util/WindowCallbackObserver.h>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera: public Component, public WindowCallbackObserver
{
private:
	glm::vec3 m_position;
	glm::vec3 m_direction;
	glm::vec3 m_up;
	//Euler (mozda izmenim u quartenion)
	float m_yaw;
	float m_pitch;
public:
	Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);
	glm::mat4 GetViewMatrix();
	virtual void Update(float delta) override;
	virtual void Render(Shader* shader, Renderer* renderer) override;
	void UpdateCamera();

	void KeyInputUpdate(int key) override {};
	void FrameBufferSizeUpdate(int width, int height) override;
	void MouseInputUpdate(double xPos, double yPos) override;
	void ScrollInputUpdate(double xOffset, double yOffset) override;
};

