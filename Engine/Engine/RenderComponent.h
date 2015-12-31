#pragma once

#include "RenderDataBinder.h"
#include "Component.h"

class RenderComponent : Component
{
public:
	virtual ~RenderComponent(){}

	void Start() {}
	void Destroy() {}

	int GetComponentType() { return RENDER_COMPONENT; }
	virtual void Draw(const RenderDataBinder& render) = 0;
};