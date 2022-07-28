#pragma once

#include "Renderer/Renderer.h"

namespace RE {

	class OpenglRenderer : public Renderer {
	public:
		void Clear() const override;
		void Draw(Ref<VertexArray> va, Ref<IndexBuffer> ib, Ref<Shader> shader, uint32_t indexCount) const override;
	};

}