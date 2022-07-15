#include "ggpch.h"
#include "Application.h"
#include "GGE/Events/ApplicationEvent.h"
#include "GGE/Log.h"

namespace GGSE
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
		if(e.IsInCategory(EventCategoryApplication))
			GGS_CLIENT_TRACE(e);

		if(e.IsInCategory(EventCategoryInput))
			GGS_CLIENT_TRACE(e);
	}

	Application* CreateApplication()
	{
		return nullptr;
	}
}
