#include <RaavanaEngine.h>
#include <iostream>

class Sandbox : public RE::Application {
public:

	RE::Ref<RE::VertexBuffer> vb;
	RE::Ref<RE::IndexBuffer> ib;
	RE::Ref<RE::VertexArray> va;
	RE::Ref<RE::Shader> shader;
	RE::Ref<RE::Renderer> renderer;

	Sandbox() {
		float vertices[] = { -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f };
		uint32_t indeces[] = { 0, 1, 2, 2, 3, 0 };

		vb = RE::VertexBuffer::Create(vertices, sizeof(vertices));
		ib = RE::IndexBuffer::Create(indeces, 6);
		va = RE::VertexArray::Create();
		shader = RE::Shader::Create("res/basic.shader");
		renderer = RE::Renderer::Create();

		auto bl = RE::VertexBufferLayout::Create();
		bl->PushFloat(2);
		va->AddBuffer(vb, bl);
	}

	~Sandbox() {
	}

	void Update() override {
		renderer->Clear();
		renderer->Draw(va, ib, shader, 6);
	}

};

RE::Application* CreateApplication() {
	return new Sandbox();
}