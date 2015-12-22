#pragma once

class Time
{
public:
	static void		Start();
	static void		Update();
	static double	GetSecondElapsed();
	static void		Play();
	static void		Pause();
private:
	static double	time_;
	static bool		isStarted_;
	static double	previousTime_;
	static double	FpsCounterTime_;
	static int		nbFrames_;

	static bool		printFps_;

};

