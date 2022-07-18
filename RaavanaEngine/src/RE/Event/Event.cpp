#include "repch.h"
#include "Event.h"

namespace RE {

	Event::Event(const std::string& name, EventType type)
		:m_Name(name), m_Type(type){}

}

