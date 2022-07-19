#pragma once

#include "core.h"
#include "Input/Input.h"

namespace RE {

	class RE_API WindowsInput : public Input {

	protected:
		bool IsKeyPressedImpl(int keycode) const override;
		bool IsMouseButtonPressedImpl(int button) const override;
		std::pair<float, float> GetMousePositionImpl() const override;

	};

}
