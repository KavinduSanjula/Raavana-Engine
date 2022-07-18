#include "repch.h"
#include "ApplicationEvent.h"

namespace RE {
	WindowClosed::WindowClosed() :Event("WindowClosed", EventType::WindowClosed) {}
	WindowResized::WindowResized(int width, int height) :Event("WindowResized", EventType::WindowResized), m_Width(width), m_Height(height) {}
}