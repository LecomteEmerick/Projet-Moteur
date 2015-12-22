#include "InputManager.h"

std::map<int, KeyState> InputManager::KeysState;
Mouse InputManager::MouseState;

void InputManager::MouseMotionFunc(GLFWwindow* window, double x, double y)
{
	InputManager::MouseState.ChangePosition(x, y);
}

void InputManager::MouseButtonFunc(GLFWwindow* window, int button, int action, int mods)
{
	switch (button)
	{
	case(GLFW_MOUSE_BUTTON_1) :
		if (action == GLFW_RELEASE)
			InputManager::MouseState.ChangeLeftButtonState(false);
		else if (action == GLFW_PRESS)
			InputManager::MouseState.ChangeLeftButtonState(true);

		break;
	case(GLFW_MOUSE_BUTTON_2) :
		if (action == GLFW_RELEASE)
			InputManager::MouseState.ChangeRightButtonState(false);
		else if (action == GLFW_PRESS)
			InputManager::MouseState.ChangeRightButtonState(true);

		break;
	}

	double x, y;

	glfwGetCursorPos(window, &x, &y);
	InputManager::MouseState.ChangePosition(x, y);
}

void InputManager::KeyboardFunc(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		InputManager::KeysState[key].PressedThisFrame = true;
	}
	else if(action == GLFW_RELEASE)
	{
		InputManager::KeysState[key].ReleaseThisFrame = true;
	}
	
	InputManager::KeysState[key].Down = action == GLFW_PRESS;
	InputManager::KeysState[key].Up = action != GLFW_PRESS;
}


void InputManager::EndFrame()
{
	InputManager::UpdateMouse();
	InputManager::UpdateKeyboard();
}

void InputManager::UpdateMouse()
{
	MouseState.ButtonLeft.EndFrameButton();
	MouseState.ButtonRight.EndFrameButton();
}

void InputManager::UpdateKeyboard()
{
	for (std::pair<int, KeyState> keyState : InputManager::KeysState)
	{
		InputManager::KeysState[keyState.first].PressedThisFrame = false;
		InputManager::KeysState[keyState.first].ReleaseThisFrame = false;
	}
}
