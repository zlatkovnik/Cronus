#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

class WindowCallbackObserver {
public:
	virtual void KeyInputUpdate(int key) = 0;
	virtual void FrameBufferSizeUpdate(int width, int height) = 0;
	virtual void MouseInputUpdate(double xPos, double yPos) = 0;
	virtual void ScrollInputUpdate(double xOffset, double yOffset) = 0;
};