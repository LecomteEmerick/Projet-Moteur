#pragma once

#include "glm.hpp"

class RenderDataBinder
{
public:
	RenderDataBinder(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix, const glm::mat4& worldTransform, const float& time) :
		ProjectionMatrix(projectionMatrix), ViewMatrix(viewMatrix), WorldTransform(worldTransform), Time(time) {}

	const glm::mat4& ProjectionMatrix_get() { return this->ProjectionMatrix; }
	const glm::mat4& ViewMatrix_get() { return this->ViewMatrix; }
	const glm::mat4& WorldMatrix_get() { return this->WorldTransform; }
	const float& Time_get() { return this->Time; }

	~RenderDataBinder() {}
private:
	glm::mat4 ProjectionMatrix;
	glm::mat4 ViewMatrix;
	glm::mat4 WorldTransform;
	float Time;
};