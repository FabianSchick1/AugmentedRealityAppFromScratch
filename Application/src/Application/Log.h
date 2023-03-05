#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace Application {

	class Log
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

// AR Core log macros
#define AR_CORE_TRACE(...)    ::Application::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AR_CORE_INFO(...)	  ::Application::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AR_CORE_WARN(...)     ::Application::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AR_CORE_ERROR(...)    ::Application::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AR_CORE_CRITICAL(...) ::Application::Log::GetCoreLogger()->critical(__VA_ARGS__)

// AR log macros
#define AR_TRACE(...)         ::Application::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AR_INFO(...)          ::Application::Log::GetClientLogger()->info(__VA_ARGS__)
#define AR_WARN(...)          ::Application::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AR_ERROR(...)         ::Application::Log::GetClientLogger()->error(__VA_ARGS__)
#define AR_CRITICAL(...)      ::Application::Log::GetClientLogger()->critical(__VA_ARGS__)