#pragma once

#include "Component.h"

class PhysicComponent : Component
{
public:
	virtual ~PhysicComponent() {}
	int GetComponentType() { return PHYSIC_COMPONENT; }
	virtual void UpdatePhysics() = 0;
};