#pragma once
#include <Daisy.h>
#include <ImGui/imgui.h>
#include <ImGui/imgui_impl_opengl3.h>
#include <ImGui/imgui_impl_glfw.h>

#define DAISY_EDITOR_VERSION "Daisy Editor v0.1"

class DaisyEditorLayer : public Daisy::GameLayer
{
public:
	DaisyEditorLayer();

	virtual void Run() override;


	virtual ~DaisyEditorLayer() override;
private:
    void SetDarkThemeColors();
    void DrawImGui();
private:
    Daisy::Window window;

    Daisy::ShaderProgram shaderProgram;

    Daisy::ComponentManager componentManager;
    Daisy::ComponentSystem componentSystem;

    Daisy::Texture texture;

    Daisy::Texture skybox;
    Daisy::Texture top;
    Daisy::Texture concrete;

    Daisy::Entity myEntity;

    glm::vec2 ws;

    ImFont* roboto;
    ImFont* robotoBold;

    bool objOneEn;
    double msf;
    double rms;
};
