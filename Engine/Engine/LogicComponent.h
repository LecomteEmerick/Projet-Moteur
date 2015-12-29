#pragma once

#include "Component.h"

class LogicComponent : Component
{
public:
	virtual ~LogicComponent() {}
	int GetComponentType() { return LOGIC_COMPONENT; }
	virtual void UpdateLogic() = 0;
};