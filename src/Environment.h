#pragma once
#include "Macro.h"
#include <vector>
#include <string>
TV_NAME_SPACE_BEGIN
class Environment
{
public:
    static Environment &GetInstance(){return smInstance;}
    void setArgs(std::vector<std::string> &args);
    std::vector<std::string> getArgs();
private:
    std::vector<std::string> mArgs;
    static Environment smInstance;
};
TV_NAME_SPACE_END
