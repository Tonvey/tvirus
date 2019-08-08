#pragma once
#include "Macro.h"
#include <vector>
#include <string>
#include <Poco/Environment.h>
#include "Singleton.hpp"
TV_NAME_SPACE_BEGIN
class Environment:
    public Singleton<Environment>,
    public Poco::Environment
{
public:
    void setArgs(std::vector<std::string> &args);
    std::vector<std::string> getArgs();
    std::string GetGitRevision()const
    {
        return GIT_REVISION;
    }
private:
    std::vector<std::string> mArgs;
};
TV_NAME_SPACE_END
