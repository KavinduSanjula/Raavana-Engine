#pragma once

#include "core.h"
#include "spdlog/spdlog.h"


namespace RE {

	class RE_API Log {
	public:
		Log() = default;
		~Log(){}

		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_CoreLogger; }

	private:
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
	};

}

#ifdef RE_DEBUG

#define RE_CORE_INFO(...)	::RE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RE_CORE_WARN(...)	::RE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RE_CORE_ERROR(...)	::RE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RE_CORE_TRACE(...)	::RE::Log::GetCoreLogger()->trace(__VA_ARGS__)


#else

#define RE_CORE_INFO(...) 
#define RE_CORE_WARN(...) 
#define RE_CORE_ERROR(...)
#define RE_CORE_TRACE(...)

#endif