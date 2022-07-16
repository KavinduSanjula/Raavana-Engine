#pragma once
#include <memory>

#include "RE/core.h"

namespace RE {

	class RE_API VertexBuffer {
	public:
		VertexBuffer() { m_RendererID = 0; }
		virtual ~VertexBuffer() {};

		virtual void SetData(const void* data, uint32_t size) = 0;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		inline virtual uint32_t GetRendererID() const { return m_RendererID; }

		static std::shared_ptr<VertexBuffer> Create(const void* data, uint32_t size);

	protected:
		uint32_t m_RendererID;
	};

}