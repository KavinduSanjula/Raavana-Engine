#include "repch.h"
#include "RectRenderer.h"
#include "RE/AssetManager/AssetManager.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace RE {


	RectRenderer::RectRenderer(Ref<Shader> shader)
		:m_Shader(shader)
	{
		m_Renderer = Renderer::Create();

		GenerateIndeces();

		m_VA = VertexArray::Create();
		m_VB = VertexBuffer::Create(nullptr, MAX_RECT_COUNT * 4 * sizeof(Vertex));
		m_IB = IndexBuffer::Create(nullptr, MAX_RECT_COUNT * 6);

		int texIDs[] = { 0,1,2,3,4,5,6,7,8,9,10 };

		m_Shader->Bind();
		m_Shader->SetUniformArrayI("u_Textures", MAX_TEXTURE_COUNT, texIDs);
		m_Shader->Unbind();

		m_IB->SetData(m_Indeces, sizeof(m_Indeces));
		m_VA->AddBuffer(m_VB, Vertex::GetLayout());
	}

	void RectRenderer::BeginBatch()
	{
		//auto proj = m_Camera->GetViewProjection();
		auto proj = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, -1.0f, 1.0f);

		m_Shader->Bind();
		m_Shader->SetUniformMat4("u_Proj", proj);
		m_Shader->Unbind();

		m_SubmitCount = 0;
		m_PtrOffset = 0;
		m_Rects.clear();
		m_TextureID = 1;
		m_TextureMap.clear();

		m_TextureMap[NO_TEXTURE] = 0;
		m_Textures[0] = AssetManager::CreateTexture(NO_TEXTURE);
	}

	void RectRenderer::Submit(const Rect& rect)
	{
		if (m_SubmitCount >= MAX_RECT_COUNT) {
			Flush();
			BeginBatch();
		}

		if (m_TextureID >= MAX_TEXTURE_COUNT) {
			Flush();
			BeginBatch();
		}

		CreateTexture(rect);

		m_Rects.push_back(rect);
		m_IndexToDraw += 6;
		m_SubmitCount++;

	}

	void RectRenderer::Flush()
	{

		for (int i = 0; i < MAX_TEXTURE_COUNT; i++) {
			if (m_Textures[i])
				m_Textures[i]->Bind(i);
		}

		m_IB->SetData(m_Indeces, sizeof(m_Indeces));

		memset(m_Vertices, 0, MAX_RECT_COUNT * 4 * sizeof(Vertex));

		int offset = 0;
		for (auto quad : m_Rects) {
			auto vertices = quad.GetVertices();
			memcpy(m_Vertices + offset, vertices.data(), 4 * sizeof(Vertex));
			offset += 4;
		}

		m_VB->SetData(m_Vertices, sizeof(m_Vertices));

		Draw();
	}

	void RectRenderer::Clear()
	{
		m_Renderer->Clear();
		m_DrawCallCount = 0;
	}

	void RectRenderer::Draw()
	{
		m_Renderer->Draw(m_VA, m_IB, m_Shader, m_IndexToDraw);
		m_DrawCallCount++;
	}

	void RectRenderer::GenerateIndeces()
	{
		int ptr = 0;
		for (int i = 0; i < MAX_RECT_COUNT; i++) {
			m_Indeces[ptr++] = 0 + (i * 4);
			m_Indeces[ptr++] = 1 + (i * 4);
			m_Indeces[ptr++] = 2 + (i * 4);
			m_Indeces[ptr++] = 2 + (i * 4);
			m_Indeces[ptr++] = 3 + (i * 4);
			m_Indeces[ptr++] = 0 + (i * 4);
		}
	}

	void RectRenderer::CreateTexture(const Rect& rect)
	{
		std::string path = rect.GetTexturePath();

		if (m_TextureMap.find(path) == m_TextureMap.end()) {

			int tex_id = (int)m_TextureID;
			m_TextureMap[path] = m_TextureID;

			m_Textures[tex_id] = Texture::Create(path);

			rect.SetTextureID(m_TextureID);
			m_TextureID++;
		}
		else {
			float texID = m_TextureMap[path];
			rect.SetTextureID(texID);
		}
	}

}