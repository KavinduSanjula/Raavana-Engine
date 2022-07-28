#pragma once

#include <string>

#include "RE/core.h"

namespace RE {

	class RE_API Texture {

	public:
		virtual ~Texture(){}

		virtual void Bind(uint32_t slot = 0) const = 0;
		virtual void Unbind() const = 0;

		static Ref<Texture> Create(const std::string& filename);

	protected:
		uint32_t m_RendererID = 0;
		int m_Width=0, m_Height=0, m_NrChannels=0;
		unsigned char* m_LocalBuffer=nullptr;
	};

}
