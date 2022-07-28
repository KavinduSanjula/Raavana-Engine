#pragma once

#include "Renderer/Shader.h"
#include "Log.h"

namespace RE {
	class OpenglShader : public Shader {
	
	public:
		OpenglShader(const std::string& shaderPath);
		~OpenglShader();

		void Bind() const override;
		void Unbind() const override;

		void SetUniformI1(const std::string& name, int value) override;

	private:
		void ReadShader();
		int GetUniformLocation(const std::string& name);
		uint32_t compile_shader(uint32_t type, std::string shaderSource) const;

	};
}