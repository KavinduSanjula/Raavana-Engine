#include "repch.h"
#include "WindowsWindow.h"


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

}