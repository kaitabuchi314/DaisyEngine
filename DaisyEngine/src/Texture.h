#pragma once
#include <include/GL/glew.h>
#include <string>
#include <stb_image.h>
#include <iostream>

namespace Daisy
{
	class Texture
	{
	public:
		Texture(std::string path);

		void Bind();
		void Unbind();
		void Flush();

		int width;
		int height;
		int nrChannels;
	private:
		unsigned int id;
	};
}