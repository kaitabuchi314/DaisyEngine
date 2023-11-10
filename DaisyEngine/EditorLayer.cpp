#include "EditorLayer.h"

namespace Daisy
{
	EditorLayer::EditorLayer(SDL_Renderer* renderer, SDL_Window* window) : pos(0,0), scale(100,100)
	{
		this->renderer = renderer;
		this->window = window;
		useful = false;
		show_text = false;
	}

	void EditorLayer::Create()
	{
		// No need to do anything before window creation! This function still needs to be here.
	}

	void EditorLayer::Start()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigDockingWithShift = false;

		ImGui::StyleColorsDark();

		ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
		ImGui_ImplSDLRenderer2_Init(renderer);

		io.Fonts->AddFontDefault();
	}

	void EditorLayer::Loop()
	{

		
		ImGui::Begin("Hello World!");
		ImGui::Text("Coding is fun!");
		ImGui::Checkbox("Is coding fun?", &useful);
		if (useful)
		{
			ImGui::Text("I agree.");
		}
		else
		{
			ImGui::Text("Say what???");
		}

		if (ImGui::Button("Show hidden text: "))
		{
			show_text = !show_text;
		}

		if (show_text)
		{
			ImGui::Text("C++ is fun.");
		}

		ImGui::End();

		ImGui::Begin("Sprite Properties");

		ImGui::Text("Position: ");
		ImGui::Text("X: ");
		ImGui::SameLine();
		ImGui::InputInt(" ", &pos.x);
		ImGui::Text("Y: ");
		ImGui::SameLine();
		ImGui::InputInt("  ", &pos.y);

		ImGui::Text("Scale: ");
		ImGui::Text("W: ");
		ImGui::SameLine();
		ImGui::InputInt("   ", &scale.x);

		ImGui::Text("H: ");
		ImGui::SameLine();
		ImGui::InputInt("    ", &scale.y);

		ImGui::End();

		ImGui::Render();
	}
	void EditorLayer::EventPolled(SDL_Event e)
	{
		ImGui_ImplSDL2_ProcessEvent(&e);
	}

	void EditorLayer::Draw()
	{
		ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
	}
	void EditorLayer::Preloop()
	{
		ImGui_ImplSDLRenderer2_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		ImGui::NewFrame();
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
	}
}
