#include "repch.h"
#include "MouseEvent.h"

namespace RE {

	MouseMoved::MouseMoved(float pos_x, float pos_y) 
		:Event("MouseMoved", EventType::MouseMoved), m_Mx(pos_x), m_My(pos_y) {}
	MouseButtonPressed::MouseButtonPressed(int button) 
		:Event("MouseButtonPressed", EventType::MouseButtonPressed), m_Button(button) {}
	MouseButtonReleased::MouseButtonReleased(int button) 
		:Event("MouseButtonReleased", EventType::MouseButtonReleased), m_Button(button) {}

}