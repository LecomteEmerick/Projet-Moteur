#include "Skybox.h"

#include "gtc\type_ptr.hpp"

#include "GameLoop.h"
#include "LoaderObj.h"

Skybox::Skybox()
{
	LoaderObj::LoadAndCreateCubeMap(skyboxFiles, this->Skybox_Texture);

	glGenVertexArrays(1, &this->Skybox_VAO);
	glGenBuffers(1, &this->Skybox_VBO);
	glBindVertexArray(this->Skybox_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->Skybox_VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glBindVertexArray(0);

	this->Skybox_Shader.LoadVertexShader("ShaderLib/skybox.vs");
	this->Skybox_Shader.LoadFragmentShader("ShaderLib/skybox.fs");
	this->Skybox_Shader.Create();

	auto program = this->Skybox_Shader.GetProgram();
	glUseProgram(program);

	auto blockIndex = glGetUniformBlockIndex(program, "ViewProj");
	glUniformBlockBinding(program, blockIndex, GameLoop::mainCamera.UBO);
	auto cubemapIndex = glGetUniformLocation(program, "u_CubeMap");

	glUniform1i(cubemapIndex, 0);
	glUseProgram(0);

	GameLoop::RegisterDrawFunction(std::bind(&Skybox::Draw, this, std::placeholders::_1));
}


void Skybox::Draw(const RenderDataBinder& render)
{
	glBindBuffer(GL_UNIFORM_BUFFER, GameLoop::mainCamera.UBO);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4) * 2, glm::value_ptr(render.ViewMatrix_get()));

	glUseProgram(this->Skybox_Shader.GetProgram());

	glBindTexture(GL_TEXTURE_CUBE_MAP, this->Skybox_Texture);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(this->Skybox_VAO);

	glDepthMask(GL_FALSE);
	glDepthFunc(GL_LEQUAL);

	glDrawArrays(GL_TRIANGLES, 0, 8 * 2 * 3);

	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LESS);
}

Skybox::~Skybox()
{

}