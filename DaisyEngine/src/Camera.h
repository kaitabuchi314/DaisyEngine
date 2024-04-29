#pragma once
#include <Window.h>
#include <glm.hpp>
#include <ext.hpp>
#include <glfw3.h>


namespace Daisy
{
	class Camera
	{
	public:
		Camera(glm::vec2 ws, bool perspective, Window window);

		void CalcView();

		glm::mat4 projection;
		glm::mat4 view;

		glm::vec3 cameraPos;
		glm::vec3 cameraFront;
		glm::vec3 cameraUp;
	};
}