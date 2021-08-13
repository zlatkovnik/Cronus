#include "Camera.h"
#include <rendering/Window.h>


Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
	:m_position(glm::vec3(posX, posY, posZ)),
	m_direction(glm::vec3(0.0f, 0.0f, -1.0f)),
	m_up(glm::vec3(upX, upY, upZ)),
	m_yaw(yaw), m_pitch(pitch)
{
	UpdateCamera();
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(m_position, m_position + m_direction, m_up);
}

void Camera::Update(float delta)
{
}

void Camera::Render(Shader* shader, Renderer* renderer)
{
}

void Camera::UpdateCamera()
{
    glm::vec3 direction;
    direction.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    direction.y = sin(glm::radians(m_pitch));
    direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_direction = glm::normalize(direction);
    m_right = glm::normalize(glm::cross(direction, glm::vec3(0.0f, 1.0f, 0.0f)));
    m_up = glm::normalize(glm::cross(m_right, direction));
}

void Camera::KeyInputUpdate(int key) {
    switch (key) {
    case 'A':
        m_position -= m_right * 0.1f;
        break;
    case 'D':
        m_position += m_right * 0.1f;
        break;
    case 'W':
        m_position += m_direction * 0.1f;
        break;
    case 'S':
        m_position -= m_direction * 0.1f;
        break;
    default:
        break;
    }
}

void Camera::FrameBufferSizeUpdate(int width, int height)
{
    Window::GetInstance()->Resize(width, height);
}

void Camera::MouseInputUpdate(float xPos, float yPos)
{
    float offsetX = xPos - m_lastPosX;
    float offsetY = m_lastPosY - yPos;

    m_lastPosX = xPos;
    m_lastPosY = yPos;

    offsetX *= m_mouseSensitivity;
    offsetY *= m_mouseSensitivity;

    m_yaw += offsetX;
    m_pitch += offsetY;

    if (m_pitch > 89.0f)
        m_pitch = 89.0f;
    if (m_pitch < -89.0f)
        m_pitch = -89.0f;

    // update Front, Right and Up Vectors using the updated Euler angles
    UpdateCamera();
}

void Camera::ScrollInputUpdate(float xOffset, float yOffset)
{
}