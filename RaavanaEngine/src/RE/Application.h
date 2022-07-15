#pragma once

#include "core.h"

namespace RE {

	class RE_API Application {
	public:
		Application();
		virtual ~Application(){}

		void Run();
		virtual void Update() = 0;

	};

}
