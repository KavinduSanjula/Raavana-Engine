#include <repch.h>
#include "AssetManager.h"

#include "Log.h"

namespace RE {

	AssetManager* AssetManager::INSTANCE = nullptr;

	AssetManager::AssetManager()
	{
		AssetManager::INSTANCE = this;
	}

	AssetManager::~AssetManager()
	{
	}

	uint32_t AssetManager::GenerateID()
	{
		return m_Available_ID++;
	}

	Ref<Texture> AssetManager::Create_Texture(const std::string& filename)
	{
		if (m_Textures.find(filename) != m_Textures.end()) {
			//RE_CORE_INFO("Texture alrady created!");
			return m_Textures[filename];
		}

		m_Textures[filename] = Texture::Create(filename);
		return m_Textures[filename];
	}

	Ref<Shader> AssetManager::Create_Shader(const std::string& filename)
	{
		if (m_Shaders.find(filename) != m_Shaders.end()) {
			//RE_CORE_INFO("Shader alrady created!");
			return m_Shaders[filename];
		}

		m_Shaders[filename] = Shader::Create(filename);
		return m_Shaders[filename];
	}

}