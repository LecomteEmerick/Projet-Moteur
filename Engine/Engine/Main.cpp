#include <iostream>

#include "GameLoop.h";

int main(void)
{
	GameLoop::Initialize();
	GameLoop::Start();
	system("pause");
}