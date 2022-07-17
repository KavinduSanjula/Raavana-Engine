#include "repch.h"
#include "WindowsWindow.h"

#include "Event/KeyboardEvent.h"

namespace RE {

	Window* Window::Create(const std::string& title, int width, int height) {
		return new WindowsWindow(title, width, height);
	}


	WindowsWindow::WindowsWindow(const std::string& title, int width, int height)
		:m_Window(nullptr)
	{
		m_Error = false;
		m_Title = title;
		m_Width = width;
		m_Height = height;

		if (!glfwInit()) {
			m_Error = true;
			return;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL);
		if (!m_Window) {
			m_Error = true;
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(m_Window);
		glewInit();

		glfwSetWindowUserPointer(m_Window, this);
		glfwSetKeyCallback(m_Window, key_callback);
			
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwTerminate();
	}

	void WindowsWindow::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void* WindowsWindow::GetNativeWindow() const
	{
		return m_Window;
	}

	bool WindowsWindow::ShouldClose() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	void WindowsWindow::SetEventCallback(std::function<void(Event*)> callback)
	{
		m_EventCallback = callback;
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

		auto win = (WindowsWindow*)glfwGetWindowUserPointer(window);
		if (!win->m_EventCallback) return;

		if (action == GLFW_PRESS) {
			Event* e = new KeyPressed(key, 0);
			win->m_EventCallback(e);
		}
		else if (action == GLFW_REPEAT) {
			Event* e = new KeyPressed(key, 1);
			win->m_EventCallback(e);
		}
		else if (action == GLFW_RELEASE) {
			Event* e = new KeyReleased(key);
			win->m_EventCallback(e);
		}
	}

}