#pragma once
#include <Daisy.h>

class SandboxLayer : public Daisy::GameLayer
{
public:
	SandboxLayer();

	virtual void Run() override;

	virtual ~SandboxLayer() override;
private:
    Daisy::Window window;

    Daisy::ShaderProgram shaderProgram;

    Daisy::Texture texture;

    Daisy::Model model;

    glm::vec2 ws;
};

inline float vertices[] =
{
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  1.0f, 1.0f,

     0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 1.0f,

     -0.5f,  0.5f,  0.5f,   0.0f, 1.0f,
      0.5f,  0.5f,  0.5f,   1.0f, 1.0f,
      0.5f,  0.5f, -0.5f,   1.0f, 0.0f,
     -0.5f,  0.5f, -0.5f,   0.0f, 0.0f,

     -0.5f, -0.5f,  0.5f,   1.0f, 1.0f,
      0.5f, -0.5f,  0.5f,   0.0f, 1.0f,
      0.5f, -0.5f, -0.5f,   0.0f, 0.0f,
     -0.5f, -0.5f, -0.5f,   1.0f, 0.0f
};

inline unsigned int indices[] =
{
    0,  1,  2,  2,  3,  0,
    4,  5,  6,  6,  7,  4,
    8,  9, 10, 10, 11,  8,
    12, 13, 14, 14, 15, 12,
    16, 17, 18, 18, 19, 16,
    20, 21, 22, 22, 23, 20
};