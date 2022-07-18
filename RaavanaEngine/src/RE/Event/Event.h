#pragma once
#include <string>

#include "core.h"

namespace RE {

	enum class EventType {
		None = 0,
		Event,
		KeyPressed, KeyReleased,
		MouseMoved,
		MouseButtonPressed, MouseButtonReleased,
		WindowClosed, WindowResized
	};

	class RE_API Event {

	public:
		Event(const std::string& name, EventType type);
		virtual ~Event(){}

		inline virtual std::string GetObjectName() const { return m_Name; }
		inline virtual EventType GetObjectType() const { return m_Type; }

	protected:
		std::string m_Name;
		EventType m_Type;
	};

}