#pragma once

#include <string>

#include "glew.h"
#include "RenderDataBinder.h"
#include "common\EsgiShader.h"

class ObjMesh
{
public:
	ObjMesh(std::string filePath);
	~ObjMesh();

	void Draw(const RenderDataBinder& render);

private:
	// mesh
	GLuint Obj_VBO;
	GLuint Obj_VAO;
	GLuint Obj_IBO;

	GLuint Obj_Texture;

	EsgiShader Obj_Shader;

	int IndicesCount;

};

