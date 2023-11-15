#pragma once

#include "Daisy.h"

#include <imgui/imgui.h>

class GameLayer : public Daisy::Layer
{
public:
	GameLayer();
	virtual ~GameLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Daisy::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Daisy::Event& e) override;
	bool OnMouseButtonPressed(Daisy::MouseButtonPressedEvent& e);
	bool OnWindowResize(Daisy::WindowResizeEvent& e);
private:
	void CreateCamera(uint32_t width, uint32_t height);
	bool circleCircle(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r);
private:
	Daisy::Scope<Daisy::OrthographicCamera> m_Camera;
	Daisy::Ref<Daisy::Texture2D> m_ShipTexture;
	bool useful;
	bool show_text;
	float x;
	float y;
	float sx;
	float sy;
};