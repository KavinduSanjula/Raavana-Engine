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
		//dispatch event to functions
		switch (e->GetObjectType()) {
		case EventType::KeyPressed:
		{
			auto ev = (KeyPressed*)e;
			OnKeyPressed(ev);
			break;
		}

		case EventType::KeyReleased:
		{
			auto ev = (KeyReleased*)e;
			OnKeyReleased(ev);
			break;
		}
		}

		delete e;
	}

	void Application::OnKeyPressed(KeyPressed* e){}
	void Application::OnKeyReleased(KeyReleased* e){}

}