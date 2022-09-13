#pragma once

#include "RE/core.h"

namespace RE {

	class RE_API AssetManager {

	public:
		AssetManager();
		~AssetManager();

	public:
		uint32_t GenerateID();

	public:
		static AssetManager* INSTANCE;
		inline static uint32_t GetUniqueID() { return AssetManager::INSTANCE->GenerateID(); }


	private:
		uint32_t m_Available_ID = 0;


	};

}