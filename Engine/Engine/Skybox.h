#pragma once

#include "common\EsgiShader.h"
#include "glew.h"
#include "RenderDataBinder.h"

class Skybox
{
public:
	Skybox();
	~Skybox();

	void Draw(const RenderDataBinder& render);

private:
	// mesh
	GLuint Skybox_VBO;
	GLuint Skybox_VAO;

	GLuint Skybox_Texture;

	EsgiShader Skybox_Shader;
};

