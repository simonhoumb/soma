#pragma once

#ifdef SM_PLATFORM_WINDOWS

extern Soma::Application* Soma::CreateApplication();

int main(int argc, char** argv) { 
	auto app = Soma::CreateApplication();
	app->Run();
	delete app;
}

#endif