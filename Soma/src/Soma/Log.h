#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Soma {
	class SOMA_API Log {
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define SOMA_CORE_TRACE(...)      ::Soma::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SOMA_CORE_INFO(...)       ::Soma::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SOMA_CORE_WARN(...)       ::Soma::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SOMA_CORE_ERROR(...)      ::Soma::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SOMA_CORE_CRITICAL(...)   ::Soma::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Core Log Macros
#define SOMA_CLIENT_TRACE(...)    ::Soma::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SOMA_CLIENT_INFO(...)     ::Soma::Log::GetClientLogger()->info(__VA_ARGS__)
#define SOMA_CLIENT_WARN(...)     ::Soma::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SOMA_CLIENT_ERROR(...)    ::Soma::Log::GetClientLogger()->error(__VA_ARGS__)
#define SOMA_CLIENT_CRITICAL(...) ::Soma::Log::GetClientLogger()->critical(__VA_ARGS__)