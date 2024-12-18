#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Soma/Events/ApplicationEvent.h"
#include "Soma/Events/MouseEvent.h"

namespace Soma {

	class SOMA_API Application {
	public:
		Application();
		virtual ~Application();
		
		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();	
}

