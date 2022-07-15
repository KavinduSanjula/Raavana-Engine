#include "Application.h"


namespace RE {

	Application::Application()
	{
		m_Window = Window::Create("Raavana Engine", 1280, 720);
	}

	Application::~Application()
	{
		delete m_Window;
	}

	void Application::Run()
	{
		if (m_Window->HasError()) return;
		while (!m_Window->ShouldClose()) {
			m_Window->Update();
			Update();
		}
	}

}