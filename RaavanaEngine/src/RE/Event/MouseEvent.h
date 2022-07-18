#pragma once

#include "core.h"
#include "Event.h"

namespace RE {

	class RE_API MouseMoved : public Event {
	public:
		MouseMoved(float pos_x, float pos_y);
		~MouseMoved(){}

		inline std::tuple<float, float> GetMousePosition() const { return { m_Mx, m_My }; }

		CREATE_STATIC("MouseMoved", EventType::MouseMoved)

	private:
		float m_Mx;
		float m_My;
	};

	class RE_API MouseButtonPressed : public Event {
	public:
		MouseButtonPressed(int button);
		~MouseButtonPressed(){}

		inline int GetButton() const { return m_Button; }

	private:
		int m_Button;
	};

	class RE_API MouseButtonReleased : public Event {
	public:
		MouseButtonReleased(int button);
		~MouseButtonReleased() {}

		inline int GetButton() const { return m_Button; }

	private:
		int m_Button;
	};

}