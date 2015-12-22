#pragma once

class Button
{
public:
	Button() : isPressed(false), isPressedThisFrame(false), isReleaseThisFrame(false) { }
	~Button() {}

	void ChangeButtonState(bool isPressed) { this->isPressed = isPressed; this->isPressedThisFrame = isPressed; this->isReleaseThisFrame = isPressed; }
	void EndFrameButton() { this->isPressedThisFrame = false; this->isReleaseThisFrame = false; }

	bool isPressed;
	bool isPressedThisFrame;
	bool isReleaseThisFrame;
};