#include <RaavanaEngine.h>
#include <iostream>

class Sandbox : public RE::Application {
public:

	RE::Ref<RE::VertexBuffer> vb;
	RE::Ref<RE::IndexBuffer> ib;
	RE::Ref<RE::VertexArray> va;
	RE::Ref<RE::Shader> shader;
	RE::Ref<RE::Texture> texture;
	RE::Ref<RE::Renderer> renderer;

	RE::RectRenderer* m_Renderer;
	RE::Rect* m_Rect = nullptr;

	Sandbox() {
		/*
		
		float vertices[] = {	
			-0.5f, -0.5f, 0.0f, 0.0f,
			 0.5f, -0.5f, 1.0f, 0.0f,
			 0.5f,  0.5f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 1.0f
		};

		

		vb = RE::VertexBuffer::Create(vertices, sizeof(vertices));
		

		auto bl = RE::VertexBufferLayout::Create();
		bl->PushFloat(2);
		bl->PushFloat(2);
		va->AddBuffer(vb, bl);
		

		renderer = RE::Renderer::Create();

		RE::Rect rect({ -1.0f,-1.0f }, { 1.0f,1.0f }, NO_TEXTURE, {1.0f,0.0f,0.0f,1.0f});

		uint32_t indeces[] = { 0, 1, 2, 2, 3, 0 };

		ib = RE::IndexBuffer::Create(indeces, 6);
		va = RE::VertexArray::Create();

		va->AddBuffer(rect.GetVertexBuffer(), RE::Vertex::GetLayout());

		shader = RE::Shader::Create("res/shaders/texture-shader.shader");
		std::cout << "Shader 1 - " << shader->GetAssetID() << std::endl;
		texture = RE::Texture::Create("res/images/cover.jpg");
		std::cout << "Texture 1 - " << texture->GetAssetID() << std::endl;
		texture->Bind(0);
		shader->Bind();
		shader->SetUniformI1("tex", 0);

		*/
	}

	~Sandbox() {
		delete m_Rect;
	}

	void Update() override {
		auto raavana_texture = RE::AssetManager::CreateTexture("res/images/cover.jpg");
		//m_Renderer->BeginBatch();
		//m_Renderer->Submit(*m_Rect);
		//m_Renderer->Flush();
	}

};

RE::Application* CreateApplication() {
	return new Sandbox();
}