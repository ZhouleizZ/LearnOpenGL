#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class ShaderProgram
{
private:
	int vertexShaderId;
	int fragmentShaderId;
	int programid;

	const char* vertexFilePath;
	const char* fragmentFilePath;
public:
	ShaderProgram(const char * vertexShaderPath,const char* fragmentShaderPath);

	void Start();

	void Stop();

	void CleanUp();

	void reloadShader();

	int createProgram();

	//uniform¹¤¾ßº¯Êý
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setMatrix4(const std::string& name, glm::mat4 value) const;
	int getProgramId() { return programid; };

	void  setUniform_Color();
	void  setUniform_Texture();
	void  setUniform_Trans();
	void  setUniform_Modelmat4(glm::vec3 cubePositions, int factor);
	void  setUniform_Viewmat4();
	void  setUniform_Projectionmat4();
private:
	int loadShader(const char* filePath,int type);
};
