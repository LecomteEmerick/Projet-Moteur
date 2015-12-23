#pragma once

#include "common\EsgiShader.h"
#include "RenderDataBinder.h"

const float vertexMap[] = {
	-10.0f, 0.0f, -10.0f, 1.0f, 1.0f, 1.0f,
	-10.0f, 0.0f,  10.0f, 1.0f, 1.0f, 1.0f,
	 10.0f, 0.0f,  10.0f, 1.0f, 1.0f, 1.0f,
	 10.0f, 0.0f, -10.0f, 1.0f, 1.0f, 1.0f
};

const unsigned short indicesMap[] = {
	0,1,2,
	2,3,0
};

class Map
{
public:
					Map();
	void			Draw(const RenderDataBinder& render) const;
	void			Destroy();
					~Map();

private:
	void			ConstructEBO();
	void			ConstructVBO();

	GLuint			EBO;
	GLuint			VBO;
	GLuint			ShaderProgram;
	EsgiShader		Shader;
};

