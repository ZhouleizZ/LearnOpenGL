#include "ShaderProgram.h"
#include "glad/glad.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include"GLFW/glfw3.h"


ShaderProgram::ShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath)
{

	vertexFilePath = vertexShaderPath;
	fragmentFilePath = fragmentShaderPath;

	programid = createProgram();
}

void ShaderProgram::Start()
{
	glUseProgram(programid);


	// ����uniform��ɫ
	float timeValue = glfwGetTime();
	float greenValue = sin(timeValue) / 2.0f + 0.5f;
	int vertexColorLocation = glGetUniformLocation(programid, "GlobalColor");
	glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
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
