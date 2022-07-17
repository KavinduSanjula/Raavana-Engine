#pragma once

#include "GL/glew.h"
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Application.h"

namespace RE {

	class RE_API WindowsWindow : public Window {

	public:
		WindowsWindow(const std::string& title, int width, int height);
		~WindowsWindow();


		void Update() override;
		void* GetNativeWindow() const override;
		bool ShouldClose() const override;

		void SetEventCallback(std::function<void(Event*)> callback) override;

		static Window* Create(const std::string& title, int width, int height);

	private:
		GLFWwindow* m_Window;
		std::function<void(Event*)> m_EventCallback;

		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};

}