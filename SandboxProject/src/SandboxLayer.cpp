#include <SandboxLayer.h>

SandboxLayer::SandboxLayer() :
    window("My Window", 800, 700),
    shaderProgram(Daisy::dfvertexShaderSource, Daisy::textureFragmentShaderSource),
    texture("box.png")//,
    //model(vertices, indices, sizeof(vertices), sizeof(indices))
{
    ws = window.GetSize();
}

void SandboxLayer::Run()
{
    Daisy::Camera camera = Daisy::Camera(ws, true);

    while (!window.ShouldClose())
    {
        Daisy::SampleMoveCamera(&camera, window);

        camera.CalcView();

        Daisy::Renderer::ClearScreen(0.0f, 82.0f, 109.0f);

        Daisy::Renderer::DrawMesh(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), glm::vec3(0.0f, 0.0f, 0.0f), &model, &texture, &shaderProgram, &camera);

        window.EndFrame();
    }
}

SandboxLayer::~SandboxLayer()
{
    model.Flush();
    texture.Flush();
    shaderProgram.Flush();

    window.Terminate();
}
