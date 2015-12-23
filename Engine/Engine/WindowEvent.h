#pragma once

#include <vector>
#include <functional>

#include "glfw3.h"

class WindowEvent
{
public:
	static void Initialize(GLFWwindow* window);

	static void RegisterMouseButtonFunction(std::function<void(GLFWwindow* , int , int , int )> mouseFunction) { WindowEvent::MouseButtonFunction.push_back(mouseFunction); }
	static void RegisterMouseMotionFunction(std::function<void(GLFWwindow* , double , double )> mouseFunction) { WindowEvent::MouseMotionFunction.push_back(mouseFunction); }
	static void RegisterKeyFunction(std::function<void(GLFWwindow* , int , int , int , int )> keyFunction) { WindowEvent::KeyboardFunction.push_back(keyFunction); }
	static void RegisterMouseWheelFunction(std::function<void(GLFWwindow* , double , double )> mouseFunction) { WindowEvent::MouseWheelFunction.push_back(mouseFunction); }

private:
	//function
	static void MouseButtonHandler(GLFWwindow* window, int button, int action, int mods);
	static void MouseMotionHandler(GLFWwindow* window , double x, double y);
	static void KeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void MouseWheelHandler(GLFWwindow* window, double xoffset, double yoffset);

	//variable
	static std::vector < std::function<void(GLFWwindow*, int, int, int)>> MouseButtonFunction;
	static std::vector < std::function<void(GLFWwindow* , double , double )>> MouseMotionFunction;
	static std::vector < std::function<void(GLFWwindow* , int , int , int , int )>> KeyboardFunction;
	static std::vector < std::function<void(GLFWwindow* , double , double )>> MouseWheelFunction;

};

