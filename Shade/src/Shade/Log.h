#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace Shade {

	class SHADE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}	

// Core log macros
#define SHADE_CORE_TRACE(...)    ::Shade::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SHADE_CORE_INFO(...)     ::Shade::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SHADE_CORE_WARN(...)     ::Shade::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SHADE_CORE_ERROR(...)    ::Shade::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SHADE_CORE_FATAL(...)    ::Shade::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SHADE_TRACE(...)         ::Shade::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SHADE_INFO(...)          ::Shade::Log::GetClientLogger()->info(__VA_ARGS__)
#define SHADE_WARN(...)          ::Shade::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SHADE_ERROR(...)         ::Shade::Log::GetClientLogger()->error(__VA_ARGS__)
#define SHADE_FATAL(...)         ::Shade::Log::GetClientLogger()->fatal(__VA_ARGS__)
