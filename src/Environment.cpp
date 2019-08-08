#include "Environment.h"
TV_NAME_SPACE_BEGIN
Environment Environment::smInstance;
void Environment::setArgs(std::vector<std::string> &args)
{
    this->mArgs = args;
}
std::vector<std::string> Environment::getArgs()
{
    return this->mArgs;
}
TV_NAME_SPACE_END
