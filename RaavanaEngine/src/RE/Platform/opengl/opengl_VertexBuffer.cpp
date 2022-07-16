#include "repch.h"
#include "opengl_VertexBuffer.h"

#include "GL/glew.h"

namespace RE {

	std::shared_ptr<VertexBuffer> VertexBuffer::Create(const void* data, uint32_t size) {
		return std::make_shared<OpenglVertexBuffer>(data, size, GL_DYNAMIC_DRAW);
	}
	
	OpenglVertexBuffer::OpenglVertexBuffer(const void* data, uint32_t size, uint32_t mode)
	{
		std::cout << "OpenGL Vertex Buffer Created!" << std::endl;
	}

	OpenglVertexBuffer::~OpenglVertexBuffer()
	{
		std::cout << "OpenGL Vertex Buffer Deleted!" << std::endl;
	}

	void OpenglVertexBuffer::SetData(const void* data, uint32_t size)
	{

	}

	void OpenglVertexBuffer::Bind() const
	{

	}

	void OpenglVertexBuffer::Unbind() const
	{

	}

}