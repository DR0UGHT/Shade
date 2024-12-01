#include "sdpch.h"
#include "Application.h"

namespace Shade
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		SHADE_CORE_TRACE(e);

		while (true);
	}
}