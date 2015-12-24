#include "LoaderObj.h"

#include "tinyobjLoader\tiny_obj_loader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void LoaderObj::LoadObjFile(const std::string &inputFile, GLuint& VBO,GLuint& IBO,GLuint& VAO, GLuint& textureObj)
{
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;

	std::string err = tinyobj::LoadObj(shapes, materials, inputFile.c_str());
	const std::vector<unsigned int>& indices = shapes[0].mesh.indices;
	const std::vector<float>& positions = shapes[0].mesh.positions;
	const std::vector<float>& normals = shapes[0].mesh.normals;
	const std::vector<float>& texcoords = shapes[0].mesh.texcoords;

	//g_Objet.ElementCount = indices.size();

	uint32_t stride = 0;

	if (positions.size()) {
		stride += 3 * sizeof(float);
	}
	if (normals.size()) {
		stride += 3 * sizeof(float);
	}
	if (texcoords.size()) {
		stride += 2 * sizeof(float);
	}

	const auto count = positions.size() / 3;
	const auto totalSize = count * stride;

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), &indices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, totalSize, nullptr, GL_STATIC_DRAW);

	// glMapBuffer retourne un pointeur sur la zone memoire allouee par glBufferData 
	// du Buffer Object qui est actuellement actif - via glBindBuffer(<cible>, <id>)
	// il est imperatif d'appeler glUnmapBuffer() une fois que l'on a termine car le
	// driver peut tres bien etre amener a modifier l'emplacement memoire du BO.
	float* vertices = (float*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	for (auto index = 0; index < count; ++index)
	{
		if (positions.size()) {
			memcpy(vertices, &positions[index * 3], 3 * sizeof(float));
			vertices += 3;
		}
		if (normals.size()) {
			memcpy(vertices, &normals[index * 3], 3 * sizeof(float));
			vertices += 3;
		}
		if (texcoords.size()) {
			memcpy(vertices, &texcoords[index * 2], 2 * sizeof(float));
			vertices += 2;
		}
	}
	glUnmapBuffer(GL_ARRAY_BUFFER);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	uint32_t offset = 3 * sizeof(float);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, stride, nullptr);
	glEnableVertexAttribArray(0);
	if (normals.size()) {
		glVertexAttribPointer(1, 3, GL_FLOAT, false, stride, (GLvoid *)offset);
		glEnableVertexAttribArray(1);
		offset += 3 * sizeof(float);
	}
	if (texcoords.size()) {
		glVertexAttribPointer(2, 2, GL_FLOAT, false, stride, (GLvoid *)offset);
		glEnableVertexAttribArray(2);
		offset += 2 * sizeof(float);
	}
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	LoadAndCreateTextureRGBA(materials[0].diffuse_texname.c_str(), textureObj);
}

bool LoaderObj::LoadAndCreateTextureRGBA(const char *filename, GLuint &texID)
{
	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);

	// il est obligatoire de specifier une valeur pour GL_TEXTURE_MIN_FILTER
	// autrement le Texture Object est considere comme invalide
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	int w, h;
	uint8_t *data = stbi_load(filename, &w, &h, nullptr, STBI_rgb_alpha);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

		stbi_image_free(data);
	}
	return (data != nullptr);
}

bool LoaderObj::LoadAndCreateCubeMap(const char* filesname[], GLuint &cubeMapID)
{
	int w, h, comp;

	glGenTextures(1, &cubeMapID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubeMapID);

	for (int faceIndex = 0; faceIndex < 6; ++faceIndex)
	{
		const char * filename = filesname[faceIndex];
		uint8_t * data = stbi_load(filename, &w, &h, &comp, STBI_rgb_alpha);
		if (data == nullptr)
			return false;
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + faceIndex, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	// glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	return true;
}
