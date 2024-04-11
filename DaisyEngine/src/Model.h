#pragma once
#include <include/GL/glew.h>
#include <Defines_Renderer.h>
#include <iostream>
namespace Daisy
{
	class Model
	{
	public:
		Model(float vertices[], unsigned int indices[], unsigned int vertCount, unsigned int indicesCount);

		void Bind();
		void Unbind();
		void Flush();

	private:
		unsigned int VBO;
		unsigned int VAO;
		unsigned int EBO;
	};
}