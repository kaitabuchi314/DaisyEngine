#pragma once
#include <include/GL/glew.h>
#include <Model.h>
#include <glm.hpp>
#include <Texture.h>
#include <ShaderProgram.h>
#include <ext.hpp>
#include <Camera.h>
#include <gtc/matrix_transform.hpp>

namespace Daisy
{
	namespace Renderer
	{
		void SetViewport(float x, float y, float w, float h);

		void ClearScreen(float r, float g, float b);

		void DrawMesh(glm::vec3 position, glm::vec3 scale, glm::vec3 rotation, Daisy::Model* mesh, Daisy::Texture* texture, Daisy::ShaderProgram* shaderProgram, Daisy::Camera* camera);

	}
}