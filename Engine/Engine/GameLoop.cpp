#include "GameLoop.h"

#include <iostream>

#include "WindowEvent.h"
#include "Time.h"
#include "InputManager.h"



std::vector < std::function<void(void)>> GameLoop::StartCall;

std::vector < std::function<void(const RenderDataBinder&)>> GameLoop::DrawCallList;
std::vector < std::function<void(void)>> GameLoop::LogicUpdateFunction;
std::vector < std::function<void(void)>> GameLoop::PhysicUpdateFunction;

std::vector < std::function<void(void)>> GameLoop::EndCall;

bool		GameLoop::isRunning;
Camera		GameLoop::mainCamera;
GLFWwindow*	GameLoop::window;
int			GameLoop::windowWidth=800;
int			GameLoop::windowHeight=600;
GUI			GameLoop::windowGUI;

//Debug
Map* GameLoop::mp;
Landmark* GameLoop::mark;

void GameLoop::Initialize()
{
	GameLoop::isRunning = false;

	glfwInit();

	GameLoop::window = glfwCreateWindow(GameLoop::windowWidth, GameLoop::windowHeight, "Randall Flagg Engine", NULL, NULL);
	glfwMakeContextCurrent(GameLoop::window);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	WindowEvent::Initialize(GameLoop::window);

	glfwSetWindowSizeCallback(GameLoop::window, GameLoop::ResizeWindow); //window resize

	GLenum error = glewInit();
	if (error != GL_NO_ERROR) {
		std::cout << error << std::endl;
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	WindowEvent::RegisterMouseButtonFunction(&InputManager::MouseButtonFunc);
	WindowEvent::RegisterMouseMotionFunction(&InputManager::MouseMotionFunc);
	WindowEvent::RegisterKeyFunction(&InputManager::KeyboardFunc);

	GameLoop::windowGUI = GUI(GameLoop::windowWidth, GameLoop::windowHeight);

	GameLoop::mp = new Map();
	GameLoop::mark = new Landmark();
}

void GameLoop::ResizeWindow(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);

	GameLoop::mainCamera.setViewportAspectRatio((float)(width/height));

	GameLoop::windowGUI.WindowSizeChange(width, height);
}

void GameLoop::Start()
{
	Time::Start();

	GameLoop::isRunning = true;
	while (GameLoop::isRunning)
	{
		Time::Update();
		
		glfwPollEvents();

		GameLoop::CallStartFunction();

		GameLoop::UpdateLogic();
		GameLoop::UpdatePhysics();
		GameLoop::UpdateRender();

		GameLoop::CallEndFunction();

		InputManager::EndFrame();

		if(glfwWindowShouldClose(GameLoop::window))
			GameLoop::isRunning = false;

	}
	glfwTerminate();
	TwTerminate();
}

void GameLoop::Exit()
{
	GameLoop::isRunning = false;
}

void GameLoop::CallStartFunction()
{
	for (std::function<void(void)> function : GameLoop::StartCall)
	{
		function();
	}
	GameLoop::StartCall.clear();
}

void GameLoop::CallEndFunction()
{
	for (std::function<void(void)> function : GameLoop::EndCall)
	{
		function();
	}
	GameLoop::EndCall.clear();
}

void GameLoop::UpdateLogic()
{
	for (std::function<void(void)> function : GameLoop::LogicUpdateFunction)
	{
		function();
	}
}

void GameLoop::UpdatePhysics()
{

}

void GameLoop::UpdateRender()
{
	int widthWindow;
	int heightWindow;

	glfwGetWindowSize(window, &widthWindow, &heightWindow);

	glViewport(0, 0, widthWindow, heightWindow);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.F);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 Projection = mainCamera.projection();
	glm::mat4 World = mainCamera.view();
	glm::mat4 View = glm::mat4(1.0f);

	RenderDataBinder render(Projection, View, World);

	for (std::function<void(const RenderDataBinder&)> function : GameLoop::DrawCallList)
	{
		function(render);
	}

	GameLoop::windowGUI.Draw();

	glfwSwapBuffers(window);
}