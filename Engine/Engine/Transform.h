#pragma once

#include "vec3.hpp"

class Transform
{
public:
	Transform() : Position(glm::vec3(0.0f,0.0f,0.0f)), Rotation(glm::vec3(0.0f, 0.0f, 0.0f)), Scale(glm::vec3(1.0f, 1.0f, 1.0f)) { }
	Transform(glm::vec3 position) : Position(position), Rotation(glm::vec3(0.0f, 0.0f, 0.0f)), Scale(glm::vec3(1.0f, 1.0f, 1.0f)) { }
	Transform(glm::vec3 position, glm::vec3 rotation) : Position(position), Rotation(rotation), Scale(glm::vec3(1.0f, 1.0f, 1.0f)) { }
	Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : Position(position), Rotation(rotation), Scale(scale) { }

	glm::vec3 Position;
	glm::vec3 Rotation; //Quaternion ensuite
	glm::vec3 Scale;

	~Transform() { }
};