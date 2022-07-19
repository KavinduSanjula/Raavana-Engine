#include "repch.h"
#include "Application.h"

#include "Event/Event.h"
#include "Event/KeyboardEvent.h"

namespace RE {

	Application* Application::instance = nullptr;

	Application::Application()
	{
		m_Window = Window::Create("Raavana Engine", 1280, 720);
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
		m_Running = true;
		Application::instance = this;
	}

	Application::~Application()
	{
		delete m_Window;
	}

	void Application::Run()
	{
		if (m_Window->HasError()) return;

		while (m_Running) {
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
		case EventType::WindowClosed:
		{
			auto ev = (WindowClosed*)e;
			OnWindowClosed(ev);
			m_Running = false;
			break;
		}
		case EventType::WindowResized:
		{
			auto ev = (WindowResized*)e;
			OnWindowResized(ev);
			break;
		}
		case EventType::MouseMoved:
		{
			auto ev = (MouseMoved*)e;
			OnMouseMoved(ev);
			break;
		}
		case EventType::MouseButtonPressed:
		{
			auto ev = (MouseButtonPressed*)e;
			OnMousePressed(ev);
			break;
		}
		case EventType::MouseButtonReleased:
		{
			auto ev = (MouseButtonReleased*)e;
			OnMouseReleased(ev);
			break;
		}
		}

		delete e;
	}

	void Application::OnKeyPressed(KeyPressed* e){}
	void Application::OnKeyReleased(KeyReleased* e){}

	void Application::OnWindowClosed(WindowClosed* e) {}
	void Application::OnWindowResized(WindowResized* e){}

	void Application::OnMouseMoved(MouseMoved* e){}
	void Application::OnMousePressed(MouseButtonPressed* e){}
	void Application::OnMouseReleased(MouseButtonReleased* e){}

}