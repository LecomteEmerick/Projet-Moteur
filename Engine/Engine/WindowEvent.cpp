#include "WindowEvent.h"

std::vector < std::function<void(GLFWwindow*, int, int, int)>> WindowEvent::MouseButtonFunction;
std::vector < std::function<void(GLFWwindow*, double, double)>> WindowEvent::MouseMotionFunction;
std::vector < std::function<void(GLFWwindow*, int, int, int, int)>> WindowEvent::KeyboardFunction;
std::vector < std::function<void(GLFWwindow*, double, double)>> WindowEvent::MouseWheelFunction;

void WindowEvent::Initialize(GLFWwindow* window)
{
	glfwSetMouseButtonCallback(window, WindowEvent::MouseButtonHandler);
	glfwSetCursorPosCallback(window, WindowEvent::MouseMotionHandler);
	glfwSetScrollCallback(window, WindowEvent::MouseWheelHandler);
	glfwSetKeyCallback(window, WindowEvent::KeyboardHandler);
}

void WindowEvent::MouseButtonHandler(GLFWwindow* window, int button, int action, int mods)
{
	for (std::function<void(GLFWwindow*, int, int, int)> function : WindowEvent::MouseButtonFunction)
	{
		function(window, button, action, mods);
	}
}

void WindowEvent::MouseMotionHandler(GLFWwindow* window, double x, double y)
{
	for (std::function<void(GLFWwindow *, double, double)> function : WindowEvent::MouseMotionFunction)
	{
		function(window, x, y);
	}
}

void WindowEvent::KeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	for (std::function<void(GLFWwindow *, int, int, int, int)> function : WindowEvent::KeyboardFunction)
	{
		function(window, key, scancode, action, mods);
	}
}

void WindowEvent::MouseWheelHandler(GLFWwindow* window, double xoffset, double yoffset)
{
	for (std::function<void(GLFWwindow*, double, double)> function : WindowEvent::MouseWheelFunction)
	{
		function(window, xoffset, yoffset);
	}
}
