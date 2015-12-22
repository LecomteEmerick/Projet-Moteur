#pragma once

#include "common\EsgiShader.h"
#include "RenderDataBinder.h"

const float vertex[] = {
	-1.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f,  1.0f, 1.0f, 0.0f, 0.0f,
	 1.0f, 0.0f,  1.0f, 1.0f, 0.0f, 0.0f,
	 1.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f
};

const unsigned short indices[] = {
	0, 1,
	1, 3,
	3, 0,
	1, 2,
	2, 3,
	3, 1
};

class Map
{
public:
					Map();
	void			Draw(const RenderDataBinder& render);
					~Map();

private:
	void			ConstructEBO();
	void			ConstructVBO();

	GLuint			EBO;
	GLuint			VBO;
	GLuint			ShaderProgram;
	EsgiShader		Shader;
};

