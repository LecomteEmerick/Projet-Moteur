#pragma once

#include "Button.h"

class Mouse
{
public:
	Mouse() : ButtonLeft(), ButtonRight(), x(0), y(0), previousX(0), previousY(0) {}
	~Mouse() {}

	void ChangeLeftButtonState(bool isPressed) { this->ButtonLeft.ChangeButtonState(isPressed); }
	void ChangeRightButtonState(bool isPressed) { this->ButtonLeft.ChangeButtonState(isPressed); }

	void ChangePosition(double x, double y) { 
		this->previousX = this->x;  this->previousY = this->y;
		this->x = x; this->y = y;
	}

	Button ButtonLeft;
	Button ButtonRight;

	double x;
	double y;

private:
	double previousX;
	double previousY;
};