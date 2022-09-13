#include <repch.h>
#include "AssetManager.h"

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

}