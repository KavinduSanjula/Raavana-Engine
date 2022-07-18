#include <RaavanaEngine.h>
#include <iostream>

class Sandbox : public RE::Application {
public:

	Sandbox() {
		std::cout << m_Window->GetTitle() << std::endl;
		float verts[] = { 0.5f,0.5f };
		auto vb = RE::VertexBuffer::Create(nullptr, 2 * sizeof(float));
		vb->SetData(verts, 2 * sizeof(float));
	}

	~Sandbox() {

	}

	void Update() override {

	}

	void OnKeyPressed(RE::KeyPressed* e) override{
		std::cout << "Key Pressed " << e->GetKey() << " " << e->GetRepeatCount() << std::endl;
	}
};

RE::Application* CreateApplication() {
	return new Sandbox();
}