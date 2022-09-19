#pragma once


#include "RE/core.h"

#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"

#include "RE/Drawables/Rect.h"


#define MAX_RECT_COUNT 2
#define MAX_TEXTURE_COUNT 10


namespace RE {

	struct BindableTexture {
		float bind_id;
		Ref<Texture> texture;
	};

	class RE_API rect_BatchRenderer {

	public:
		rect_BatchRenderer(const Ref<Shader>& shader);
		~rect_BatchRenderer();

		void Clear();
	
		void Begin();
		void Attach(const Rect& rect);
		void Dettach(const Rect& rect);
		void Flush();

		inline int _GetDrawcallCount() { return _draw_call_count; }

	private:
		void GenerateIndeces();
		void CreateTexture(const Rect& rect);

	private:
		std::vector<Rect> m_Rects;
		std::unordered_map<uint32_t, BindableTexture> m_Textures;

		Vertex m_Verticies[4 * MAX_RECT_COUNT];
		int m_Indecies[6 * MAX_RECT_COUNT];

		Ref<Renderer> m_Renderer;
		Ref<VertexBuffer> m_vb;
		Ref<VertexArray> m_va;
		Ref<IndexBuffer> m_ib;
		Ref<Shader> m_shader;
		Ref<Texture> m_white_texture;

		uint32_t m_SubmitCount;
		uint32_t m_IndexCount;
		uint32_t m_TextureID;

		Float4 m_ClearColor = { 0.1, 0.1, 0.1, 1.0 };

		int _draw_call_count = 0;

	};

}