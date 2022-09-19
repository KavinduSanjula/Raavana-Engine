#pragma once
#include "RE/core.h"
#include "VertexBufferLayout.h"

namespace RE {

	struct Float4 {
		float x, y, z, w;
	};
	struct Float3 {
		float x, y, z;
	};
	struct Float2 {
		float x, y;
	};

	struct RE_API Vertex {
		Float3 Position;
		Float4 Color;
		Float2 TexCoord;
		float TexID;

		static Ref<VertexBufferLayout> GetLayout() {

			Ref<VertexBufferLayout> layout = VertexBufferLayout::Create();
			layout->PushFloat(3);
			layout->PushFloat(4);
			layout->PushFloat(2);
			layout->PushFloat(1);

			return layout;
		}
	};

}