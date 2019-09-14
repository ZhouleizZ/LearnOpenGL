#pragma once

class ShaderProgram
{
private:
	int vertexShaderId;
	int fragmentShaderId;
	int programid;
public:
	ShaderProgram(const char * vertexShaderPath,const char* fragmentShaderPath);

	void Start();

	void Stop();

	void CleanUp();

private:
	int loadShader(const char* filePath,int type);
};
