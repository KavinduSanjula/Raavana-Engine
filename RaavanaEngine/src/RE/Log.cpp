#include "repch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace RE {
	std::shared_ptr<spdlog::logger> Log::m_CoreLogger = nullptr;

	void Log::Init()
	{

		spdlog::set_pattern("[%T]:[%n] (%^%l%$) %v");

		m_CoreLogger = spdlog::stdout_color_mt("RAAVANA");
		m_CoreLogger->set_level(spdlog::level::trace);

	}

}

