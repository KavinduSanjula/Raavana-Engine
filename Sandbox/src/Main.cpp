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
	
	std::vector<RE::Rect*> rects;


	Sandbox() 
	{
		shader = RE::Shader::Create("res/shaders/texture-shader.shader");
		batch_renderer = new RE::rect_BatchRenderer(shader);

		for (int y = 0; y < 500; y += 100) {
			for (int x = 0; x < 1000; x += 200) {
				rects.push_back(new RE::Rect({ x + 100,y + 100 }, { 190, 90 }, "res/images/cover.jpg"));
			}
		}

		rects[5]->SetTexturePath("res/images/cover-2.jpg");
		rects[9]->SetTexturePath("res/images/cover-blue.jpg");
		rects[16]->SetTexturePath("res/images/cover-2.jpg");
		rects[20]->SetTexturePath("res/images/cover-blue.jpg");

		glm::mat4 P = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f);
		shader->Bind();
		shader->SetUniformMat4("u_Proj", P);
		shader->Unbind();
		
		

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
		batch_renderer->Clear();
		batch_renderer->Begin();
		for (auto rect : rects) {
			batch_renderer->Attach(*rect);
		}
		batch_renderer->Flush();

		//std::cout << "Draw Calls - " << batch_renderer->_GetDrawcallCount() << std::endl;
	}

};

RE::Application* CreateApplication() {
	return new Sandbox();
}