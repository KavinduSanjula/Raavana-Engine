#pragma once
#include <vector>

#include "RE/core.h"

namespace RE {

	struct VertexBufferLayoutElement {
		unsigned int type;
		unsigned int count;
		unsigned int normalized;
		unsigned int size;
	};


	class RE_API VertexBufferLayout {

	public:

		inline std::vector<VertexBufferLayoutElement> GetElements() const { return m_Elements; }
		inline uint32_t GetStride() const { return m_Stride; }

		virtual void PushFloat(uint32_t count) = 0;

		static Ref<VertexBufferLayout> Create();

	protected:
		uint32_t m_Stride = 0;
		std::vector<VertexBufferLayoutElement> m_Elements;

	};

}