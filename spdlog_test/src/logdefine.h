#include <logsystem.h>

#define BOBBY_LOG_TRACE(log) mylogger::LoggerSystem::TraceLog(log)
#define BOBBY_LOG_DEBUG(log) mylogger::LoggerSystem::DebugLog(log)
#define BOBBY_LOG_INFO(log) mylogger::LoggerSystem::InfoLog(log)
#define BOBBY_LOG_Warn(log) mylogger::LoggerSystem::WarnLog(log)
#define BOBBY_LOG_ERROR(log) mylogger::LoggerSystem::ErrLog(log)
#define BOBBY_LOG_CRITICAL(log) mylogger::LoggerSystem::CriticalLog(log)
#define BOBBY_LOG_OFF(log) mylogger::LoggerSystem::OffLog(log)