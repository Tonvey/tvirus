#include "Application.h"
#include "Environment.h"
#include <Poco/Foundation.h>
#include "Updater.h"
#include "Logger.h"
using namespace std;
TV_NAME_SPACE_BEGIN
Application::Application(int argc,char **argv)
{
    vector<string> args;
    args.reserve(argc);
    for(int i = 0 ;i<argc ; ++i)
    {
        args.push_back(argv[i]);
    }
    Environment::GetInstance().setArgs(args);
}
int Application::run()
{
    Logger::GetInstance();
    logger_trace("trace");
    logger_debug("debug");
    logger_infomation("infomation");
    logger_warning("warning");
    logger_error("error");
    logger_critical("critical");
    logger_fatal("fatal");
    return 0;
}
TV_NAME_SPACE_END
