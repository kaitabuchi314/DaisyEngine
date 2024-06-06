#include "Renderer.h"

namespace Daisy
{

	namespace Renderer
	{
        void SetViewport(float x, float y, float w, float h)
        {

            glViewport(x, y, w, h);
        }

		void ClearScreen(float r, float g, float b)
		{
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);
			glClearColor(r/255,g/255,b/255, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

        void DrawMesh(glm::vec3 position, glm::vec3 scale, glm::vec3 rotation, Daisy::Model* mesh, Daisy::Texture* texture, Daisy::ShaderProgram* shaderProgram, Daisy::Camera* camera)
        {
            mesh->Bind();
            glm::mat4 model = glm::mat4(1.0f);
            glm::vec3 rr = glm::radians(rotation);
            //glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(1.0f, 0.5f, 0.0f));
            //glm::mat4 rotationMatrix = glm::yawPitchRoll(rr.x, rr.y, rr.z);

            model = glm::rotate(model, rr.z, glm::vec3(0.0f, 0.0f, 1.0f));
            // Pitch (around the X-axis)
            model = glm::rotate(model, rr.y, glm::vec3(1.0f, 0.0f, 0.0f));
            // Yaw (around the Y-axis)
            model = glm::rotate(model, rr.x, glm::vec3(0.0f, 1.0f, 0.0f));

            model = glm::translate(model, position);
            model = glm::scale(model, scale);

            shaderProgram->Bind();
            texture->Bind();

            glUniformMatrix4fv(glGetUniformLocation(shaderProgram->id, "model"), 1, GL_FALSE, glm::value_ptr(model));
            glUniformMatrix4fv(glGetUniformLocation(shaderProgram->id, "view"), 1, GL_FALSE, glm::value_ptr(camera->view));
            glUniformMatrix4fv(glGetUniformLocation(shaderProgram->id, "projection"), 1, GL_FALSE, glm::value_ptr(camera->projection));


            glDrawElements(GL_TRIANGLES, mesh->vertCount, GL_UNSIGNED_INT, 0);

            texture->Unbind();

            mesh->Unbind();

            shaderProgram->Unbind();
        }
	}

    namespace Renderer2D
    {
        void Init2D()
        {
            float vertices[] =
            {

                -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,
                 0.5f, -0.5f, 0.0f,  1.0f, 0.0f,
                 0.5f,  0.5f, 0.0f,  1.0f, 1.0f,
                -0.5f,  0.5f, 0.0f,  0.0f, 1.0f
            };

            unsigned int indices[] =
            {
                0, 1, 2,
                2, 3, 0
            };

            plane = new Model(vertices, indices, sizeof(vertices), sizeof(indices));
            glEnable(GL_BLEND);

            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            plane->Bind();
        }

        void SetViewport(float x, float y, float w, float h)
        {
            glViewport(x, y, w, h);
        }

        void ClearScreen(float r, float g, float b)
        {
            glClearColor(r / 255, g / 255, b / 255, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void DrawImage(glm::vec3 position, glm::vec3 scale, float angle, Daisy::Texture* texture, Daisy::ShaderProgram* shaderProgram, Daisy::Camera* camera)
        {
            glm::mat4 model = glm::mat4(1.0f);
            float rr = glm::radians(angle);
            //glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(1.0f, 0.5f, 0.0f));
            //glm::mat4 rotationMatrix = glm::yawPitchRoll(rr.x, rr.y, rr.z);
            model = glm::translate(model, position);
            model = glm::scale(model, scale);
            model = glm::rotate(model, rr, glm::vec3(0.0f, 0.0f, 1.0f));
            // Pitch (around the X-axis)
            //model = glm::rotate(model, rr.y, glm::vec3(1.0f, 0.0f, 0.0f));
            // Yaw (around the Y-axis)
            //model = glm::rotate(model, rr.x, glm::vec3(0.0f, 1.0f, 0.0f));



            shaderProgram->Bind();

            glUniformMatrix4fv(glGetUniformLocation(shaderProgram->id, "model"), 1, GL_FALSE, glm::value_ptr(model));
            glUniformMatrix4fv(glGetUniformLocation(shaderProgram->id, "view"), 1, GL_FALSE, glm::value_ptr(camera->view));
            glUniformMatrix4fv(glGetUniformLocation(shaderProgram->id, "projection"), 1, GL_FALSE, glm::value_ptr(camera->projection));

            texture->Bind();

            glDrawElements(GL_TRIANGLES, plane->vertCount, GL_UNSIGNED_INT, 0);

            texture->Unbind();

            shaderProgram->Unbind();
        }

        void Flush()
        {
            plane->Unbind();
            delete plane;
        }
    }
}