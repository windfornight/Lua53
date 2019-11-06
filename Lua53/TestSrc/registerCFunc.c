#include "registerCFunc.h"
#include "lstate.h"
#include <math.h>
#include <stdlib.h>
#include "lua.h"
#include "lauxlib.h"

static int l_sin(lua_State *L) {
	double d = luaL_checknumber(L, 1);//lua_tonumber(L, 1); /* get argument */
	lua_pushnumber(L, sin(d)); /* push result */
	return 1; /* number of results */
}



static const struct luaL_Reg mylib[] = {
	{"mysin", l_sin},
	{NULL, NULL}
};

static int luaopen(lua_State *L) {
	luaL_newlib(L, mylib);
	return 1;
}

int luaopen_mylib(lua_State *L) {
	//luaL_openlib(L, "mylib", mylib, 0);
	luaL_requiref(L, "mylib", luaopen, 1);
	lua_pop(L, 1);  /* remove lib */
	return 1;
}

void testRegisterCFunc(lua_State *L)
{
	//lua_pushcfunction(L, l_sin);
	//lua_setglobal(L, "mysin");
	luaopen_mylib(L);
}