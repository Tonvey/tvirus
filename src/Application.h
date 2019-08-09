#pragma once
#include "Macro.h"
#include "LuaEngine.h"
TV_NAME_SPACE_BEGIN
class Application
{
public:
    Application(int argc, char **argv);
    int run();
private:
    LuaEngine mScriptEngine;
};
TV_NAME_SPACE_END
