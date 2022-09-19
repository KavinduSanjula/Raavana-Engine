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

		m_WhiteTexture = AssetManager::CreateTexture(NO_TEXTURE);

		int texIDs[] = { 0,1,2,3,4,5,6,7,8,9,10 };

		m_Shader->Bind();
		m_Shader->SetUniformArrayI("u_Textures", MAX_TEXTURE_COUNT, texIDs);
		m_Shader->Unbind();

		m_IB->SetData(m_Indeces, sizeof(m_Indeces));
		m_VA->AddBuffer(m_VB, Vertex::GetLayout());
	}

	void RectRenderer::BeginBatch()
	{
		m_SubmitCount = 0;

		m_Rects.clear();

		m_TextureID = 1;
		m_TextureMap.clear();
		m_TextureMap[m_WhiteTexture->GetAssetID()] = { 0.0f, m_WhiteTexture };
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

		for (auto[uid,b_tex] : m_TextureMap) {
			b_tex.texture->Bind(b_tex.bind_id);
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

	void RectRenderer::Clear(float r, float g, float b, float a)
	{
		m_Renderer->Clear(r,g,b,a);
	}

	void RectRenderer::Draw()
	{
		Clear(m_ClearColor.x, m_ClearColor.y, m_ClearColor.z, m_ClearColor.w);
		m_Renderer->Draw(m_VA, m_IB, m_Shader, m_IndexToDraw);
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
		Ref<Texture> texture = AssetManager::CreateTexture(path);
		uint32_t texture_id = texture->GetAssetID();

		if (m_TextureMap.find(texture_id) == m_TextureMap.end()) {

			m_TextureMap[texture_id] = { m_TextureID, texture };
			rect.SetTextureID(m_TextureID);
			m_TextureID++;

		}
		else {
			rect.SetTextureID(m_TextureMap[texture_id].bind_id);
		}
	}

}