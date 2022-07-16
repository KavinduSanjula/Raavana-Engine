#include <RaavanaEngine.h>
#include <iostream>

class Sandbox : public RE::Application {
public:

	Sandbox() {
		std::cout << m_Window->GetTitle() << std::endl;
		float verts[] = { 0.5f,0.5f };
		auto vb = RE::VertexBuffer::Create(verts, 2 * sizeof(float));
	}

	~Sandbox() {

	}

	void Update() override {

	}

};

RE::Application* CreateApplication() {
	return new Sandbox();
}