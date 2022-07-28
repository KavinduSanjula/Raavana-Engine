#pragma once
#include "core.h"
#include "Renderer/VertexBuffer.h"

namespace RE {

	class OpenglVertexBuffer : public VertexBuffer {

	public:
		OpenglVertexBuffer(const void* data, uint32_t size, uint32_t mode);
		~OpenglVertexBuffer();

		void SetData(const void* data, uint32_t size) override;

		void Bind() const override;
		void Unbind() const override;
	};

}