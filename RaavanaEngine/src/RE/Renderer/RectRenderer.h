#pragma once

#include <unordered_map>
#include <array>
#include <string>

#include "Vertex.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"
#include "Renderer.h"


#include "RE/core.h"
#include "RE/Drawables/Rect.h"


#define MAX_RECT_COUNT 1
#define MAX_TEXTURE_COUNT 1


namespace RE {

	struct BindableTexture {
		float bind_id;
		Ref<Texture> texture;
	};

	class RE_API RectRenderer {

	public:
		RectRenderer(Ref<Shader> shader);

		void Clear(float r, float g, float b, float a);
		void BeginBatch();
		void Submit(const Rect& Rect);
		void Flush();

	private:
		void Draw();
		void GenerateIndeces();
		void CreateTexture(const Rect& path);

	private:

		int m_SubmitCount = 0;
		int m_IndexToDraw = 0;
		float m_TextureID = 1;

		Vertex m_Vertices[4 * MAX_RECT_COUNT];
		uint32_t m_Indeces[6 * MAX_RECT_COUNT];
		std::vector<Rect> m_Rects;

		Ref<VertexArray> m_VA;
		Ref<VertexBuffer> m_VB;
		Ref<IndexBuffer> m_IB;
		Ref<Shader> m_Shader;
		Ref<Renderer> m_Renderer;
		Ref<Texture> m_WhiteTexture;

		std::unordered_map<uint32_t, BindableTexture> m_TextureMap;

		Float4 m_ClearColor = { 0.1,0.1,0.1,1.0 };

	};

}
