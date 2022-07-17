#pragma once

#include "core.h"
#include "Event.h"

namespace RE {

	class RE_API KeyPressed : public Event {
	public:
		KeyPressed(int key, int mode);
		virtual ~KeyPressed(){}

		CREATE_STATIC("KeyPressed", EventType::KeyPressed)

	private:
		int m_KeyCode;
		int m_Mode;
	};

}