#include <RaavanaEngine.h>
#include <iostream>

class Sandbox : public RE::Application {
public:

	Sandbox() {
		float vertices[] = { -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f };
		uint32_t indeces[] = { 0, 1, 2, 2, 3, 0 };

		auto vb = RE::VertexBuffer::Create(vertices, sizeof(vertices));
		auto ib = RE::IndexBuffer::Create(indeces, 6);
		auto va = RE::VertexArray::Create();
		auto shader = RE::Shader::Create("main.shader");

		auto bl = RE::VertexBufferLayout::Create();
		bl->PushFloat(2);
		va->AddBuffer(vb, bl);

		auto r = RE::Renderer::Create();
		r->Clear();
		r->Draw(va, ib,shader, 6);
	}

	~Sandbox() {
	}

	void Update() override {
		float vertices[] = { -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f };
		uint32_t indeces[] = { 0, 1, 2, 2, 3, 0 };

		auto vb = RE::VertexBuffer::Create(vertices, sizeof(vertices));
		auto ib = RE::IndexBuffer::Create(indeces, 6);
		auto va = RE::VertexArray::Create();
		auto shader = RE::Shader::Create("main.shader");

		auto bl = RE::VertexBufferLayout::Create();
		bl->PushFloat(2);
		va->AddBuffer(vb, bl);

		auto r = RE::Renderer::Create();
		r->Clear();
		r->Draw(va, ib, shader, 6);
	}

};

RE::Application* CreateApplication() {
	return new Sandbox();
}