#include "repch.h"
#include "opengl_Texture.h"
#include "Log.h"

#include "RE/AssetManager/AssetManager.h"

#include <GL/glew.h>
#include <stb-image/stb_image.h>

namespace RE {

	Ref<Texture> Texture::Create(const std::string& filename) {
		return std::make_shared<OpenglTexture>(filename);
	}

	OpenglTexture::OpenglTexture(const std::string& filename)
	{
		m_AssetID = AssetManager::GetUniqueID();

		if (filename == NO_TEXTURE) {
			unsigned char data[] = { 255,255,255,255 };
			m_LocalBuffer = data;
			m_Width = 1;
			m_Height = 1;
			CreateTexture();
		}
		else {
			stbi_set_flip_vertically_on_load(1);
			m_LocalBuffer = stbi_load(filename.c_str(), &m_Width, &m_Height, &m_NrChannels, 4);

			if (!m_LocalBuffer) {
				RE_CORE_ERROR("Couldn't load the texture!");
			}

			CreateTexture();
			stbi_image_free(m_LocalBuffer);
		}
	}

	OpenglTexture::~OpenglTexture()
	{
		glDeleteTextures(1, &m_RendererID);
	}

	void OpenglTexture::Bind(uint32_t slot) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_RendererID);
	}

	void OpenglTexture::Unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void OpenglTexture::CreateTexture()
	{
		glGenTextures(1, &m_RendererID);
		glBindTexture(GL_TEXTURE_2D, m_RendererID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}