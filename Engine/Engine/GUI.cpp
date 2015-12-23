#include "GUI.h"

#include "WindowEvent.h"
#include "Time.h"

GUI::GUI(int width, int height)
{
	TwWindowSize(width, height);
	TwInit(TW_OPENGL, NULL);

	WindowEvent::RegisterMouseButtonFunction(std::bind(&GUI::TwMouseButtonBinder,this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,std::placeholders::_4));
	WindowEvent::RegisterMouseMotionFunction(std::bind(&GUI::TwMouseMotionBinder, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	WindowEvent::RegisterMouseWheelFunction(std::bind(&GUI::TwMouseWheelBinder, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	WindowEvent::RegisterKeyFunction(std::bind(&GUI::TwKeyboardBinder, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));

	this->SetDebugGui();
}

void GUI::SetDebugGui()
{
	objTweakBar = TwNewBar("EngineInfos");
	//TwDefine(" EngineInfos size='100 10' ");
	TwAddVarRO(objTweakBar, "FPS :", TW_TYPE_INT32, &Time::Fps, "");
}

void GUI::WindowSizeChange(int width, int height)
{
	TwWindowSize(width, height);
}

void GUI::Draw()
{
	TwDraw();
}

GUI::~GUI()
{
}
