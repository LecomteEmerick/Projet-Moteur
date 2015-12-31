#pragma once

#include <map>
#include <string>

#include "glew.h"
#include "common\EsgiShader.h"

class ShaderManager
{
public:
	static void Initialize();
private:
	static EsgiShader Shader;

	static std::map<std::string, GLuint> ShaderProgramList;

	static const std::string ShaderLibPath;
};

