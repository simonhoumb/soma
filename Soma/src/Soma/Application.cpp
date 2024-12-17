#include "smpch.h"
#include "Application.h"
#include "Soma/Events/ApplicationEvent.h"
#include "Soma/Events/MouseEvent.h"

namespace Soma {

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}