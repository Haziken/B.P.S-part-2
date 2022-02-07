#pragma once
#include <string>
extern "C" 
{
#include "libs/Lua/lua.h"
#include "libs/Lua/lauxlib.h"
#include "libs/Lua/lualib.h"
}
//#include <LuaBridge/LuaBridge.h>

#pragma comment(lib, "libs/Lua/liblua54.a")

class LuaRunner
{
public:
	LuaRunner(const std::string& filePath);
	~LuaRunner();

private:
	//lua_State* L;
};

