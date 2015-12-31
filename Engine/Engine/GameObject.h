#pragma once

#include <vector>
#include <memory>

#include "Transform.h"

class Component;

#include "Component.h"

class GameObject
{
public:
	GameObject();
	void AddComponents(Component* comp);
	void RemoveComponents(std::unique_ptr<Component> comp);
	~GameObject();
private:
	char* Name;
	std::vector<std::unique_ptr<Component>> Components;
	Transform Transform;
};

