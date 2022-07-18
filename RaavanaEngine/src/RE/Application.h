#pragma once

#include "core.h"
#include "Window.h"

#include "Event/Event.h"
#include "Event/KeyboardEvent.h"

namespace RE {

	class RE_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event* e);

		virtual void Update() = 0;

		virtual void OnKeyPressed(KeyPressed* e);
		virtual void OnKeyReleased(KeyReleased* e);

	protected:
		Window* m_Window;

	};

}
