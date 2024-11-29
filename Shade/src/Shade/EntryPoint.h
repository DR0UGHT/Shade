#pragma once

#ifdef SD_PLATFORM_WINDOWS

extern Shade::Application* Shade::CreateApplication();

int main(int argc, char** argv)
{
	printf("Shade Engine\n");
	auto app = Shade::CreateApplication();
	app->Run();
	delete app;
}

#endif