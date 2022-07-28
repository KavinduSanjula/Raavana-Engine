#pragma once

#include "Renderer/VertexArray.h"

namespace RE {

	class OpenglVertexArray : public VertexArray {

	public:
		OpenglVertexArray();
		~OpenglVertexArray();

		void AddBuffer(const Ref<VertexBuffer> vb, const Ref<VertexBufferLayout> layout) override;
		void Bind() const override;
		void UnBind() const override;
	};

}