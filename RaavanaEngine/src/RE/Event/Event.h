#pragma once
#include "core.h"

namespace RE {

#define CREATE_STATIC(name,type) inline static std::string GetStaticName() { return (name); }\
								 inline static EventType GetStaticType() { return (type); }

	enum class EventType {
		None = 0,
		_Event,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased,
		WindowClosed, WindowResized
	};

	class RE_API Event {

	public:
		Event(const std::string& name, EventType type);
		virtual ~Event(){}

		inline virtual std::string GetObjectName() const { return m_Name; }
		inline virtual EventType GetObjectType() const { return m_Type; }

		inline static std::string GetStaticName() { return "Event"; }
		inline static EventType GetStaticType() { return EventType::_Event; }

	protected:
		std::string m_Name;
		EventType m_Type;
	};

}