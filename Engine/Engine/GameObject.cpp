#include "GameObject.h"

#include <iostream>

#include "GameLoop.h"

#include "LogicComponent.h"
#include "PhysicComponent.h"
#include "RenderComponent.h"

GameObject::GameObject()
{
}

void GameObject::AddComponents(Component* comp)
{
	switch (comp->GetComponentType())
	{
	case RENDER_COMPONENT:
		GameLoop::RegisterDrawFunction(std::bind(&RenderComponent::Draw, (RenderComponent*)comp, std::placeholders::_1));
		break;
	case LOGIC_COMPONENT:
		GameLoop::RegisterLogicUpdateFunction(std::bind(&LogicComponent::UpdateLogic , (LogicComponent*)comp));
		break;
	case PHYSIC_COMPONENT:
		GameLoop::RegisterPhysicUpdateFunction(std::bind(&PhysicComponent::UpdatePhysics, (PhysicComponent*)comp));
		break;
	default:
		std::cout << "Error Component undefined." << std::endl << this << std::endl << "Component : " << comp << std::endl;
		return;
	}
	comp->GameObject = this;
	this->Components.push_back(std::unique_ptr<Component>(comp));
}

void GameObject::RemoveComponents(std::unique_ptr<Component> comp)
{
	this->Components.erase(std::find(this->Components.begin(), this->Components.end(), comp));
}

GameObject::~GameObject()
{
}
