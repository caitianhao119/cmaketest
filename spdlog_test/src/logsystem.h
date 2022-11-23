#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/logger.h>
#include <string>
#include <vector>
#include "baselogger.h"

#pragma once
namespace mylogger {

class LoggerSystem {
public:
    static void SetLogger(std::shared_ptr<BaseLogger>);
    static void TraceLog(const std::string &str);
    static void DebugLog(const std::string &str);
    static void InfoLog(const std::string &str);
    static void WarnLog(const std::string &str);
    static void ErrLog(const std::string &str);
    static void CriticalLog(const std::string &str);
    static void OffLog(const std::string &str);
private:
    static void Log(const spdlog::level::level_enum level, const std::string &str);
    static std::vector<std::shared_ptr<BaseLogger>> logger_vector;
};

}