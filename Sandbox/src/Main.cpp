#include <RaavanaEngine.h>
#include <iostream>
class Sandbox : public RE::Application {
public:
	Sandbox() {
		std::cout << m_Window->GetTitle() << std::endl;
	}

	~Sandbox() {

	}

	void Update() override {

	}
};

RE::Application* CreateApplication() {
	return new Sandbox();
}