#pragma once

#include <string>

#define GLEW_STATIC
#include "glew.h"

class LoaderObj
{
public:
	static void LoadObjFile(const std::string &inputFile, GLuint& VBO, GLuint& IBO, GLuint& VAO, GLuint& textureObj);
	static bool LoadAndCreateTextureRGBA(const char *filename, GLuint &texID);
	static bool LoadAndCreateCubeMap(const char* filesname[], GLuint &cubeMapID);
};

