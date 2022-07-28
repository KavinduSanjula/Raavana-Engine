#include "repch.h"
#include "opengl_VertexBufferLayout.h"

#include "Log.h"
#include "../opengl.h"

namespace RE {

	Ref<VertexBufferLayout> VertexBufferLayout::Create() {
		return std::make_shared<OpenglVertexBufferLayout>();
	}

	void OpenglVertexBufferLayout::PushFloat(uint32_t count)
	{
		RE_CORE_INFO("Pushing floats {0}", count);
		VertexBufferLayoutElement element({ GL_FLOAT, count, GL_FALSE, sizeof(float) });
		m_Elements.push_back(element);
		m_Stride += count * sizeof(float);
	}

}