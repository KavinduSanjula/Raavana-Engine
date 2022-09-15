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
#define MAX_TEXTURE_COUNT 3


namespace RE {

	class RE_API RectRenderer {
	private:

		int m_SubmitCount = 0;
		int m_PtrOffset = 0;
		int m_DrawCallCount = 0;
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


		std::unordered_map<std::string, float> m_TextureMap;
		std::array<Ref<Texture>, MAX_TEXTURE_COUNT> m_Textures;


	public:
		RectRenderer(Ref<Shader> shader); // Ref<Camera>& camera);

		void BeginBatch();
		void Submit(const Rect& Rect);
		void Flush();
		void Clear();

		inline int GetDrawCallCount() const { return m_DrawCallCount; }

	private:
		void Draw();
		void GenerateIndeces();
		void CreateTexture(const Rect& path);

	};

}
