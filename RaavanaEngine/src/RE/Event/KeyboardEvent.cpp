#include "repch.h"
#include "KeyboardEvent.h"

namespace RE {
	

	KeyPressed::KeyPressed(int key, int repeat_count)
		:Event("KeyPressed",EventType::KeyPressed), m_KeyCode(key), m_RepeatCount(repeat_count)
	{
	}

	KeyReleased::KeyReleased(int key)
		: Event("KeyReleased", EventType::KeyReleased), m_KeyCode(key)
	{
	}

}