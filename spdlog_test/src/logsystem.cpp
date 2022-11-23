#include "logsystem.h"

namespace mylogger {

std::vector<std::shared_ptr<BaseLogger>> LoggerSystem::logger_vector;

void LoggerSystem::SetLogger(std::shared_ptr<BaseLogger> logger) {
    if (logger == nullptr) {
        return;
    }
    logger_vector.emplace_back(logger);
}

void LoggerSystem::Log(const spdlog::level::level_enum level, const std::string &str) {
    for (std::shared_ptr<BaseLogger> logger: logger_vector) {
        logger->Log(level, str);
    }
}

void LoggerSystem::TraceLog(const std::string &str) {
    Log(spdlog::level::trace, str);
}

void LoggerSystem::DebugLog(const std::string &str) {
    Log(spdlog::level::debug, str);
}

void LoggerSystem::ErrLog(const std::string &str) {
    Log(spdlog::level::err, str);
}

void LoggerSystem::InfoLog(const std::string &str) {
    Log(spdlog::level::info, str);
}

void LoggerSystem::WarnLog(const std::string &str) {
    Log(spdlog::level::warn, str);
}

void LoggerSystem::CriticalLog(const std::string &str) {
    Log(spdlog::level::critical, str);
}

void LoggerSystem::OffLog(const std::string &str) {
    Log(spdlog::level::off, str);
}

}
