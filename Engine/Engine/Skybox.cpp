#include "Skybox.h"

#include <vector>

#include "gtc\type_ptr.hpp"

#include "GameLoop.h"
#include "LoaderObj.h"

Skybox::Skybox()
{
	std::vector<const GLchar*> faces;
	faces.push_back("../../Textures/skybox/right.jpg");
	faces.push_back("../../Textures/skybox/left.jpg");
	faces.push_back("../../Textures/skybox/top.jpg");
	faces.push_back("../../Textures/skybox/bottom.jpg");
	faces.push_back("../../Textures/skybox/back.jpg");
	faces.push_back("../../Textures/skybox/front.jpg");

	GLfloat skyboxVertices[] = {
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f,  1.0f
	};

	glGenVertexArrays(1, &this->Skybox_VAO);
	glGenBuffers(1, &this->Skybox_VBO);

	glBindVertexArray(this->Skybox_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->Skybox_VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

	glBindVertexArray(0);

	LoaderObj::LoadAndCreateCubeMap(faces, this->Skybox_Texture);

	this->Skybox_Shader.LoadVertexShader("ShaderLib/skybox.vs");
	this->Skybox_Shader.LoadFragmentShader("ShaderLib/skybox.fs");
	this->Skybox_Shader.Create();

	/*auto program = this->Skybox_Shader.GetProgram();
	glUseProgram(program);

	auto blockIndex = glGetUniformBlockIndex(program, "ViewProj");
	glUniformBlockBinding(program, blockIndex, GameLoop::mainCamera.UBO);
	auto cubemapIndex = glGetUniformLocation(program, "u_CubeMap");

	glUniform1i(cubemapIndex, 0);
	glUseProgram(0);*/

	GameLoop::RegisterDrawFunction(std::bind(&Skybox::Draw, this, std::placeholders::_1));
}


void Skybox::Draw(const RenderDataBinder& render)
{
	//glBindBuffer(GL_UNIFORM_BUFFER, GameLoop::mainCamera.UBO);
	//glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4) * 2, glm::value_ptr(render.ViewMatrix_get()));

	glDepthMask(GL_FALSE);

	auto program = this->Skybox_Shader.GetProgram();

	glUseProgram(program);

	glUniformMatrix4fv(glGetUniformLocation(program, "view"), 1, GL_FALSE, glm::value_ptr(render.ViewMatrix_get()));
	glUniformMatrix4fv(glGetUniformLocation(program, "projection"), 1, GL_FALSE, glm::value_ptr(render.ProjectionMatrix_get()));

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindVertexArray(this->Skybox_VAO);
	glActiveTexture(GL_TEXTURE0);

	glUniform1i(glGetUniformLocation(program, "skybox"), 0);

	glBindTexture(GL_TEXTURE_CUBE_MAP, this->Skybox_Texture);

	//glDepthFunc(GL_LEQUAL);

	glDrawArrays(GL_TRIANGLES, 0, 36);//8 * 2 * 3);

	glBindVertexArray(0);
	glDepthMask(GL_TRUE);
	//glDepthFunc(GL_LESS);
}

Skybox::~Skybox()
{

}