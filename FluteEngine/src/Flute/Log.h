#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Flute
{
	class FLUTE_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;   //核心日志
		static std::shared_ptr<spdlog::logger> s_ClientLogger; //客户端日志
	};
}

//核心日志宏
#define FL_CORE_ERROR(...)    ::Flute::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FL_CORE_WARN(...)     ::Flute::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FL_CORE_INFO(...)     ::Flute::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FL_CORE_TRACE(...)    ::Flute::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FL_CORE_FATAL(...)    ::Flute::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//客户端日志宏
#define FL_ERROR(...)         ::Flute::Log::GetClientLogger()->error(__VA_ARGS__)
#define FL_WARN(...)          ::Flute::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FL_INFO(...)          ::Flute::Log::GetClientLogger()->info(__VA_ARGS__)
#define FL_TRACE(...)         ::Flute::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FL_FATAL(...)         ::Flute::Log::GetClientLogger()->fatal(__VA_ARGS__)
