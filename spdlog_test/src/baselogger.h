#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/logger.h>
#include <string>

#pragma once
namespace mylogger {

class BaseLogger {
public:
    BaseLogger() {}
    void Log(const spdlog::level::level_enum level, const std::string &str);
protected:
    std::shared_ptr<spdlog::logger> logger;
    std::string name;
};

class BasicSTLogger: public BaseLogger {
public:
    bool setBasicLogger(const std::string &logname, const std::string &path);
};

class StdOutSTLOgger: public BaseLogger {
public:
    bool setBasicLogger(const std::string &logname);
};

}