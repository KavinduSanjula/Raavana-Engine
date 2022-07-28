#include "repch.h"
#include "opengl_VertexArray.h"

#include "opengl.h"

namespace RE {

	Ref<VertexArray> VertexArray::Create() {
		return std::make_shared<OpenglVertexArray>();
	}

	OpenglVertexArray::OpenglVertexArray()
	{
		glGenVertexArrays(1, &m_RendererID);
	}

	OpenglVertexArray::~OpenglVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenglVertexArray::AddBuffer(const Ref<VertexBuffer> vb, const Ref<VertexBufferLayout> layout)
	{
		Bind();
		vb->Bind();

		int offset = 0;
		auto elements = layout->GetElements();
		for (uint32_t i = 0; i < elements.size(); i++) {
			auto& element = elements[i];

			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, element.count, element.type, element.normalized, layout->GetStride(), (void*)(offset * element.size));
			offset += element.count;
		}

		UnBind();
	}

	void OpenglVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenglVertexArray::UnBind() const
	{
		glBindVertexArray(0);
	}
}