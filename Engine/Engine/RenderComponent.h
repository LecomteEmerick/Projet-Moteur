#pragma once

#include "RenderDataBinder.h"
#include "Component.h"

class RenderComponent : Component
{
public:
	virtual ~RenderComponent(){}

	int GetComponentType() { return RENDER_COMPONENT; }
	virtual void Draw(const RenderDataBinder& render) = 0;
};