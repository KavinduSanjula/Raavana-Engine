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

};

RE::Application* CreateApplication() {
	return new Sandbox();
}