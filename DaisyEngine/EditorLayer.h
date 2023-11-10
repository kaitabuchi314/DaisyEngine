#pragma once
#include "GameLayer.h"
#include "SDL2/include/SDL.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_sdl2.h"
#include "ImGui/imgui_impl_sdlrenderer2.h"
#include "Vector2.h"

namespace Daisy
{
	class EditorLayer : public GameLayer
	{
	public:
		Vector2 pos;
		Vector2 scale;

		EditorLayer(SDL_Renderer* renderer, SDL_Window* window);
		void Create();
		void Start();
		void Loop();
		void EventPolled(SDL_Event e);
		void Draw();
		void Preloop();
	private:
		SDL_Renderer* renderer;
		SDL_Window* window;
		bool useful;
		bool show_text;
	};
}