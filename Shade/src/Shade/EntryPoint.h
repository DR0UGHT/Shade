#pragma once

#ifdef SD_PLATFORM_WINDOWS

extern Shade::Application* Shade::CreateApplication();

int main(int argc, char** argv)
{
	Shade::Log::Init();
	SHADE_CORE_WARN("Initialized Log!");
	SHADE_INFO("Hello!");


	auto app = Shade::CreateApplication();
	app->Run();
	delete app;
}

#endif