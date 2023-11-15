#pragma once

#include "Daisy/Core/Layer.h"

#include "Daisy/Events/ApplicationEvent.h"
#include "Daisy/Events/KeyEvent.h"
#include "Daisy/Events/MouseEvent.h"

namespace Daisy {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}