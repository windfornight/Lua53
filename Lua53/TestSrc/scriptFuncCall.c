#include <stdio.h>
#include "scriptFuncCall.h"
#include "utils.h"
#include "lstate.h"
#include "lauxlib.h"
#include "lualib.h"

void load(const char *filename, int *width, int *height) {
	lua_State *L = luaL_newstate();
	luaopen_base(L);
	luaopen_io(L);
	luaopen_string(L);
	luaopen_math(L);
	if (luaL_loadfile(L, filename) || lua_pcall(L, 0, 0, 0))
		error(L, "cannot run configuration file: %s", lua_tostring(L, -1));
	lua_getglobal(L, "width");
	lua_getglobal(L, "height");
	if (!lua_isnumber(L, -2))
		error(L, "`width' should be a number\n");
	if (!lua_isnumber(L, -1))
		error(L, "`height' should be a number\n");
	*width = (int)lua_tonumber(L, -2);
	*height = (int)lua_tonumber(L, -1);
	lua_close(L);
}

double f(double x, double y) {
	const *filename = "LuaScript/config.lua";
	lua_State *L = luaL_newstate();
	luaopen_base(L);
	luaopen_io(L);
	luaopen_string(L);
	//luaopen_math(L);
	luaL_openlibs(L);
	if (luaL_loadfile(L, filename) || lua_pcall(L, 0, 0, 0))
		error(L, "cannot run configuration file: %s", lua_tostring(L, -1));
	double z;
	/* push functions and arguments */
	lua_getglobal(L, "f"); /* function to be called */
	lua_pushnumber(L, x); /* push 1st argument */
	lua_pushnumber(L, y); /* push 2nd argument */
	/* do the call (2 arguments, 1 result) */
	if (lua_pcall(L, 2, 1, 0) != 0)
		error(L, "error running function `f': %s", lua_tostring(L, -1));
	/* retrieve result */
	if (!lua_isnumber(L, -1))
		error(L, "function `f' must return a number");
	z = lua_tonumber(L, -1);
	lua_pop(L, 1); /* pop returned value */
	lua_close(L);
	return z;
}

void testScriptCallFunc()
{
	int width = 0, height = 0;
	load("LuaScript/config.lua", &width, &height);
	//printf("width:%d, height:%d", width, height);
	printf("z is %lf\n", f(0.5, 2));
}







