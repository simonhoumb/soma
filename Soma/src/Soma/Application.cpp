#include "smpch.h"
#include "Application.h"
#include "Soma/Log.h"
#include "Soma/Events/ApplicationEvent.h"
#include "Soma/Events/MouseEvent.h"

namespace Soma {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e1(1920, 1080);
		SOMA_CORE_TRACE(e1.ToString());
		while (true) {}
	}
}