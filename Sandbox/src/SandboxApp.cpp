#include <Soma.h>

class ExampleLayer : public Soma::Layer {
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override {
		SOMA_CLIENT_INFO("ExampleLayer::Update");
	}

	void OnEvent(Soma::Event& event) override {
		SOMA_CLIENT_TRACE("{0}", event.ToString());
	}
};

class Sandbox : public Soma::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}

};

Soma::Application* Soma::CreateApplication() {
	return new Sandbox();
}