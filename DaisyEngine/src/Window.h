#pragma once

#include <include/GL/glew.h>
#include <glfw3.h>
#include <string>
#include <iostream>

namespace Daisy
{
	class Window
	{
	public:
		Window(int width, int height, std::string title);
		bool WindowClosed();
		void EndFrame();
		void Flush();

		GLFWwindow* window;
	};
};