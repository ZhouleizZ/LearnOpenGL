#pragma once
#include "ShaderProgram.h"

extern const char* VERTEX_SHADER_FILLPATH;
extern const char* FRAGMENT_SHADER_FILLPATH;

class StaticShader : public ShaderProgram
{
public:

	StaticShader() :ShaderProgram(VERTEX_SHADER_FILLPATH, FRAGMENT_SHADER_FILLPATH) {}

};