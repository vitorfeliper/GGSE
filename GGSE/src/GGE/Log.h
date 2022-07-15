#pragma once
#pragma warning (disable: 4251)

#include "ggpch.h"
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace GGSE
{
	class GanjGameEngine_API Log
	{
	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr <spdlog::logger> s_CoreLogger;
		static std::shared_ptr <spdlog::logger> s_ClientLogger;
	};
}
#pragma region MACROS

// Core log macros
#define GGS_CORE_TRACE(...)   ::GGSE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GGS_CORE_INFO(...)    ::GGSE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GGS_CORE_WARN(...)    ::GGSE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GGS_CORE_ERROR(...)   ::GGSE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GGS_CORE_FATAL(...)	  ::GGSE::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define GGS_CLIENT_TRACE(...) ::GGSE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GGS_CLIENT_INFO(...)  ::GGSE::Log::GetClientLogger()->info(__VA_ARGS__)
#define GGS_CLIENT_WARN(...)  ::GGSE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GGS_CLIENT_ERROR(...) ::GGSE::Log::GetClientLogger()->error(__VA_ARGS__)
#define GGS_CLIENT_FATAL(...) ::GGSE::Log::GetClientLogger()->fatal(__VA_ARGS__)


#pragma endregion