#pragma once

#include "core.h"
#include "Math/types.h"
#include "Renderer/VertexBufferLayout.h"

namespace RE {

	struct RE_API Vertex {

		Float3 Position;
		Float4 Color;
		Float2 TexCoord;
		float TexID;

		static Ref<VertexBufferLayout> GetLayout() {

			auto layout = VertexBufferLayout::Create();

			layout->PushFloat(3);
			layout->PushFloat(4);
			layout->PushFloat(2);
			layout->PushFloat(1);

			return layout;
		}
	};

}