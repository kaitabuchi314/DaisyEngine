#pragma once
#include <Daisy.h>
#include <ImGui/imgui.h>
#include <ImGui/imgui_impl_opengl3.h>
#include <ImGui/imgui_impl_glfw.h>
#include <vector>
#include <algorithm>
#include <Petunia.h>
#include <memory>

#include <scriptlist.h>


#define DAISY_EDITOR_VERSION "Daisy Editor v0.1"

class DaisyEditorLayer : public Daisy::GameLayer
{
public:
	DaisyEditorLayer();

	virtual void Run() override;


	virtual ~DaisyEditorLayer() override;
private: // UI
    void ImGuiFrame();
    void SetDarkThemeColors();
    void SetPanelThemeColors();
    void DrawImGui();
    void DrawSpriteComponentUI();
    void DrawTransformComponentUI();
    void DrawScriptComponentUI();
private: // ECS
    void AddEntity();
    void SceneChange(int sceneID);
private:
    Daisy::Window window;

    Daisy::ShaderProgram shaderProgram;

    Daisy::Scene scene;

    Daisy::ComponentManager componentManager;
    Daisy::ComponentSystem componentSystem;

    glm::vec2 ws;

    glm::vec2 initialMousePos;
    glm::vec3 initialCameraPos;


    ImFont* roboto;
    ImFont* robotoBold;

    bool objOneEn = true;
    bool isDragging = false;
    double msf;
    double rms;
    int activeEditingEntity = -1;
};
