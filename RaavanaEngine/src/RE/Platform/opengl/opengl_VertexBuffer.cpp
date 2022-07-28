#include "repch.h"
#include "opengl_VertexBuffer.h"

#include "opengl.h"
#include "Log.h"

namespace RE {

	std::shared_ptr<VertexBuffer> VertexBuffer::Create(const void* data, uint32_t size) {
		return std::make_shared<OpenglVertexBuffer>(data, size, GL_DYNAMIC_DRAW);
	}
	
	OpenglVertexBuffer::OpenglVertexBuffer(const void* data, uint32_t size, uint32_t mode)
	{
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, data, mode);

		RE_CORE_INFO("Vertex Buffer Created!");
	}

	OpenglVertexBuffer::~OpenglVertexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
		RE_CORE_INFO("Vertex Buffer Deleted!");
	}

	void OpenglVertexBuffer::SetData(const void* data, uint32_t size)
	{
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	}

	void OpenglVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void OpenglVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

}