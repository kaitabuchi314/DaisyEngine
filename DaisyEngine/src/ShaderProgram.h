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

		unsigned int id;
	};
}