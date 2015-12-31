#include <iostream>

#include "GameLoop.h";
#include "ShaderManager.h"

int main(int argc, char **argv)
{
	GameLoop::Initialize();
	ShaderManager::Initialize();
	GameLoop::Start();
	//system("pause");
}