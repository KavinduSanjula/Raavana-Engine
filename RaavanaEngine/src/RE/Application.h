#pragma once

#include "core.h"
#include "Window.h"

namespace RE {

	class RE_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		virtual void Update() = 0;

	protected:
		Window* m_Window;

	};

}
