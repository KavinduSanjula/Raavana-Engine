#pragma once

#include "RE/core.h"
#include "Event.h"

namespace RE {

	class RE_API WindowClosed : public Event {
	public:
		WindowClosed();
		~WindowClosed() {}

	};

	class RE_API WindowResized : public Event {
	public:
		WindowResized(int width, int height);
		~WindowResized(){}

		inline std::tuple<int, int> GetSize() const { return { m_Width,m_Height }; }

	private:
		int m_Width; 
		int m_Height;
	};
}