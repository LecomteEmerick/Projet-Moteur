#pragma once

#include <map>

#define GLFW_INCLUDE_NONE
#include "glfw3.h"

#include "KeyState.h"
#include "Mouse.h"

class InputManager
{
public:
	static void InputManager::EndFrame();

	static void KeyboardFunc(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void MouseButtonFunc(GLFWwindow* window, int button, int action, int mods);
	static void MouseMotionFunc(GLFWwindow* window, double x, double y);

	static std::map<int, KeyState> KeysState;
	static Mouse MouseState;

private:
	static void UpdateKeyboard();
	static void UpdateMouse();
};

