#include "Scene.h"

Scene::Scene()
{
	this->ObjList.push_back(ObjMesh("ObjLib/Sonic/Sonic.obj"));
}


Scene::~Scene()
{
}
