#pragma once

#include <vector>
#include <functional>

#define GLEW_STATIC 1
#include "glew.h"
#include "glm.hpp"

#define GLFW_INCLUDE_GLU
#include "glfw3.h"

#include "RenderDataBinder.h"
#include "Camera.h"
class GameLoop
{
public:
	//Function
	static void Initialize();
	static void Start();
	static void Exit();

	static void RegisterDrawFunction(std::function<void(const RenderDataBinder&)> drawFunction) { GameLoop::DrawCallList.push_back(drawFunction); }
	static void RegisterPhysicUpdateFunction(std::function<void(const float& time)> updatePhysicsFunction) { GameLoop::PhysicUpdateFunction.push_back(updatePhysicsFunction); }
	static void RegisterLogicUpdateFunction(std::function<void(const float& time)> updateLogicFunction) { GameLoop::LogicUpdateFunction.push_back(updateLogicFunction); }
private:
	//Function
	static void UpdateLogic();
	static void UpdatePhysics();
	static void UpdateRender();

	static void	MouseFunctionHandler(GLFWwindow* window, int button, int action, int mods);
	static void	KeyboardFunctionHandler(GLFWwindow* window, int key, int scancode, int action, int mods);

	//Variable
	static std::vector < std::function<void(const RenderDataBinder& RenderInfos)>> DrawCallList;
	static std::vector < std::function<void(const float& time)>> LogicUpdateFunction;
	static std::vector < std::function<void(const float& time)>> PhysicUpdateFunction;

	static bool			isRunning;
	static Camera		mainCamera;
	static GLFWwindow*	window;
	static int			windowWidth;
	static int			windowHeight;
};

