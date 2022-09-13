#include "repch.h"
#include "opengl_Shader.h"

#include "opengl.h"

#include "RE/AssetManager/AssetManager.h"

namespace RE {

	void create_error_shader(ShaderSource& source);

	Ref<Shader> Shader::Create(const std::string& shaderPath) {
		return std::make_shared<OpenglShader>(shaderPath);
	}

	OpenglShader::OpenglShader(const std::string& shaderPath)
	{
		m_AssetID = AssetManager::GetUniqueID();

		m_ShaderPath = shaderPath;

		ReadShader();
		uint32_t vertexShader = compile_shader(GL_VERTEX_SHADER, m_Source.VertexShaderSource);
		uint32_t fragmentShader = compile_shader(GL_FRAGMENT_SHADER, m_Source.FragmentShaderSource);

		m_RendererID = glCreateProgram();
		glAttachShader(m_RendererID, vertexShader);
		glAttachShader(m_RendererID, fragmentShader);
		glLinkProgram(m_RendererID);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		glUseProgram(m_RendererID);
	}

	OpenglShader::~OpenglShader()
	{
		glDeleteProgram(m_RendererID);
	}

	void OpenglShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenglShader::Unbind() const
	{
		glUseProgram(0);
	}

	void OpenglShader::SetUniformI1(const std::string& name, int value)
	{
		glUniform1i(GetUniformLocation(name), value);
	}

	void OpenglShader::ReadShader()
	{
		std::ifstream file(m_ShaderPath);
		std::string line;

		if (!file.is_open()) {

			RE_CORE_ERROR("File not found {0}", m_ShaderPath);
			create_error_shader(m_Source);
			return;
		}

		int i = -1;
		while (getline(file, line)) {

			if (line.find("#type Fragment") != line.npos) {
				i = 1;
				continue;
			}
			else if (line.find("#type Vertex") != line.npos) {
				i = 0;
				continue;
			}
			if (i != -1) {
				m_Source[i] += line + "\n";
			}
		}

		if (i == -1)
		{
			RE_CORE_ERROR("No shader");
			create_error_shader(m_Source);
			return;
		}
	}

	int OpenglShader::GetUniformLocation(const std::string& name)
	{
		return glGetUniformLocation(m_RendererID, name.c_str());
	}

	uint32_t OpenglShader::compile_shader(uint32_t type, std::string shaderSource) const
	{
		const char* shader_source = shaderSource.c_str();
		uint32_t shader = glCreateShader(type);
		glShaderSource(shader, 1, &shader_source, NULL);
		glCompileShader(shader);

		int  success;
		char infoLog[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << infoLog << std::endl;
			__debugbreak;
			//ASSERT(false);
		}

		return shader;
	}

	void create_error_shader(ShaderSource& source) {
		std::string vs = "\n"
			"#version 330 core \n"
			"layout (location = 0) in vec2 aPos; \n"
			"void main() { \n"
			"gl_Position = vec4(aPos,1.0,1.0); \n"
			"} \n";

		std::string fs = "\n"
			"#version 330 core \n"
			"out vec4 Color; \n"
			"void main() \n"
			" { \n"
			"Color = vec4(1.0,0.0,1.0,1.0); \n"
			"} \n";

		source.VertexShaderSource = vs;
		source.FragmentShaderSource = fs;
	}
}