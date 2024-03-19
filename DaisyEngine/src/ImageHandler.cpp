#pragma once
#include "Renderer2D.h"

namespace Daisy
{

    Renderer2D* activeRenderer;
    void ActivateRenderer(Renderer2D* renderer) { activeRenderer = renderer; };

    Image LoadImage(std::string path)
    {
        stbi_set_flip_vertically_on_load(true);

        int width, height, nrChannels;
        unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
        if (!data)
        {
            std::cerr << "Failed to load texture" << std::endl;
        }

        GLuint texture;

        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        if (nrChannels == 3) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        }
        else if (nrChannels == 4) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        }
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
        return Image(texture);
    }

    void DrawImage(Image tex, float x, float y, float scaleX, float scaleY)
    {

        glUseProgram(activeRenderer->shaderProgram);
        int constantPositionLocation = glGetUniformLocation(activeRenderer->shaderProgram, "position");
        glUniform2f(constantPositionLocation, x, y);
        int constantScaleLocation = glGetUniformLocation(activeRenderer->shaderProgram, "scale");
        glUniform2f(constantScaleLocation, scaleX, scaleY);

        glBindTexture(GL_TEXTURE_2D, tex.id);

        glBindVertexArray(activeRenderer->VAO);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glBindVertexArray(0);
    }
}