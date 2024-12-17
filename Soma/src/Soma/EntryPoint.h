#pragma once

#ifdef SOMA_PLATFORM_WINDOWS

extern Soma::Application* Soma::CreateApplication();

int main(int argc, char** argv) { 
	Soma::Log::Init();

	auto app = Soma::CreateApplication();
	app->Run();
	delete app;
}

#endif