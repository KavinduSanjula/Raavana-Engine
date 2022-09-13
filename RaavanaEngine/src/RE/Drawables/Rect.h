#pragma once

#include "RE/core.h"
#include "RE/Renderer/Vertex.h"
#include "RE/Renderer/VertexBuffer.h"

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

#include <string>
#include <array>

namespace RE {

	class RE_API Rect {
	private:
		mutable std::array<Vertex, 4> m_Vertices;
		std::string m_TexturePath;

		glm::vec2 m_Pos;
		glm::vec2 m_Size;
		glm::vec4 m_Color;

	public:
		Rect(const glm::vec2& pos, const glm::vec2& size, const std::string& texture, const glm::vec4& color = {1.0,1.0,1.0,1.0});
		~Rect();

		inline std::array<Vertex, 4> GetVertices() const { return m_Vertices; }
		inline std::string GetTexturePath() const { return m_TexturePath; }

		void SetTextureID(float texID) const;
		Ref<VertexBuffer> GetVertexBuffer();
	};

}
