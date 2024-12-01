#pragma once

#include "Core.h"
#include "Shade/Events/Event.h"
#include "Shade/Events/ApplicationEvent.h"
#include "Shade/Log.h"

namespace Shade
{
	class SHADE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
