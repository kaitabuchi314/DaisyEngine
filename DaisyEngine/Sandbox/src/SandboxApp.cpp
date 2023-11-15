#include <Daisy.h>
#include <Daisy/Core/EntryPoint.h>

#include "GameLayer.h"

class Sandbox : public Daisy::Application
{
public:
	Sandbox()
	{
		PushLayer(new GameLayer());
	}

	~Sandbox()

	{
	}
};

Daisy::Application* Daisy::CreateApplication()
{
	return new Sandbox();
}