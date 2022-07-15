#pragma once

#include "GL/glew.h"
#include <GLFW/glfw3.h>

#include "RE/Window.h"

namespace RE {

	class RE_API WindowsWindow : public Window {

	public:
		WindowsWindow(const std::string& title, int width, int height);
		~WindowsWindow();


		void Update() override;
		bool ShouldClose() const override;

		static Window* Create(const std::string& title, int width, int height);

	private:
		GLFWwindow* m_Window;		
	};

}