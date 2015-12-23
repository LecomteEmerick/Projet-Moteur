#pragma once

#include "RenderDataBinder.h"
#include "common\EsgiShader.h"

const float vertex[] = { 
	0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f
};

const unsigned short indices[] = {
	0, 1,
	0, 2,
	0, 3
};

class Landmark
{
public:
					Landmark();
	void			Draw(const RenderDataBinder& render) const;
	void			Destroy();
					~Landmark();
private:
	void			ConstructEBO();
	void			ConstructVBO();
	GLuint			EBO;
	GLuint			VBO;
	GLuint			ShaderProgram;
	EsgiShader		Shader;
};

