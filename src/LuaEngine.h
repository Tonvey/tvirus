#pragma once
#include "Macro.h"
#include <lua.hpp>
TV_NAME_SPACE_BEGIN
class LuaEngine
{
public:
    LuaEngine();
    ~LuaEngine();
    void run();
private:
    lua_State *mL=nullptr;
};
TV_NAME_SPACE_END
