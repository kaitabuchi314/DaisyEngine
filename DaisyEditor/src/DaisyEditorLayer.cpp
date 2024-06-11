#include <DaisyEditorLayer.h>

DaisyEditorLayer::DaisyEditorLayer() :
    window(DAISY_EDITOR_VERSION, 1260, 900),

    shaderProgram(Daisy::dfvertexShaderSource, Daisy::textureFragmentShaderSource),
    componentManager(),
    componentSystem()
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

    Daisy::SetCurrentScene(&scene1);
}

void DaisyEditorLayer::Run()
{
    Daisy::Camera camera = Daisy::Camera(ws, true, window);
    Daisy::SetMainCamera(&camera);
    Daisy::SetShaderProgram(&shaderProgram);
    float w = 500;
    float vx = 800;
    float vy = 800;

    Daisy::Renderer2D::SetViewport(0, 0, ws.x, ws.y);

    double o_t = window.GetTime();
    double t = o_t;
    double o_rt = window.GetTime();
    double rt = o_rt;

    Daisy::Debug::Log("Starting Application.");

    while (!window.ShouldClose())
    {
        t = window.GetTime();
        msf = (t - o_t) * 1000;

        o_t = t;

        if (!ImGui::GetIO().WantTextInput)
            Daisy::SampleMoveCamera2D(&camera, window);
        
        camera.CalcView();

        rt = window.GetTime();

        componentSystem.update(componentManager, msf);
      
        Daisy::Renderer2D::ClearScreen((0.1f * 0.55f) * 255, (0.105f * 0.55f) * 255, (0.11f * 0.55f)*255);
 
        for (int i = 0; i < Daisy::GetActiveScene()->GetEntities().size(); i++)
        {
            Daisy::TransformComponent transformComponent = componentManager.getComponent<Daisy::TransformComponent>(Daisy::GetActiveScene()->GetEntities()[i]);

            componentSystem.render(componentManager);
        }

        // Dist builds do not include ImGui
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

void DaisyEditorLayer::DrawImGui()
{
    ImGui::Begin("Settings");
    
    ImGui::PushFont(robotoBold);

    if (Daisy::GetActiveScene()->GetEntities().size() > 0 && ImGui::Button((std::to_string(Daisy::GetActiveScene()->GetEntities()[activeEditingEntity]) + std::string(": ")).c_str()))
    {
        objOneEn = !objOneEn;
    }

    ImGui::PopFont();
    ImGui::Separator();

    if (objOneEn && Daisy::GetActiveScene()->GetEntities().size() > 0)
    {
        if (componentManager.hasComponent<Daisy::TransformComponent>(Daisy::GetActiveScene()->GetEntities()[activeEditingEntity]))
        {
            ImGui::PushFont(robotoBold);

            ImGui::Text("Transform Component: ");
            ImGui::PopFont();

            ImGui::PushFont(roboto);

            Daisy::TransformComponent* transformComponent = &componentManager.getComponent<Daisy::TransformComponent>(Daisy::GetActiveScene()->GetEntities()[activeEditingEntity]);

            float sc[3] = { transformComponent->position.x,transformComponent->position.y,transformComponent->position.z };

            ImGui::Text("Position: ");
            ImGui::SameLine();
            ImGui::InputFloat3("###positioninput", sc);


            transformComponent->position.x = sc[0];
            transformComponent->position.y = sc[1];
            transformComponent->position.z = sc[2];

            float sac[3] = { transformComponent->scale.x,transformComponent->scale.y,transformComponent->scale.z };

            ImGui::Text("Scale: ");
            ImGui::SameLine();
            ImGui::InputFloat3("###scaleinput", sac);

            transformComponent->scale.x = sac[0];
            transformComponent->scale.y = sac[1];
            transformComponent->scale.z = sac[2];

            ImGui::Text("Rotation: ");
            ImGui::SameLine();
            ImGui::SliderFloat("###rotationinput", &transformComponent->rotation.z, -360, 360);

            ImGui::PopFont();

            ImGui::Separator();
        }

        if (componentManager.hasComponent<Daisy::SpriteComponent>(Daisy::GetActiveScene()->GetEntities()[activeEditingEntity]))
        {
            ImGui::PushFont(robotoBold);

            ImGui::Text("Sprite Component: ");
            ImGui::PopFont();

            ImGui::PushFont(roboto);

            ImGui::Dummy(ImVec2(0, 0.1f));
            
            ImGui::Text("Texture Path: ");
            ImGui::SameLine();
            Daisy::SpriteComponent* spc = &componentManager.getComponent<Daisy::SpriteComponent>(Daisy::GetActiveScene()->GetEntities()[activeEditingEntity]);

            ImGui::InputText("###texturepathinput", spc->path, 128);
            if (ImGui::Button("Load"))
            {
                spc->image = Daisy::Texture(spc->path);
            }

            ImGui::PopFont();
        }

    }

    ImGui::End();

    ImGui::Begin("Objects");

    for (int i = 0; i < Daisy::GetActiveScene()->GetEntities().size(); i++)
    {
        if (i == activeEditingEntity)
        {
            ImGui::PushFont(robotoBold);
        } else
        {
            ImGui::PushFont(roboto);
        }

        if (ImGui::Button(std::to_string(Daisy::GetActiveScene()->GetEntities()[i]).c_str()))
        {
            activeEditingEntity = i;
        }

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

    ImGui::Begin("Topbar");

    int currentIDX = Daisy::GetActiveScene()->GetEntities().size();

    if (ImGui::Button("Add Entity"))
    {
        AddEntity();
        componentManager.addComponent<Daisy::TransformComponent>(Daisy::GetActiveScene()->GetEntities()[currentIDX], Daisy::TransformComponent {glm::vec3(), glm::vec3(1, 1, 1), glm::vec3(), Daisy::GetActiveScene()->GetEntities()[currentIDX]});
    }
   
    ImGui::End();

    ImGui::Begin("Add Component");

    if (ImGui::Button("Sprite Component") && Daisy::GetActiveScene()->GetEntities().size() > 0)
    {
        componentManager.addComponent<Daisy::SpriteComponent>(Daisy::GetActiveScene()->GetEntities()[activeEditingEntity], Daisy::SpriteComponent(Daisy::Texture(""), Daisy::GetActiveScene()->GetEntities()[activeEditingEntity]));
    }
    else if (ImGui::Button("Placeholder"))
    {

    }

    ImGui::End();

    ImGui::Begin("Scenes");

    ImGui::Text("Scene To Open: ");
    ImGui::SameLine();
    static char scene[128];
    ImGui::InputText("###scenetoopen", scene, IM_ARRAYSIZE(scene));

    bool open = ImGui::Button("Open");

    if (open)
    {
        if (std::string(scene).c_str() == std::string("Scene 1"))
        {
            Daisy::SetCurrentScene(&scene1);
        }
        else if (std::string(scene) == std::string("Scene 2"))
        {
            Daisy::SetCurrentScene(&scene2);
        }
    }

    ImGui::End();

}

void DaisyEditorLayer::AddEntity()
{
    int currentIDX = Daisy::GetActiveScene()->GetEntities().size();
    Daisy::GetActiveScene()->AddEntity(Daisy::CreateEntity());

    componentSystem.addEntity(Daisy::GetActiveScene()->GetEntities()[currentIDX]);
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
    for (int i = 0; i < Daisy::GetActiveScene()->GetEntities().size(); i++)
    {
        if (componentManager.hasComponent<Daisy::SpriteComponent>(Daisy::GetActiveScene()->GetEntities()[i]))
        {
            componentManager.getComponent<Daisy::SpriteComponent>(Daisy::GetActiveScene()->GetEntities()[i]).image.Flush();
        }
    }

    shaderProgram.Flush();

    window.Terminate();
    Daisy::Renderer2D::Flush();
}
