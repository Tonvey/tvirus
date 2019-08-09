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
    //init log module
    Logger::GetInstance();
}
int Application::run()
{
    this->mScriptEngine.run();
    return 0;
}
TV_NAME_SPACE_END
