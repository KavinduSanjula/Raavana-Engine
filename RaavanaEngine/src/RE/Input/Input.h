#pragma once

#include "RE/core.h"
#include "keycodes.h"

namespace RE {

	class RE_API Input {

	public:
		inline static bool IsKeyPressed(int keycode) { return instance->IsKeyPressedImpl(keycode); }
		inline static bool IsMouseButtonPressed(int button) { return instance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<float, float> GetMousePosition() { return instance->GetMousePositionImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(int keycode) const = 0;
		virtual bool IsMouseButtonPressedImpl(int button) const = 0;
		virtual std::pair<float, float> GetMousePositionImpl() const = 0;

	private:
		static Input* instance;

	};

}