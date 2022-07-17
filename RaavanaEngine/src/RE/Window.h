#pragma once
#include <string>
#include <functional>


#include "RE/core.h"
#include "Event/Event.h"

namespace RE {

	class RE_API Window {
	public:
		Window(){}
		virtual ~Window() {}

		virtual void Update() = 0;
		virtual bool ShouldClose() const = 0;

		virtual void SetEventCallback(std::function<void(Event*)> callback) = 0;

		virtual void* GetNativeWindow() const = 0;

		inline virtual std::string GetTitle() const { return m_Title; }
		inline virtual int GetWidth() const { return m_Width; }
		inline virtual int GetHeight()const { return m_Height; }
		inline virtual bool HasError() const { return m_Error; }

		static Window* Create(const std::string& title, int width, int height);

	protected:
		bool m_Error = false;
		std::string m_Title="NO_TITLE";
		int m_Width=0, m_Height=0;
	};

}
