#pragma once
#include <include/GL/glew.h>
#include <Model.h>
#include <glm.hpp>
#include <Texture.h>
#include <ShaderProgram.h>
#include <ext.hpp>
#include <Camera.h>

namespace Daisy
{
	namespace Renderer
	{
		void ClearScreen(float r, float g, float b);

		void DrawMesh(glm::vec3 position, glm::vec3 scale, float angle, Daisy::Model* mesh, Daisy::Texture* texture, Daisy::ShaderProgram* shaderProgram, Daisy::Camera* camera);

	}
}