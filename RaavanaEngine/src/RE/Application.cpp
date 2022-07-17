#include "repch.h"
#include "Application.h"

#include "Event/Event.h"
#include "Event/KeyboardEvent.h"

namespace RE {

	Application::Application()
	{
		m_Window = Window::Create("Raavana Engine", 1280, 720);
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
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

	void Application::OnEvent(Event* e)
	{
		delete e;
	}

}