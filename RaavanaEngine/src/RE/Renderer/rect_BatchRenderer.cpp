#include "repch.h"
#include "rect_BatchRenderer.h"

#include "AssetManager/AssetManager.h"

namespace RE {



	rect_BatchRenderer::rect_BatchRenderer(const Ref<Shader>& shader)
		:m_shader(shader)
	{
		m_Renderer = Renderer::Create();
		m_vb = VertexBuffer::Create(nullptr, 4 * MAX_RECT_COUNT * sizeof(Vertex));
		m_ib = IndexBuffer::Create(nullptr, 6 * MAX_RECT_COUNT);
		m_va = VertexArray::Create();

		GenerateIndeces();

		m_ib->SetData(m_Indecies, 6 * MAX_RECT_COUNT);
		m_va->AddBuffer(m_vb, Vertex::GetLayout());

		int texIDs[] = { 0,1,2,3,4,5,6,7,8,9,10 };

		m_shader->Bind();
		m_shader->SetUniformArrayI("u_Textures", MAX_TEXTURE_COUNT, texIDs);
		m_shader->Unbind();

		m_white_texture = AssetManager::CreateTexture(NO_TEXTURE);

	}

	rect_BatchRenderer::~rect_BatchRenderer()
	{
	}

	void rect_BatchRenderer::Clear()
	{
		m_Renderer->Clear(m_ClearColor.x, m_ClearColor.y, m_ClearColor.z, m_ClearColor.w);
		_draw_call_count = 0;
	}

	void rect_BatchRenderer::Begin()
	{
		m_SubmitCount = 0;
		m_IndexCount = 0;
		m_TextureID = 1;

		m_Textures.clear();
		m_Textures[m_white_texture->GetAssetID()] = { 0.0f,m_white_texture };

		m_Rects.clear();
	}

	void rect_BatchRenderer::Attach(const Rect& rect)
	{
		int texture_count = m_Textures.size();

		if (m_SubmitCount >= MAX_RECT_COUNT) {
			Flush();
			Begin();
		}

		if (texture_count >= MAX_TEXTURE_COUNT) {
			Flush();
			Begin();
		}

		CreateTexture(rect);

		m_SubmitCount++;
		m_IndexCount += 6;
		m_Rects.push_back(rect);
	}

	void rect_BatchRenderer::Dettach(const Rect& rect)
	{
	}

	void rect_BatchRenderer::Flush()
	{
		for (auto [uid, tex] : m_Textures) {
			tex.texture->Bind(tex.bind_id);
		}

		memset(m_Verticies, 0, sizeof(m_Verticies));

		int offset = 0;
		for (auto rect : m_Rects) {
			std::array<Vertex, 4> vert_data = rect.GetVertices();
			memcpy(m_Verticies + offset, vert_data.data(), 4 * sizeof(Vertex));
			offset += 4;
		}

		m_vb->SetData(m_Verticies,sizeof(m_Verticies));

		m_Renderer->Draw(m_va, m_ib, m_shader, m_IndexCount);

		_draw_call_count++;
	}

	void rect_BatchRenderer::GenerateIndeces()
	{
		int ptr = 0;
		for (int i = 0; i < MAX_RECT_COUNT; i++) {
			m_Indecies[ptr++] = 0 + (i * 4);
			m_Indecies[ptr++] = 1 + (i * 4);
			m_Indecies[ptr++] = 2 + (i * 4);
			m_Indecies[ptr++] = 2 + (i * 4);
			m_Indecies[ptr++] = 3 + (i * 4);
			m_Indecies[ptr++] = 0 + (i * 4);
		}
	}

	void rect_BatchRenderer::CreateTexture(const Rect& rect)
	{
		std::string path = rect.GetTexturePath();
		Ref<Texture> texture = AssetManager::CreateTexture(path);
		uint32_t texture_id = texture->GetAssetID();

		if (m_Textures.find(texture_id) == m_Textures.end()) {

			m_Textures[texture_id] = { (float)m_TextureID, texture };
			rect.SetTextureID(m_TextureID);
			m_TextureID++;

		}
		else {
			rect.SetTextureID(m_Textures[texture_id].bind_id);
		}
	}

}