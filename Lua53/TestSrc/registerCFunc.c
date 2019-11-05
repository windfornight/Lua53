#include "registerCFunc.h"
#include "lstate.h"
#include <math.h>
#include <stdlib.h>
#include "lua.h"

static int l_sin(lua_State *L) {
	double d = luaL_checknumber(L, 1);//lua_tonumber(L, 1); /* get argument */
	lua_pushnumber(L, sin(d)); /* push result */
	return 1; /* number of results */
}


void testRegisterCFunc(lua_State *L)
{
	lua_pushcfunction(L, l_sin);
	lua_setglobal(L, "mysin");
}