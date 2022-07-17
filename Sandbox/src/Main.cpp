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

	void OnEvent(RE::Event* e) override{
		if (e->GetObjectType() == RE::EventType::KeyPressed) {

			auto ev = *((RE::KeyPressed*)e);
			if (ev.GetRepeatCount() > 0) {
				std::cout << "Repeating " << ev.GetKey() << std::endl;
			}
			else {
				std::cout << "Pressed " << ev.GetKey() << std::endl;
			}
		}
		if (e->GetObjectType() == RE::EventType::KeyReleased) {

			auto ev = *((RE::KeyReleased*)e);
			std::cout << "Key released " << ev.GetKey() << std::endl;
		}

		delete e;
	}

};

RE::Application* CreateApplication() {
	return new Sandbox();
}