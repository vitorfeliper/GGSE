#pragma once

#include "Core.h"

namespace GGSE
{
	class GanjGameEngine_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

