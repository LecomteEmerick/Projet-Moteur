#pragma once

#include <vector>

#include "glew.h"

class Mesh
{
public:
	Mesh(float vertex[]);
	Mesh(float vertex[], int indices[]);
	Mesh(char* objFilename);
	~Mesh();
private:


	GLuint	EBO;
	GLuint	VBO;
};

