#include "repch.h"
#include "KeyboardEvent.h"

namespace RE {
	

	KeyPressed::KeyPressed(int key, int mode)
		:Event("KeyPressed",EventType::KeyPressed), m_KeyCode(key), m_Mode(mode)
	{
		std::cout << "KeyPressed " << key << std::endl;
	}

}