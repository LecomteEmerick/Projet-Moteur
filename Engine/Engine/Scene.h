#pragma once

#include <vector>

#include "Map.h"
#include "Landmark.h"
#include "Skybox.h"
#include "ObjMesh.h"

class Scene
{
public:
	Scene();
	~Scene();
private:
	Landmark mark;
	std::vector<ObjMesh> ObjList;
	Skybox skybox;
};

