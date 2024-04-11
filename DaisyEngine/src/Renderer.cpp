#include "Renderer.h"

namespace Daisy
{

	namespace Renderer
	{
		void ClearScreen(float r, float g, float b)
		{
			glClearColor(r/255,g/255,b/255, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

        void DrawMesh(glm::vec3 position, glm::vec3 scale, float angle, Daisy::Model* mesh, Daisy::Texture* texture, Daisy::ShaderProgram* shaderProgram, Daisy::Camera* camera)
        {
            mesh->Bind();

            glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(1.0f, 0.5f, 0.0f));

            model = glm::translate(model, position);
            model = glm::scale(model, scale);

            shaderProgram->Bind();

            glUniformMatrix4fv(glGetUniformLocation(shaderProgram->id, "model"), 1, GL_FALSE, glm::value_ptr(model));
            glUniformMatrix4fv(glGetUniformLocation(shaderProgram->id, "view"), 1, GL_FALSE, glm::value_ptr(camera->view));
            glUniformMatrix4fv(glGetUniformLocation(shaderProgram->id, "projection"), 1, GL_FALSE, glm::value_ptr(camera->projection));

            texture->Bind();

            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

            texture->Unbind();

            mesh->Unbind();

            shaderProgram->Unbind();
        }
	}
}