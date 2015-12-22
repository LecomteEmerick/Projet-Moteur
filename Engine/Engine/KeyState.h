#pragma once

class KeyState
{
public:

	KeyState() : Down(false), Up(true), PressedThisFrame(false), ReleaseThisFrame(false) {}
	~KeyState() {}

	bool Down;
	bool Up;
	bool PressedThisFrame;
	bool ReleaseThisFrame;
};