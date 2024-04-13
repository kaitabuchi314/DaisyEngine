#include <DaisyEditorLayer.h>

DaisyEditorLayer::DaisyEditorLayer() :
    window("Daisy Editor v0.1", 1350, 900),
    shaderProgram(Daisy::dfvertexShaderSource, Daisy::textureFragmentShaderSource),
    texture("../SandboxProject/box.png"),
    top("../SandboxProject/top.png"),
    skybox("../SandboxProject/skybox.png"),
    concrete("../SandboxProject/concrete.jpg"),
    model(vertices, indices, sizeof(vertices), sizeof(indices)),
    position(0,0,0),
    scale(1,1,1)
{
    ws = window.GetSize();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    roboto = io.Fonts->AddFontFromFileTTF("Fonts/Roboto-Regular.ttf", 15);
    robotoBold = io.Fonts->AddFontFromFileTTF("Fonts/Roboto-Bold.ttf", 18);

    // Setup Dear ImGui style
    SetDarkThemeColors();
    //ImGui::StyleColorsDark();
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
        Daisy::SampleMoveCamera(&camera, window);
        camera.CalcView();

        if (Daisy::windowResized)
        {
            Daisy::Renderer::SetViewport(0, 0, ws.x, ws.y);
        }

        Daisy::Renderer::ClearScreen(0.0f, 82.0f, 109.0f);

        Daisy::Renderer::DrawMesh(position, scale, glm::vec3(0.0f, 0.0f, 0.0f), &model, &texture, &shaderProgram, &camera);
        Daisy::Renderer::DrawMesh(glm::vec3(0.0f,-1.0f,0.0f), glm::vec3(10,1,10), glm::vec3(0.0f, 0.0f, 0.0f), &model, &concrete, &shaderProgram, &camera);


        
        DrawSkybox(camera);
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);

        DrawImGui();

        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        ws = window.GetSize();
        window.EndFrame();
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void DaisyEditorLayer::DrawSkybox(Daisy::Camera camera)
{
    Daisy::Renderer::DrawMesh(glm::vec3(), glm::vec3(100,100,100), glm::vec3(0.0f, 0.0f, 0.0f), &model, &skybox, &shaderProgram, &camera);
    Daisy::Renderer::DrawMesh(glm::vec3(0, 99, 0), glm::vec3(100, 100, 100), glm::vec3(0.0f, 0.0f, 0.0f), &model, &top, &shaderProgram, &camera);

}

void DaisyEditorLayer::DrawImGui()
{

    ImGui::Begin("Settings");


    ImGui::PushFont(robotoBold);

    if (ImGui::Button("Object: "))
    {
        objOneEn = !objOneEn;
    }

    ImGui::PopFont();
    ImGui::Separator();

    if (objOneEn)
    {

        ImGui::PushFont(roboto);


        float sc[3] = { position.x,position.y,position.z };

        ImGui::Text("Position: ");
        ImGui::SameLine();
        ImGui::InputFloat3("###positioninput", sc);


        position.x = sc[0];
        position.y = sc[1];
        position.z = sc[2];

        float sac[3] = { scale.x,scale.y,scale.z };

        ImGui::Text("Scale: ");
        ImGui::SameLine();
        ImGui::InputFloat3("###scaleinput", sac);

        scale.x = sac[0];
        scale.y = sac[1];
        scale.z = sac[2];

        ImGui::PopFont();
    }

    ImGui::End();

}

void DaisyEditorLayer::SetDarkThemeColors() // Hazel 2D Theme Colors. Credit to StudioCherno and Hazel 2D
{
    auto& colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_WindowBg] = ImVec4{ 0.1f * 0.55f, 0.105f * 0.55f, 0.11f * 0.55f, 1.0f };

    // Headers
    colors[ImGuiCol_Header] = ImVec4{ 0.2f * 0.55f, 0.205f * 0.55f, 0.21f * 0.55f, 1.0f };
    colors[ImGuiCol_HeaderHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
    colors[ImGuiCol_HeaderActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

    // Buttons
    colors[ImGuiCol_Button] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
    colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
    colors[ImGuiCol_ButtonActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

    // Frame BG
    colors[ImGuiCol_FrameBg] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
    colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
    colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

    // Tabs
    colors[ImGuiCol_Tab] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
    colors[ImGuiCol_TabHovered] = ImVec4{ 0.38f, 0.3805f, 0.381f, 1.0f };
    colors[ImGuiCol_TabActive] = ImVec4{ 0.28f, 0.2805f, 0.281f, 1.0f };
    colors[ImGuiCol_TabUnfocused] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };

    // Title
    colors[ImGuiCol_TitleBg] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
    colors[ImGuiCol_TitleBgActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
}


DaisyEditorLayer::~DaisyEditorLayer()
{
    model.Flush();
    texture.Flush();
    shaderProgram.Flush();

    window.Terminate();
}
