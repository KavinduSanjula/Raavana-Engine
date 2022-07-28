#include "repch.h"
#include "opengl_Renderer.h"

#include "opengl.h"

namespace RE {

	Ref<Renderer> Renderer::Create() { return std::make_shared<OpenglRenderer>(); }

	void OpenglRenderer::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void OpenglRenderer::Draw(Ref<VertexArray> va, Ref<IndexBuffer> ib, Ref<Shader> shader, uint32_t indexCount) const
	{
		va->Bind();
		ib->Bind();
		shader->Bind();
		glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
	}

}