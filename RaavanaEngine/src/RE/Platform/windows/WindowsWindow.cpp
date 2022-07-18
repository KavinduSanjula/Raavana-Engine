#include "repch.h"
#include "WindowsWindow.h"

#include "Event/KeyboardEvent.h"
#include "Event/ApplicationEvent.h"
#include "Event/MouseEvent.h"

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
		glfwSetWindowSizeCallback(m_Window, size_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwTerminate();
	}

	void WindowsWindow::Update()
	{
		if (glfwWindowShouldClose(m_Window)) {
			Event* e = new WindowClosed();
			m_EventCallback(e);
		}
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void* WindowsWindow::GetNativeWindow() const
	{
		return m_Window;
	}

	void WindowsWindow::ResizeViewport() const
	{
		glViewport(0, 0, m_Width, m_Height);
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

	void size_callback(GLFWwindow* window, int width, int height) {

		auto win = (WindowsWindow*)glfwGetWindowUserPointer(window);
		win->m_Width = width;
		win->m_Height = height;
		win->ResizeViewport();

		Event* e = new WindowResized(width, height);
		win->m_EventCallback(e);
	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
		auto win = (WindowsWindow*)glfwGetWindowUserPointer(window);
		Event* e = new MouseMoved((float)xpos, (float)ypos);
		win->m_EventCallback(e);
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
		auto win = (WindowsWindow*)glfwGetWindowUserPointer(window);

		if (action == GLFW_PRESS) {
			Event* e = new MouseButtonPressed(button);
			win->m_EventCallback(e);
		}
		else if (action == GLFW_RELEASE) {
			Event* e = new MouseButtonReleased(button);
			win->m_EventCallback(e);
		}
	}

}