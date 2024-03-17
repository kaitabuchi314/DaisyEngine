#include <include/GL/glew.h>
#include <glfw3.h>
#include <stb_image.h>
#include <iostream>
#include <Window.h>
#include <Renderer2D.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

int main()
{
    Daisy::Window window(1000, 800, "My Window");

    Daisy::Renderer2D renderer;
    renderer.InitOpenGL();

    renderer.GenShaders();
    renderer.GenBuffers();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui::StyleColorsDark();
    Daisy::Image img = renderer.LoadImage("guy.png");

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window.window, true);
    ImGui_ImplOpenGL3_Init();

    float x = 0;
    float y = 0;

    while (!window.WindowClosed())
    {
        x = x + 1;
        y = y + 1;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
        renderer.ClearScreen(0.3f, 0.6f, 0.2f);

        renderer.DrawImage(img, x, y);

        ImGui::Begin("Settings");
        ImGui::Text("Hello, ImGui!");
        ImGui::End();
        ImGui::EndFrame();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        window.EndFrame();
    }

    
    Daisy::FlushImage(img);
    renderer.Flush();
    window.Flush();
    return 0;
}