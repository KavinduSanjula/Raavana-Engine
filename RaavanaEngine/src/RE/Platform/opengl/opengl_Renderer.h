#pragma once

#include "Renderer/Renderer.h"

namespace RE {

	class OpenglRenderer : public Renderer {
	public:
		void Clear(float r, float g, float b, float a) const override;
		void Draw(Ref<VertexArray> va, Ref<IndexBuffer> ib, Ref<Shader> shader, uint32_t indexCount) const override;
	};

}