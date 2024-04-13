#pragma once
#include <include/GL/glew.h>
#include <glfw3.h>
#include <iostream>
#include <glm.hpp>

namespace Daisy
{
	class Window
	{
	public:
		Window(const char* windowName, int w, int h);

		bool ShouldClose();
		void EndFrame();
		void Terminate();
		glm::vec2 GetSize();

		GLFWwindow* window;
	};

	namespace KeyInput
	{
		bool GetKeyDown(Daisy::Window window, int key);

		bool GetKeyUp(Daisy::Window window, int key);
	}
}