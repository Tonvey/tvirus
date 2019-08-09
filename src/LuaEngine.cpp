#include "LuaEngine.h"
#include <stdio.h>
#include "Logger.h"
/* Convenience stuff */
static void close_state(lua_State **L) { lua_close(*L); }
#define cleanup(x) __attribute__((cleanup(x)))
#define auto_lclose cleanup(close_state) 
TV_NAME_SPACE_BEGIN
LuaEngine::LuaEngine()
{
    /* Create VM state */
    //auto_lclose lua_State *L = luaL_newstate();
    mL = luaL_newstate();
    if (!mL)
    {
        logger_fatal("Cannot new lua state");
        exit(-1);
    }
}
void LuaEngine::run()
{
    luaL_openlibs(mL); /* Open standard libraries */
    /* Load config file */
    luaL_loadfile(mL, "main.lua"); /* (1) */
    int ret = lua_pcall(mL, 0, 0, 0);
    if (ret != 0) {
        fprintf(stderr, "%s\n", lua_tostring(mL, -1));
    }
    /* Read out config */
    lua_getglobal(mL, "address"); /* (2) */
    lua_getglobal(mL, "port");
    printf("address: %s, port: %ld\n", /* (3) */
           lua_tostring(mL, -2), lua_tointeger(mL, -1));
    lua_settop(mL, 0); /* (4) */
}
LuaEngine::~LuaEngine()
{
    if(mL)
    {
        lua_close(mL);
    }
}
TV_NAME_SPACE_END
