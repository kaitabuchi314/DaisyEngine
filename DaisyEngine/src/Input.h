#pragma once
#include <glfw3.h>
namespace Daisy
{
	namespace Input
	{
		struct KeyboardEvent
		{
			int key;
			int action;
		};
		inline int keyPressed = 0;
		inline int keyUp = 0;
		bool GetKeyPressed(int key);
		bool GetKeyUp(int key);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	}
}