#pragma once

#include "RE/Renderer/VertexBufferLayout.h"
#include "RE/core.h"

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace RE {

	struct RE_API Vertex {
		glm::vec3 Position;
		glm::vec4 Color;
		glm::vec2 TexCoord;
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
