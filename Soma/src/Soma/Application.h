#pragma once

#include "Core.h"

namespace Soma {

	class SOMA_API Application {
	public:
		Application();
		virtual ~Application();
		
		void Run();
	};

	Application* CreateApplication();	
}

