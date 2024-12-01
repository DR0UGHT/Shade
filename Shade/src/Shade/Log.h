#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

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

	namespace util {
		template<typename T>
		std::string toString(const T& t) {
			if constexpr (std::is_same_v<T, std::string>) {
				return t;
			}
			else {
				std::ostringstream oss;
				oss << t;
				return oss.str();
			}
		}

	}

}	

// Core log macros
#define SHADE_CORE_TRACE(...)    ::Shade::Log::GetCoreLogger()->trace(Shade::util::toString(__VA_ARGS__))
#define SHADE_CORE_INFO(...)     ::Shade::Log::GetCoreLogger()->info(Shade::util::toString(__VA_ARGS__))
#define SHADE_CORE_WARN(...)     ::Shade::Log::GetCoreLogger()->warn(Shade::util::toString(__VA_ARGS__))
#define SHADE_CORE_ERROR(...)    ::Shade::Log::GetCoreLogger()->error(Shade::util::toString(__VA_ARGS__))
#define SHADE_CORE_FATAL(...)    ::Shade::Log::GetCoreLogger()->fatal(Shade::util::toString(__VA_ARGS__))

// Client log macros
#define SHADE_TRACE(...)         ::Shade::Log::GetClientLogger()->trace(Shade::util::toString(__VA_ARGS__))
#define SHADE_INFO(...)          ::Shade::Log::GetClientLogger()->info(Shade::util::toString(__VA_ARGS__))
#define SHADE_WARN(...)          ::Shade::Log::GetClientLogger()->warn(Shade::util::toString(__VA_ARGS__))
#define SHADE_ERROR(...)         ::Shade::Log::GetClientLogger()->error(Shade::util::toString(__VA_ARGS__))
#define SHADE_FATAL(...)         ::Shade::Log::GetClientLogger()->fatal(Shade::util::toString(__VA_ARGS__))
