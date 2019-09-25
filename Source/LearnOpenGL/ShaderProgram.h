#pragma once
#include <iostream>
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
private:
	int loadShader(const char* filePath,int type);
};
