#pragma once
#include "Macro.h"
#include <string>
#include "Singleton.hpp"
TV_NAME_SPACE_BEGIN
class Updater : public Singleton<Updater>
{
public:
    void Update(std::string patchFile);
};
TV_NAME_SPACE_END
