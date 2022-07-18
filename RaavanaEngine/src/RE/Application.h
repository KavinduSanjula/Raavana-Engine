#pragma once

#include "core.h"
#include "Window.h"

#include "Event/Event.h"
#include "Event/KeyboardEvent.h"
#include "Event/ApplicationEvent.h"
#include "Event/MouseEvent.h"

namespace RE {

	class RE_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event* e);

		virtual void Update() = 0;

		virtual void OnWindowClosed(WindowClosed* e);
		virtual void OnWindowResized(WindowResized* e);

		virtual void OnKeyPressed(KeyPressed* e);
		virtual void OnKeyReleased(KeyReleased* e);

		virtual void OnMouseMoved(MouseMoved* e);
		virtual void OnMousePressed(MouseButtonPressed* e);
		virtual void OnMouseReleased(MouseButtonReleased* e);

	protected:
		Window* m_Window;

	private:
		bool m_Running = false;

	};

}
