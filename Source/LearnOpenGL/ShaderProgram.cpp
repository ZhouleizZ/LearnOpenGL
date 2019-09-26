#include "ShaderProgram.h"
#include "glad/glad.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include"GLFW/glfw3.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

ShaderProgram::ShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath)
{

	vertexFilePath = vertexShaderPath;
	fragmentFilePath = fragmentShaderPath;

	programid = createProgram();
}

void ShaderProgram::Start()
{
	glUseProgram(programid);

	setUniform_Color();
	setUniform_Texture();

	setUniform_Trans();

	setUniform_Viewmat4();
	setUniform_Projectionmat4();

}

void ShaderProgram::Stop()
{
	glUseProgram(0);
}

void ShaderProgram::CleanUp()
{
	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);

	glDetachShader(programid, vertexShaderId);
	glDetachShader(programid, fragmentShaderId);

	glDeleteProgram(programid);
}

void ShaderProgram::reloadShader()
{
	int reload_program_id = createProgram();
	if (reload_program_id)
	{
		glDeleteProgram(programid);
		programid = reload_program_id;
	}
}

 int ShaderProgram::createProgram()
{
	vertexShaderId = loadShader(vertexFilePath, GL_VERTEX_SHADER);
	fragmentShaderId = loadShader(fragmentFilePath, GL_FRAGMENT_SHADER);

	int pId = glCreateProgram();
	glAttachShader(pId, vertexShaderId);
	glAttachShader(pId, fragmentShaderId);
	glLinkProgram(pId);

	int success;
	glGetShaderiv(pId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		char ShaderPrograminfoLog[512];
		glGetShaderInfoLog(pId, 512, NULL, ShaderPrograminfoLog);
		std::cout << "Link program Error, info :" << ShaderPrograminfoLog << std::endl;
	}
	// ɾ����ɫ���������Ѿ����ӵ����ǵĳ������ˣ��Ѿ�������Ҫ��
	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);
	return pId;
}

 void ShaderProgram::setBool(const std::string& name, bool value) const
 {
	 glUniform1i(glGetUniformLocation(programid, name.c_str()), (int)value);
 }

 void ShaderProgram::setInt(const std::string& name, int value) const
 {
	 glUniform1i(glGetUniformLocation(programid, name.c_str()), value);
 }

 void ShaderProgram::setFloat(const std::string& name, float value) const
 {
	 glUniform1i(glGetUniformLocation(programid, name.c_str()), value);
 }

 void ShaderProgram::setUniform_Color()
 {
	 // ����uniform��ɫ
	 float timeValue = glfwGetTime();
	 float greenValue = sin(timeValue) / 2.0f + 0.5f;
	 int vertexColorLocation = glGetUniformLocation(programid, "GlobalColor");
	 glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
 }

 void ShaderProgram::setUniform_Texture()
 {
	 setInt("texture1", 0);
	 setInt("texture2", 1);
 }

 void ShaderProgram::setUniform_Trans()
 {
	 glm::mat4 trans;
	 /*trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
	 trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));*/
	 trans = glm::translate(trans, glm::vec3(0.f, 0.f, 0.0f));
	 trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
	 unsigned int transformLoc = glGetUniformLocation(programid, "transform");
	 glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
 }

 void ShaderProgram::setUniform_Modelmat4(glm::vec3 cubePositions,int factor)
 {
	 //ģ�;��� �任������ռ�
	 glm::mat4 model_;
	 model_ = glm::translate(model_, cubePositions);
	 float angle = 20.0f * factor;
	 model_ = glm::rotate(model_, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
	 int modelLoc = glGetUniformLocation(getProgramId(), "model");
	 glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model_));
 }

 void ShaderProgram::setUniform_Viewmat4()
 {
	 //�۲���� �任���ӽǿռ�
	 glm::mat4 view;
	 // ע�⣬���ǽ�����������Ҫ�����ƶ������ķ������ƶ���
	 view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.5f));
	 int viewLoc = glGetUniformLocation(programid, "view");
	 glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
 }

 void ShaderProgram::setUniform_Projectionmat4()
 {
	 //͸�Ӿ���  �任���ü��ռ�
	 glm::mat4 projection;
	 projection = glm::perspective(glm::radians(45.0f), 640.f / 480.f, 0.1f, 100.0f);
	 int projectionLoc = glGetUniformLocation(programid, "projection");
	 glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
 }

int ShaderProgram::loadShader(const char* filePath, int type)
{
	// 1. ���ļ�·���л�ȡ����/Ƭ����ɫ��
	std::string strShaderCode;
	std::ifstream shaderFile;
	// ��֤ifstream��������׳��쳣��
	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// ���ļ�
		std::stringstream shaderStream;
		shaderFile.open(filePath);
		// ��ȡ�ļ��Ļ������ݵ���������
		shaderStream << shaderFile.rdbuf();
		// �ر��ļ�������
		shaderFile.close();
		// ת����������string
		strShaderCode = shaderStream.str();

	}
	catch (std::exception e)
	{
		std::cout << "load shader error" << std::endl;
	}

	int shaderId = glCreateShader(type);
	const char* cShaderCode = strShaderCode.c_str();
	glShaderSource(shaderId,1,&cShaderCode,NULL);

	glCompileShader(shaderId);
	
	// ��ӡ�����������еĻ�
	int success;
	glGetShaderiv(shaderId,GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(shaderId,512,NULL,infoLog);
		std::cout << "compile shader Error, info :" << infoLog << std::endl;
	}

	return shaderId;
}
