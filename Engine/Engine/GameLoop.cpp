#include "GameLoop.h"

std::vector < std::function<void(const RenderDataBinder& RenderInfos)>> GameLoop::DrawCallList;
std::vector < std::function<void(const float& time)>> GameLoop::LogicUpdateFunction;
std::vector < std::function<void(const float& time)>> GameLoop::PhysicUpdateFunction;

bool		GameLoop::isRunning;
Camera		GameLoop::mainCamera;
GLFWwindow*	GameLoop::window;
int			GameLoop::windowWidth=800;
int			GameLoop::windowHeight=600;

void GameLoop::Initialize()
{
	GameLoop::mainCamera = Camera();
	GameLoop::mainCamera.Depth = 10.0f;
	GameLoop::mainCamera.setPosition(glm::vec3(0.0f, 0.0f, GameLoop::mainCamera.Depth));
	GameLoop::mainCamera.lookAt(glm::vec3(0.0f, 0.0f, 0.0f));
	GameLoop::mainCamera.CameraSpeed = 100.0f;
	GameLoop::mainCamera.CameraSensitivity = 50.0f;

	GameLoop::isRunning = false;

	glfwInit();

	GameLoop::window = glfwCreateWindow(GameLoop::windowWidth, GameLoop::windowHeight, "R.F Engine", NULL, NULL);
	glfwMakeContextCurrent(GameLoop::window);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	glfwSetKeyCallback(GameLoop::window, KeyboardFunctionHandler);
	glfwSetMouseButtonCallback(GameLoop::window, MouseFunctionHandler);
}

void GameLoop::Start()
{
	GameLoop::isRunning = true;
	while (GameLoop::isRunning)
	{
		GameLoop::UpdateLogic();
		GameLoop::UpdatePhysics();
		GameLoop::UpdateRender();
	}
}

void GameLoop::Exit()
{
	GameLoop::isRunning = false;
}

void GameLoop::UpdateLogic()
{

}

void GameLoop::UpdatePhysics()
{

}

void GameLoop::UpdateRender()
{

}

void GameLoop::MouseFunctionHandler(GLFWwindow* window, int button, int action, int mods)
{

}

void GameLoop::KeyboardFunctionHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}