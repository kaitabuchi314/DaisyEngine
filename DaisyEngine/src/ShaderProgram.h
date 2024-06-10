#pragma once
#include <include/GL/glew.h>
#include <iostream>

namespace Daisy
{
	class ShaderProgram
	{
	public:
		ShaderProgram(const char* vertexShader, const char* fragmentShader);

		void Bind();
		void Unbind();
		void Flush();
	public:
		unsigned int id;
	};

	inline ShaderProgram* mainShaderProgram;
	inline void SetShaderProgram(ShaderProgram* shaderProgram) { mainShaderProgram = shaderProgram; };
	inline ShaderProgram* GetShaderProgram() { return mainShaderProgram; };
}