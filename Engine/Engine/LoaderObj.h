#pragma once

#include <string>
#include <vector>

#define GLEW_STATIC
#include "glew.h"

class LoaderObj
{
public:
	static void LoadObjFile(const std::string &inputFile, GLuint& VBO, GLuint& IBO, GLuint& VAO, GLuint& textureObj, int& elementCount);
	static bool LoadAndCreateTextureRGBA(const char *filename, GLuint &texID);
	static bool LoadAndCreateCubeMap(std::vector<const GLchar*> filesname, GLuint &cubeMapID);
};

