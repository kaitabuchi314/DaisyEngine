#pragma once
#include "Daisy/Core/Core.h"

#ifdef HZ_PLATFORM_WINDOWS

extern Daisy::Application* Daisy::CreateApplication();

int main(int argc, char** argv)
{
	Daisy::Log::Init();

	HZ_PROFILE_BEGIN_SESSION("Startup", "DaisyProfile-Startup.json");
	auto app = Daisy::CreateApplication();
	HZ_PROFILE_END_SESSION();

	HZ_PROFILE_BEGIN_SESSION("Runtime", "DaisyProfile-Runtime.json");
	app->Run();
	HZ_PROFILE_END_SESSION();

	HZ_PROFILE_BEGIN_SESSION("Startup", "DaisyProfile-Shutdown.json");
	delete app;
	HZ_PROFILE_END_SESSION();
}

#endif
