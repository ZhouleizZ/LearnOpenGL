#pragma once
#include "ShaderProgram.h"

const char* VERTEX_SHADER_FILLPATH = "../../Shader/vertexShader.vs";
const char* FRAGMENT_SHADER_FILLPATH = "../../Shader/fragmentShader.fs";

class StaticShader : public ShaderProgram
{
public:
	StaticShader() :ShaderProgram(VERTEX_SHADER_FILLPATH, FRAGMENT_SHADER_FILLPATH) {}

};