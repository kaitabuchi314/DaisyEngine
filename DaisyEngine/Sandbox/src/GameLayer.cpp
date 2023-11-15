#include "GameLayer.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace Daisy;

GameLayer::GameLayer()
	: Layer("GameLayer")
{
	auto& window = Application::Get().GetWindow();
	CreateCamera(window.GetWidth(), window.GetHeight());
	x = 0;
	y = 0;
	sx = 1;
	sy = 1;
}

void GameLayer::OnAttach()
{
	m_ShipTexture = Texture2D::Create("assets/textures/Ship.png");

	ImGuiIO io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;  

}

void GameLayer::OnDetach()
{
}

void GameLayer::OnUpdate(Daisy::Timestep ts)
{
	// Render
	Daisy::RenderCommand::SetClearColor({ 0.0f, 0.0f, 0.0f, 1 });
	Daisy::RenderCommand::Clear();

	Daisy::Renderer2D::BeginScene(*m_Camera);
	Renderer2D::DrawQuad({ x, y, 0 }, { sx, sy }, -1.5708, m_ShipTexture);
	Daisy::Renderer2D::EndScene();
}

void GameLayer::OnImGuiRender()
{
	ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
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
	ImGui::InputFloat(" ", &x);
	ImGui::Text("Y: ");
	ImGui::SameLine();
	ImGui::InputFloat("  ", &y);

	ImGui::Text("Scale: ");
	ImGui::Text("W: ");
	ImGui::SameLine();
	ImGui::InputFloat("   ", &sx);

	ImGui::Text("H: ");
	ImGui::SameLine();
	ImGui::InputFloat("    ", &sy);

	ImGui::End();
}

void GameLayer::OnEvent(Daisy::Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowResizeEvent>(HZ_BIND_EVENT_FN(GameLayer::OnWindowResize));
	dispatcher.Dispatch<MouseButtonPressedEvent>(HZ_BIND_EVENT_FN(GameLayer::OnMouseButtonPressed));
}

bool GameLayer::OnMouseButtonPressed(Daisy::MouseButtonPressedEvent& e)
{
	return true;
}

bool GameLayer::OnWindowResize(Daisy::WindowResizeEvent& e)
{
	CreateCamera(e.GetWidth(), e.GetHeight());
	return false;
}

void GameLayer::CreateCamera(uint32_t width, uint32_t height)
{
	float aspectRatio = (float)width / (float)height;

	float camWidth = 8.0f;
	float bottom = -camWidth;
	float top = camWidth;
	float left = bottom * aspectRatio;
	float right = top *aspectRatio;
	m_Camera = CreateScope<OrthographicCamera>(left, right, bottom, top);
}
bool GameLayer::circleCircle(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r)
{

	// get distance between the circle's centers
	// use the Pythagorean Theorem to compute the distance
	float distX = c1x - c2x;
	float distY = c1y - c2y;
	float distance = sqrt((distX * distX) + (distY * distY));

	// if the distance is less than the sum of the circle's
	// radii, the circles are touching!
	if (distance <= c1r + c2r) {
		return true;
	}
	return false;
}