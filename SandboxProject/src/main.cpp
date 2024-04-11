#include <Daisy.h>

float vertices[] =
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

unsigned int indices[] =
{
    0,  1,  2,  2,  3,  0,
    4,  5,  6,  6,  7,  4,
    8,  9, 10, 10, 11,  8,
    12, 13, 14, 14, 15, 12,
    16, 17, 18, 18, 19, 16,
    20, 21, 22, 22, 23, 20
};


int main()
{
    Daisy::Window window = Daisy::Window("My Window", 800, 700);

    Daisy::ShaderProgram shaderProgram = Daisy::ShaderProgram(Daisy::dfvertexShaderSource, Daisy::textureFragmentShaderSource);

    Daisy::Texture texture = Daisy::Texture("box.png");

    Daisy::Model model = Daisy::Model(vertices, indices, sizeof(vertices), sizeof(indices));

    glm::vec2 ws = window.GetSize();

    Daisy::Camera camera = Daisy::Camera(ws);


    while (!window.ShouldClose())
    {
        Daisy::SampleMoveCamera(&camera, window);

        camera.CalcView();

        Daisy::Renderer::ClearScreen(0.0f, 82.0f, 109.0f);

        Daisy::Renderer::DrawMesh(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), 100, &model, &texture, &shaderProgram, &camera);

        window.EndFrame();
    }

    model.Flush();
    texture.Flush();
    shaderProgram.Flush();
    
    window.Terminate();
    return 0;
}