#pragma once

#include "glm.hpp"

class RenderDataBinder
{
public:
	RenderDataBinder(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix, const glm::mat4& worldTransform) :
		ProjectionMatrix(projectionMatrix), ViewMatrix(viewMatrix), WorldTransform(worldTransform) {}

	const glm::mat4& ProjectionMatrix_get() const { return this->ProjectionMatrix; }
	const glm::mat4& ViewMatrix_get() const { return this->ViewMatrix; }
	const glm::mat4& WorldMatrix_get() const { return this->WorldTransform; }

	~RenderDataBinder() {}
private:
	glm::mat4 ViewMatrix;
	glm::mat4 ProjectionMatrix;
	glm::mat4 WorldTransform;
};