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
	glm::vec3 m_right;
	//Euler (mozda izmenim u quartenion)
	float m_yaw;
	float m_pitch;

	float m_lastPosX = 0.0f;
	float m_lastPosY = 0.0f;

	float m_movementSpeed = 2.5f;
	float m_mouseSensitivity = 0.1f;

	bool m_firstMouse = true;
public:
	Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw = -90.0f, float pitch = 0.0f);
	glm::mat4 GetViewMatrix();
	virtual void Update(float delta) override;
	virtual void Render(Shader* shader, Renderer* renderer) override;
	void UpdateCamera();

	void KeyInputUpdate(int key) override;
	void FrameBufferSizeUpdate(int width, int height) override;
	void MouseInputUpdate(float xPos, float yPos) override;
	void ScrollInputUpdate(float xOffset, float yOffset) override;
};

