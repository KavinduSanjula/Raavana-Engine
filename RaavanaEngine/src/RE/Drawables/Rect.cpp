#include <repch.h>
#include "Rect.h"

namespace RE {

	void make_quad(std::array<Vertex, 4>& arr, const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color, float texID);


	Rect::Rect(const glm::vec2& pos, const glm::vec2& size, const std::string& texture, const glm::vec4& color /*= {1.0,1.0,1.0,1.0}*/)
		:m_Pos(pos), m_Size(size), m_Color(color), m_TexturePath(texture)
	{
		make_quad(m_Vertices, m_Pos, m_Size, m_Color, 0);
	}

	Rect::~Rect()
	{

	}

	void Rect::SetTextureID(float texID) const
	{
		make_quad(m_Vertices, m_Pos, m_Size, m_Color, texID);
	}

	Ref<VertexBuffer> Rect::GetVertexBuffer()
	{
		std::array<Vertex, 4> verticies = GetVertices();
		auto vb = VertexBuffer::Create(&verticies, sizeof(verticies));
		return vb;
	}

	void make_quad(std::array<Vertex, 4>& arr, const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color, float texID) {
		arr[0].Position = { pos.x,pos.y, 0 };
		arr[0].Color = { color.x, color.y, color.z, color.w };
		arr[0].TexCoord = { 0,0 };
		arr[0].TexID = texID;

		arr[1].Position =  { pos.x + size.x, pos.y, 0};
		arr[1].Color = { color.x, color.y, color.z, color.w };
		arr[1].TexCoord = { 1,0 };
		arr[1].TexID = texID;

		arr[2].Position =  { pos.x + size.x, pos.y + size.y, 0};
		arr[2].Color = { color.x, color.y, color.z, color.w };
		arr[2].TexCoord = { 1,1 };
		arr[2].TexID = texID;

		arr[3].Position = { pos.x, pos.y + size.y, 0};
		arr[3].Color = { color.x, color.y, color.z, color.w };
		arr[3].TexCoord = { 0,1 };
		arr[3].TexID = texID;
	}

}