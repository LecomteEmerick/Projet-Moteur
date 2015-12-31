#pragma once

#include "RenderDataBinder.h"
#include "common\EsgiShader.h"

class BasicShader
{
public:
	BasicShader();
	void Draw(const RenderDataBinder& render);
	~BasicShader();
private:
	GLuint program;
	EsgiShader shader;
};

