#pragma once

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
private:
	int loadShader(const char* filePath,int type);
};
