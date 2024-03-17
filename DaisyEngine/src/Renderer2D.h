#pragma once
#include <include/GL/glew.h>
#include <glfw3.h>
#include <stb_image.h>
#include <iostream>

namespace Daisy
{

    struct Image
    {
        GLuint id;
    };

    void FlushImage(Image img);

    class Renderer2D
    {
    public:
        GLuint VBO, VAO, EBO;
        GLuint fragmentShader;
        GLuint vertexShader;
        GLuint shaderProgram;

        void InitRenderer();
        void InitOpenGL();
        void GenShaders();
        void GenBuffers();

        Image LoadImage(std::string path);

        void DrawImage(Image tex, float x, float y, float scaleX, float scaleY);

        void ClearScreen(float r, float g, float b);

        void Flush();
    };
}