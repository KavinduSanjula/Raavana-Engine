#pragma once
#include <string>
#include "RE/core.h"

namespace RE {

	struct ShaderSource {
		std::string VertexShaderSource;
		std::string FragmentShaderSource;

		std::string& operator[] (int index) {
			if (index == 0)
				return VertexShaderSource;
			else
				return FragmentShaderSource;
		}
	};

	class RE_API Shader {

	public:

		virtual ~Shader() {}

		inline uint32_t GetRendererID() const { return m_RendererID; }

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		inline uint32_t GetAssetID() const { return m_AssetID; }

		static Ref<Shader> Create(const std::string& shaderPath);

		virtual void SetUniformI1(const std::string& name, int val) = 0;
		//void SetUniformMat4(const std::string& name, glm::mat4& mat);
		//void SetUniformArrayI(const std::string& name, uint32_t count, int* data);

	protected:
		uint32_t m_AssetID;
		uint32_t m_RendererID;
		std::string m_ShaderPath;
		ShaderSource m_Source;
	};
}