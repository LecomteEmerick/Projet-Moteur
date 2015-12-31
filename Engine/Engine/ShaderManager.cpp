#include "ShaderManager.h"

#include "boost\filesystem.hpp"

EsgiShader ShaderManager::Shader;
std::map<std::string, GLuint> ShaderManager::ShaderProgramList;
const std::string ShaderManager::ShaderLibPath = "../../ShaderLib/";

void ShaderManager::Initialize()
{
	boost::filesystem::directory_iterator end_itr;

	for (boost::filesystem::directory_iterator itr(ShaderManager::ShaderLibPath); itr != end_itr; ++itr)
	{
		//boost::filesystem::path p(itr->path);
		std::string filename = itr->path().stem().string();
		if (ShaderManager::ShaderProgramList.find(filename) == ShaderManager::ShaderProgramList.end())
		{
			bool test = ShaderManager::Shader.LoadVertexShader((ShaderManager::ShaderLibPath + filename + ".vs").c_str());
			bool test2 = ShaderManager::Shader.LoadFragmentShader((ShaderManager::ShaderLibPath + filename + ".fs").c_str());
			ShaderManager::Shader.Create();

			ShaderManager::ShaderProgramList[filename] = ShaderManager::Shader.GetProgram();
		}
	}
}
