#include <Soma.h>

class Sandbox : public Soma::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}

};

Soma::Application* Soma::CreateApplication() {
	return new Sandbox();
}