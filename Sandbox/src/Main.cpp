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


	RE::rect_BatchRenderer* batch_renderer;
	RE::Rect* rect;


	Sandbox() 
	{
		shader = RE::Shader::Create("res/shaders/texture-shader.shader");
		batch_renderer = new RE::rect_BatchRenderer(shader);
		rect = new RE::Rect({ 100, 300 }, { 100, 100 }, "res/images/cover.jpg");

		RE::Rect r2({ 100,100}, { 100,100 }, "res/images/cover.jpg");

		glm::mat4 P = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f);
		shader->Bind();
		shader->SetUniformMat4("u_Proj", P);
		shader->Unbind();
		
		batch_renderer->Attach(*rect);
		batch_renderer->Attach(r2);

	}

	/*
	void CreateShape(float x, float y, float w, float h) 
	{	
		float verticies[] = {
			x,	 y,	 0.0f,  1.0f,0.0f,1.0f,1.0f,  0.0f, 0.0f,  0.0f,
			x+w, y,	 0.0f,  1.0f,1.0f,1.0f,1.0f,  0.0f, 0.0f,  0.0f,
			x+w, y+h, 0.0f,  1.0f,1.0f,0.0f,1.0f,  0.0f, 0.0f,  0.0f,
			x,	 y+h, 0.0f,  0.0f,1.0f,1.0f,1.0f,  0.0f, 0.0f,  0.0f,
		};

		uint32_t indecies[6] = { 0,1,2,2,3,0 };

		RE::Rect rect = RE::Rect({ 100,200 }, { 100,100 }, NO_TEXTURE);
		auto vertex_data = rect.GetVertices();

		RE::Vertex verticies[4];
		memcpy(verticies, vertex_data.data(), 4 * sizeof(RE::Vertex));

		renderer = RE::Renderer::Create();
		vb = RE::VertexBuffer::Create(verticies, sizeof(verticies));
		ib = RE::IndexBuffer::Create(indecies, 6);
		va = RE::VertexArray::Create();

		auto layout = RE::VertexBufferLayout::Create();
		layout->PushFloat(3);
		layout->PushFloat(4);
		layout->PushFloat(2);
		layout->PushFloat(1);

		va->AddBuffer(vb, layout);
	}
		*/

	~Sandbox() 
	{
	}

	void Update() override 
	{
		//batch_renderer->BeginBatch();
		
		batch_renderer->Flush();
	}

};

RE::Application* CreateApplication() {
	return new Sandbox();
}