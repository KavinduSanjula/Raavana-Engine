#pragma once

#include "Renderer/Texture.h"

namespace RE {
	
	class OpenglTexture : public Texture {
	public:
		OpenglTexture(const std::string& filename);
		~OpenglTexture();

		void Bind(uint32_t slot=0) const override;
		void Unbind() const override;

	private:
		void CreateTexture();
	};
}