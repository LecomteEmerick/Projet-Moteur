#pragma once

#include "Map.h"
#include "Landmark.h"
#include "Skybox.h"

class Scene
{
public:
	Scene();
	~Scene();
private:
	Landmark mark;
	Map mp;
	Skybox skybox;
};

