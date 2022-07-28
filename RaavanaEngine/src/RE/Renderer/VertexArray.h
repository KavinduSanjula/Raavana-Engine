#pragma once

#include "RE/core.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace RE {

	class RE_API VertexArray
	{

	public:
		VertexArray() {}
		virtual ~VertexArray() {}

		inline uint32_t GetRendererID() const { return m_RendererID; }

		virtual void AddBuffer(const Ref<VertexBuffer> vb, const Ref<VertexBufferLayout> layout) = 0;
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		static Ref<VertexArray> Create();

	protected:
		uint32_t m_RendererID = 0;
	};
}