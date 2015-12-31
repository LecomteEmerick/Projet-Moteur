#pragma once

#include <memory>

#include "ComponentType.h"

class GameObject;

#include "GameObject.h"

class Component
{
public:
	//virtual ~Component() {}

	virtual void Start() {}
	virtual void Destroy() {}
	virtual int GetComponentType() = 0;

	GameObject* GameObject;
};