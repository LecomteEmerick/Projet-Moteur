#pragma once

#include "Component.h"

class PhysicComponent : Component
{
public:
	~PhysicComponent() {}

	void Start() {}
	void Destroy() {}

	int GetComponentType() { return PHYSIC_COMPONENT; }
	virtual void UpdatePhysics() = 0;
};