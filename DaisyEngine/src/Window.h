#pragma once
#include <include/GL/glew.h>
#include <glfw3.h>
#include <iostream>
#include <glm.hpp>

namespace Daisy
{
	inline bool windowResized = true;
	inline int windowWidth = 0;
	inline int windowHeight = 0;

	class Window
	{
	public:
		Window(const char* windowName, int w, int h);

		bool ShouldClose();
		void EndFrame();
		void Terminate();
		bool GetMouseDown(int button);
		bool GetMouseUp(int button);
		glm::vec2 GetMousePosition();
		glm::vec2 GetSize();
		double GetTime();
	public:
		GLFWwindow* window;
	private:
		glm::vec2 mousePosition;
	};

	void ResizeCallback(GLFWwindow* window, int width, int height);

	namespace KeyInput
	{
		bool GetKeyDown(Daisy::Window window, int key);

		bool GetKeyUp(Daisy::Window window, int key);
	}
}