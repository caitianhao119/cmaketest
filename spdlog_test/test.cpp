#include <baselogger.h>
#include <logsystem.h>
#include <logdefine.h>
#include "config.h"

 int main()
 {
    std::shared_ptr<mylogger::BasicSTLogger> logger(new mylogger::BasicSTLogger());
    std::shared_ptr<mylogger::StdOutSTLOgger> std_logger(new mylogger::StdOutSTLOgger());
    std::string file_name = std::string(FILE_ROOT_PATH) + "/log.txt";
    logger->setBasicLogger("test", file_name);
    std_logger->setBasicLogger("stdout");

    mylogger::LoggerSystem::SetLogger(logger);
    mylogger::LoggerSystem::SetLogger(std_logger);
    BOBBY_LOG_ERROR("bobby");

 }

//  https://blog.csdn.net/qq_39568245/article/details/115714105
// https://tashaxing.blog.csdn.net/article/details/111992209?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-111992209-blog-121284474.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-111992209-blog-121284474.pc_relevant_default&utm_relevant_index=2