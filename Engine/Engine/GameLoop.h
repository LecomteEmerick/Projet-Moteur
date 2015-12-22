#pragma once

#include <vector>
#include <functional>

#define GLEW_STATIC
#include "glew.h"
#define GLFW_INCLUDE_GLU
#include "glfw3.h"

#include "glm.hpp"

#include "RenderDataBinder.h"
#include "Camera.h"

//Debug
#include "Map.h"

class GameLoop
{
public:
	//Function
	static void Initialize();
	static void Start();
	static void Exit();

	static void RegisterStartFunction(std::function<void(void)> startFunction) { GameLoop::StartCall.push_back(startFunction); }
	static void RegisterEndFunction(std::function<void(void)> endFunction) { GameLoop::EndCall.push_back(endFunction); }

	static void RegisterDrawFunction(std::function<void(const RenderDataBinder& RenderInfos)> drawFunction) { GameLoop::DrawCallList.push_back(drawFunction); }
	static void RegisterPhysicUpdateFunction(std::function<void(void)> updatePhysicsFunction) { GameLoop::PhysicUpdateFunction.push_back(updatePhysicsFunction); }
	static void RegisterLogicUpdateFunction(std::function<void(void)> updateLogicFunction) { GameLoop::LogicUpdateFunction.push_back(updateLogicFunction); }
private:
	//Function
	static void CallStartFunction();
	static void CallEndFunction();

	static void UpdateLogic();
	static void UpdatePhysics();
	static void UpdateRender();

	//Variable
	static std::vector < std::function<void(void)>> GameLoop::StartCall;

	static std::vector < std::function<void(const RenderDataBinder& RenderInfos)>> DrawCallList;
	static std::vector < std::function<void(void)>> LogicUpdateFunction;
	static std::vector < std::function<void(void)>> PhysicUpdateFunction;

	static std::vector < std::function<void(void)>> GameLoop::EndCall;

	static bool			isRunning;
	static Camera		mainCamera;
	static GLFWwindow*	window;
	static int			windowWidth;
	static int			windowHeight;

	//Debug
	//static Map* mp;
};

