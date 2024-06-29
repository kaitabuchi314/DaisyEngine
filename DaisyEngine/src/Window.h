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

	inline Window* activeWindow;
	inline void SetActiveWindow(Window* a) { activeWindow = a; };
	inline Window* GetActiveWindow() { return activeWindow; };

	inline bool GetMouseDown(int button) { return GetActiveWindow()->GetMouseDown(0); };
	inline bool GetMouseUp(int button) { return GetActiveWindow()->GetMouseUp(0); };
	inline glm::vec2 GetMousePos() { return GetActiveWindow()->GetMousePosition(); };

	void ResizeCallback(GLFWwindow* window, int width, int height);

	namespace KeyInput
	{
		bool GetKeyDown(int key);

		bool GetKeyUp(int key);
	}
}