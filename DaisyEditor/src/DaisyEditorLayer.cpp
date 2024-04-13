#include <DaisyEditorLayer.h>

DaisyEditorLayer::DaisyEditorLayer() :
    window("My Window", 800, 700),
    shaderProgram(Daisy::dfvertexShaderSource, Daisy::textureFragmentShaderSource),
    texture("../SandboxProject/box.png"),
    model(vertices, indices, sizeof(vertices), sizeof(indices))
{
    ws = window.GetSize();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window.window, true);

    ImGui_ImplOpenGL3_Init("#version 130");
}

void DaisyEditorLayer::Run()
{
    Daisy::Camera camera = Daisy::Camera(ws);

    while (!window.ShouldClose())
    {
        camera.CalcView();
        Daisy::Renderer::SetViewport(0, 0, ws.x, ws.y);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);

        Daisy::Renderer::ClearScreen(0.0f, 82.0f, 109.0f);

        Daisy::Renderer::DrawMesh(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), glm::vec3(0.0f, 0.0f, 0.0f), &model, &texture, &shaderProgram, &camera);

        ImGui::Begin("Settings");


        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        ws = window.GetSize();

        window.EndFrame();
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

DaisyEditorLayer::~DaisyEditorLayer()
{
    model.Flush();
    texture.Flush();
    shaderProgram.Flush();

    window.Terminate();
}
