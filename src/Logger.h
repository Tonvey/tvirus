#pragma once
#include "Macro.h"
#include "Singleton.hpp"
#include <Poco/Logger.h>
#include <memory>
TV_NAME_SPACE_BEGIN
#define logger_debug(...) poco_debug(Poco::Logger::root(),__VA_ARGS__)
#define logger_infomation(...) poco_information(Poco::Logger::root(),__VA_ARGS__)
#define logger_warning(...) poco_warning(poco::Logger::root(),__VA_ARGS__)
#define logger_error(...) poco_error(poco::Logger::root(),__VA_ARGS__)
#define logger_critical(...) poco_critical(Poco::Logger::root(),__VA_ARGS__)
#define logger_fatal(...) poco_fatal(Poco::Logger::root(),__VA_ARGS__)
class Logger:
    public Singleton<Logger>
{
    friend Singleton<Logger>;
public:
    void Debug(std::string content);
    void Info(std::string content);
    void Warn(std::string content);
    void Error(std::string content);
    void Crit(std::string content);
private:
    Logger();
};
TV_NAME_SPACE_END
