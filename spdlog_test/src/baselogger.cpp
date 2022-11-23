#include "baselogger.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace mylogger {

void BaseLogger::Log(const spdlog::level::level_enum level, const std::string &str) {
    if (logger == nullptr) {
        return;
    }
    logger->log(level, str);
}

bool BasicSTLogger::setBasicLogger(const std::string &logname, const std::string &path) {
    logger = spdlog::basic_logger_st(logname, path);
    if (logger == nullptr) {
        return false;
    }
    this->name = logname;
    return true;
}

bool StdOutSTLOgger::setBasicLogger(const std::string &logname) {
    logger = spdlog::stdout_color_st(logname);
    if (logger == nullptr) {
        return false;
    }
    this->name = logname;
    logger->set_pattern("%Y-%m-%d %H:%M:%S.%f <thread %t> [%l] [%@] %v");
    return true;
}
}
