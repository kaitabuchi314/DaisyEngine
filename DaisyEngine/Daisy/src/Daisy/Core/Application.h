#pragma once

#include "Daisy/Core/Core.h"

#include "Daisy/Core/Window.h"
#include "Daisy/Core/LayerStack.h"
#include "Daisy/Events/Event.h"
#include "Daisy/Events/ApplicationEvent.h"

#include "Daisy/Core/Timestep.h"

#include "Daisy/ImGui/ImGuiLayer.h"

namespace Daisy {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}