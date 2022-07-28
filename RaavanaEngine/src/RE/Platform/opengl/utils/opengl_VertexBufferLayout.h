#pragma once

#include "Renderer/VertexBufferLayout.h"

namespace RE {

	class OpenglVertexBufferLayout : public VertexBufferLayout
	{
		void PushFloat(uint32_t count) override;
	};
}