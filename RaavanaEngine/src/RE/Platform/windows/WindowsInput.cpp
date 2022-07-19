#include "repch.h"
#include "WindowsInput.h"

#include "Application.h"
#include <GLFW/glfw3.h>

namespace RE {

	Input* Input::instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keycode) const
	{
		auto window = (GLFWwindow*)Application::instance->GetNativeWindow();
		int state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button) const
	{
		auto window = (GLFWwindow*)Application::instance->GetNativeWindow();
		int state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl() const
	{
		auto window = (GLFWwindow*)Application::instance->GetNativeWindow();
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { (float)xpos, (float)ypos };
	}

}