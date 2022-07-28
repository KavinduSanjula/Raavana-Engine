#pragma once

#include "RE/core.h"

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

namespace RE {
	class RE_API Renderer {

	public:
		virtual void Clear() const = 0;
		virtual void Draw(Ref<VertexArray> va, Ref<IndexBuffer> ib, Ref<Shader> shader, uint32_t index_count) const = 0;

		static Ref<Renderer> Create();
	};
}