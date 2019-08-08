#pragma once
#include "Macro.h"
#include <string>
#include <stdexcept>
TV_NAME_SPACE_BEGIN
class Patcher
{
public:
    static Patcher &getInstance(){return smInstance;}
    void DoPatch(std::string oldFile,std::string newFile,std::string patchFile);
    void DoDiff(std::string oldFile,std::string newFile,std::string patchFile);
private:
    Patcher();
    Patcher(const Patcher&)=delete;
    void operator=(const Patcher&)=delete;
    void operator=(Patcher&&)=delete;
    static Patcher smInstance;
};
TV_NAME_SPACE_END
