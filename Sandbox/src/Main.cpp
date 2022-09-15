#include <RaavanaEngine.h>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

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

		glm::mat4 proj = glm::ortho(0,10,0,1);
		glm::mat4  view = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f));
		glm::mat4 vp = proj * view;

		m_Rect = new RE::Rect({ 0,0 }, { 1,1 }, NO_TEXTURE, {1.0f, 1.0f,1.0f,1.0f });
		shader = RE::AssetManager::CreateShader("res/shaders/texture-shader.shader");
		shader->Bind();
		shader->SetUniformMat4("u_Proj", vp);
		shader->Unbind();

		uint32_t indeces[] = { 0, 1, 2, 2, 3, 0 };

		RE::Vertex verticies[4];

		auto data = m_Rect->GetVertices();

		memcpy(verticies, data.data(), 4 * sizeof(RE::Vertex));

		vb = RE::VertexBuffer::Create(verticies, 4 * sizeof(RE::Vertex));
		ib = RE::IndexBuffer::Create(indeces, 6);
		va = RE::VertexArray::Create();

		va->AddBuffer(vb,RE::Vertex::GetLayout());

		renderer = RE::Renderer::Create();
		auto tex = RE::AssetManager::CreateTexture("res/images/cover.jpg");
		auto tex2 = RE::AssetManager::CreateTexture(NO_TEXTURE);
		//tex->Bind(0);
		tex2->Bind(0);


	}

	~Sandbox() {
		delete m_Rect;
	}

	void Update() override {
		renderer->Draw(va, ib, shader, 6);
	}

};

RE::Application* CreateApplication() {
	return new Sandbox();
}