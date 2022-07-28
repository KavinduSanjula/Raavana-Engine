#pragma once
#include "core.h"
#include "Renderer/IndexBuffer.h"

namespace RE {

	class OpenglIndexBuffer : public IndexBuffer {

	public:
		OpenglIndexBuffer(const void* data, uint32_t count, uint32_t mode);
		~OpenglIndexBuffer();

		void SetData(const void* data, uint32_t count) override;

		void Bind() const override;
		void Unbind() const override;
	};

}