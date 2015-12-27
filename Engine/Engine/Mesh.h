#pragma once

#include <string>

#include "glew.h"
#include "glm.hpp"

class Mesh
{
public:
	Mesh(float vertices[], int indices[]);
	Mesh(std::string objFileName);
	~Mesh();
private:
	// transform
	glm::vec3 position;
	glm::vec3 rotation;
	glm::mat4 worldMatrix;
	// mesh
	GLuint VBO;
	GLuint IBO;
	GLuint ElementCount;
	GLenum PrimitiveType;
	GLuint VAO;
	// material
	GLuint textureObj;
};

