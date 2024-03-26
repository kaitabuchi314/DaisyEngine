#include "Input.h"
#include <iostream>

namespace Daisy
{
	namespace Input
	{
		bool GetKeyPressed(int key)
		{
			return key == keyPressed;
		}
		bool GetKeyUp(int key)
		{
			return key == keyUp;
		}
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (action == GLFW_PRESS)
			{
				keyPressed = key;
			}
			else if (action == GLFW_RELEASE)
			{
				keyUp = key;
				keyPressed = 0;
			}
		}
	}
}