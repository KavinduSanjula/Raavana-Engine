#pragma once

#include "RE/core.h"
#include "RE/Renderer/Texture.h"
#include "RE/Renderer/Shader.h"

#include <unordered_map>

namespace RE {

	class RE_API AssetManager {

	public:
		AssetManager();
		~AssetManager();

	private:
		uint32_t GenerateID();
		Ref<Texture> Create_Texture(const std::string& filename);
		Ref<Shader> Create_Shader(const std::string& filename);


	public:
		static AssetManager* INSTANCE;
		inline static uint32_t GetUniqueID() { return AssetManager::INSTANCE->GenerateID(); }

		inline static Ref<Texture> CreateTexture(const std::string& filename = NO_TEXTURE) { return AssetManager::INSTANCE->Create_Texture(filename); }
		inline static Ref<Shader> CreateShader(const std::string& filename) { return AssetManager::INSTANCE->Create_Shader(filename); }


	private:
		uint32_t m_Available_ID = 0;
		std::unordered_map<std::string, Ref<Texture>> m_Textures;
		std::unordered_map<std::string, Ref<Shader>> m_Shaders;


	};

}