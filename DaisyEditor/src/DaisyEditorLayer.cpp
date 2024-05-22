#include <DaisyEditorLayer.h>

DaisyEditorLayer::DaisyEditorLayer() :

    window(DAISY_EDITOR_VERSION, 1260, 900),

    shaderProgram(Daisy::dfvertexShaderSource, Daisy::textureFragmentShaderSource),
    texture("../SandboxProject/guy.png"),
    top("../SandboxProject/top.png"),
    skybox("../SandboxProject/skybox.png"),
    concrete("../SandboxProject/concrete.jpg"),
    //model(vertices, indices, sizeof(vertices), sizeof(indices)),
    position(0,0,0),
    scale(1,1,0)
{
    ws = window.GetSize();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    roboto = io.Fonts->AddFontFromFileTTF("Fonts/Roboto-Regular.ttf", 15);
    robotoBold = io.Fonts->AddFontFromFileTTF("Fonts/Roboto-Bold.ttf", 16);

    SetDarkThemeColors();

    ImGui_ImplGlfw_InitForOpenGL(window.window, true);

    ImGui_ImplOpenGL3_Init("#version 130");
    Daisy::Renderer2D::Init2D();
    
}

void DaisyEditorLayer::Run()
{
    Daisy::Camera camera = Daisy::Camera(ws, true, window);
    float w = 500;
    float vx = 800;
    float vy = 800;

    Daisy::Renderer2D::SetViewport(0, 0, ws.x, ws.y);

    std::cout << ws.x;
    double o_t = window.GetTime();
    double t = o_t;
    double o_rt = window.GetTime();
    double rt = o_rt;
    while (!window.ShouldClose())
    {
        t = window.GetTime();
        msf = (t - o_t) * 1000;

        o_t = t;

        Daisy::SampleMoveCamera2D(&camera, window);
        camera.CalcView();

        rt = window.GetTime();

        Daisy::Renderer2D::ClearScreen((0.1f * 0.55f) * 255, (0.105f * 0.55f) * 255, (0.11f * 0.55f)*255);

        Daisy::Renderer2D::DrawImage(position, scale, 0.0f, &texture, &shaderProgram, &camera);
        Daisy::Renderer2D::DrawImage(glm::vec3(0.0f,-1.0f,0.0f), glm::vec3(2,1,1), 100.0f, &concrete, &shaderProgram, &camera);

        DrawSkybox(camera);

#ifndef DIST
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
        DrawImGui();

        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
#endif
        rms = (rt - o_rt) * 1000;

        o_rt = rt;

        ws = window.GetSize();
        window.EndFrame();

    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void DaisyEditorLayer::DrawSkybox(Daisy::Camera camera)
{
    Daisy::Renderer2D::DrawImage(glm::vec3(), glm::vec3(100, 100, 0), 0, &skybox, &shaderProgram, &camera);

    //3D code
    //Daisy::Renderer::DrawMesh(glm::vec3(), glm::vec3(100,100,100), glm::vec3(0.0f, 0.0f, 0.0f), &model, &skybox, &shaderProgram, &camera);
    //Daisy::Renderer::DrawMesh(glm::vec3(0, 99, 0), glm::vec3(100, 100, 100), glm::vec3(0.0f, 0.0f, 0.0f), &model, &top, &shaderProgram, &camera);
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

    ImGui::Begin("Stats");

    glm::vec2 mp = window.GetMousePosition();

    ImGui::Text("Mouse X: ");

    ImGui::SameLine();
    
    ImGui::Text(std::to_string(mp.x).c_str());

    ImGui::Text("Mouse Y: ");

    ImGui::SameLine();

    ImGui::Text(std::to_string(mp.y).c_str());

    ImGui::Separator();

    if (window.GetMouseDown(DAISY_MOUSE_BUTTON_1))
    {
        ImGui::Text("Mouse Button 1 Pressed");
    } else if (window.GetMouseDown(DAISY_MOUSE_BUTTON_2))
    {
        ImGui::Text("Mouse Button 2 Pressed");
    } else if (window.GetMouseDown(DAISY_MOUSE_BUTTON_3))
    {
        ImGui::Text("Mouse Button 3 Pressed");
    }

    ImGui::Separator();

    ImGui::Text((std::string("Ms/f: ") + std::to_string(msf)).c_str());
    ImGui::Text((std::string("Render Time: ") + std::to_string(rms)).c_str());
    ImGui::Text((std::string("Compute Time: ") + std::to_string(msf-rms)).c_str());
    

    ImGui::End();

}

void DaisyEditorLayer::SetDarkThemeColors() // Hazel 2D Theme Colors. Credit to StudioCherno and Hazel 2D
{
    auto& style = ImGui::GetStyle();
    auto& colors = style.Colors;
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
    style.TabRounding = 3.5f;
    style.FrameRounding = 3.5f;
    style.GrabRounding = 3.5f;
    style.WindowRounding = 3.5f;
    style.PopupRounding = 3.5f;
}

DaisyEditorLayer::~DaisyEditorLayer()
{
    //model.Flush();
    texture.Flush();
    shaderProgram.Flush();

    window.Terminate();
    Daisy::Renderer2D::Flush();
}
