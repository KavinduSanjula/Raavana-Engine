#pragma once
#include <memory>

#include "RE/core.h"

namespace RE {

	class RE_API IndexBuffer {
	public:
		IndexBuffer() { m_RendererID = 0; m_IndexCount = 0; }
		virtual ~IndexBuffer() {};

		virtual void SetData(const void* data, uint32_t count) = 0;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		inline virtual uint32_t GetRendererID() const { return m_RendererID; }

		static std::shared_ptr<IndexBuffer> Create(const void* data, uint32_t count);

	protected:
		uint32_t m_RendererID;
		uint32_t m_IndexCount;
	};

}