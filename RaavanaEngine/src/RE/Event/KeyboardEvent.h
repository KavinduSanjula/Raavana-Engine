#pragma once

#include "RE/core.h"
#include "Event.h"

namespace RE {

	class RE_API KeyPressed : public Event {
	public:
		KeyPressed(int key, int repeat_count);
		virtual ~KeyPressed(){}

		inline int GetKey() const { return m_KeyCode; }
		inline int GetRepeatCount() const { return m_RepeatCount; }

		CREATE_STATIC("KeyPressed", EventType::KeyPressed)

	private:
		int m_KeyCode;
		int m_RepeatCount;
	};

	class RE_API KeyReleased : public Event {
	public:
		KeyReleased(int key);
		virtual ~KeyReleased() {}

		inline int GetKey() const { return m_KeyCode; }

		CREATE_STATIC("KeyReleased", EventType::KeyReleased)

	private:
		int m_KeyCode;
	};

}