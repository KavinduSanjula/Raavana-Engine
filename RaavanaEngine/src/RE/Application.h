#pragma once

#include "core.h"
#include "Window.h"
#include "Event/Event.h"

namespace RE {

	class RE_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		virtual void OnEvent(Event* e);
		virtual void Update() = 0;

	protected:
		Window* m_Window;

	};

}
