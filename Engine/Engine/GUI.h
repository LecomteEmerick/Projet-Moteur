#pragma once

#include "glfw3.h"
#include "AntTweakBar.h"

class GUI
{
public:
			GUI() {}
			GUI(int Width, int Height);
	void	SetDebugGui();
	void	WindowSizeChange(int width,int height);
	void	Draw();
			~GUI();
private:
	//function
	void TwMouseButtonBinder(GLFWwindow* window, int button, int action, int mods) { TwEventMouseButtonGLFW(button, action); }
	void TwMouseMotionBinder(GLFWwindow* window, double x, double y) { TwEventMousePosGLFW(x, y); }
	void TwMouseWheelBinder(GLFWwindow* window, double xoffset, double yoffset) { TwEventMouseWheelGLFW(xoffset); }
	void TwKeyboardBinder(GLFWwindow* window, int key, int scancode, int action, int mods) { TwEventKeyGLFW(key,action); }

	TwBar*	objTweakBar;
};

