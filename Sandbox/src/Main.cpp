#include <RaavanaEngine.h>
#include <iostream>

class Sandbox : public RE::Application {
public:

	Sandbox() {
	}

	~Sandbox() {
	}

	void Update() override {
	}

	void OnKeyPressed(RE::KeyPressed* e) override {
		if (e->GetKey() == RE_KEY_A) {
			std::cout << "A Key Pressed!" << std::endl;
		}
	}

};

RE::Application* CreateApplication() {
	return new Sandbox();
}