#include "Time.h"

#include <iostream>

#define GLFW_INCLUDE_NONE
#include "glfw3.h"

double	Time::time_;
double	Time::previousTime_;
double	Time::FpsCounterTime_;
bool	Time::isStarted_;
int		Time::nbFrames_;

bool	Time::printFps_;
int	Time::Fps;


void Time::Start()
{
	Time::previousTime_ = glfwGetTime();
	Time::time_ = 1.0f;
	Time::isStarted_ = true;
	Time::FpsCounterTime_ = Time::previousTime_;
	Time::nbFrames_ = 0;
	Time::printFps_ = true;
	Time::Fps = 0;
}

void Time::Update()
{
	double currentTime;
	double delta;

	currentTime = glfwGetTime();
	delta = currentTime - Time::previousTime_;
	Time::previousTime_ = currentTime;

	Time::time_ = 1.0f;
	if (isStarted_)
		Time::time_ += delta;

	if (printFps_)
	{
		nbFrames_++;
		if (Time::previousTime_ - Time::FpsCounterTime_ >= 1.0)
		{
			//std::cout << double(nbFrames_) << " fps\n" << std::endl;
			Fps = nbFrames_;
			nbFrames_ = 0;
			Time::FpsCounterTime_ += 1.0;
		}
	}
}

double Time::GetSecondElapsed()
{
	return Time::time_ - 1.0f;
}

void Time::Play()
{
	Time::isStarted_ = true;
}

void Time::Pause()
{
	Time::isStarted_ = false;
}