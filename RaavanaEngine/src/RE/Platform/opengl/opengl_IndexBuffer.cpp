#include "repch.h"
#include "opengl_IndexBuffer.h"

#include "opengl.h"

namespace RE {

	std::shared_ptr<IndexBuffer> IndexBuffer::Create(const void* data, uint32_t count) {
		return std::make_shared<OpenglIndexBuffer>(data, count, GL_DYNAMIC_DRAW);
	}

	OpenglIndexBuffer::OpenglIndexBuffer(const void* data, uint32_t count, uint32_t mode)
	{
		m_IndexCount = count;

		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), data, mode);
	}

	OpenglIndexBuffer::~OpenglIndexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenglIndexBuffer::SetData(const void* data, uint32_t count)
	{
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, count * sizeof(uint32_t), data);
	}

	void OpenglIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void OpenglIndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}