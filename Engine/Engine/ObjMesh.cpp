#include "ObjMesh.h"

#include "GameLoop.h"
#include "LoaderObj.h"



#include "glm.hpp"
#include "gtx\euler_angles.hpp"
#include "gtc\type_ptr.hpp"

ObjMesh::ObjMesh(std::string filePath)
{
	LoaderObj::LoadObjFile(filePath, this->Obj_VBO, this->Obj_IBO, this->Obj_VAO, this->Obj_Texture, this->IndicesCount);

	this->Obj_Shader.LoadVertexShader("ShaderLib/basicObj.vs");
	this->Obj_Shader.LoadFragmentShader("ShaderLib/basicObj.fs");
	this->Obj_Shader.Create();

	GameLoop::RegisterDrawFunction(std::bind(&ObjMesh::Draw, this, std::placeholders::_1));
}

void ObjMesh::Draw(const RenderDataBinder& render)
{


	auto program = this->Obj_Shader.GetProgram();
	glUseProgram(program);

	glUniformMatrix4fv(glGetUniformLocation(program, "view"), 1, GL_FALSE, glm::value_ptr(render.ViewMatrix_get()));
	glUniformMatrix4fv(glGetUniformLocation(program, "projection"), 1, GL_FALSE, glm::value_ptr(render.ProjectionMatrix_get()));

	auto worldLocation = glGetUniformLocation(program, "u_worldMatrix");

	glBindTexture(GL_TEXTURE_2D, this->Obj_Texture);

	glBindVertexArray(this->Obj_VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->Obj_IBO);


	float yaw = glm::radians(0.0f);
	float pitch = glm::radians(0.0f);
	float roll = glm::radians(0.0f);
	glm::mat4& transform = glm::eulerAngleYXZ(yaw, pitch, roll);
	glUniformMatrix4fv(worldLocation, 1, GL_FALSE, glm::value_ptr(transform));

	glDrawElements(GL_TRIANGLES, IndicesCount, GL_UNSIGNED_INT, 0);
}

ObjMesh::~ObjMesh()
{

}
